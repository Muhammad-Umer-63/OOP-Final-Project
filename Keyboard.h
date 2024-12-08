#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream> //string stream
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace std;

class Keyboard {

private:

	int counter;
	string inputArray[5];
	void initVariables();
	string key;


public:

	Keyboard();
	~Keyboard();

	void handleInputKeyboard(const sf::Event& ev, Screen& s1);
	void handleInput(string);

	bool checkIFKeyIsPressed(string);

	void setKey(string);
	string getKey();
	void resetKey();

	string* getInputArray();
	bool isInputComplete() const;
	void resetInput();

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

void Keyboard::handleInputKeyboard(const sf::Event& ev, Screen& s1)
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

void Keyboard::handleInput(string charchter)
{

	if (counter < 5) {

		cout << "\nCounter :" << counter << endl;
		this->inputArray[counter] = charchter;

		if (inputArray[counter] != " ") { //cater backspace

			counter++;

		}

	}

}

bool Keyboard::checkIFKeyIsPressed(string word) //should reset aswell i think
{

	if (word >= "a" && word <= "z" || word == " ") {

		return true;

	}

	else {

		return false;

	}


}

void Keyboard::setKey(string key)
{

	this->key = key;

}

string Keyboard::getKey()
{

	return this->key;

}

void Keyboard::resetKey()
{

	this->key = ".";

}

string* Keyboard::getInputArray()
{

	return inputArray;

}

bool Keyboard::isInputComplete() const
{

	return this->counter == 5;

}

void Keyboard::resetInput()
{

	this->counter = 0;

	for (int i = 0; i < 5; i++) {

		this->inputArray[i] = " ";

	}

}

//get key and change key