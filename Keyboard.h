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
	void initVariables();


public:

	Keyboard();
	~Keyboard();

	void handleInput();

	void updateKeyboard();
	void renderKeyboard();

};

void Keyboard::initVariables() {

	this->counter = 0;

}


Keyboard::Keyboard() {

	this->initVariables();

}

Keyboard::~Keyboard() {}

void Keyboard::handleInput()
{

	//if (sf::Keyboard::) {



	//}

}


void Keyboard::updateKeyboard()
{


	
}

void Keyboard::renderKeyboard()
{
}
