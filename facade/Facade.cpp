#include <iostream>

class SubsystemA {
public:
    void suboperation() {
        std::cout << "subsystem A suboperation" << std::endl;
    }
};

class SubsystemB {
public:
    void suboperation() {
        std::cout << "subsystem B suboperation" << std::endl;
    }
};

class SubsystemC {
public:
    void suboperation() {
        std::cout << "subsystem C suboperation" << std::endl;
    }
};

class Facade {
public:
    Facade() : _subsystemA(), _subsystemB(), _subsystemC() {}

    void operation1() {
        std::cout << "facade operation 1" << std::endl;
        _subsystemA->suboperation();
        _subsystemB->suboperation();
    }

    void operation2() {
        std::cout << "facade operation 2" << std::endl;
        _subsystemC->suboperation();
    }

private:
    SubsystemA *_subsystemA;
    SubsystemB *_subsystemB;
    SubsystemC *_subsystemC;
};

int main() {
    Facade *facade = new Facade();

    facade->operation1();
    facade->operation2();
    delete facade;

    return 0;
}