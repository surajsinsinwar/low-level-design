/*
    The Decorator Pattern allows you to dynamically add new behaviors or responsibilities to objects without modifying their existing code or class.


    Imagine you run a coffee shop ☕.
        You start with a base drink class like Espresso, DarkRoast, etc.
        Then you have add-ons: milk, soy, mocha, whipped cream, etc.
*/

/*
    🧱 Step 1: Start with the Basic Requirement
        We’re building a coffee ordering system ☕️.
        Base requirement:
            We sell different kinds of beverages like:
                Espresso
                DarkRoast
                HouseBlend
            Each beverage has:
                a description
                a cost
        So we begin with this:
*/

#include <iostream>
using namespace std;

class Beverage {
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};

class Espresso : public Beverage {
public:
    string getDescription() const override { return "Espresso"; }
    double cost() const override { return 1.99; }
};

/*
    ✅ This works great for basic drinks.
    🧩 Step 2: Add the next requirement
        Now your customer says:
            “We want to sell milk, soy, mocha, and whip toppings with any beverage.”
        You think:
            “Okay, I’ll just modify my classes to include options.”
        So you add booleans:
*/

class Beverage {
public:
    bool hasMilk = false;
    bool hasSoy = false;
    bool hasWhip = false;

    virtual double cost() const = 0;
};
class Espresso : public Beverage {
public:
    double cost() const override {
        double price = 1.99;
        if (hasMilk) price += 0.10;
        if (hasSoy) price += 0.15;
        if (hasWhip) price += 0.20;
        return price;
    }
};
 
/*
    Espresso e;
    e.hasSoy = true;
    e.hasWhip = true;
    cout << e.cost(); // 1.99 + 0.15 + 0.20

    ❌ Problem 1: Violation of SRP (Single Responsibility Principle)
    ❌ Problem 2: Violation of OCP (Open/Closed Principle)
    ❌ Problem 3: Combinatorial Explosion

    🧩 Step 4: Try to Solve Using Only Inheritance

    Beverage
    ├── Espresso
    │    ├── EspressoWithMilk
    │    ├── EspressoWithSoy
    │    ├── EspressoWithSoyAndWhip
    │    └── EspressoWithMilkAndWhip
    ├── DarkRoast
    │    ├── DarkRoastWithSoy
    │    └── ...

    This seems fine for a few condiments but blows up exponentially.
    You’re stuck maintaining a huge, rigid hierarchy just to represent combinations of runtime options.
    → This means inheritance alone can’t solve this problem.

    Step 5: Look for an Alternative — Dynamic Composition
    You realize:
        “All condiments behave the same way — they wrap a beverage and add something (cost, description).”
        So instead of making every combination a new subclass,
        we can make condiments independent wrappers that can be composed dynamically.
*/

class Bevrage {
    public:
    virtual string getDiscription() = 0;
    virtual int getCost() = 0;
};
class Espresso : public Bevrage {
    public:
    string getDiscription() override {
        return "Espresso";
    }
    int getCost() override {
        return 5;
    }
};

class decorator : public Bevrage {
    protected:
    Bevrage* bevrage;
    public:
    decorator(Bevrage* bevrage) {
        this->bevrage = bevrage;
    }
};
class Mocha : public decorator {
    public:
    Mocha(Bevrage* bevrage) : decorator(bevrage) {}
    string getDiscription() override {
        return bevrage->getDiscription() + ", Mocha";
    }
    int getCost() override {
        return bevrage->getCost() + 2;
    }
};

int main() {

    Bevrage* espresso = new Espresso();
    cout << espresso->getDiscription() << " Cost: " << espresso->getCost() << "\n";

    Bevrage* mochaEspresso = new Mocha(espresso);
    cout << mochaEspresso->getDiscription() << " Cost: " << mochaEspresso->getCost() << "\n";

    return 0;
}