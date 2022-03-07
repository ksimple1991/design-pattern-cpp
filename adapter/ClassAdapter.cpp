#include <iostream>

/**
 * Target
 * 目标对象
 */
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

/**
 * Adapter
 * 实现目标接口
 */
class Adapter : public Target, private Adaptee {
public:
    virtual void request() {
        specificRequest();
    }
};

int main() {
    Target *t = new Adapter();
    t->request();
    delete t;

    return 0;
}
