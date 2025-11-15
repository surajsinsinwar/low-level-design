/*
🧠 Before Scenario (Without Adapter)
    Let’s take a very simple real-world inspired example:
    You are building a Media Player application that can play MP3 files.
    Now, someone asks you to add support for MP4 files — but you already have a third-party library that can play MP4s, and its interface is different.
*/

#include <iostream>
#include <string>
using namespace std;

// Client expects this interface
class MediaPlayer {
public:
    virtual void play(string audioType, string fileName) = 0;
};

// Existing implementation that plays mp3
class AudioPlayer : public MediaPlayer {
public:
    void play(string audioType, string fileName) override {
        if (audioType == "mp3") {
            cout << "Playing mp3 file: " << fileName << endl;
        } else {
            cout << "Invalid media. " << audioType << " format not supported" << endl;
        }
    }
};

// Third-party library for mp4 files (different interface)
class AdvancedMediaPlayer {
public:
    void playMp4(string fileName) {
        cout << "Playing mp4 file: " << fileName << endl;
    }
};

int main() {
    AudioPlayer player;
    player.play("mp3", "song.mp3");
    player.play("mp4", "video.mp4");  // ❌ Not supported
    return 0;
}

/*
    ❌ Problem
        AudioPlayer only knows how to play MP3 files.
        The new AdvancedMediaPlayer library has a different interface (method name and type).
        We cannot directly integrate AdvancedMediaPlayer without changing AudioPlayer’s code (violating Open/Closed Principle).
        We want to reuse AdvancedMediaPlayer without modifying it.
    ✅ After Scenario (With Adapter)
        We’ll introduce an Adapter that:
        Implements the target interface (MediaPlayer) expected by the client.
        Internally uses the AdvancedMediaPlayer to handle MP4 files.
*/

#include <iostream>
#include <string>
using namespace std;

// Target interface (expected by client)
class MediaPlayer {
public:
    virtual void play(string audioType, string fileName) = 0;
};

// Adaptee (incompatible library)
class AdvancedMediaPlayer {
public:
    void playMp4(string fileName) {
        cout << "Playing mp4 file: " << fileName << endl;
    }
};

// Adapter class
class MediaAdapter : public MediaPlayer {
    AdvancedMediaPlayer advancedPlayer;

public:
    void play(string audioType, string fileName) override {
        if (audioType == "mp4") {
            advancedPlayer.playMp4(fileName);
        }
    }
};

// Concrete class using adapter
class AudioPlayer : public MediaPlayer {
public:
    void play(string audioType, string fileName) override {
        if (audioType == "mp3") {
            cout << "Playing mp3 file: " << fileName << endl;
        } 
        else if (audioType == "mp4") {
            MediaAdapter adapter;
            adapter.play(audioType, fileName);
        } 
        else {
            cout << "Invalid media. " << audioType << " format not supported" << endl;
        }
    }
};

int main() {
    AudioPlayer player;
    player.play("mp3", "song.mp3");
    player.play("mp4", "video.mp4");   // ✅ Now works through adapter
    return 0;
}
/*
    We can remove if else logic from AudioPlayer by seprating adapter creation logic into another class/factory.
*/