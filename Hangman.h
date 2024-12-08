#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream> //string stream
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Category.h"
#include "HangmanFigure.h"
#include "Game.h"

using namespace std;

class Hangman : public Game {

private:

	//Rendering Varibles
	//sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode video;

	sf::Clock clock;
	int timer;

	sf::Texture keyboard_texture;
	sf::Sprite keyboard_sprite;

	//class HangmanFigure

	HangmanFigure figure;

	//class Category
	Category category;

	//private variables
	bool endGame;
	string hiddenWord;
	int hiddenWord_len;

	//initializing functions
	void initVariables();
	//void initWindow();
	void initTexture();
	void initSprite();

public:
	
	//Constructor / Destructor
	Hangman(Screen& s1);
	virtual ~Hangman();

	//Accessors // to keep in game loop

	const bool running(Screen& s1) const;
	const bool getEndGame() const;
	virtual void StartGame(Screen& s1);

	void updateSprite();
	void updateClock();

	void renderSprite(Screen& s1);

	//Events Handling
	void pollEvents(Screen& s1);
	void handleInput(string);

	//starting again
	void startOver();

	//Updating
	void update(Screen& s1);

	//Rendering
	void render(Screen& s1);

};

void Hangman::initVariables() {

	//this->window = nullptr;
	this->endGame = false;
	this->hiddenWord = category.getRandomWord();
	cout << hiddenWord << endl;
	this->hiddenWord_len = hiddenWord.length();
	cout << "HiddenWord_Len : " << hiddenWord_len << endl;
	this->category.initHistory(hiddenWord_len);
	//cout << "History Lenght:::::::" << category.getCurrentHistoryLen() << endl;
	this->timer = 0;

}


//void Hangman::initWindow() {
//
//	this->video.width = 800;
//	this->video.height = 600;
//	this->window = new sf::RenderWindow(sf::VideoMode(video), "Hangman", sf::Style::Default);
//	this->window->setFramerateLimit(60);
//
//}


void Hangman::initTexture() {

	this->keyboard_texture.loadFromFile("Sprites/Hangman/Keyboard.png");

}

void Hangman::initSprite() {

	this->keyboard_sprite.setTexture(this->keyboard_texture);
	this->keyboard_sprite.setOrigin(sf::Vector2f(10.f, 10.f));
	this->keyboard_sprite.scale(sf::Vector2f(1.f, 1.f));

}

void Hangman::updateSprite() {}

void Hangman::updateClock()
{

	this->clock.getElapsedTime().asSeconds();
	this->timer++;
	this->clock.restart();

}

void Hangman::renderSprite(Screen& s1) {

	s1.drawSprite(this->keyboard_sprite);

}

const bool Hangman::running(Screen& s1) const { return s1.isOpen(); }

const bool Hangman::getEndGame() const { return this->endGame; }

Hangman::Hangman(Screen& s1) {

	this->initVariables();
	//this->initWindow();

}

Hangman::~Hangman() { //delete this->window; 

}


void Hangman::pollEvents(Screen& s1) {

	string inputChar;

	while (s1.window.pollEvent(this->ev)) {

		switch (this->ev.type) {

		case sf::Event::Closed:

			s1.close();
			break;

		case sf::Event::KeyPressed:

			if (this->ev.key.code == sf::Keyboard::Escape) {

				s1.close();
				break;

			}

			else if (this->ev.key.code == sf::Keyboard::A) {

				inputChar = "a";
				this->handleInput(inputChar);
				break;
			}

			else if (this->ev.key.code == sf::Keyboard::B) {

				inputChar = "b";
				this->handleInput(inputChar);
				break;

			}
			else if (this->ev.key.code == sf::Keyboard::C) {

				inputChar = "c";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::D) {

				inputChar = "d";
				this->handleInput(inputChar);
				break;

			}
			else if (this->ev.key.code == sf::Keyboard::E) {

				inputChar = "e";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::F) {

				inputChar = "f";
				this->handleInput(inputChar);
				break;
			}

			else if (this->ev.key.code == sf::Keyboard::G) {

				inputChar = "g";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::H) {

				inputChar = "h";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::I) {

				inputChar = "i";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::J) {

				inputChar = "j";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::K) {

				inputChar = "k";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::L) {

				inputChar = "l";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::M) {

				inputChar = "m";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::N) {

				inputChar = "n";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::O) {

				inputChar = "o";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::P) {

				inputChar = "p";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::Q) {

				inputChar = "q";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::R) {

				inputChar = "r";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::S) {

				inputChar = "s";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::T) {

				inputChar = "t";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::U) {

				inputChar = "u";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::V) {

				inputChar = "v";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::W) {

				inputChar = "w";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::X) {

				inputChar = "x";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::Y) {

				inputChar = "y";
				this->handleInput(inputChar);
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::Z) {

				inputChar = "z";
				this->handleInput(inputChar);
				break;
			}

		}

	}

}

void Hangman::handleInput(string word)
{
	if (this->endGame == false) {

		bool checkForChange = category.compareWithHiddenWord(hiddenWord, hiddenWord_len, word);

		if (!checkForChange) {

			figure.updateSprite();

		}

		else {

			this->category.updateText();
			this->updateSprite();

		}

	}

	string* hidden = new string[hiddenWord_len];

	for (int i = 0; i < hiddenWord_len; i++) { hidden[i] = hiddenWord[i]; }

	if (category.checkIfWordHasMatchedTillEnd(hidden) && figure.handleLives() > 0) {//yahan pe aik aur loop lag sakta

		this->startOver();
		cout << "HiddenWord_Len : " << hiddenWord_len << endl;

	}

	delete[] hidden;

}

void Hangman::startOver()
{

	this->hiddenWord = category.getRandomWord();
	cout << hiddenWord << endl;
	this->hiddenWord_len = hiddenWord.length();
	this->category.initHistory(hiddenWord_len);


}

void Hangman::update(Screen& s1) {

	this->pollEvents(s1); //order very important //game management


	/*int choice;
	cout << "Option : "; cin >> choice;
	if (choice == 1)
	*/

	//string word;

	//cout << "Enter a word : "; cin >> word; // hnadle input ka aik function ban sakta hai?
	////cout << "\nHidden Word Len: " << hiddenWord_len << endl;
	//bool checkForChange = category.compareWithHiddenWord(hiddenWord, hiddenWord_len, word);

	//if (!checkForChange) {

	//	figure.updateSprite();
	//	
	//}

	//else {

	//	this->category.updateText();
	//	this->updateSprite();

	//}




//End game condition

//cout << this->timer << endl;
	if (this->figure.handleLives() == 0) {  //some thing is definaltely happening //10 seconds???

		cout << "\nHiddenWord Was : " << this->hiddenWord << endl;
		cout << "Womp Womp You Lost" << endl;
		this->endGame = true;

	}


}

void Hangman::render(Screen& s1) { //open your eyes visual

	s1.clear();

	this->figure.renderSprite(s1);

	this->category.renderText(s1);

	this->updateClock();

	this->renderSprite(s1);

	s1.display();

}

void Hangman::StartGame(Screen& s1) {

	while (this->running(s1) && !getEndGame()) {

		//update
		this->update(s1);

		//render
		this->render(s1);

	}

}// game logic interaction?

//while loop which you have to make and do khuoobsorti and stuff