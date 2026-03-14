#include <iostream>
#include <sstream>
using namespace std;

class SQLQuery {
    string baseQuery;
    string whereClause;
    string orderByClause;

public:
    class Builder {
        SQLQuery query;
    public:
        Builder(string table) {
            query.baseQuery = "SELECT * FROM " + table;
        }

        Builder& where(string condition) {
            if (query.whereClause.empty())
                query.whereClause = " WHERE " + condition;
            else
                query.whereClause += " AND " + condition;
            return *this;
        }

        Builder& orderBy(string column) {
            query.orderByClause = " ORDER BY " + column;
            return *this;
        }

        SQLQuery build() { return query; }
    };

    string str() const {
        return baseQuery + whereClause + orderByClause + ";";
    }
};

int main() {
    SQLQuery query = SQLQuery::Builder("employees")
                        .where("age > 25")
                        .where("department = 'HR'")
                        .orderBy("salary DESC")
                        .build();

    cout << query.str() << endl;
}
