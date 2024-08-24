#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <unordered_set>
#include <atomic>
#include <fstream>
#include <vector>

using namespace std;

static const char* kInvalidOperation = "Invalid operation";
static const char* kInvalidExpression = "Invalid expression";
static const char* kDividedByZero = "Division by zero";

class Expression {
public:
    Expression(int left, string operation, int right);
    Expression(unique_ptr<Expression> left, string operation, unique_ptr<Expression> right);
    Expression(int left);
    Expression(const Expression& other);
    int evaluate();
    void dump(std::ostream& os) const;

private:
    void validateOperation(const string& operation) const;

private:
    std::array<int, 2> value;
    std::vector<std::unique_ptr<Expression>> expression;
    string operation;
    atomic<bool> done;
    int res;
    const std::unordered_set<string> kValidOperations{"+", "-", "*", "/"};
};

void Expression::validateOperation(const string& operation) const {
    if (!kValidOperations.count(operation))
        throw std::runtime_error(kInvalidOperation);
}

Expression::Expression(int left, string operation, int right) : operation(operation), value({left, right}) {
   validateOperation(operation);
}

Expression::Expression(unique_ptr<Expression> left, string operation, unique_ptr<Expression> right) {
    if (!left || !right)
        throw std::runtime_error(kInvalidExpression);
    expression.emplace_back(std::move(left));
    expression.emplace_back(std::move(right));
    this->operation = operation;
}

Expression::Expression(int left) : value{left, 0} { }

Expression::Expression(const Expression& other) {
    value = other.value;
    operation = other.operation;
    done.store(other.done);
    res = other.res;
    if (other.expression[0]) {
        expression[0] = std::make_unique<Expression>(*other.expression[0]);
    }
    if (other.expression[1]) {
        expression[1] = std::make_unique<Expression>(*other.expression[1]);
    }
}

int Expression::evaluate() {
    if (done)
        return res;
    if (operation.empty())
        return value[0];

    auto leftValue = expression[0] ? expression[0]->evaluate() : value[0];
    auto rightValue = expression[1] ? expression[1]->evaluate() : value[1];

    switch (operation[0]) {
        case '+':
            res = leftValue + rightValue;
            break;
        case '-':
            res = leftValue - rightValue;
            break;
        case '*':
            res = leftValue * rightValue;
            break;
        case '/':
            if (rightValue == 0)
                throw std::runtime_error(kDividedByZero);
            res = leftValue / rightValue;
            break;
        default:
            throw std::runtime_error(kInvalidOperation);
    }
    done = true;
    return res;
}

void Expression::dump(std::ostream& os) const {
    if (operation.empty()) {
         os << value[0];
         return;
    }
    for (int i = 0; i < 2; i++) {
        if (expression[i]) {
            os << "(";
            expression[i]->dump(os);
            os << ")";
        } else {
            os << value[i];
        }
        os << operation;
    }
}

int main(int argc, char *argv[]) {
    try {
        Expression e1(std::make_unique<Expression>(20, "+", 8), "/", std::make_unique<Expression>(6));
        std::cout << e1.evaluate() << std::endl;
        Expression e2(std::make_unique<Expression>(20, "-", 8), "/", std::make_unique<Expression>(0));
        std::cout << e2.evaluate() << std::endl;
        Expression e3(e1);
        std::cout << e3.evaluate() << std::endl;
        std::ofstream file("expression.txt");
        if (file.is_open()) {
            e1.dump(file);
            file.close();
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}