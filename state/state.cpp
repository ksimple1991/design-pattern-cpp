#include <iostream>

class Context;

class State {
public:
    State() : _context(nullptr) {}
    ~State() {}

    virtual void handle1() = 0;
    virtual void handle2() = 0;

    void setContext(Context *context) {
        _context = context;
    }
protected:
    Context *_context;
};

class ConcreteStateA : public State {
public:
    ~ConcreteStateA() {}

    void handle1() {
        // 本状态下必须处理的逻辑
        std::cout << "ConcreteStateA handle1" << std::endl;
    }

    void handle2();
};

class ConcreteStateB : public State {
public:
    ~ConcreteStateB() {}

    void handle1();

    void handle2() {
        // 本状态下必须处理的逻辑
        std::cout << "ConcreteStateB handle2" << std::endl;
    }
};

class Context {
public:
    Context() : _currentState(nullptr) {}
    ~Context() {}

    State* getCurrentState() const {
        return _currentState;
    }

    void setCurrentState(State *state) {
        // if (_currentState != nullptr) {
        //     delete _currentState;
        // }
        _currentState = state;
        _currentState->setContext(this);
    }

    void handle1() {
        _currentState->handle1();
    }

    void handle2() {
        _currentState->handle2();
    }

public:
    static State *STATEA;
    static State *STATEB;

private:
    State *_currentState;
};

State * Context::STATEA = new ConcreteStateA();
State * Context::STATEB = new ConcreteStateB();

void ConcreteStateA::handle2() {
    // 设置当前状态为stateB
    _context->setCurrentState(Context::STATEB);

    // 过渡到stateB，由Context实现
    _context->handle2();
}

void ConcreteStateB::handle1() {
    // 设置当前状态为stateA
    _context->setCurrentState(Context::STATEA);
    // 过渡到stateA状态，由context实现
    _context->handle1();
}

int main() {
    Context *context = new Context();
    context->setCurrentState(Context::STATEA);
    context->handle1();
    context->handle2();

    delete context;
    return 0;
}


