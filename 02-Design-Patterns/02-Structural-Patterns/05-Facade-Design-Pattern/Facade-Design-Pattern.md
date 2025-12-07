🧩 1. Definition
    Facade Design Pattern provides a simplified, unified interface to a complex subsystem.
    It hides the complexity of multiple classes or systems and exposes only what is necessary through a single entry point.


⚙️ 2. Where & How It Can Be Used
    You can use Facade when:
    You have a complex system with many interacting classes (e.g., 10+ APIs or modules).
    You want to simplify client usage by providing a single, easy-to-use interface.
    You need to decouple clients from the underlying subsystem implementation (making code easier to maintain or replace).


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Before Facade:
┌────────────┐
│   Client   │
└────┬───────┘
     │
     ├────▶ DVDPlayer
     ├────▶ Projector
     ├────▶ Amplifier
     ├────▶ Lights
     └────▶ PopcornMaker

After Facade:
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
