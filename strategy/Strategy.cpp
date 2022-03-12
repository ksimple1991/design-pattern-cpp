#include <iostream>

class Strategy {
public:
    virtual ~Strategy() {}
    virtual void algorithmInterface() = 0;
};


class ConcreteStrategyA : public Strategy {
public:
    virtual void algorithmInterface() {
        std::cout << "ConcreteStrategyA algorithm interface" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    virtual void algorithmInterface() {
        std::cout << "ConcreteStrategyB algorithm interface" << std::endl;
    }
};

class ConcreteStrategyC : public Strategy {
public:
    virtual void algorithmInterface() {
        std::cout << "ConcreteStrategyC algorithm interface" << std::endl;
    }
};

class Context {
public:
    Context(Strategy* const stratey) : _strategy(stratey) {

    }

    ~Context() {
        delete _strategy;
    }

    void contextInterface() {
        _strategy->algorithmInterface();
    }

private:
    Strategy* _strategy;
};


int main() {
    Context context(new ConcreteStrategyC());
    context.contextInterface();

    return 0;
}

