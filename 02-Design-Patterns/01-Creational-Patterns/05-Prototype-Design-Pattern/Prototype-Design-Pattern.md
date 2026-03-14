🏁 Definition (In Simple Words)

Prototype Design Pattern is a creational pattern that lets you create new objects by copying existing ones, instead of creating them from scratch.
It helps when object creation is costly, complex, or repetitive, and you need to make slightly modified copies of pre-configured objects.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Before:
Each time we create a new knight (knight1, knight2, etc.),

┌──────────────────────────┐
│        Knight            │
├──────────────────────────┤
│ - model: string          │
│ - weapon: string         │
│ - health: int            │
│ - speed: int             │
├──────────────────────────┤
│ + loadModel(model)       │
│ + setWeapon(weapon)      │
│ + setHealth(health)      │
│ + setSpeed(speed)        │
└──────────────────────────┘
        ↑
        │  (created separately)
        │
 ┌──────────────┐     ┌──────────────┐
 │  knight1     │     │  knight2     │
 ├──────────────┤     ├──────────────┤
 │ heavy setup  │     │ heavy setup  │
 │ same params  │     │ same params  │
 └──────────────┘     └──────────────┘

🧠 Explanation
    Each Knight instance (knight1, knight2) is created independently.
    Each initialization (model loading, health setup, etc.) is repeated.
    Object creation is costly and redundant.

✅ AFTER PROTOTYPE PATTERN
💡 Solution: We create one base Knight prototype,and then clone it whenever we need a new knight.
Only small differences (like weapon) are changed.

⚙️ Scenario Summary
We first build KnightPrototype, which is fully configured once.
Then we clone it for each new knight, making light modifications as needed.

┌──────────────────────────┐
│    Prototype (Interface) │
├──────────────────────────┤
│ + clone() : Prototype*   │
└──────────────────────────┘
            ▲
            │
            │
┌──────────────────────────┐
│         Knight            │
├──────────────────────────┤
│ - model: string          │
│ - weapon: string         │
│ - health: int            │
│ - speed: int             │
├──────────────────────────┤
│ + clone() : Knight*      │
│ + showDetails()          │
└──────────────────────────┘
            ▲
            │ clone()
            │
 ┌──────────────────────┐
 │   knightPrototype    │
 │  (Base preconfigured)│
 └──────────────────────┘
        │          │
        │clone()   │clone()
        ▼          ▼
 ┌──────────────┐  ┌──────────────┐
 │  knight1     │  │  knight2     │
 │ weapon: sword│  │ weapon: axe  │
 └──────────────┘  └──────────────┘


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


It’s particularly useful in situations where:
    Creating a new object is expensive, time-consuming, or resource-intensive.
    You want to avoid duplicating complex initialization logic.
    You need many similar objects with only slight differences.


| Aspect            | Description                                                                  |
| ----------------- | ---------------------------------------------------------------------------- |
| **Problem**       | Creating complex or heavy objects repeatedly                                 |
| **Solution**      | Clone existing objects instead of rebuilding them                            |
| **Key Mechanism** | Each class implements a `clone()` method                                     |
| **Type**          | Creational Design Pattern                                                    |
| **Analogy**       | Think of it as "photocopying" an object instead of “drawing it from scratch” |
