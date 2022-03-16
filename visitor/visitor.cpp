#include <iostream>

class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual ~Visitor() {}

    virtual void visitElementA(ConcreteElementA *element) = 0;
    virtual void visitElementB(ConcreteElementB *element) = 0;
};

class ConcreteVisitorA : public Visitor {
public:
    ~ConcreteVisitorA() = default;

    virtual void visitElementA(ConcreteElementA *element) {
        std::cout << "Concrete visitor A: element A visited" << std::endl;
    }

    virtual void visitElementB(ConcreteElementB *element) {
        std::cout << "Concrete visitor A: element B visited" << std::endl;
    }
};

class ConcreteVisitorB : public Visitor {
public:
    ~ConcreteVisitorB() = default;

    virtual void visitElementA(ConcreteElementA *element) {
        std::cout << "Concrete visitor B: element A visited" << std::endl;
    }

    virtual void visitElementB(ConcreteElementB *element) {
        std::cout << "Concrete visitor B: element B visited" << std::endl;
    }
};

class Element {
public:
    virtual ~Element() = default;

    virtual void accept(Visitor &visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    virtual ~ConcreteElementA() = default;

    void accept(Visitor &visitor) {
        visitor.visitElementA(this);
    }
};

class ConcreteElementB : public Element {
public:
    virtual ~ConcreteElementB() = default;

    void accept(Visitor &visitor) {
        visitor.visitElementB(this);
    }
};

int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ConcreteVisitorA visitorA;
    ConcreteVisitorB visitorB;

    elementA.accept(visitorA);
    elementA.accept(visitorB);

    elementB.accept(visitorA);
    elementB.accept(visitorB);

    return 0;
}

