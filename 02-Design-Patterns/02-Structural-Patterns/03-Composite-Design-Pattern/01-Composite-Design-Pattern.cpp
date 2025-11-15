/*
    Let’s take an example:
        You are building a File Explorer system that can display files and folders.
        You have two classes:
        File → represents a single file.
        Folder → represents a folder containing files.
    Now you need a method showDetails() to print the structure.
*/

class File {
public:
    string name;
    File(string name) : name(name) {}
    void showDetails() {
        cout << "File: " << name << endl;
    }
};

class Folder {
public:
    string name;
    vector<File*> files;
    Folder(string name) : name(name) {}
    void addFile(File* file) {
        files.push_back(file);
    }
    void showDetails() {
        cout << "Folder: " << name << endl;
        for (auto f : files) {
            f->showDetails();
        }
    }
};

/*
    🚨 Problem:
        The Folder class can only contain File, not other folders.
        To support nested folders, you’d need special cases for folders inside folders.
        The client has to know whether it’s dealing with a file or a folder before calling methods — no uniformity.

    🧠 5. Solution — Using Composite Design Pattern
        We introduce a common interface FileSystemComponent
        Both File and Folder implement this interface.
        So now:
            File = Leaf
            Folder = Composite
        Both share the same interface, and the client can treat them the same.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Component Interface
class FileSystemComponent {
public:
    virtual void showDetails() = 0;
    virtual ~FileSystemComponent() {}
};

// Leaf
class File : public FileSystemComponent {
    string name;
public:
    File(string name) : name(name) {}
    void showDetails() override {
        cout << "File: " << name << endl;
    }
};

// Composite
class Folder : public FileSystemComponent {
    string name;
    vector<FileSystemComponent*> children;
public:
    Folder(string name) : name(name) {}
    void add(FileSystemComponent* component) {
        children.push_back(component);
    }
    void showDetails() override {
        cout << "Folder: " << name << endl;
        for (auto child : children) {
            child->showDetails();
        }
    }
};

// Client Code
int main() {
    File* file1 = new File("a.txt");
    File* file2 = new File("b.txt");

    Folder* folder1 = new Folder("Documents");
    folder1->add(file1);
    folder1->add(file2);

    Folder* root = new Folder("Root");
    root->add(folder1);
    root->add(new File("readme.md"));

    root->showDetails();
}

/*
    Output:
        Folder: Root
        Folder: Documents
        File: a.txt
        File: b.txt
        File: readme.md

    ER Diagram:
                        ┌──────────────────────────┐
                        │   FileSystemComponent    │  <<Interface>>
                        │──────────────────────────│
                        │ + showDetails()          │
                        └──────────▲───────────────┘
                                    │
                ┌─────────────────┴──────────────────┐
                │                                    │
        ┌────────────────────────┐          ┌────────────────────────┐
        │         File            │          │        Folder          │
        │────────────────────────│          │────────────────────────│
        │ - name : string         │          │ - name : string         │
        │                         │          │ - children : List<FileSystemComponent*>│
        │ + showDetails()         │          │ + add(FileSystemComponent*) │
        └────────────────────────┘          └────────────────────────┘

*/