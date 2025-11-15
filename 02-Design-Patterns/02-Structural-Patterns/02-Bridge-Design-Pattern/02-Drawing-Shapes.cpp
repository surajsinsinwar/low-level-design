#include <iostream>
#include <string>
using namespace std;

// ===============================
// 1️⃣ IMPLEMENTOR INTERFACE
// ===============================
class DrawingAPI {
public:
    virtual void drawShape(const string& shapeName) = 0;
    virtual ~DrawingAPI() {}
};

// ===============================
// 2️⃣ CONCRETE IMPLEMENTORS
// ===============================
class OpenGLAPI : public DrawingAPI {
public:
    void drawShape(const string& shapeName) override {
        cout << "Drawing " << shapeName << " using OpenGL API" << endl;
    }
};

class DirectXAPI : public DrawingAPI {
public:
    void drawShape(const string& shapeName) override {
        cout << "Drawing " << shapeName << " using DirectX API" << endl;
    }
};

// ===============================
// 3️⃣ ABSTRACTION
// ===============================
class Shape {
protected:
    DrawingAPI* drawingAPI;   // Bridge via composition
public:
    Shape(DrawingAPI* api) : drawingAPI(api) {}
    virtual void draw() = 0;  // Abstract operation
    virtual ~Shape() {}
};

// ===============================
// 4️⃣ REFINED ABSTRACTIONS
// ===============================
class Circle : public Shape {
public:
    Circle(DrawingAPI* api) : Shape(api) {}
    void draw() override {
        drawingAPI->drawShape("Circle");
    }
};

class Triangle : public Shape {
public:
    Triangle(DrawingAPI* api) : Shape(api) {}
    void draw() override {
        drawingAPI->drawShape("Triangle");
    }
};

class Rectangle : public Shape {
public:
    Rectangle(DrawingAPI* api) : Shape(api) {}
    void draw() override {
        drawingAPI->drawShape("Rectangle");
    }
};

// ===============================
// 5️⃣ CLIENT CODE
// ===============================
int main() {
    // Create Implementors (APIs)
    DrawingAPI* openGL = new OpenGLAPI();
    DrawingAPI* directX = new DirectXAPI();

    // Create Shapes (Abstractions) using Bridge connection
    Shape* circle = new Circle(openGL);
    Shape* triangle = new Triangle(directX);
    Shape* rectangle = new Rectangle(openGL);

    // Draw shapes using different APIs
    circle->draw();
    triangle->draw();
    rectangle->draw();

    // Cleanup
    delete circle;
    delete triangle;
    delete rectangle;
    delete openGL;
    delete directX;

    return 0;
}
