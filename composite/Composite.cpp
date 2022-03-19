#include <iostream>
#include <vector>

class Component {
public:
    virtual ~Component() {}

    virtual Component *getChild(const unsigned int index) const {
        return 0;
    }

    virtual void add(Component *) {

    }

    virtual void remove(int) {

    }

    virtual void operation() = 0;
};

class Composite : public Component {
public:
    ~Composite() {
        for (unsigned int i = 0; i < _childrens.size(); ++i) {
            delete _childrens[i];
        }
        _childrens.clear();
    }

    Component *getChild(const unsigned int index) const {
        return _childrens[index];
    }

    void add(Component *component) {
        _childrens.push_back(component);
    }

    void remove(const unsigned int index) {
        Component *child = _childrens[index];
        _childrens.erase(_childrens.begin() + index);
        delete child;
    }

    void operation() {
        for (unsigned int i = 0; i < _childrens.size(); ++i) {
            _childrens[i]->operation();
        }
    }
private:
    std::vector<Component *> _childrens;
};

class Leaf : public Component {
public:
    Leaf(const int i) : _id(i) {

    }

    ~Leaf() {}

    void operation() {
        std::cout << "Leaf " << _id << " operation" << std::endl;
    }

private:
    unsigned int _id;
};

int main() {
    Composite composite;

    for (unsigned int i = 0; i < 6; ++i) {
        composite.add(new Leaf(i));
    }

    composite.remove(0);
    composite.operation();

    return 0;
}
