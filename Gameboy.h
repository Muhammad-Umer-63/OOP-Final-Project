#pragma once
#include"Game.h"
#include<iostream>
//#include"SnakeGame.h"
using namespace std;

class Menu {
public:
    sf::Texture menutexture;
    sf::Sprite menusprite;
    bool flag = false;
    

public:

    sf::Sprite displayMainMenu() {
        if (!menutexture.loadFromFile("Sprites/Gameboy Sprites/gameboy.png")) {
        }
        menusprite.setTexture(menutexture);
        return menusprite;
    }

    sf::Sprite displayGameMenu() {
        if (!menutexture.loadFromFile("Sprites/Gameboy Sprites/game.png")) {
        }
        menusprite.setTexture(menutexture);
        return menusprite;
    }
};
//////////////////////////////////////////////////////////////////////
class InputClass {
public:
    InputClass() {}

    char mapKey(char key) {
       
        return key;
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

    void drawSprite(const sf::Sprite& sprite) {
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
public:
    sf::Sound sound1;
    sf::SoundBuffer buffer;
    sf::SoundBuffer background;
    sf::Sound backgroundsound;
      

public:
    Sound() {
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
    

};
////////////////////////////////////////////////////


class Gameboy {
private:
    Screen screen;
    Menu menu;
    Sound sounddd;
    Game* g1;
    sf::Sound soundscam;
    sf::SoundBuffer bufferscam;
    sf::RectangleShape GamesButton;  
    sf::RectangleShape ExitButton;  
    sf::RectangleShape snakeButton;
    sf::RectangleShape WordleButton;
    sf::RectangleShape HangmanButton;

public:
    Gameboy() {
        GamesButton.setSize(sf::Vector2f(150, 60)); 
        GamesButton.setFillColor(sf::Color::Transparent);
        GamesButton.setPosition(330, 230);  

        ExitButton.setSize(sf::Vector2f(90, 50));
        ExitButton.setFillColor(sf::Color::Transparent);
        ExitButton.setPosition(360, 300); 

        snakeButton.setSize(sf::Vector2f(400, 60));
        snakeButton.setFillColor(sf::Color::Transparent);
        snakeButton.setPosition(200, 160);

        WordleButton.setSize(sf::Vector2f(270, 50));
        WordleButton.setFillColor(sf::Color::Transparent);
        WordleButton.setPosition(260, 240);

        HangmanButton.setSize(sf::Vector2f(310, 60));
        HangmanButton.setFillColor(sf::Color::Transparent);
        HangmanButton.setPosition(240, 320);

       
        if (!bufferscam.loadFromFile("Sound/scam_1992.ogg")) {
            throw std::runtime_error("Failed to load sound file scam_1992.ogg");
        }
        soundscam.setBuffer(bufferscam);
        sounddd.playSound(bufferscam);
    }

    void run() {
        menu.displayMainMenu();

        while (screen.isOpen()) {

            sf::Event event;
            while (screen.window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    screen.window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    screen.window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(screen.window);
                    if (!menu.flag) {

                        if (GamesButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            cout << "Game menu selected!" << endl;
                            menu.flag = true;
                        }

                        if (ExitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            cout << "Exit" << endl;
                            screen.window.close();
                        }
                    }
                    else {

                        if (snakeButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            cout << "Snake game selected!" << endl;
                            screen.window.clear();
                            g1 = new SnakeGame(screen.window);
                            g1->StartGame(screen.window);
                           // g1->PlaySound(sounddd.hit);
                            

                        }
                        if (HangmanButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            cout << "hangman game selected!" << endl;
                        }
                        if (WordleButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            cout << "Wordle game selected!" << endl;
                        }
                    }
                }
            }
      

                screen.handleEvents();
                screen.clear();
                if (!menu.flag) {
                    screen.drawSprite(menu.menusprite);
                    screen.window.draw(GamesButton);
                    screen.window.draw(ExitButton);

                }
                else {
                    menu.displayGameMenu();
                    screen.drawSprite(menu.displayGameMenu());
                    screen.window.draw(snakeButton);
                    screen.window.draw(WordleButton);
                    screen.window.draw(HangmanButton);
                }


                

                screen.display();



            }
        }

    
};
///////////////////////////////////////////////////////////////
