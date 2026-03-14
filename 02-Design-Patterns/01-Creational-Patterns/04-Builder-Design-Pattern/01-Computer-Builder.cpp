#include <iostream>
using namespace std;

class Computer {
private:
    string cpu;
    string ram;
    string gpu;
    bool wifi;

public:
    Computer(string cpu, string ram, string gpu, bool wifi)
        : cpu(cpu), ram(ram), gpu(gpu), wifi(wifi) {}

    void show() {
        cout << cpu << " " << ram << " " << gpu << " wifi:" << wifi << endl;
    }
};

class ComputerBuilder {
    private:
        string cpu;
        string ram;
        string gpu;

    public:
        ComputerBuilder& setCPU(string c) {
            cpu = c;
            return *this;
        }

        ComputerBuilder& setRAM(string r) {
            ram = r;
            return *this;
        }

        ComputerBuilder& setGPU(string g) {
            gpu = g;
            return *this;
        }

        Computer build() {
            return Computer(cpu, ram, gpu);
        }
    };

int main() {

    Computer c = ComputerBuilder()
                .setCPU("i9")
                .setRAM("32GB")
                .setGPU("RTX")
                .build();

    c.show();
}

/*
    1️⃣ What if Some Parameters Are Mandatory and Some Are Optional?
        Approach 1 — Pass Mandatory Parameters in Builder Constructor (Most Common)
        Approach 2 — Validate Inside build() - You allow everything to be set via setters but validate before building.

    2️⃣ When There Is a Specific Sequence to Setting Parameters?
        Approach 1 - Use Directors - The Director controls the construction order.
        Approach 2 - Enforce Sequence in Builder Methods - You allow everything to be set via setters but use builder methods that enforce the sequence.
        Example:
            ComputerBuilder builder;
            builder.setCPU()
            builder.setRAM()
            builder.setGPU()
            Computer c = builder.build(); // Enforce that setCPU must be called before setRAM, and setRAM before setGPU.
*/