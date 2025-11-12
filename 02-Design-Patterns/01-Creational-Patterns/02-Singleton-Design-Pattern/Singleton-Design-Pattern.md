🧩 What is the Singleton Pattern?

Definition:
    The Singleton Pattern ensures that only one instance of a class exists throughout the program, and provides a global point of access to that instance.


Some classes logically should have only one instance in a system.
Examples:
    Logger (only one logging mechanism)
    DatabaseConnection (shared connection pool)
    ConfigurationManager (single source of truth for app configs)
    ThreadPool (common executor service)

If we allow multiple instances, it can lead to:
    inconsistent state
    unnecessary resource usage
    synchronization issues

So, Singleton pattern makes sure only one instance is ever created.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


🧠 Key Idea
We do three main things:
    1. Make the constructor private — prevents external instantiation.
    2. Create a static instance inside the class — single shared instance.
    3. Provide a static method (usually getInstance()) to return that instance.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


| Scenario                     | Why Singleton fits                                                             |
| ---------------------------- | ------------------------------------------------------------------------------ |
| **Database Connection Pool** | Only one pool should exist; multiple ones waste resources and cause contention |
| **Logger Service**           | Single logger ensures consistent formatting and file access                    |
| **Configuration Manager**    | App settings are loaded once and shared globally                               |
| **Cache Manager**            | One central cache layer avoids inconsistent data                               |
| **Metrics Collector**        | All modules report to the same metrics service                                 |


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


🧩 Restating Your Understanding
“We want a class (or a class that represents a whole service)
to be initialized only once and that same instance should be used everywhere in the application.”