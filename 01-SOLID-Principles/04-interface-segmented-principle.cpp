/*
    Interfaces should be such, that client should not implement methods they do not use.
    Segregate interfaces to smaller and specific ones.
*/

class RestaurantEmployee {
    public:
        virtual void washDishes() = 0;
        virtual void cookFood() = 0;
        virtual void serveCustomers() = 0;
};

class waiter : public RestaurantEmployee {
    public:
        void washDishes() override {
            throw runtime_error("Waiter does not wash dishes");
        }
        void cookFood() override {
            throw runtime_error("Waiter does not cook food");
        }
        void serveCustomers() override {
            // Serving customers logic here
        }
};

/*
    Here, waiter class violates Interface Segregation Principle
    because it cannot properly implement washDishes and cookFood methods from RestaurantEmployee interface.
*/

class WaiterInterface{
    public:
        virtual void serveCustomers() = 0;
};

class ChefInterface{
    public:
        virtual void cookFood() = 0;
        virtual void decideMenu() = 0;
};

class waiter : public WaiterInterface {
    public:
        void serveCustomers() override {
            // Serving customers logic here
        }
};