🧩 Definition
The Bridge Design Pattern is a Structural Design Pattern that decouples an abstraction from its implementation so that both can vary independently.
In simpler terms:
It separates the “what to do” (abstraction) from “how to do it” (implementation) — allowing both to evolve without affecting each other.

✅ In the Bridge Pattern, we have:
    One class hierarchy called the Abstraction — it defines what the system does.
    Another class hierarchy called the Implementation — it defines how it does it.
    The Abstraction class holds a reference (object) to the Implementation interface, and uses it to delegate work.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


The Bridge Pattern is used when you have multiple entities that share the same functionality (interface or abstraction) but may have different implementations or execution behaviors
— and you want to decouple what they do from how they do it.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Before:
+---------------------+
|  CircleOpenGL       |
|---------------------|
| + draw()            |
| "Circle using OpenGL"|
+---------------------+

+---------------------+
|  CircleDirectX      |
|---------------------|
| + draw()            |
| "Circle using DirectX"|
+---------------------+

+---------------------+
|  RectangleOpenGL    |
|---------------------|
| + draw()            |
| "Rectangle using OpenGL"|
+---------------------+

+---------------------+
|  RectangleDirectX   |
|---------------------|
| + draw()            |
| "Rectangle using DirectX"|
+---------------------+

After:

             +-------------------+
             |   DrawingAPI      |  << Interface >>
             |-------------------|
             | + drawCircle(...) |
             +-------------------+
                  /       \
                 /         \
+-------------------+   +-------------------+
|    OpenGLAPI      |   |    DirectXAPI     |
|-------------------|   |-------------------|
| + drawCircle(...) |   | + drawCircle(...) |
+-------------------+   +-------------------+


                    (bridge via composition)
                             ▲
                             │
+-------------------+         │
|      Shape        |  << Abstract Class >>
|-------------------|
| # drawingAPI      |--- association ---> DrawingAPI
| + draw()          |
+-------------------+
         ▲
         │
         │
+-------------------+
|      Circle       |
|-------------------|
| + draw()          |
+-------------------+

