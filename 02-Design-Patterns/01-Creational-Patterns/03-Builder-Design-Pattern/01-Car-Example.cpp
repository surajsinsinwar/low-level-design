/*
🚗 Example: Building a Car Object (Real Builder Use Case)

🧩 Before Scenario — The Problem

Let’s say we are designing a system for a car manufacturing service.
Each car has different configurations and complex steps involved:

class Car {
public:
    string engine;
    string transmission;
    bool hasGPS;
    bool hasSunroof;
    bool hasAirbags;

    Car(string engine, string transmission, bool hasGPS, bool hasSunroof, bool hasAirbags)
        : engine(engine), transmission(transmission), hasGPS(hasGPS), hasSunroof(hasSunroof), hasAirbags(hasAirbags) {}
};


Now, we have different types of cars:
    Sports Car: V8 Engine, Manual Transmission, Sunroof
    Luxury Car: V6 Engine, Automatic, GPS, Airbags
    Economy Car: V4 Engine, Manual, No GPS
If we continue this way — we’ll either need:
    Tons of constructors, or
    Large initialization logic with if-else chains, or
    A giant factory full of messy code.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


🧱 Identifying the Problem
The creation logic for each type of Car is complex and step-based.
Example:
    Choose engine
    Add transmission
    Add optional features (GPS, Sunroof)
    Add safety features (Airbags)
And these steps can vary by type of car.
So we need:
    To build complex objects step by step
    Without mixing creation logic into the Car class
    And without making it hard to read or extend


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Product
class Car {
public:
    string engine;
    string transmission;
    bool hasGPS = false;
    bool hasSunroof = false;
    bool hasAirbags = false;

    void showCar() const {
        cout << "Car with " << engine << " engine, " << transmission << " transmission";
        if (hasGPS) cout << ", GPS";
        if (hasSunroof) cout << ", Sunroof";
        if (hasAirbags) cout << ", Airbags";
        cout << endl;
    }
};

// Builder Interface
class CarBuilder {
public:
    virtual void buildEngine() = 0;
    virtual void buildTransmission() = 0;
    virtual void buildFeatures() = 0;
    virtual Car getCar() = 0;
    virtual ~CarBuilder() = default;
};

// Concrete Builder 1
class SportsCarBuilder : public CarBuilder {
    Car car;
public:
    void buildEngine() override { car.engine = "V8"; }
    void buildTransmission() override { car.transmission = "Manual"; }
    void buildFeatures() override {
        car.hasSunroof = true;
        car.hasAirbags = true;
    }
    Car getCar() override { return car; }
};

// Concrete Builder 2
class LuxuryCarBuilder : public CarBuilder {
    Car car;
public:
    void buildEngine() override { car.engine = "V6"; }
    void buildTransmission() override { car.transmission = "Automatic"; }
    void buildFeatures() override {
        car.hasGPS = true;
        car.hasAirbags = true;
        car.hasSunroof = true;
    }
    Car getCar() override { return car; }
};

// Concrete Builder 3
class EconomyCarBuilder : public CarBuilder {
    Car car;
public:
    void buildEngine() override { car.engine = "V4"; }
    void buildTransmission() override { car.transmission = "Manual"; }
    void buildFeatures() override {
        car.hasAirbags = true;
    }
    Car getCar() override { return car; }
};

// Director
class Director {
public:
    Car construct(CarBuilder& builder) {
        builder.buildEngine();
        builder.buildTransmission();
        builder.buildFeatures();
        return builder.getCar();
    }
};

// Client
int main() {
    Director director;

    SportsCarBuilder sportsBuilder;
    LuxuryCarBuilder luxuryBuilder;
    EconomyCarBuilder economyBuilder;

    Car sportsCar = director.construct(sportsBuilder);
    Car luxuryCar = director.construct(luxuryBuilder);
    Car economyCar = director.construct(economyBuilder);

    sportsCar.showCar();
    luxuryCar.showCar();
    economyCar.showCar();
}
