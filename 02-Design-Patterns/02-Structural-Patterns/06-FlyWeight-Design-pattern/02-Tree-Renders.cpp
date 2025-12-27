#include <iostream>
#include <unordered_map>
using namespace std;

class TreeType {
public:
    string name;
    string texture;

    TreeType(string name, string texture) : name(name), texture(texture) {}

    void draw(int x, int y, string color) {
        cout << "Drawing " << name << " tree at (" << x << "," << y << ") with " << color << endl;
    }
};

class TreeFactory {
    unordered_map<string, TreeType*> types;
public:
    TreeType* getTreeType(string name, string texture) {
        if (types.find(name) == types.end())
            types[name] = new TreeType(name, texture);
        return types[name];
    }
};

class Tree {
    int x, y;
    string color;
    TreeType* type;
public:
    Tree(int x, int y, string color, TreeType* type)
        : x(x), y(y), color(color), type(type) {}

    void draw() {
        type->draw(x, y, color);
    }
};

int main() {
    TreeFactory factory;

    TreeType* oakType = factory.getTreeType("Oak", "oak_texture.png");
    Tree t1(10, 20, "Green", oakType);
    Tree t2(30, 40, "Light Green", oakType);

    t1.draw();
    t2.draw();
}
