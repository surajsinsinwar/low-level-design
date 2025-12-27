🧩 Definition
The Proxy Pattern provides a surrogate or placeholder for another object to control access to it.
In simple terms:
    Instead of interacting directly with a real object, you interact with a proxy that controls how and when the real object is accessed or created.


🧠 Core Idea
A proxy acts as a gatekeeper — it can:
    Defer creation (lazy loading)
    Control access
    Add additional behavior (like logging, caching, or validation)
    Communicate remotely (remote proxies)


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


🧰 Use Cases of Proxy Pattern
| Type                      | Purpose                         | Example                         |
| ------------------------- | ------------------------------- | ------------------------------- |
| **Virtual Proxy**         | Delay expensive object creation | Image viewer loads image lazily |
| **Remote Proxy**          | Access remote objects           | RMI, microservices client       |
| **Protection Proxy**      | Access control                  | User roles & permissions        |
| **Caching Proxy**         | Cache results                   | API response cache              |
| **Logging Proxy**         | Monitor calls                   | AOP method interceptors         |
| **Smart Reference Proxy** | Manage lifecycle                | C++ smart pointers              |



                         ┌────────────────────────┐
                         │        Client          │
                         │────────────────────────│
                         │ - image: Image         │
                         │ + displayImage()       │
                         └───────────┬────────────┘
                                     │
                                     │ uses
                                     ▼
                     ┌────────────────────────┐
                     │        Image           │
                     │ <<Interface>>          │
                     │────────────────────────│
                     │ + display()            │
                     └───────────▲────────────┘
                                 │
               ┌────────────────┴─────────────────┐
               │                                  │
 ┌────────────────────────┐         ┌────────────────────────┐
 │       RealImage        │         │       ProxyImage       │
 │────────────────────────│         │────────────────────────│
 │ - filename: string     │         │ - filename: string     │
 │ + display()            │         │ - realImage: RealImage │
 │ + loadFromDisk()       │         │ + display()            │
 └────────────────────────┘         └────────────────────────┘


🔍 How It Works
    Client creates a ProxyImage("photo.png").
    The proxy doesn’t load the actual image yet.
    When display() is called:
    Proxy checks if realImage exists.
    If not → loads it from disk.
    Then calls realImage.display().
    