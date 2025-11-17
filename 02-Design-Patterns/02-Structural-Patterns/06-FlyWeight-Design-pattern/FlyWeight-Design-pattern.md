🧩 Definition
    Flyweight Design Pattern is a structural design pattern that is used to minimize memory usage or computational expenses by sharing common parts of objects instead of creating new ones every time.

It is especially useful when an application needs to create a large number of similar objects, and storing all of them individually would be expensive in terms of memory.


🎯 Key Idea
    Separate intrinsic and extrinsic states:
        Intrinsic State → shared and stored in the Flyweight (immutable data).
        Extrinsic State → passed from outside (context-specific data).


| # | Use Case               | Description                              | Example                                                        |
| - | ---------------------- | ---------------------------------------- | -------------------------------------------------------------- |
| 1 | Text Rendering         | Many characters share the same font data | Each letter object shares font & style, only position differs  |
| 2 | Game Development       | Large number of repeating entities       | Trees, rocks, enemies that share textures/models               |
| 3 | GUI Applications       | Similar UI controls reused               | Buttons or icons with shared visual attributes                 |
| 4 | Document Editor        | Characters or symbols                    | “A”, “B”, “C” share glyph data, but have different coordinates |
| 5 | Map or Simulation Apps | Repeated map tiles or objects            | Same tree/building object reused at different locations        |
| 6 | Network Systems        | Reused connection configurations         | Reusing sockets or connection pools with shared configuration  |
| 7 | Data Caching           | Repeated data structures                 | Cache reusable immutable data objects instead of duplicating   |



Imagine a game that renders 100,000 trees.
    Each tree has:
        type
        texture (image)
        position (x, y)
        color
    Each tree object stores its own texture, consuming a lot of memory.

┌──────────────────────┐
│       Tree           │
│──────────────────────│
│ + type               │
│ + color              │
│ + x, y               │
│ + texture (big)      │  ← duplicated for every tree
└──────────────────────┘
So, 100,000 trees × 1MB texture = 100 GB memory!

✅ Using Flyweight
We separate shared and unique data:
    Intrinsic State (shared) → Tree type, texture
    Extrinsic State (unique) → Position, color
    We introduce a FlyweightFactory that reuses shared tree data.

🧠 Structure:
    TreeType (Flyweight) → shared data (texture, type)
    Tree (Context) → unique data (x, y, color)
    TreeFactory → manages and reuses TreeTypes

                ┌──────────────────────┐
                │     TreeFactory      │
                │──────────────────────│
                │ + getTreeType()      │
                └─────────┬────────────┘
                          │
                          ▼
┌──────────────────────┐          ┌────────────────────────┐
│       Tree           │          │       TreeType         │
│──────────────────────│          │────────────────────────│
│ + x, y               │          │ + name                 │
│ + color              │          │ + texture              │
│ + draw()             │◄─────────│ + render(shared data)  │
└──────────────────────┘          └────────────────────────┘
   (Extrinsic data only)              (Intrinsic data)
