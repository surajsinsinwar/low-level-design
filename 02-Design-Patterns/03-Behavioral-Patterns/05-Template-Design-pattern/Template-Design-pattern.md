🧩 Definition
    Template Method Pattern defines the skeleton of an algorithm in a base (abstract) class but allows subclasses to redefine specific steps of the algorithm without changing its overall structure.
    It promotes code reuse, consistency, and control over algorithm flow.

🧭 Key Idea
    You define the “template” (fixed structure) once and allow subclasses to customize only certain steps.

AbstractClass
 ├── templateMethod()         <-- defines algorithm structure
 ├── step1()                  <-- implemented (fixed)
 ├── step2()                  <-- abstract (customizable)
 └── step3()                  <-- abstract (customizable)

ConcreteClassA / ConcreteClassB
 └── implements step2(), step3()


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


| **Use Case**       | **Description**                                                          | **Example**                  |
| ------------------ | ------------------------------------------------------------------------ | ---------------------------- |
| Data Parsing       | Define a common parsing flow, let subclasses parse specific data formats | JSONParser, XMLParser        |
| Report Generation  | Define report generation steps, subclasses customize formatting          | PDFReport, ExcelReport       |
| Game AI            | Define AI behavior flow, subclasses change movement logic                | AggressiveAI, DefensiveAI    |
| Payment Processing | Define payment flow, subclasses implement specific gateways              | PayPalPayment, StripePayment |
| Cooking Recipe App | Define cooking sequence, subclasses define actual steps                  | PastaRecipe, PizzaRecipe     |


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


           ┌──────────────────────┐
           │      Beverage        │
           │  <<Abstract Class>>   │
           │──────────────────────│
           │ + prepareBeverage()  │  <-- Template Method
           │ + boilWater()        │
           │ + pourInCup()        │
           │ + brew() : abstract  │
           │ + addCondiments() : abstract │
           └──────────▲──────────┘
                      │
      ┌───────────────┼────────────────┐
      │                                │
┌───────────────┐              ┌────────────────┐
│     Tea       │              │    Coffee      │
│───────────────│              │────────────────│
│ + brew()      │              │ + brew()       │
│ + addCondiments() │          │ + addCondiments() │
└───────────────┘              └────────────────┘

