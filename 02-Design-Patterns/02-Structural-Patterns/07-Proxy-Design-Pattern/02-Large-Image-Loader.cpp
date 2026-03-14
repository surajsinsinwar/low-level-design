#include <iostream>
#include <string>
using namespace std;

class Image {
public:
    virtual void display() = 0;
    virtual ~Image() {}
};

class RealImage : public Image {
    string filename;
public:
    RealImage(string fname) : filename(fname) {
        loadFromDisk();
    }
    void loadFromDisk() {
        cout << "Loading image from disk: " << filename << endl;
    }
    void display() override {
        cout << "Displaying image: " << filename << endl;
    }
};

class ProxyImage : public Image {
    string filename;
    RealImage* realImage = nullptr;
public:
    ProxyImage(string fname) : filename(fname) {}
    void display() override {
        if (realImage == nullptr)
            realImage = new RealImage(filename); // Lazy loading
        realImage->display();
    }
    ~ProxyImage() {
        delete realImage;
    }
};

int main() {
    Image* image = new ProxyImage("photo.png");
    
    cout << "\nImage not loaded yet...\n";
    cout << "\nNow displaying image for the first time:\n";
    image->display();  // Loads and displays
    
    cout << "\nDisplaying again (no reload):\n";
    image->display();  // Uses cached object
    
    delete image;
    return 0;
}
