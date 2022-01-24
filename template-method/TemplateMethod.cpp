#include <iostream>

/*
 * AbstractClass
 * implements a template method defining the skeleton of an algorithm
 */
class AbstractClass {
public:
    virtual ~AbstractClass() {}

    void templateMethod() {

        primitiveOperation1();

        if (isAllowOperation2()) {
            primitiveOperation2();
        }
    }

protected:
    virtual void primitiveOperation1() = 0;

    virtual void primitiveOperation2() = 0;

    virtual bool isAllowOperation2() {
        return true;
    }
};

/*
 * Concrete Class
 * implements the primitive operations to carry out specific steps
 * of the algorithm, there may be many Concrete classes, each implementing
 * the full set of the required operation
 */
class ConcreteClass1 : public AbstractClass {
public:
    ConcreteClass1() : _allowOperation2(true) {}
    ~ConcreteClass1() {}

    void setAllowOperation2(bool enable) {
        _allowOperation2 = enable;
    }

protected:
    void primitiveOperation1() {
        std::cout << "ConcreteClass1: " << "primitiveOperation1" << std::endl;
    }

    void primitiveOperation2() {
        std::cout << "ConcreteClass1: " << "primitiveOperation2" << std::endl;
    }

    bool isAllowOperation2() {
        return _allowOperation2;
    }

private:
    bool _allowOperation2;
};

class ConcreteClass2 : public AbstractClass {
public:
    ~ConcreteClass2() {}

protected:
    void primitiveOperation1() {
        std::cout << "ConcreteClass2: " << "primitiveOperation1" << std::endl;
    }

    void primitiveOperation2() {
        std::cout << "ConcreteClass2: " << "primitiveOperation2" << std::endl;
    }

    bool isAllowOperation2() {
        std::cout << "ConcreteClass2 not allow operation2" << std::endl;
        return false;
    }
};

int main(int argc, char **argv) {
    AbstractClass *ab1 = new ConcreteClass1();
    ab1->templateMethod();
    delete ab1;

    AbstractClass *ab2 = new ConcreteClass2();
    ab2->templateMethod();
    delete ab2;
    return 0;
}
