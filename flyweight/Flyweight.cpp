#include <iostream>
#include <map>

/**
 * 抽象享元类
 * 一个产品的抽象类，同时定义出对象的外部状态和内部状态的接口或实现
 */
class Flyweight {
public:
    Flyweight() = default;
    virtual ~Flyweight() {}

    // 定义业务操作
    virtual void operation() = 0;
};

class UnsharedFlyweight : public Flyweight {
public:
    UnsharedFlyweight(const int intrinsic_state) : 
        _intrinsic_state(intrinsic_state) {}

    ~UnsharedFlyweight() {}

    void operation() {
        std::cout << "Unshared flyweight with state " << _intrinsic_state << std::endl;
    }
private:
    int _intrinsic_state;
};

class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(const int all_state) : _extrinsic_state(all_state) {
    }

    ~ConcreteFlyweight() {}

    void operation() {
        std::cout << "Concrete flyweight state " << _extrinsic_state << std::endl;
    }

private:
    int _extrinsic_state;
};

class FlyweightFactory {
public:
    ~FlyweightFactory() {
        for (auto it = _flies.begin(); it != _flies.end(); ++it) {
            delete it->second;
        }
        _flies.clear();
    }

    Flyweight *getFlyweight(const int key) {
        if (_flies.find(key) != _flies.end()) {
            return _flies[key];
        }

        Flyweight *fly = new ConcreteFlyweight(key);
        _flies.insert(std::pair<int, Flyweight*>(key, fly));
        return fly;
    }

private:
    std::map<int, Flyweight*> _flies;
};

int main() {
    FlyweightFactory *factory = new FlyweightFactory();
    factory->getFlyweight(1)->operation();
    factory->getFlyweight(2)->operation();
    delete factory;
    return 0;
}
