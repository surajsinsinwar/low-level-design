/*
                     +----------------------+
                     |     MediaPlayer      |  <--- Target Interface
                     +----------------------+
                              ^
                              |
        +---------------------+-----------------------+
        |                                             |
 +---------------+                          +----------------+
 |   Mp3Player   |                          |   Mp4Adapter   |  <--- Adapter
 +---------------+                          +----------------+
                                              |
                                              v
                                   +----------------------+
                                   |  AdvancedMediaPlayer |  <--- Adaptee
                                   +----------------------+

 +--------------------+
 | MediaAdapterFactory|  <--- Factory that maps type -> player
 +--------------------+
          ^
          |
 +--------------------+
 |    AudioPlayer     |  <--- Client (no if-else!)
 +--------------------+

*/


#include <iostream>
#include <string>
#include <map>
using namespace std;

// ---- Target Interface ----
class MediaPlayer {
public:
    virtual void play(string fileName) = 0;
    virtual ~MediaPlayer() {}
};

// ---- Adaptee (incompatible class) ----
class AdvancedMediaPlayer {
public:
    void playMp4(string fileName) {
        cout << "Playing mp4 file: " << fileName << endl;
    }
};

// ---- Concrete Implementations for Each Type ----
class Mp3Player : public MediaPlayer {
public:
    void play(string fileName) override {
        cout << "Playing mp3 file: " << fileName << endl;
    }
};

// Adapter converting AdvancedMediaPlayer interface to MediaPlayer
class Mp4Adapter : public MediaPlayer {
    AdvancedMediaPlayer advancedPlayer;
public:
    void play(string fileName) override {
        advancedPlayer.playMp4(fileName);
    }
};

// ---- Adapter Manager (Factory + Adapter logic) ----
class MediaAdapterFactory {
    map<string, MediaPlayer*> players;
public:
    MediaAdapterFactory() {
        // Register supported players
        players["mp3"] = new Mp3Player();
        players["mp4"] = new Mp4Adapter();
    }

    MediaPlayer* getPlayer(string type) {
        if (players.find(type) != players.end()) {
            return players[type];
        }
        return nullptr;
    }

    ~MediaAdapterFactory() {
        for (auto& p : players) delete p.second;
    }
};

// ---- Client Class ----
class AudioPlayer {
    MediaAdapterFactory factory;
public:
    void play(string audioType, string fileName) {
        MediaPlayer* player = factory.getPlayer(audioType);
        if (player) player->play(fileName);
        else cout << "Invalid media type: " << audioType << endl;
    }
};

// ---- Main ----
int main() {
    AudioPlayer player;
    player.play("mp3", "song.mp3");
    player.play("mp4", "video.mp4");
    player.play("avi", "movie.avi");  // Unsupported
    return 0;
}
