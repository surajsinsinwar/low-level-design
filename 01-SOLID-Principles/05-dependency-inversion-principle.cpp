/*
    Class should depend upon interfaces rather than concrete classes.
    High-level modules should not depend upon low-level modules.
*/

class Mouse {
    public:
        virtual void click() = 0;
        virtual void scroll() = 0;
};
class WiredMouse : public Mouse {
    public:
        void click() override {
            // Wired mouse click logic here
        }
        void scroll() override {
            // Wired mouse scroll logic here
        }
};
class WirelessMouse : public Mouse {
    public:
        void click() override {
            // Wireless mouse click logic here
        }
        void scroll() override {    
            // Wireless mouse scroll logic here
        }
};

class Keyboard {
    public:
        virtual void type() = 0;
};
class WiredKeyboard : public Keyboard {
    public:
        void type() override {
            // Wired keyboard type logic here
        }
};
class WirelessKeyboard : public Keyboard {
    public:
        void type() override {
            // Wireless keyboard type logic here
        }
};

class MacBook {
    private:
        wirelessMouse* mouse;
        WiredKeyboard* keyboard;
    public:
        MacBook(wirelessMouse* mouse, WiredKeyboard* keyboard) {
            this->mouse = mouse;
            this->keyboard = keyboard;
        }
};

/*
    Here, MacBook class depends on concrete classes WirelessMouse and WiredKeyboard.
    This violates Dependency Inversion Principle.
    To adhere to DIP, MacBook should depend on Mouse and Keyboard interfaces instead.
*/