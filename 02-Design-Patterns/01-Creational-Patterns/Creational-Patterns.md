🧩 Definition
Creational Design Patterns are design patterns that provide various object creation mechanisms,
which increase flexibility and reuse of existing code by decoupling object creation from its usage.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


🎯 Purpose of Creational Patterns in LLD
The main purpose is to control how objects are created — instead of creating them directly using constructors (new keyword in C++/Java), creational patterns let you:
    1.  Encapsulate object creation logic (hide complexity).
    2.  Promote loose coupling between client and concrete classes.
    3.  Support scalability — easy to add new object types without changing client code.
    4.  Ensure control over the lifecycle (e.g., single instance, cached instance, etc.).
    5.  Make code more maintainable and testable.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


| Pattern                 | Purpose                                                                                                                                                | Example Scenario                                                                                 |
| ----------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------ |
| **1. Factory Method**   | Defines an interface for creating an object, but lets subclasses decide which class to instantiate.                                                    | Create different types of `Notifications` (`SMS`, `Email`, `Push`) without changing client code. |
| **2. Abstract Factory** | Provides an interface for creating **families of related objects** without specifying their concrete classes.                                          | Create UI elements (`Button`, `Textbox`) for different OS themes (Windows/Mac).                  |
| **3. Builder**          | Separates the **construction** of a complex object from its **representation**, so the same construction process can create different representations. | Construct complex `House` objects (wooden house, stone house) step by step.                      |
| **4. Prototype**        | Creates new objects by **cloning existing ones** instead of creating from scratch.                                                                     | Clone an existing `Document` or `Shape` template with the same configuration.                    |
| **5. Singleton**        | Ensures that a class has **only one instance** and provides a **global access point** to it.                                                           | Manage a single `DatabaseConnection` or `Logger` instance.                                       |


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


💡 In LLD terms
When designing a system, creational patterns help you answer:
    1.  “Who should be responsible for creating objects?”
    2.  “How can I make the code flexible if I need to add a new type later?”
    3.  “How can I prevent multiple copies of an object?”