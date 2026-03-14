🧩 Definition
    Chain of Responsibility (CoR) Design Pattern is a behavioral design pattern that allows multiple objects to handle a request without coupling the sender to any particular receiver.
    Instead of handling the request directly, each handler decides either to process it or to pass it along to the next handler in the chain.

🧠 Key Idea
    “Decouple sender and receiver by passing the request along a chain of potential handlers until one handles it.”


| **Use Case**                              | **Description**                                                                         |
| ----------------------------------------- | --------------------------------------------------------------------------------------- |
| **Event Handling System**                 | GUI event bubbling where events move from child to parent elements (e.g., mouse click). |
| **Logging Frameworks**                    | Different log levels (DEBUG, INFO, ERROR) handled by different loggers in sequence.     |
| **Authentication/Authorization Pipeline** | Multiple checks like API key → JWT → Role-based access → Permissions.                   |
| **Request Validation**                    | Sequential validation of request fields by multiple validators.                         |
| **Customer Support Ticket Escalation**    | Requests escalate from junior support → senior → manager.                               |
| **Middleware Pipeline**                   | Web servers (like Express.js or ASP.NET) process requests through middleware layers.    |
| **Error Handling Systems**                | Errors passed up the chain until handled appropriately.                                 |


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


             +--------------------+
             |   DispenseChain    |<----------------+
             |--------------------|                 |
             | +setNext()         |                 |
             | +dispense()        | (abstract)      |
             +---------+----------+                 |
                       ^                            |
   +-------------------+----------------------------+
   |                    |                           |
+----------------+ +----------------+ +----------------+
| ₹2000Dispenser | | ₹500Dispenser  | | ₹100Dispenser  |
+----------------+ +----------------+ +----------------+
| +dispense()    | | +dispense()    | | +dispense()    |
+----------------+ +----------------+ +----------------+
