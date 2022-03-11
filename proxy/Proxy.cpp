#include <iostream>

class ISubject {
public:
    virtual ~ISubject() {}
    virtual void request() = 0;
};

class RealSubject : public ISubject {
public:
    void request() {
        std::cout << "real subject request" << std::endl;
    }
};

class Proxy : public ISubject {
public:
    Proxy() {
        _subject = new RealSubject();
    }

    // 通过构造函数传递代理者
    Proxy(ISubject *subject) : _subject(subject) {

    }

    ~Proxy() {
        delete _subject;
    }

    void request() {
        before();
        _subject->request();
        after();
    }

private:
    void before() {
        std::cout << "do something before" << std::endl;
    }

    void after() {
        std::cout << "do something after" << std::endl;
    }

private:
    ISubject *_subject;
};


int main() {
    Proxy *proxy = new Proxy();
    proxy->request();
    delete proxy;

    return 0;
}
