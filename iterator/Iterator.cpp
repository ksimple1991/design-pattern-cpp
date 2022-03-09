#include <iostream>
#include <stdexcept>
#include <vector>

class Aggregate;
class Iterator;
class ConcreteAggregate;
class ConcreteIterator;

class Aggregate {
public:
    virtual ~Aggregate() {}

    virtual Iterator* createIterator() = 0;
};

class ConcreteAggregate : public Aggregate {
public:
    ConcreteAggregate(const unsigned int size) {
        _list = new int[size]();
        _count = size;
    }

    ~ConcreteAggregate() {
        delete[] _list;
    }

    Iterator* createIterator();

    unsigned int size() const {
        return _count;
    }

    int at(unsigned int index) {
        return _list[index];
    }

private:
    int *_list;
    unsigned int _count;
};

class Iterator {
public:
    virtual ~Iterator() {}

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() const = 0;
    virtual int currentItem() const = 0;
};

class ConcreteIterator : public Iterator {
public:
    ConcreteIterator(ConcreteAggregate *list) :
        _list(list), _cursor(0) {}

    ~ConcreteIterator() {}

    void first() {
        _cursor = 0;
    }

    void next() {
        ++_cursor;
    }

    bool hasNext() const {
        return (_cursor < _list->size());
    }

    int currentItem() const {
        return hasNext() ? _list->at(_cursor) : -1;
    }

private:
  ConcreteAggregate *_list;
  unsigned int _cursor;
};

Iterator* ConcreteAggregate::createIterator() {
    return new ConcreteIterator(this);
}

int main() {
    unsigned int size = 5;
    ConcreteAggregate list = ConcreteAggregate(size);
    Iterator *it = list.createIterator();

    for (; it->hasNext(); it->next()) {
        std::cout << "Item value: " << it->currentItem() << std::endl;
    }

    delete it;
    return 0;
}
