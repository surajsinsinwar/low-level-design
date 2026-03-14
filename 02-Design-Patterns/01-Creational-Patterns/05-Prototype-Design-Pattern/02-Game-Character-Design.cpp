#include <iostream>
#include <string>
using namespace std;

// Prototype Interface
class Prototype {
public:
    virtual Prototype* clone() = 0; // Clone method
    virtual void showDetails() = 0;
    virtual ~Prototype() {}
};

// Concrete Class: Knight
class Knight : public Prototype {
private:
    string model;
    string weapon;
    int health;
    int speed;

public:
    Knight(string m, string w, int h, int s)
        : model(m), weapon(w), health(h), speed(s) {}

    // Copy constructor-based clone implementation
    Knight* clone() override {
        return new Knight(*this);
    }

    void setWeapon(string w) {
        weapon = w;
    }

    void showDetails() override {
        cout << "Knight => [Model: " << model
             << ", Weapon: " << weapon
             << ", Health: " << health
             << ", Speed: " << speed << "]" << endl;
    }
};

// Client Code
int main() {
    // Step 1: Create a base prototype knight
    Knight* baseKnight = new Knight("Heavy Armor", "Sword", 100, 10);
    cout << "Base Knight Prototype:" << endl;
    baseKnight->showDetails();

    // Step 2: Clone it for new knights
    Knight* knight1 = baseKnight->clone();
    knight1->setWeapon("Axe");

    Knight* knight2 = baseKnight->clone();
    knight2->setWeapon("Bow");

    cout << "\nCloned Knights:" << endl;
    knight1->showDetails();
    knight2->showDetails();

    // Clean up
    delete baseKnight;
    delete knight1;
    delete knight2;

    return 0;
}
