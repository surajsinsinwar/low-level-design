/*
🧩 Before Scenario — The Problem
Imagine you’re working on a game where you have to create different types of characters:
    Knight
    Wizard
    Archer
Each character has a complex initialization — like:
    loading 3D models,
    configuring AI parameters,
    setting default stats, weapons, and animations, etc.
Now, creating each new character from scratch is time-consuming and memory heavy, especially if you only need a copy of an existing one with minor changes.
For example:

*/

Knight* knight1 = new Knight();
knight1->loadModel("heavy_armor");
knight1->setWeapon("sword");
knight1->setHealth(100);
knight1->setSpeed(10);

// Now we want another knight with same base but just change weapon:
Knight* knight2 = new Knight(); // again does heavy setup!
knight2->loadModel("heavy_armor");
knight2->setWeapon("axe");
knight2->setHealth(100);
knight2->setSpeed(10);

/*
❌ Problem:
    You’re repeating expensive object creation logic again and again for objects that are almost identical.
    You need an easier, faster way to duplicate existing objects rather than reconstructing them.

🧠 Introducing the Prototype Pattern — The Solution
The Prototype Pattern solves this by:
    allowing you to clone existing objects instead of creating them from scratch.
    each class defines a clone() method that returns a copy of itself.
So instead of calling new and setting everything again,
you just do this 👇
*/

Knight* knight1 = new Knight();
knight1->loadModel("heavy_armor");
knight1->setWeapon("sword");
knight1->setHealth(100);
knight1->setSpeed(10);

// Clone instead of rebuild
Knight* knight2 = knight1->clone();
knight2->setWeapon("axe");


/*
Now:
    knight1 and knight2 share the same base configuration.
    knight2 can modify only what’s different.
    No redundant setup or heavy initialization.
✅ Benefits:
    Saves time (no repetitive setup).
    Saves memory if cloning uses internal sharing mechanisms.
    Makes it easier to create new variants of objects at runtime.
    Keeps creation logic encapsulated within the object itself.

⚙️ How It Works Internally
    Usually, we define a base interface like this:
*/


class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void show() = 0;
};

class Knight : public Prototype {
    int health;
    string weapon;
public:
    Knight(int h, string w) : health(h), weapon(w) {}
    Knight* clone() override {
        return new Knight(*this); // uses copy constructor
    }
    void show() override {
        cout << "Knight with " << weapon << " and health " << health << endl;
    }
};

int main() {
    Knight* k1 = new Knight(100, "Sword");
    Knight* k2 = k1->clone(); // cloning
    k2->show();
}
