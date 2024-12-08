#pragma once
#include<iostream>
#include"Game.h"
#include "Wordle.h"
#include "Hangman.h"
#include "SoundSystem.h"
#include "Screen.h"
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

	int counter;
	string key;

public:

    InputClass() {
	
		this->key =" ";
		this->counter = 0;

	}

    string mapKey() {
       
        return this->key;

    }

	void handleInputKeyboard(const sf::Event& ev, Screen& s1)
	{
		cout << "\nClick\n";

		string inputChar;

		if (ev.type == sf::Event::KeyPressed) {


			if (ev.key.code == sf::Keyboard::Escape) {

				cout << "Closed Pressed" << "\n";
				s1.close();

			}

			if (ev.key.code == sf::Keyboard::Escape) {

				cout << "\nEscape Pressed\n";
				s1.close();

			}

			if (counter < 5) {

				if (ev.key.code == sf::Keyboard::A) {

					inputChar = "a";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}

				else if (ev.key.code == sf::Keyboard::B) {

					inputChar = "b";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();


				}
				else if (ev.key.code == sf::Keyboard::C) {

					inputChar = "c";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::D) {

					inputChar = "d";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::E) {

					inputChar = "e";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::F) {

					inputChar = "f";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}

				else if (ev.key.code == sf::Keyboard::G) {

					inputChar = "g";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::H) {

					inputChar = "h";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::I) {

					inputChar = "i";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::J) {

					inputChar = "j";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::K) {

					inputChar = "k";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::L) {

					inputChar = "l";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::M) {

					inputChar = "m";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::N) {

					inputChar = "n";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::O) {

					inputChar = "o";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::P) {

					inputChar = "p";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::Q) {

					inputChar = "q";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::R) {

					inputChar = "r";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::S) {

					inputChar = "s";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::T) {

					inputChar = "t";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::U) {

					inputChar = "u";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::V) {

					inputChar = "v";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::W) {

					inputChar = "w";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::X) {

					inputChar = "x";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::Y) {

					inputChar = "y";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}
				else if (ev.key.code == sf::Keyboard::Z) {

					inputChar = "z";
					this->setKey(inputChar);
					this->handleInput(inputChar);
					//this->checkIFKeyIsPressed();

				}

			}

			if (ev.key.code == sf::Keyboard::BackSpace && counter > 0) {

				this->counter -= 1;
				inputChar = " ";
				this->setKey(inputChar);
				cout << "BackSpace\n";
				this->handleInput(inputChar);
				//this->checkIFKeyIsPressed();

			}


		}

	}

	void handleInput(string charchter){}

	bool checkIFKeyIsPressed(string word) //should reset aswell i think
	{

		if (word >= "a" && word <= "z" || word == " ") {

			return true;

		}

		else {

			return false;

		}


	}

	void setKey(string key)
	{

		this->key = key;

	}

    
};
/////////////////////////////////////////////////////////


//class Screen {
//public:
//    sf::RenderWindow window;
//
//    Screen() 
//        : window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006") {
//        window.setFramerateLimit(60);
//    }
//
//    void clear() {
//        window.clear(sf::Color::Black);
//    }
//
//    void display() {
//        window.display();
//    }
//
//    void drawSprite(const sf::Sprite& sprite) {
//        window.draw(sprite);
//    }
// 
//    bool isOpen() const {
//        return window.isOpen();
//    }
//
//    void handleEvents() {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//    }
//};

////////////////////////////////////////////////////////
//class SoundSystem {
//public:
//    sf::Sound sound1;
//    sf::SoundBuffer buffer;
//    sf::SoundBuffer background;
//    sf::Sound backgroundsound;
//    sf::Music m1;
//
//public:
//
//    SoundSystem() {
//
//        background.loadFromFile("Sound/scam_1992.ogg");
//        backgroundsound.setBuffer(background);
//      
//    }
//
//    void playSound(const sf::SoundBuffer& externalBuffer) {
//        sound1.setBuffer(externalBuffer);
//        sound1.play();
//        cout << "Playing sound from provided buffer." << endl;
//    }
//
//    void stopSound() {
//        sound1.stop();
//        cout << "Sound stopped." << endl;
//    }
//
//    void playMusic(const string& externalBuffer) {
//
//        m1.openFromFile(externalBuffer);
//
//
//    }
//
//
//
//};
////////////////////////////////////////////////////


class Gameboy {
private:
    Screen screen;
    Menu menu;
    SoundSystem sounddd;
    Game* g1;
    Game* g2;
    Game* g3;
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

       
       /* if (!bufferscam.loadFromFile("Sound/scam_1992.ogg")) {
            cout<< "\nFailed to load sound file scam_1992.ogg\n";
        }*/
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
                            g1 = new SnakeGame(screen);
                            g1->StartGame(screen);
                           // g1->PlaySound(sounddd.hit);
                            delete g1;

                        }
                        if (HangmanButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            cout << "hangman game selected!" << endl;
                            screen.window.clear();
                            g3 = new Hangman(screen);
                            g3->StartGame(screen);
                            delete g3;


                        }
                        if (WordleButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            cout << "Wordle game selected!" << endl;
                            screen.window.clear();
                            g2 = new Wordle(screen);
                            g2->StartGame(screen);
                            delete g2;
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