#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance; // static pointer to single instance
    Singleton() {               // private constructor
        cout << "Singleton Instance Created\n";
    }

public:
    // Delete copy constructor and assignment operator to prevent copies
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton!\n";
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->showMessage();

    cout << "Address of s1: " << s1 << endl;
    cout << "Address of s2: " << s2 << endl;

    return 0;
}
