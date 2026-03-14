/*
    The Abstract Factory Pattern is a creational pattern that lets you create families of related objects — without specifying their concrete classes.

    Think of it like a “Factory of Factories.”
    Instead of making one kind of object (like Payment), you can create related objects (like Payment + Refund + TransactionValidator) that all belong to one family
    — e.g., Stripe, Razorpay, PayPal, etc.

    ⚙️ When to Use It
    ✅ When you have multiple product families (e.g., Stripe, PayPal, Razorpay)
    ✅ Each family has multiple related components (e.g., Payment, Refund, Validator)
    ✅ You want to switch families easily, without touching client code.
*/

/*
    💡 Analogy
    Think of payment service providers:
        Stripe
        Razorpay
        PayPal
    Each provider has its own way to:
        Make a payment
        Issue a refund
        Validate a transaction
    You want your system to work with any provider, just by switching the factory.

    🔹 Step 1: Define Abstract Products
*/

#include <iostream>
#include <string>
using namespace std;

// Abstract Product A
class Payment {
public:
    virtual void pay(int amount) = 0;
    virtual ~Payment() = default;
};

// Abstract Product B
class Refund {
public:
    virtual void refund(int amount) = 0;
    virtual ~Refund() = default;
};

/*
    🔹 Step 2: Define Concrete Products for Each Family
*/

// Stripe Family
class StripePayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Stripe: Paid " << amount << " successfully.\n";
    }
};

class StripeRefund : public Refund {
public:
    void refund(int amount) override {
        cout << "Stripe: Refunded " << amount << " successfully.\n";
    }
};

// Razorpay Family
class RazorpayPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Razorpay: Paid " << amount << " successfully.\n";
    }
};

class RazorpayRefund : public Refund {
public:
    void refund(int amount) override {
        cout << "Razorpay: Refunded " << amount << " successfully.\n";
    }
};

/*
    🔹 Step 3: Define Abstract Factory Interface
*/
// Abstract Factory
class PaymentGatewayFactory {
public:
    virtual Payment* createPayment() = 0;
    virtual Refund* createRefund() = 0;
    virtual ~PaymentGatewayFactory() = default;
};


/*
    🔹 Step 4: Define Concrete Factories for Each Family
*/

// Stripe Factory
class StripeFactory : public PaymentGatewayFactory {
public:
    Payment* createPayment() override {
        return new StripePayment();
    }
    Refund* createRefund() override {
        return new StripeRefund();
    }
};

// Razorpay Factory
class RazorpayFactory : public PaymentGatewayFactory {
public:
    Payment* createPayment() override {
        return new RazorpayPayment();
    }
    Refund* createRefund() override {
        return new RazorpayRefund();
    }
};


/*
    Client Code
*/

int main() {
    // Choose which family you want to use (could be decided by config/env)
    PaymentGatewayFactory* factory = new RazorpayFactory();

    Payment* payment = factory->createPayment();
    Refund* refund = factory->createRefund();

    payment->pay(1000);
    refund->refund(500);

    // Cleanup
    delete payment;
    delete refund;
    delete factory;
}