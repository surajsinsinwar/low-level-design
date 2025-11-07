/*
    If Class B is a subclass of Class A,
    then we should be able to replace object of A with object of B without disrupting the behavior of the program.

    Subclass should extend the behavior of the parent class not narrow it down.
*/

class Bike {
    public:
        virtual void turnOnEngine() = 0;
        virtual void accelerate() = 0;
};

class MotorCycle : public Bike {
    private:
        bool isEngineOn = false;
        int speed = 0;
    public:
        void turnOnEngine() override {
            isEngineOn = true;
        }
        void accelerate() override {
            speed += 10;
        }
};

class Bicycle : public Bike{
    public:
        void turnOnEngine() override {
            throw runtime_error("Bicycle does not have an engine");
        }
        void accelerate() override {
            // Bicycle acceleration logic here
        }
};

/*
    Here, Bicycle class violates Liskov Substitution Principle
    because it cannot properly implement the turnOnEngine method from Bike class.
*/