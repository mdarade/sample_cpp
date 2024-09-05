#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <fstream>
#include <vector>

using namespace std;

static const char* kInvalidOperation = "Invalid operation";
static const char* kInvalidExpression = "Invalid expression";
static const char* kDividedByZero = "Division by zero";

class Expression {
public:
    virtual ~Expression() = default;
    virtual int evaluate() const = 0;
    virtual void dump(std::ostream& os) const = 0;
    virtual std::unique_ptr<Expression> copy() const = 0;
protected:
    mutable bool done;
    mutable int result;
};

class LeafExpression : public Expression {
public:
    explicit LeafExpression(int value) : value_(value) {}
    int evaluate() const override { return value_; }
    void dump(std::ostream& os) const override { os << value_; }
    std::unique_ptr<Expression> copy() const override { return std::make_unique<LeafExpression>(*this); }
private:
    int value_;
};

class CompositeExpression : public Expression {
public:
    CompositeExpression(unique_ptr<Expression> left, string operation, unique_ptr<Expression> right);
    CompositeExpression(const CompositeExpression& other);
    int evaluate() const override;
    void dump(std::ostream& os) const override;
    std::unique_ptr<Expression> copy() const override { return std::make_unique<CompositeExpression>(*this); }
private:
    void validateOperation(const string& operation) const {
        static const std::unordered_set<string> kValidOperations{"+", "-", "*", "/"};
        if (!kValidOperations.count(operation))
            throw std::runtime_error(kInvalidOperation);
    }
    unique_ptr<Expression> left_;
    unique_ptr<Expression> right_;
    string operation_;
};

CompositeExpression::CompositeExpression(unique_ptr<Expression> left, string operation, unique_ptr<Expression> right)
    : left_(std::move(left)), operation_(std::move(operation)), right_(std::move(right)) {
    validateOperation(operation_);
    if (!left_ || !right_)
    throw std::runtime_error(kInvalidExpression);
}

CompositeExpression::CompositeExpression(const CompositeExpression& other)
    : left_(other.left_ ? other.left_->copy() : nullptr),
        operation_(other.operation_),
        right_(other.right_ ? other.right_->copy() : nullptr) {
}

int CompositeExpression::evaluate() const {
    if (done) return result;
    auto leftValue = left_->evaluate();
    auto rightValue = right_->evaluate();
    switch (operation_[0]) {
        case '+':
            result = leftValue + rightValue;
            break;
        case '-':
            result = leftValue - rightValue;
            break;
        case '*':
            result = leftValue * rightValue;
            break;
        case '/':
            if (rightValue == 0)
                throw std::runtime_error(kDividedByZero);
            result = leftValue / rightValue;
            break;
        default:
            throw std::runtime_error(kInvalidOperation);
    }
    done = true;
    return result;
}

void CompositeExpression::dump(std::ostream& os) const {
    os << "(";
    left_->dump(os);
    os << " " << operation_ << " ";
    right_->dump(os);
    os << ")";
}

int main(int argc, char *argv[]) {
    try {
        unique_ptr<Expression> e1 = make_unique<CompositeExpression>(
            make_unique<CompositeExpression>(make_unique<LeafExpression>(20), "+", make_unique<LeafExpression>(8)),
            "/", make_unique<LeafExpression>(6));
        std::cout << e1->evaluate() << std::endl;

        unique_ptr<Expression> e2 = make_unique<CompositeExpression>(
            make_unique<CompositeExpression>(make_unique<LeafExpression>(20), "-", make_unique<LeafExpression>(8)),
            "/", make_unique<LeafExpression>(2));
        std::cout << e2->evaluate() << std::endl;

        unique_ptr<Expression> e3(e1->copy());
        std::cout << e3->evaluate() << std::endl;

        std::ofstream file("expression.txt");
        if (file.is_open()) {
            e3->dump(file);
            file.close();
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}