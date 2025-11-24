/*
    We have two separate classes: TeaMaker and CoffeeMaker.
    Each class duplicates code for steps like boiling water and pouring into cup.
*/

// ❌ Before using Template Pattern

class TeaMaker {
public:
    void prepareTea() {
        boilWater();
        brewTea();
        pourInCup();
        addLemon();
    }

private:
    void boilWater() { cout << "Boiling water\n"; }
    void brewTea() { cout << "Steeping the tea\n"; }
    void pourInCup() { cout << "Pouring into cup\n"; }
    void addLemon() { cout << "Adding lemon\n"; }
};

class CoffeeMaker {
public:
    void prepareCoffee() {
        boilWater();
        brewCoffee();
        pourInCup();
        addSugarAndMilk();
    }

private:
    void boilWater() { cout << "Boiling water\n"; }
    void brewCoffee() { cout << "Dripping coffee through filter\n"; }
    void pourInCup() { cout << "Pouring into cup\n"; }
    void addSugarAndMilk() { cout << "Adding sugar and milk\n"; }
};


/*
    👎 Problems:
        Duplicate code (boilWater(), pourInCup()).
        Difficult to add new beverages with same steps.

    ✅ After Applying Template Pattern
        We introduce an abstract base class Beverage that defines the template method — the fixed algorithm flow.
*/

// ✅ After using Template Pattern

#include <iostream>
using namespace std;

class Beverage {
public:
    // Template method (fixed algorithm)
    void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

protected:
    void boilWater() { cout << "Boiling water\n"; }
    void pourInCup() { cout << "Pouring into cup\n"; }

    // Abstract methods (customizable)
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
};

// Concrete implementation for Tea
class Tea : public Beverage {
protected:
    void brew() override { cout << "Steeping the tea\n"; }
    void addCondiments() override { cout << "Adding lemon\n"; }
};

// Concrete implementation for Coffee
class Coffee : public Beverage {
protected:
    void brew() override { cout << "Dripping coffee through filter\n"; }
    void addCondiments() override { cout << "Adding sugar and milk\n"; }
};

int main() {
    Tea tea;
    Coffee coffee;

    cout << "Preparing tea:\n";
    tea.prepareBeverage();

    cout << "\nPreparing coffee:\n";
    coffee.prepareBeverage();
}