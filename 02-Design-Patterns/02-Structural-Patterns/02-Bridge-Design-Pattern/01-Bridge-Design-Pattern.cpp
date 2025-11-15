/*
    🧱 Before Scenario (Without Bridge Pattern)
    Scenario: Shapes with different drawing APIs
    Imagine you’re building a graphics library that supports different shapes (like Circle, Rectangle) and different rendering APIs (like OpenGL, DirectX).
*/

class CircleOpenGL {
public:
    void draw() { cout << "Drawing Circle using OpenGL\n"; }
};

class CircleDirectX {
public:
    void draw() { cout << "Drawing Circle using DirectX\n"; }
};

class RectangleOpenGL {
public:
    void draw() { cout << "Drawing Rectangle using OpenGL\n"; }
};

class RectangleDirectX {
public:
    void draw() { cout << "Drawing Rectangle using DirectX\n"; }
};


/*
    ❌ Problem
        The number of classes grows exponentially with the number of shapes and rendering APIs.
        Adding a new shape or rendering API requires creating multiple new classes.
        Code duplication across different shape-API combinations.

    Observation: Both the entities (Shapes and Rendering APIs) have same functionality (draw) but different implementations.

    ✅ (With Bridge Pattern)
        The Bridge Pattern fixes this by splitting abstraction (Shape) and implementation (DrawingAPI) into separate class hierarchies
        — and connecting them via a bridge (composition).
*/

/*
    Step 1: Define the “Implementor” Interface (the bridge target)
*/

class DrawingAPI {
public:
    virtual void drawCircle(float x, float y, float radius) = 0;
    virtual ~DrawingAPI() {}
};

/*
    Step 2: Concrete Implementations of the Bridge
*/

class OpenGLAPI : public DrawingAPI {
public:
    void drawCircle(float x, float y, float radius) override {
        cout << "Drawing Circle using OpenGL at (" << x << ", " << y << ")\n";
    }
};

class DirectXAPI : public DrawingAPI {
public:
    void drawCircle(float x, float y, float radius) override {
        cout << "Drawing Circle using DirectX at (" << x << ", " << y << ")\n";
    }
};

/*
    Step 3: Abstraction Layer (Shape)
*/

class Shape {
protected:
    DrawingAPI* drawingAPI;   // Bridge link
public:
    Shape(DrawingAPI* api) : drawingAPI(api) {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

/*
    Step 4: Concrete Abstraction
*/

class Circle : public Shape {
    float x, y, radius;
public:
    Circle(float x, float y, float r, DrawingAPI* api)
        : Shape(api), x(x), y(y), radius(r) {}

    void draw() override {
        drawingAPI->drawCircle(x, y, radius);
    }
};

/*
    Step 5: Client Code
*/

int main() {
    DrawingAPI* opengl = new OpenGLAPI();
    DrawingAPI* directx = new DirectXAPI();

    Shape* circle1 = new Circle(1, 2, 3, opengl);
    Shape* circle2 = new Circle(4, 5, 6, directx);

    circle1->draw();
    circle2->draw();

    delete circle1;
    delete circle2;
    delete opengl;
    delete directx;
}
