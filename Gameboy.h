#pragma once
//#include"Game.h"
#include<iostream>
//#include"SnakeGame.h"
using namespace std;

class Menu {
private:
    sf::Texture menutexture;

public:
    sf::Sprite menusprite;

    sf::Sprite displayMainMenu() {
        if (!menutexture.loadFromFile("gameboy.png")) {
            throw std::runtime_error("Failed to load gameboy.png");
        }
        menusprite.setTexture(menutexture);
        return menusprite;
    }

    sf::Sprite displayGameMenu() {
        if (!menutexture.loadFromFile("game.png")) {
            throw std::runtime_error("Failed to load game.png");
        }
        menusprite.setTexture(menutexture);
        return menusprite;
    }
};
//////////////////////////////////////////////////////////////////////
class InputClass {
public:
    InputClass() {}

    char mapKey() {
        char key;
        cout << "Enter a key: ";
        cin >> key;
        return key;
    }

    void handleInput() {
        char key = mapKey();

        switch (key) {
        case 'w':
        case 'W':
            cout << "Move Up\n";
            break;
        case 's':
        case 'S':
            cout << "Move Down\n";
            break;
        case 'a':
        case 'A':
            cout << "Move Left\n";
            break;
        case 'd':
        case 'D':
            cout << "Move Right\n";
            break;
        case 'q':
        case 'Q':
            cout << "Quit Game\n";
            break;
        default:
            cout << "Invalid Key Pressed: " << key << "\n";
        }
    }
};
/////////////////////////////////////////////////////////


class Screen {
public:
    sf::RenderWindow window;

    Screen()
        : window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006") {
        window.setFramerateLimit(60);
    }

    void clear() {
        window.clear(sf::Color::Black);
    }

    void display() {
        window.display();
    }

    void draw(const sf::Sprite& sprite) {
        window.draw(sprite);
    }

    bool isOpen() const {
        return window.isOpen();
    }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
};
////////////////////////////////////////////////////////
class Sound {
private:
    sf::Sound sound1;
    sf::SoundBuffer buffer;
    

public:
    Sound() {
        
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
};
////////////////////////////////////////////////////


class Gameboy {
private:
    Screen screen;
    Menu menu;
    Sound sounddd;
    sf::Sound soundscam;
    sf::SoundBuffer bufferscam;

public:
    Gameboy() {
        if (!bufferscam.loadFromFile("scam_1992.ogg")) {
            throw std::runtime_error("Failed to load sound file scam_1992.ogg");
        }
        soundscam.setBuffer(bufferscam);
        sounddd.playSound(bufferscam);
    }

    void run() {
        menu.displayMainMenu();

        while (screen.isOpen()) {

            screen.handleEvents();
            screen.clear();
            screen.draw(menu.menusprite);
            screen.display();


            
        }
    }
};
///////////////////////////////////////////////////////////////
