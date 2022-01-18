#include <iostream>

class ProductA {
public:
    virtual ~ProductA() {}
    virtual const char* getName() = 0;

    // ...
};

class ConcreteProductAX : public ProductA {
public:
    virtual ~ConcreteProductAX() {}

    virtual const char* getName() {
        return "A-X";
    }
};


class ConcreteProductAY : public ProductA {
public:
    virtual ~ConcreteProductAY() {}

    virtual const char* getName() {
        return "A-Y";
    }
};

class ProductB {
public:
    virtual ~ProductB() {}
    virtual const char* getName() = 0;
};

class ConcreteProductBX : public ProductB {
public:
    virtual ~ConcreteProductBX() {}

    virtual const char* getName() {
        return "B-X";
    }
};

class ConcreteProductBY : public ProductB {
public:
    virtual ~ConcreteProductBY() {}

    virtual const char* getName() {
        return "B-Y";
    }
};

/**
 * 抽象工厂
 * 提供用于创建一系列对象的抽象接口
 */
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}

    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class ConcreteFactoryX : AbstractFactory {
public:
    virtual ~ConcreteFactoryX() {}

    virtual ProductA* createProductA() {
        return new ConcreteProductAX;
    }

    virtual ProductB* createProductB() {
        return new ConcreteProductBX;
    }
};

class ConcreteFactoryY : AbstractFactory {
public:
    virtual ~ConcreteFactoryY() {}

    virtual ProductA* createProductA() {
        return new ConcreteProductAY;
    }

    virtual ProductB* createProductB() {
        return new ConcreteProductBY;
    }
};

int main() {
    ConcreteFactoryX *factoryX = new ConcreteFactoryX();
    ConcreteFactoryY *factoryY = new ConcreteFactoryY();
    
    ProductA *productA = factoryX->createProductA();
    std::cout << productA->getName() << std::endl;

    ProductB *productB = factoryX->createProductB();
    std::cout << productB->getName() << std::endl;

    delete productA;
    delete productB;

    delete factoryX;
    delete factoryY;

    return 0;
}