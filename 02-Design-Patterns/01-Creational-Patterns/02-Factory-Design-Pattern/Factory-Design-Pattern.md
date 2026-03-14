🧩 What is the Factory Pattern

Defination:
    Factory Method delegates the responsibility of object creation to a separate method or class instead of creating objects directly using constructors.

The goal is:
1️⃣ Decouple Object Creation from Usage
2️⃣ Centralize Object Creation Logic in case of multiple services with same functionality
3️⃣ Enable Runtime Object Selection

Use Factory Method when:
  There is one product type (Payment)
  But multiple implementations (Stripe, PayPal)

Use cases:
1️⃣ When the Exact Object Is Not Known Until Runtime
    Example:
        Payment payment = PaymentFactory::create(type);
        payment.pay();
    Runtime decision:
        type = "UPI"  → UPIPayment
        type = "CARD" → CreditCardPayment
        type = "PAYPAL" → PaypalPayment

2️⃣ When Object Creation Logic Is Complex
    Sometimes object creation involves:
        1. reading configuration
        2. validating inputs
        3. creating dependencies
        4. initializing resources
        5. logging
        6. authentication setup

Note: Passing type and having if else is not idea
        If/else can be elemenated using Satergy


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


+-----------------------------------+
|             Payment               |
+-----------------------------------+
| + pay() : void                    |
+-----------------------------------+
        ▲              ▲
        |              |
        |              |
+---------------+  +---------------+
| CreditCardPay |  |  UPIPayment   |
+---------------+  +---------------+
| + pay()       |  | + pay()       |
+---------------+  +---------------+

          ▲
          |
          | creates objects directly
          |
+-----------------------------------+
|             Client                |
+-----------------------------------+
| + main() : void                   |
|                                   |
| if(type=="UPI")                   |
|   new UPIPayment()                |
| if(type=="CARD")                  |
|   new CreditCardPayment()         |
+-----------------------------------+

Here the client directly creates concrete objects.
Client → CreditCardPayment
Client → UPIPayment
Client → PaypalPayment


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                     +----------------------+
                     |       Payment        |
                     +----------------------+
                     | + pay(amount) : void |
                     +----------------------+
                             ▲
             ┌───────────────┼───────────────┐
             │               │               │
+---------------------+ +---------------------+ +---------------------+
| CreditCardPayment   | | PayPalPayment       | | UPIPayment          |
+---------------------+ +---------------------+ +---------------------+
| + pay(amount):void  | | + pay(amount):void  | | + pay(amount):void  |
+---------------------+ +---------------------+ +---------------------+


                   +------------------------------------+
                   |         PaymentProcessor           |
                   +------------------------------------+
                   | + createPayment() : Payment        |  <<Factory Method>>
                   | + process(amount) : void           |
                   +------------------------------------+
                                 ▲
                 ┌───────────────┼────────────────┐
                 │               │                │
+-------------------------+ +-------------------------+ +-------------------------+
| CreditCardProcessor     | | PayPalProcessor         | | UPIProcessor            |
+-------------------------+ +-------------------------+ +-------------------------+
| + createPayment():Payment| | + createPayment():Payment| | + createPayment():Payment|
+-------------------------+ +-------------------------+ +-------------------------+


                     +----------------------+
                     |        Client        |
                     +----------------------+
                     | + main() : void      |
                     +----------------------+
                     | uses PaymentProcessor|
                     +----------------------+

Client
  ↓
Factory
  ↓
Concrete Classes
