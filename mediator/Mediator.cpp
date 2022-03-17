#include <iostream>
#include <vector>
#include <string>

class Mediator;

class Colleague {
public:
    Colleague(Mediator *const m, const unsigned int i) : 
        _mediator(m), _id(i) {}

    virtual ~Colleague() {}

    unsigned int getId() const {
        return _id;
    }

    virtual void send(std::string ) = 0;
    virtual void receive(std::string ) = 0;

protected:
    Mediator *_mediator;
    unsigned int _id;
};

class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator *const m, const unsigned int i) : 
        Colleague(m, i) {}
    
    ~ConcreteColleague() = default;

    void send(std::string msg);

    void receive(std::string msg) {
        std::cout << "Message " << msg << " received by Colleague " << _id << std::endl;
    }
};

class Mediator {
public:
    virtual ~Mediator() = default;

    virtual void add(Colleague *const c) = 0;
    virtual void distribute(Colleague *const sender, std::string msg) = 0;

protected:
    Mediator() = default;
};

class ConcreteMediator : public Mediator {
public:
    ~ConcreteMediator() {
        for (auto i = 0; i < _colleagues.size(); ++i) {
            delete _colleagues[i];
        }

        _colleagues.clear();
    }

    void add(Colleague *const c) {
        _colleagues.push_back(c);
    }

    void distribute(Colleague *const sender, std::string msg) {
        for (unsigned int i = 0; i < _colleagues.size(); ++i) {
            if (_colleagues[i]->getId() != sender->getId()) {
                _colleagues[i]->receive(msg);
            }           
        }
    }

private:
    std::vector<Colleague *> _colleagues;
};

void ConcreteColleague::send(std::string msg) {
    std::cout << "Message " << msg << " sent by Colleague " << _id << std::endl;
    _mediator->distribute(this, msg);
}

int main() {
    Mediator *mediator = new ConcreteMediator();

    Colleague *c1 = new ConcreteColleague(mediator, 1);
    Colleague *c2 = new ConcreteColleague(mediator, 2);
    Colleague *c3 = new ConcreteColleague(mediator, 3);

    mediator->add(c1);
    mediator->add(c2);
    mediator->add(c3);

    c1->send("Hello!");
    c3->send("Woo!");

    delete mediator;
    return 0;
}

