🧩 Definition
    Adapter Design Pattern allows incompatible interfaces to work together by providing a wrapper (adapter) that translates one interface into another expected by the client.
In short:
    It converts the interface of a class into another interface that the client expects.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Let’s take a very simple real-world inspired example:
You are building a Media Player application that can play MP3 files.

Now, someone asks you to add support for MP4 files — but you already have a third-party library that can play MP4s, and its interface is different.


         +---------------------+
         |    MediaPlayer      | <--- Target Interface
         +---------------------+
                    ^
                    |
        +-----------+-----------+
        |                       
+----------------+     
|   AudioPlayer  |     
+----------------+

               +----------------------+
               | AdvancedMediaPlayer  | <--- third-party library that can play MP4s
               +----------------------+

❌ Problem
    AudioPlayer only knows how to play MP3 files.
    The new AdvancedMediaPlayer library has a different interface (method name and type).
    We cannot directly integrate AdvancedMediaPlayer without changing AudioPlayer’s code (violating Open/Closed Principle).
    We want to reuse AdvancedMediaPlayer without modifying it

✅ After Scenario (With Adapter)
    We’ll introduce an Adapter that:
    Implements the target interface (MediaPlayer) expected by the client.
    Internally uses the AdvancedMediaPlayer to handle MP4 files.


         +---------------------+
         |    MediaPlayer      | <--- Target Interface
         +---------------------+
                    ^
                    |
        +-----------+-----------+
        |                       |
+----------------+     +-------------------+
|   AudioPlayer  |     |   MediaAdapter    | <--- Adapter
+----------------+     +-------------------+
                       | uses              |
                       v
               +----------------------+
               | AdvancedMediaPlayer  | <--- Adaptee
               +----------------------+


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


It’s particularly useful in situations where:
    You’re integrating with a legacy system or a third-party library that doesn’t match your current interface.
    You want to reuse existing functionality without modifying its source code.
    You need to bridge the gap between new and old code, or between systems built with different interface designs.

| Problem                                  | How Adapter Solves It                               |
| ---------------------------------------- | --------------------------------------------------- |
| Different interfaces (client vs library) | Adapter converts one interface to another           |
| Client can’t use new library directly    | Adapter acts as a middle layer                      |
| Would need to change client code         | No changes needed — just plug adapter               |
| Violates Open/Closed if changed directly | Adapter adheres to Open/Closed — we extend behavior |
