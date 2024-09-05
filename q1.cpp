#include <iostream>

class A {
public:
    A() {
        std::cout << "A::A()" << std::endl; 
    }

    virtual void foo() {
        std::cout << "A::foo()" << std::endl; 
    }

    virtual void bar() {
        std::cout << "A::bar()" << std::endl; 
    }

    ~A() {
       std::cout << "A::~A()" << std::endl; 
    }
};

class B : public A {
public:
    B() {
        std::cout << "B::B()" << std::endl; 
    }

    void foo() override {
        std::cout << "B::foo()" << std::endl;
    }

    ~B() {
        std::cout << "B::~B()" << std::endl; 
    }
};

int main() {
    A a; 
    a.foo(); 
    a.bar(); 

    A* b = new B(); 
    b->foo(); 
    b->bar(); 

    delete b; 

    std::cout << "last line";
    return 0;
}