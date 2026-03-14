/*
    Without State Pattern, code becomes full of conditional logic:
*/

class Document {
private:
    string state;
public:
    Document() { state = "Draft"; }

    void publish() {
        if (state == "Draft") {
            cout << "Document sent for review.\n";
            state = "Moderation";
        } else if (state == "Moderation") {
            cout << "Document approved and published.\n";
            state = "Published";
        } else {
            cout << "Document already published.\n";
        }
    }

    void edit() {
        if (state == "Draft") {
            cout << "Editing document.\n";
        } else {
            cout << "Cannot edit unless in Draft.\n";
        }
    }
};


/*
    We separate each state into its own class and delegate actions to the current state object.
*/

#include <iostream>
#include <string>
using namespace std;

class Document; // forward declaration

// --- State Interface ---
class State {
public:
    virtual void publish(Document* doc) = 0;
    virtual void edit(Document* doc) = 0;
    virtual ~State() {}
};

// --- Concrete States ---
class DraftState : public State {
public:
    void publish(Document* doc) override;
    void edit(Document* doc) override {
        cout << "Editing the draft...\n";
    }
};

class ModerationState : public State {
public:
    void publish(Document* doc) override;
    void edit(Document* doc) override {
        cout << "Cannot edit document under review.\n";
    }
};

class PublishedState : public State {
public:
    void publish(Document* doc) override {
        cout << "Document already published.\n";
    }
    void edit(Document* doc) override {
        cout << "Cannot edit published document.\n";
    }
};

// --- Context ---
class Document {
private:
    State* state;
public:
    Document() : state(new DraftState()) {}
    void setState(State* s) { state = s; }

    void publish() { state->publish(this); }
    void edit() { state->edit(this); }
};

// --- State Transitions ---
void DraftState::publish(Document* doc) {
    cout << "Document sent for review.\n";
    doc->setState(new ModerationState());
}

void ModerationState::publish(Document* doc) {
    cout << "Document approved and published.\n";
    doc->setState(new PublishedState());
}

// --- Usage ---
int main() {
    Document doc;
    doc.edit();
    doc.publish();
    doc.publish();
    doc.edit();
    return 0;
}
