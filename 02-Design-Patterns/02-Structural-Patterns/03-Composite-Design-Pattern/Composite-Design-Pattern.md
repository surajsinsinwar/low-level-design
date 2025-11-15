🧩 1. Definition
Composite Design Pattern allows you to treat individual objects and groups (compositions) of objects uniformly.
In other words, it lets clients deal with both single objects (leaves) and composite objects (collections of leaves) through a common interface.

Definition:
    The Composite Design Pattern composes objects into tree structures to represent part-whole hierarchies. It lets clients treat individual objects and compositions of objects uniformly.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


📍 Where to Use
Use Composite Pattern when:
    You have a hierarchical structure (like files/folders, organization trees, UI components, etc.).
    You want to treat single objects and groups of objects in the same way.
    The goal is to let the client treat both single objects and groups of objects uniformly — through a common interface.

⚙️ How It Works
    You define a common interface (Component) for both simple and complex elements.
    Leaf represents simple elements.
    Composite represents complex elements that can have children.
    Clients only interact with the Component interface, making the structure flexible and scalable.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


                 ┌──────────────────────────┐
                 │   FileSystemComponent    │  <<Interface>>
                 │──────────────────────────│
                 │ + showDetails()          │
                 └──────────▲───────────────┘
                            │
          ┌─────────────────┴──────────────────┐
          │                                    │
┌────────────────────────┐          ┌────────────────────────┐
│         File            │          │        Folder          │
│────────────────────────│          │────────────────────────│
│ - name : string         │          │ - name : string         │
│                         │          │ - children : List<FileSystemComponent*>│
│ + showDetails()         │          │ + add(FileSystemComponent*) │
└────────────────────────┘          └────────────────────────┘


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


| Concept   | Role                | Example               |
| --------- | ------------------- | --------------------- |
| Component | Common interface    | `FileSystemComponent` |
| Leaf      | Single item         | `File`                |
| Composite | Group of components | `Folder`              |
| Client    | Uses both uniformly | Calls `showDetails()` |
