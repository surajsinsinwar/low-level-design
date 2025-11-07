/*
    The Observer Pattern is a behavioral design pattern used in Low-Level Design (LLD) to define a one-to-many dependency between objects 
    — so that when one object (the subject) changes its state, all its dependents (observers) are automatically notified and updated.

    Core Idea:
        When one object changes, others who depend on it should automatically know — without tight coupling.

    Real-World Analogy:
        Think of a YouTube channel (Subject) and its Subscribers (Observers):
        When the YouTuber uploads a new video, all subscribers get a notification.
*/

#include <iostream>
#include <vector>
using namespace std;

class Observer {
    public:
        virtual void update(int temperature) = 0;
};

class Subject{
    public:
        virtual void registerObserver(Observer* observer) = 0;
        virtual void removeObserver(Observer* observer) = 0;
        virtual void notifyObservers() = 0;
};

class WeatherStation : public Subject {
    private:
        vector<Observer*> observers;
        int temperature;
    public:
        void registerObserver(Observer* observer) override {
            observers.push_back(observer);
        }
        void removeObserver(Observer* observer) override {
            observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        }
        void notifyObservers() override {
            for (Observer* observer : observers) {
                observer->update(temperature);
            }
        }
        void setTemperature(int temp) {
            temperature = temp;
            notifyObservers();
        }
};

class DisplayDevice : public Observer {
    private:
        string name;
    public:
        DisplayDevice(string name) {
            this->name = name;
        }
        void update(int temperature) override {
            cout << "Display " << name << ": Temperature updated to " << temperature << "°C" << endl;
        }
};

int main() {
    WeatherStation station;
    DisplayDevice phone("Phone");
    DisplayDevice tv("TV");

    station.registerObserver(&phone);
    station.registerObserver(&tv);

    station.setTemperature(25);
    station.setTemperature(30);
}