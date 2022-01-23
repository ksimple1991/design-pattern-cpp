#include <iostream>
#include <string>

class Product {
public:
    virtual ~Product() {}

    virtual std::string getName() const = 0;
};

class ConcreteProductA : public Product {
public:
    ~ConcreteProductA() {}

    std::string getName() const {
        return "type A";
    }
};

class ConcreteProductB : public Product {
public:
    ~ConcreteProductB() {}

    std::string getName() const {
        return "type B";
    }
};

/**
 * 
 * 
 */
class Creator {
public:
    virtual ~Creator() {}

    virtual Product *createProductA() = 0;
    virtual Product *createProductB() = 0;

    virtual void removeProduct(Product *product) = 0;
};

class ConcreteCreator : public Creator {
public:
    virtual ~ConcreteCreator() {}

    Product *createProductA() {
        return new ConcreteProductA();
    }

    Product *createProductB() {
        return new ConcreteProductB();
    }

    void removeProduct(Product *product) {
        delete product;
    }
};


int main(int argc, char **argv) {
    Creator *creator = new ConcreteCreator();

    Product *productA = creator->createProductA();
    std::cout << "Product: " << productA->getName() << std::endl;
    creator->removeProduct(productA);
    
    Product *productB = creator->createProductB();
    std::cout << "Product: " << productB->getName() << std::endl;
    creator->removeProduct(productB);

    delete creator;
    return 0;
}
