#pragma once
#include"Game.h"
#include<iostream>
using namespace std;

class Menu {
public:
    sf::Texture menutexture;
    sf::Sprite menusprite;
public:
    Menu() {}
    sf::Sprite displayMenu() {
        menutexture.loadFromFile("gameboy.png");
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
private:
    sf::RenderWindow window;
public:
    Screen() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
        window.setFramerateLimit(60);
    }
    void drawScreen(sf::Sprite sprite) {
        window.draw(sprite);
    }


};
////////////////////////////////////////////////////////
class Sound {
private:
    sf::Sound sound;

public:
    Sound() {}

    void playSound(const sf::SoundBuffer& externalBuffer) {
        sound.setBuffer(externalBuffer);
        sound.play();
        cout << "Playing sound from provided buffer." << endl;
    }

    void stopSound() {
        sound.stop();
        cout << "Sound stopped." << endl;
    }
};
////////////////////////////////////////////////////


class Gameboy {
private:
	Screen *s1;
	Menu m1;
	InputClass *i1;
	Sound sound1;

public:
	Gameboy(): i1(new InputClass), s1(new Screen) {
		
		s1->drawScreen(m1.displayMenu());
		
	}




};
///////////////////////////////////////////////////////////////
