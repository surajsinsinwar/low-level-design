/*
    Example for 2️⃣ When Object Creation Logic Is Complex
*/

#include <iostream>
#include <string>
using namespace std;

class DatabaseConnection {
public:
    DatabaseConnection(string host, int port) {
        cout << "Connecting to DB at " << host << ":" << port << endl;
    }

    void authenticate(string user, string password) {
        cout << "Authenticating user: " << user << endl;
    }

    void setPoolSize(int size) {
        cout << "Setting pool size: " << size << endl;
    }

    void setTimeout(int timeout) {
        cout << "Setting timeout: " << timeout << endl;
    }
};

int main() {
    // Client doing all initialization
    DatabaseConnection* db = new DatabaseConnection("localhost", 5432);
    db->authenticate("admin", "password");
    db->setPoolSize(10);
    db->setTimeout(30);

    cout << "Database ready to use\n";

    delete db;
}