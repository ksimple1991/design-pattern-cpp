#include <iostream>
#include <vector>

class Memento {
public:
    Memento(const std::string& state) : _state(state) {}

    std::string getState() const {
        return _state;
    }

    void setState(const std::string& state) {
        _state = state;
    }

private:
    std::string _state;
};

class Originator {
public:
    Originator() = default;
    ~Originator() = default;

    void setState(const std::string state) {
        _state = state;
    }

    std::string getState() const {
        return _state;
    }

    // 创建备忘录
    Memento* createMemento() const {
        return new Memento(_state);
    }

    // 恢复到备忘录
    void restoreMemento(const Memento *memento) {
        setState(memento->getState());
    }

private:
    std::string _state;
};

class Caretaker {
public:
    Caretaker(Originator * const originator) : _originator(originator) {}

    ~Caretaker() {
        for (unsigned i = 0; i < _history.size(); ++i) {
            delete _history[i];
        }
        _history.clear();
    }

    void save() {
        std::cout << "Save state " << std::endl;
        _history.push_back(_originator->createMemento());
    }

    void undo() {
        if (_history.empty()) {
            std::cout << "Unable to undo state " << std::endl;
            return;
        }
    
        Memento *m = _history.back();
        _history.pop_back();
        _originator->restoreMemento(m);

        std::cout << "Undo state " << std::endl;
    }

private:
    Originator *_originator;
    std::vector<Memento*> _history;
};

int main() {
    Originator *originator = new Originator();
    Caretaker *caretaker = new Caretaker(originator);

    originator->setState("State1");
    caretaker->save();

    originator->setState("State2");
    caretaker->save();

    originator->setState("State3");
    caretaker->undo();

    std::cout << "Actual state is " << originator->getState() << std::endl;

    delete originator;
    delete caretaker;
    return 0;
}

