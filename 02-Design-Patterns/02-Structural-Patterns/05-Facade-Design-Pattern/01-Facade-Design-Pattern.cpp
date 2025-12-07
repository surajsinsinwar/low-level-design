/*
    Let’s take an example of a Home Theater System.
        Imagine you have these classes:
            DVDPlayer
            Projector
            Amplifier
            Lights
            PopcornMaker

    Now, to watch a movie, the user must:
*/

int main() {
    // Complex sequence of operations
    dvd.on();
    dvd.play("Avengers");
    projector.on();
    projector.setInput(dvd);
    amplifier.on();
    amplifier.setVolume(5);
    lights.dim(20);
    popcornMaker.on();
    popcornMaker.pop();
}

/*
    ┌────────────┐
    │   Client   │
    └────┬───────┘
        │
        ├────▶ DVDPlayer
        ├────▶ Projector
        ├────▶ Amplifier
        ├────▶ Lights
        └────▶ PopcornMaker


    The user must know about every subsystem, call many methods, and in the correct sequence.
    This creates:
        Tight coupling between client and all subsystems
        Difficult maintenance (changes in subsystem affect all clients)
        Harder readability & testability

    Facade Pattern Solution
        We introduce a single class → HomeTheaterFacade
            This class knows how to coordinate all these systems internally.
            Now, the user can just do:
*/

void HomeTheaterFacade::watchMovie(string movie) {
    popcornMaker.on();
    popcornMaker.pop();
    lights.dim(20);
    projector.on();
    amplifier.on();
    amplifier.setVolume(5);
    dvd.on();
    dvd.play(movie);
}

int main(){
    homeTheater.watchMovie("Avengers");
    homeTheater.endMovie();
}

/*
    ┌────────────┐
    │   Client   │
    └────┬───────┘
        │
        ▼
    ┌────────────────────┐
    │  HomeTheaterFacade │
    └────┬──────┬────────┘
        │      │
        ▼      ▼
    ┌────────┐ ┌────────┐ ┌────────┐ ┌────────┐ ┌────────┐
    │ DVD    │ │ Projector │ │ Amp │ │ Lights │ │ Popcorn │
    └────────┘ └──────────┘ └──────┘ └────────┘ └────────┘


    ✅ Benefits:
        Client doesn’t need to know subsystem details
        Reduces complexity dramatically
        Decouples client from system internals
        Improves code organization & testability
*/