/*
                    ┌────────────────────────────┐
                    │        Employee            │  <<Interface>>
                    │────────────────────────────│
                    │ + showDetails()            │
                    └────────────▲───────────────┘
                                 │
              ┌──────────────────┴──────────────────┐
              │                                     │
┌────────────────────────────┐       ┌────────────────────────────┐
│         Developer          │       │          Manager           │
│────────────────────────────│       │────────────────────────────│
│ - name : string            │       │ - name : string            │
│ - role : string            │       │ - team : List<Employee*>   │
│ + showDetails()            │       │ + add(Employee*)           │
└────────────────────────────┘       │ + showDetails()            │
                                     └────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Component Interface
class Employee {
public:
    virtual void showDetails() = 0;
    virtual ~Employee() {}
};

// Leaf
class Developer : public Employee {
    string name;
    string role;
public:
    Developer(string name, string role) : name(name), role(role) {}
    void showDetails() override {
        cout << "Developer: " << name << " (" << role << ")" << endl;
    }
};

// Composite
class Manager : public Employee {
    string name;
    vector<Employee*> team;
public:
    Manager(string name) : name(name) {}
    void add(Employee* emp) {
        team.push_back(emp);
    }
    void showDetails() override {
        cout << "Manager: " << name << endl;
        for (auto e : team) {
            e->showDetails();
        }
    }
};

// Client
int main() {
    Developer* dev1 = new Developer("Alice", "Frontend");
    Developer* dev2 = new Developer("Bob", "Backend");
    Developer* dev3 = new Developer("Charlie", "DevOps");

    Manager* engManager = new Manager("Eve");
    engManager->add(dev1);
    engManager->add(dev2);
    engManager->add(dev3);

    Developer* qa1 = new Developer("David", "QA");
    Manager* qaManager = new Manager("Sophia");
    qaManager->add(qa1);

    Manager* ceo = new Manager("Michael (CEO)");
    ceo->add(engManager);
    ceo->add(qaManager);

    ceo->showDetails();
    return 0;
}

/*
    Output:
        Manager: Michael (CEO)
        Manager: Eve
        Developer: Alice (Frontend)
        Developer: Bob (Backend)
        Developer: Charlie (DevOps)
        Manager: Sophia
        Developer: David (QA)
*/