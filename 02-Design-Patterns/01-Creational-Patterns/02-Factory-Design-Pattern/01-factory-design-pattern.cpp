
/*

    🏦 Example: Payment Gateway System
    Imagine you are building a backend that supports multiple payment methods — like Credit Card, PayPal, UPI.

    🔹 Step 1: Naïve Implementation (No Pattern)
*/

#include <iostream>
#include <string>
using namespace std;

class Payment {
public:
    virtual void pay(int amount) = 0;
};

class CreditCardPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card.\n";
    }
};

class PayPalPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal.\n";
    }
};

class UPIPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI.\n";
    }
};

int main() {
    string type = "paypal";
    Payment* payment = nullptr;

    if (type == "creditcard")
        payment = new CreditCardPayment();
    else if (type == "paypal")
        payment = new PayPalPayment();
    else if (type == "upi")
        payment = new UPIPayment();

    payment->pay(500);
    delete payment;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
    ✅ Works fine for now.
    ❌ But problems:
        Tight coupling — main() knows every class name (CreditCardPayment, UPIPayment...).
        Hard to extend — adding ApplePay means you must modify main().
        Breaks OCP — every time we add new payment type, we edit existing client code.

    🔹 Step 2: Introducing a Simple Factory
*/

#include <iostream>
#include <string>
using namespace std;

class Payment {
public:
    virtual void pay(int amount) = 0;
};

class CreditCardPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card.\n";
    }
};

class PayPalPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal.\n";
    }
};

class UPIPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI.\n";
    }
};

// ✅ Factory introduced
class PaymentFactory {
public:
    static Payment* createPayment(string type) {
        if (type == "creditcard")
            return new CreditCardPayment();
        else if (type == "paypal")
            return new PayPalPayment();
        else if (type == "upi")
            return new UPIPayment();
        else
            return nullptr;
    }
};

// 🧠 Client code is simpler now
int main() {
    Payment* payment = PaymentFactory::createPayment("upi");
    if (payment) {
        payment->pay(1000);
        delete payment;
    } else {
        cout << "Invalid payment type.\n";
    }
}

/*
    ✅ Benefits:
        Client no longer knows about concrete classes.
        Centralized place for object creation.
        Easier to extend — only change factory, not everywhere else.
    ❌ Still has:
        if/else chain inside factory.
        Need to modify factory when new payment types are added → still slightly violates OCP.

    🔹 Step 3: Eliminating if/else and Fully Hiding Implementation
*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

// 1️⃣ Product Interface
class Payment {
public:
    virtual void pay(int amount) = 0;
    virtual ~Payment() = default;
};

// 2️⃣ Concrete Products
class CreditCardPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card.\n";
    }
};

class PayPalPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal.\n";
    }
};

class UPIPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI.\n";
    }
};

// 3️⃣ Factory Base (Creator)
class PaymentProcessor {
public:
    virtual Payment* createPayment() = 0;  // Factory Method
    void process(int amount) {
        Payment* p = createPayment();
        p->pay(amount);
        delete p;
    }
    virtual ~PaymentProcessor() = default;
};

// 4️⃣ Concrete Factories
class CreditCardProcessor : public PaymentProcessor {
public:
    Payment* createPayment() override {
        return new CreditCardPayment();
    }
};

class PayPalProcessor : public PaymentProcessor {
public:
    Payment* createPayment() override {
        return new PayPalPayment();
    }
};

class UPIProcessor : public PaymentProcessor {
public:
    Payment* createPayment() override {
        return new UPIPayment();
    }
};

// 5️⃣ Client Code
int main() {
    PaymentProcessor* processor = new PayPalProcessor();
    processor->process(2000);
    delete processor;
}

/*
    Now adding a new payment method (say CryptoPayment) just means:
    Create CryptoPayment (implements Payment)
    Create CryptoProcessor (implements PaymentProcessor)
    ✅ No existing code changes → Open-Closed Principle achieve
*/