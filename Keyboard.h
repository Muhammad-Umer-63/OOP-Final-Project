#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream> //string stream
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


class Keyboard {

private:

	int counter;
	string inputArray[5];
	void initVariables();


public:

	Keyboard();
	~Keyboard();

	string* handleInputKeyboard(sf::Event);

	void handleInput(string);

	void updateKeyboard();
	void renderKeyboard();

};

void Keyboard::initVariables() {

	this->counter = 0;
	for (int i = 0; i < 5; i++) {

		this->inputArray[i] = " ";

	}


}


Keyboard::Keyboard() {

	this->initVariables();

}

Keyboard::~Keyboard() {}

string* Keyboard::handleInputKeyboard(sf::Event ev)
{

	string inputChar;

	while (counter < 5) {

		switch (ev.key.code) {

		case sf::Event::KeyPressed:

			if (ev.key.code == sf::Keyboard::A) {

				inputChar = "a";
				this->handleInput(inputChar);
				break;

			}

			else if (ev.key.code == sf::Keyboard::B) {

				inputChar = "b";
				this->handleInput(inputChar);
				break;

			}
			else if (ev.key.code == sf::Keyboard::C) {

				inputChar = "c";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::D) {

				inputChar = "d";
				this->handleInput(inputChar);
				break;

			}
			else if (ev.key.code == sf::Keyboard::E) {

				inputChar = "e";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::F) {

				inputChar = "f";
				this->handleInput(inputChar);
				break;
			}

			else if (ev.key.code == sf::Keyboard::G) {

				inputChar = "g";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::H) {

				inputChar = "h";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::I) {

				inputChar = "i";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::J) {

				inputChar = "j";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::K) {

				inputChar = "k";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::L) {

				inputChar = "l";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::M) {

				inputChar = "m";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::N) {

				inputChar = "n";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::O) {

				inputChar = "o";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::P) {

				inputChar = "p";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::Q) {

				inputChar = "q";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::R) {

				inputChar = "r";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::S) {

				inputChar = "s";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::T) {

				inputChar = "t";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::U) {

				inputChar = "u";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::V) {

				inputChar = "v";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::W) {

				inputChar = "w";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::X) {

				inputChar = "x";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::Y) {

				inputChar = "y";
				this->handleInput(inputChar);
				break;
			}
			else if (ev.key.code == sf::Keyboard::Z) {

				inputChar = "z";
				this->handleInput(inputChar);
				break;
			}

		}

	}

	return this->inputArray;

}

void Keyboard::handleInput(string charchter)
{

	if (counter < 5) { 
	
		this->inputArray[counter];
		counter++;
		cout << counter;
	}

	else if (counter == 5) {

		this->counter = 0;

	}


}

void Keyboard::updateKeyboard() {




}

void Keyboard::renderKeyboard()
{
}
