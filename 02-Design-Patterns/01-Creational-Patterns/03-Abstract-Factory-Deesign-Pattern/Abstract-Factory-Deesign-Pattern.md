🧩 What is the Abstract Factory Pattern

Definition:
    Abstract Factory provides an interface for creating families of related or dependent objects without specifying their concrete classes.
    Instead of creating a single product, Abstract Factory creates multiple related products together using a single factory.

🎯 The Goal
    1️⃣ Create families of related objects
    2️⃣ Ensure compatibility between products

📌 Use Abstract Factory When
    There are:
        Multiple product types (Payment, Refund)
        AND
        Multiple implementations (families) (Stripe, Razorpay)


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


+-----------------------------------+
|             Client                |
+-----------------------------------+
| if(gateway=="Stripe")             |
|   new StripePayment()             |
|   new StripeRefund()              |
|                                   |
| if(gateway=="Razorpay")           |
|   new RazorpayPayment()           |
|   new RazorpayRefund()            |
+-----------------------------------+
Client depends on all concrete classes


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

              +----------------------+
              | PaymentGatewayFactory|
              +----------------------+
              | +createPayment()     |
              | +createRefund()      |
              +----------------------+
                       ▲
         ┌─────────────┴─────────────┐
         │                           │
+---------------------+    +---------------------+
|     StripeFactory   |    |   RazorpayFactory   |
+---------------------+    +---------------------+
| createPayment()     |    | createPayment()     |
| createRefund()      |    | createRefund()      |
+---------------------+    +---------------------+


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


📌 Quick Memory Rule
    Factory Method
        1 Product
        Multiple Implementation

        Example:
            Payment
            ├ StripePayment
            ├ RazorpayPayment
            └ PaypalPayment
    Abstract Factory
        Multiple Products
        Multiple Families

        Example:
                Stripe            Razorpay
        Payment    StripePayment     RazorpayPayment
        Refund     StripeRefund      RazorpayRefund
        🧠 One-Line Summary

    Abstract Factory is a factory of factories that creates families of related objects.