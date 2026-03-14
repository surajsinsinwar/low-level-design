/*
    🧩 Problem Statement
        Suppose you go to an ATM and withdraw ₹8,700.
        The ATM should give you:
            4 × ₹2000 notes = ₹8000
            1 × ₹500 note = ₹500
            2 × ₹100 notes = ₹200

        We can have different handlers for each denomination — ₹2000, ₹500, and ₹100.
        Each handler:
            Tries to dispense as many notes as possible for its denomination.
            Then passes the remaining amount to the next handler in the chain.

    All logic is inside one class with multiple if-else blocks.
*/

#include <iostream>
using namespace std;

class ATM {
public:
    void dispenseCash(int amount) {
        if (amount >= 2000) {
            int num = amount / 2000;
            amount = amount % 2000;
            cout << "Dispensing " << num << " x ₹2000 notes\n";
        }
        if (amount >= 500) {
            int num = amount / 500;
            amount = amount % 500;
            cout << "Dispensing " << num << " x ₹500 notes\n";
        }
        if (amount >= 100) {
            int num = amount / 100;
            amount = amount % 100;
            cout << "Dispensing " << num << " x ₹100 notes\n";
        }
        if (amount != 0)
            cout << "Amount cannot be dispensed!\n";
    }
};

int main() {
    ATM atm;
    atm.dispenseCash(8700);
}


/*
    Now we create separate handler classes for each denomination.
*/

#include <iostream>
using namespace std;

class DispenseChain {
protected:
    DispenseChain* next;
public:
    void setNext(DispenseChain* nextHandler) {
        next = nextHandler;
    }
    virtual void dispense(int amount) = 0;
};

class Rupees2000Dispenser : public DispenseChain {
public:
    void dispense(int amount) override {
        if (amount >= 2000) {
            int num = amount / 2000;
            int remainder = amount % 2000;
            cout << "Dispensing " << num << " x ₹2000 notes\n";
            if (remainder != 0 && next)
                next->dispense(remainder);
        } else if (next) {
            next->dispense(amount);
        }
    }
};

class Rupees500Dispenser : public DispenseChain {
public:
    void dispense(int amount) override {
        if (amount >= 500) {
            int num = amount / 500;
            int remainder = amount % 500;
            cout << "Dispensing " << num << " x ₹500 notes\n";
            if (remainder != 0 && next)
                next->dispense(remainder);
        } else if (next) {
            next->dispense(amount);
        }
    }
};

class Rupees100Dispenser : public DispenseChain {
public:
    void dispense(int amount) override {
        if (amount >= 100) {
            int num = amount / 100;
            int remainder = amount % 100;
            cout << "Dispensing " << num << " x ₹100 notes\n";
            if (remainder != 0 && next)
                next->dispense(remainder);
        } else {
            cout << "Amount cannot be dispensed!\n";
        }
    }
};

int main() {
    // Create handlers
    Rupees2000Dispenser d2000;
    Rupees500Dispenser d500;
    Rupees100Dispenser d100;

    // Build chain: 2000 → 500 → 100
    d2000.setNext(&d500);
    d500.setNext(&d100);

    int amount = 8700;
    cout << "Requesting ₹" << amount << endl;
    d2000.dispense(amount);
}
