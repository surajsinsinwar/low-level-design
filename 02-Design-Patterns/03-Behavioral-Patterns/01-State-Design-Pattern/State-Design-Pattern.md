🧩 State Design Pattern
    Definition
        The State Design Pattern allows an object to change its behavior dynamically when its internal state changes.
        It appears as if the object changes its class — i.e., it behaves differently in different states without using complex conditional logic.
    Key idea:
        Instead of using multiple if-else or switch statements to handle state-specific behavior, we encapsulate each state into a separate class and delegate behavior to the current state object.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


| **Use Case**      | **Description**                                              | **Example**                                                |
| ----------------- | ------------------------------------------------------------ | ---------------------------------------------------------- |
| UI Components     | Behavior of a button or toggle changes when enabled/disabled | A button click does nothing when disabled                  |
| Media Player      | Play, pause, stop states with different behaviors            | When paused, clicking play resumes instead of starting new |
| TCP Connection    | Different behaviors for open, closed, and listening states   | A “send” request works only in connected state             |
| Vending Machine   | Different actions based on machine state                     | Insert coin → select product → dispense product            |
| Document Workflow | Draft, Moderation, Published states                          | Only in Draft state can edit happen                        |
| Game Development  | Player behavior changes with states                          | Normal mode vs Power-up mode                               |
| ATM Machine       | Operations depend on authentication state                    | “Withdraw” works only when logged in                       |


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


               <<interface>>
                 +-------------+
                 |   State     |
                 |-------------|
                 | +publish(Context*) : void
                 | +edit(Context*)    : void
                 +------+------+
                        ^
                        | implements / inherits
  +---------------------+----------------------+
  |                    |                       |
  |                    |                       |
+--------+        +-------------+         +--------------+
|Draft   |        |Moderation   |         |Published     |
|State   |        |State        |         |State         |
|--------|        |-------------|         |--------------|
|+publish(Context*)|+publish(Ctx*)|        |+publish(Ctx*)|
|+edit(Context*)   |+edit(Ctx*)   |        |+edit(Ctx*)   |
+--------+        +-------------+         +--------------+
                        ^
                        |  <-- no direct references to other states
                        |
                 +------+------+
                 |   Document  |
                 | (Context)   |
                 |-------------|
                 | - state: State*    (or unique_ptr<State>)
                 |-------------|
                 | +publish()         |
                 | +edit()            |
                 | +setState(State*)  |
                 +--------------------+
