#include <iostream>

class Receiver {
public:
    Receiver() = default;
    ~Receiver() = default;

    void action() {
        std::cout << "Receiver: execute action" << std::endl;
    }
};

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;

protected:
    Command() {}
};


class ConcreteCommand : public Command {
public:
    ConcreteCommand(Receiver* receiver) : _receiver(receiver) {}

    ~ConcreteCommand() {
        if (_receiver != nullptr) {
            delete _receiver;
        }
    }

    void execute() {
        _receiver->action();
    }

private:
    Receiver *_receiver;
};

class Invoker {
public:
    void set(Command *c) {
        _command = c;
    }

    void confirm() {
        if (_command) {
            _command->execute();
        }
    }

private:
    Command *_command;
};

int main() {
    ConcreteCommand command(new Receiver());

    Invoker invoker;
    invoker.set(&command);
    invoker.confirm();

    return 0;
}
