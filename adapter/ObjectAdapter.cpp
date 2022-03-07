#include <iostream>

class Target {
public:
    virtual ~Target() {}
    virtual void request() = 0;
};


class Adaptee {
public:
    void specificRequest() {
        std::cout << "specific request" << std::endl;
    }
};


class Adapter : public Target {
public:
    Adapter() : _adaptee() {}
    ~Adapter() {
        delete _adaptee;
    }

    void request() {
        _adaptee->specificRequest();
    }

private:
    Adaptee *_adaptee;
};

int main() {
    Target *target = new Adapter();
    target->request();
    delete target;

    return 0;
}
