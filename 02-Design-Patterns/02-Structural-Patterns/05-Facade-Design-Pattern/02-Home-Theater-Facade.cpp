#include <iostream>
#include <string>
using namespace std;

// ---------------- Subsystem Classes ----------------

class DVDPlayer {
    string currentDisc;
public:
    void on() { cout << "[DVD] Power ON.\n"; }
    void off() { cout << "[DVD] Power OFF.\n"; }
    void play(const string& movie) {
        currentDisc = movie;
        cout << "[DVD] Playing \"" << movie << "\".\n";
    }
    void stop() {
        cout << "[DVD] Stopped.\n";
        currentDisc.clear();
    }
    string getCurrentDisc() const { return currentDisc; }
};

class Projector {
public:
    void on() { cout << "[Projector] Power ON.\n"; }
    void off() { cout << "[Projector] Power OFF.\n"; }
    void wideScreenMode() { cout << "[Projector] Set to widescreen mode.\n"; }
    void setInput(const string& source) {
        cout << "[Projector] Input set to: " << source << ".\n";
    }
};

class Amplifier {
    int volume = 5;
public:
    void on() { cout << "[Amplifier] Power ON.\n"; }
    void off() { cout << "[Amplifier] Power OFF.\n"; }
    void setVolume(int vol) {
        volume = vol;
        cout << "[Amplifier] Volume set to " << volume << ".\n";
    }
    void setSurroundSound() { cout << "[Amplifier] Surround sound enabled.\n"; }
};

class Lights {
public:
    void on() { cout << "[Lights] Lights ON.\n"; }
    void off() { cout << "[Lights] Lights OFF.\n"; }
    void dim(int percent) { cout << "[Lights] Dimming lights to " << percent << "%.\n"; }
};

class PopcornMaker {
public:
    void on() { cout << "[PopcornMaker] Power ON.\n"; }
    void off() { cout << "[PopcornMaker] Power OFF.\n"; }
    void pop() { cout << "[PopcornMaker] Popcorn is popping 🍿.\n"; }
};

// ---------------- Facade Class ----------------

class HomeTheaterFacade {
    DVDPlayer* dvd;
    Projector* projector;
    Amplifier* amp;
    Lights* lights;
    PopcornMaker* popcornMaker;

public:
    HomeTheaterFacade(DVDPlayer* d, Projector* p, Amplifier* a, Lights* l, PopcornMaker* pm)
        : dvd(d), projector(p), amp(a), lights(l), popcornMaker(pm) {}

    void watchMovie(const string& movie) {
        cout << "\n=== Starting Movie Experience ===\n";
        popcornMaker->on();
        popcornMaker->pop();

        lights->dim(10);

        projector->on();
        projector->setInput("DVD Player");
        projector->wideScreenMode();

        amp->on();
        amp->setSurroundSound();
        amp->setVolume(7);

        dvd->on();
        dvd->play(movie);

        cout << "=== Enjoy the movie! ===\n";
    }

    void endMovie() {
        cout << "\n=== Shutting Movie Experience Down ===\n";
        dvd->stop();
        dvd->off();

        amp->off();

        projector->off();

        lights->on();

        popcornMaker->off();
        cout << "=== Movie experience ended ===\n";
    }

    void pauseMovie() {
        cout << "\n--- Pausing movie ---\n";
        dvd->stop();
    }

    void resumeMovie(const string& movie) {
        cout << "\n--- Resuming movie ---\n";
        dvd->play(movie);
    }
};

// ---------------- Client Code ----------------

int main() {
    // Create subsystem components
    DVDPlayer dvd;
    Projector projector;
    Amplifier amp;
    Lights lights;
    PopcornMaker popcorn;

    // Create the Facade
    HomeTheaterFacade homeTheater(&dvd, &projector, &amp, &lights, &popcorn);

    // Client interacts only with Facade
    homeTheater.watchMovie("The Matrix");

    // Simulate pause and resume
    homeTheater.pauseMovie();
    homeTheater.resumeMovie("The Matrix");

    // End movie
    homeTheater.endMovie();

    return 0;
}
