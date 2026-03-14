🧾 Definition

The Builder Design Pattern is a creational pattern that lets you construct complex objects step by step.
It separates the construction logic from the final representation, so the same construction process can create different object forms.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


✅ In short:
Use Builder Pattern whenever:
    The object has many optional parameters
    The creation has multiple dependent steps
    You want clear and controlled object construction

Difference between Builder and Decorator pattern
| Pattern       | Intent                                               | Relationship Type                                                         | Who Controls Object Creation / Modification |
| ------------- | ---------------------------------------------------- | ------------------------------------------------------------------------- | ------------------------------------------- |
| **Builder**   | Encapsulate *object construction* logic and steps    | **has-a** (builder *has* the product being built)                         | Controlled by *system / director*           |
| **Decorator** | Dynamically *extend or modify behavior* of an object | **is-a** and **has-a** (decorator *is a* base type and *has a* base type) | Controlled by *client / user*               |

Core Difference
Pattern             Focus
Factory             Method	Which object to create
Builder	            How to construct the object step-by-step