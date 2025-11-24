Behavioral Design Patterns are a category of design patterns that focus on how objects communicate and interact with each other.
They help make the interactions between objects more flexible, reusable, and easier to maintain — without tightly coupling the classes together.

🧠 Definition
    Behavioral Design Patterns are concerned with algorithms and the assignment of responsibilities between objects.
    They define how objects interact and communicate in a way that increases flexibility in carrying out communication.

⚙️ Key Purpose
    To improve communication between objects.
    To reduce dependencies between interacting objects.
    To encapsulate behavior that can change independently from the objects that use it.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


| **Pattern Name**            | **Description / Purpose**                                                                                | **Real-World Analogy / Example**                                      |
| --------------------------- | -------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| **Chain of Responsibility** | Passes a request along a chain of handlers until one handles it.                                         | Customer support escalation system (L1 → L2 → Manager).               |
| **Command**                 | Encapsulates a request as an object to parameterize clients with different requests.                     | Undo/Redo operations in editors.                                      |
| **Interpreter**             | Defines a grammar for a language and uses an interpreter to interpret sentences in that language.        | SQL query parser or regex engine.                                     |
| **Iterator**                | Provides a way to access elements of a collection sequentially without exposing its structure.           | Looping through a playlist or array.                                  |
| **Mediator**                | Defines an object that centralizes communication between different classes.                              | Air traffic controller coordinating planes.                           |
| **Memento**                 | Captures and restores an object’s internal state without violating encapsulation.                        | Save/restore feature in a game.                                       |
| **Observer**                | Defines a one-to-many dependency so that when one object changes state, all its dependents are notified. | Notification system (YouTube subscriptions).                          |
| **State**                   | Allows an object to alter its behavior when its internal state changes.                                  | Vending machine with states like “No Coin”, “Has Coin”, “Dispensing”. |
| **Strategy**                | Defines a family of algorithms, encapsulates each one, and makes them interchangeable.                   | Payment methods (CreditCard, PayPal, UPI).                            |
| **Template Method**         | Defines the skeleton of an algorithm, deferring some steps to subclasses.                                | Cooking recipe where ingredients may vary.                            |
| **Visitor**                 | Allows adding new operations to existing object structures without modifying them.                       | Tax calculation for different types of invoices.                      |
