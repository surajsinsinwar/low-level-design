#include <iostream>
using namespace std;

// Strategy Interface
class IFlyStrategy {
public:
    virtual void fly() = 0;
};

class SimpleFly : public IFlyStrategy {
public:
    void fly() override {
        cout << "Simple Fly\n";
    }
};

class NoFly : public IFlyStrategy {
public:
    void fly() override {
        cout << "No Fly\n";
    }
};

class JetFly : public IFlyStrategy {
public:
    void fly() override {
        cout << "Jet Fly\n";
    }
};

class Duck {
private:
    IFlyStrategy* flyStrategy;

public:
    Duck(IFlyStrategy* flyStrategy) {
        this->flyStrategy = flyStrategy;
    }
    void fly() {
        flyStrategy->fly();
    }
};

class CityDuck : public Duck {
public:
    CityDuck(IFlyStrategy* flyStrategy) : Duck(flyStrategy) {}
};

class BathDuck : public Duck {
public:
    BathDuck(IFlyStrategy* flyStrategy) : Duck(flyStrategy) {}
};

int main() {
    NoFly noFly;
    SimpleFly simpleFly;
    JetFly jetFly;

    CityDuck cityDuck(&simpleFly);
    BathDuck bathDuck(&noFly);

    cityDuck.fly();  // Output: Simple Fly
    bathDuck.fly();  // Output: No Fly

    return 0;
}
