#include <iostream>

class Implementor {
public:
    virtual ~Implementor() {}

    virtual void action() = 0;
};

class ConcreteImplementorA : public Implementor {
public:
    ~ConcreteImplementorA() {}

    void action() {
        std::cout << "Concrete Implementor A" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    ~ConcreteImplementorB() {}

    void action() {
        std::cout << "Concrete Implementor B" << std::endl;
    }
};

class Abstraction {
public:
    virtual ~Abstraction() {}

    virtual void operation() = 0;
};

class RefinedAbstraction : public Abstraction {
public:
    ~RefinedAbstraction() {}

    RefinedAbstraction(Implementor *impl) : _impl(impl) {}

    void operation() {
        _impl->action();
    }

private:
    Implementor *_impl;
};

int main() {
    Implementor *implA = new ConcreteImplementorA();
    Abstraction *abstractionA = new RefinedAbstraction(implA);
    abstractionA->operation();
    delete abstractionA;
    delete implA;

    Implementor *implB = new ConcreteImplementorB();
    Abstraction *abstractionB = new RefinedAbstraction(implB);
    abstractionB->operation();
    delete abstractionB;
    delete implB;
    return 0;
}
