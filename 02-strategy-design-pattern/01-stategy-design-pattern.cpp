/*
    Strategy Pattern helps remove interdependency between child classes by extracting shared behavior into separate strategy interfaces.

    Basically, it's a way to support open/closed principle or duplicate logic by encapsulating behavior that can vary.

    Defination:
        Strategy Pattern exists to remove duplicated behavior from child classes and avoid forcing behavior into the parent class.
        It encapsulates that behavior into separate "strategy" classes so that behavior can vary independently.
*/

class Animal {
public:
    virtual void sound() = 0;
};

class Dog : public Animal {
public:
    void sound() { cout << "Bark\n"; }
    void walk() { cout << "Walk normally\n"; }
};

class Cat : public Animal {
public:
    void sound() { cout << "Meow\n"; }
    void walk() { cout << "Walk normally\n"; }  // Duplicate logic!
};

/*
    Here Dog and Cat both walk the same way.
    But walk() doesn’t belong to Animal base class, because some animals may walk differently (example: Snake doesn’t walk).

    If you put walk() in parent → violates logic.
    If you keep walk() in each child → duplicate code.

    This is where Strategy fits perfectly.
*/

class WalkStrategy {
    public:
        virtual void walk() = 0;
};
class NormalWalk : public WalkStrategy {
    public:
        void walk() override { cout << "Walk normally\n"; }
};
class NoWalk : public WalkStrategy {
    public:
        void walk() override { cout << "Cannot walk\n"; }
};

class Animal {
protected:
    WalkStrategy* walkStrategy;
public:
    virtual void sound() = 0;
    void walk() {
        walkStrategy->walk();
    }
};


class Dog : public Animal {
public:
    Dog() { walkStrategy = new NormalWalk(); }
    void sound() override { cout << "Bark\n"; }
};

class Cat : public Animal {
public:
    Cat() { walkStrategy = new NormalWalk(); }
    void sound() override { cout << "Meow\n"; }
};

class Snake : public Animal {
public:
    Snake() { walkStrategy = new NoWalk(); }
    void sound() override { cout << "Hisss\n"; }
};


