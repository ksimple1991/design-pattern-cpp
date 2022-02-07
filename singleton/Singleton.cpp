#include <iostream>


class Singleton {
public:
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;

    static Singleton* get() { 
        if (instance == nullptr) {
            instance = new Singleton();
        }

        return instance;
    }

    static void restart() {
        if (instance != nullptr) {
            delete instance;
        }
        instance = nullptr;
    }

    void tell() {
        std::cout << "This is Singleton." << std::endl;
    }

private:
    Singleton() {}
    static Singleton *instance;
};

int main() {
    Singleton::get()->tell();
    Singleton::restart();

    return 0;
}
