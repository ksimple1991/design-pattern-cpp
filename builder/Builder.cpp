#include <iostream>
#include <string>

class Product {
public:
    Product() = default;
    ~Product() = default;

    void makeA(const std::string &part) {
        _partA = part;
    }

    void makeB(const std::string &part) {
        _partB = part;
    }

    void makeC(const std::string &part) {
        _partC = part;
    }

    std::string get() {
        return (_partA + " " + _partB + " " + _partC);
    }

private:
    std::string _partA;
    std::string _partB;
    std::string _partC;
};

class Builder {
public:
    Builder() = default;
    virtual ~Builder() {}

    Product get() {
        return _product;
    }

    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;

protected:
    Product _product;
};


class ConcreteBuilderX : public Builder {
public:
    void buildPartA() {
        _product.makeA("A-X");
    }

    void buildPartB() {
        _product.makeB("B-X");
    }

    void buildPartC() {
        _product.makeC("C-X");
    }
};

class ConcreteBuilderY : public Builder {
public:
    void buildPartA() {
        _product.makeA("A-Y");
    }

    void buildPartB() {
        _product.makeB("B-Y");
    }

    void buildPartC() {
        _product.makeC("C-Y");
    }
};

class Director {
public:
    Director() : _builder(nullptr) {

    }

    ~Director() {
        if (_builder != nullptr) delete _builder;
    }

    void set(Builder *b) {
        if (_builder != nullptr) delete _builder;

        _builder = b;
    }

    Product get() {
        return _builder->get();
    }

    void construct() {
        _builder->buildPartA();
        _builder->buildPartB();
        _builder->buildPartC();
    }

private:
    Builder *_builder;
};

int main() {
    Director director;

    director.set(new ConcreteBuilderX);
    director.construct();
    Product product1 = director.get();
    std::cout << "1st product parts: " << product1.get() << std::endl;

    director.set(new ConcreteBuilderY);
    director.construct();
    Product product2 = director.get();
    std::cout << "2nd product parts: " << product2.get() << std::endl;

    return 0;
}
