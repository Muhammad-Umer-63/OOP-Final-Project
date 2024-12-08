#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;


class SoundSystem {
public:
    sf::Sound sound1;
    sf::SoundBuffer buffer;
    sf::SoundBuffer background;
    sf::Sound backgroundsound;
    sf::Music m1;

public:

    SoundSystem() {

        background.loadFromFile("Sound/scam_1992.ogg");
        backgroundsound.setBuffer(background);

    }

    void playSound(const sf::SoundBuffer& externalBuffer) {
        sound1.setBuffer(externalBuffer);
        sound1.play();
        cout << "Playing sound from provided buffer." << endl;
    }

    void stopSound() {
        sound1.stop();
        cout << "Sound stopped." << endl;
    }

    void playMusic(const string& externalBuffer) {

        m1.openFromFile(externalBuffer);
        m1.play();

    }

};