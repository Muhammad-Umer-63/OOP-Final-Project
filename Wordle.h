#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream> //string stream
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "WordDictionary.h"
#include "Keyboard.h"
#include "Letter.h"


class Wordle {

private:

	sf::RenderWindow* window;
	sf::VideoMode video;
	sf::Event ev;

	bool endGame;

	void initVariables();
	void initWindow();

public :


	Wordle();
	virtual ~Wordle();


	const bool running() const;
	const bool getEndGame() const;

	void pollEvents();
	void update();
	void render();

	void gameLoop();


};


void Wordle::initVariables() {

	this->window = NULL;
	this->endGame = false;

}

void Wordle::initWindow(){

	this->video.width = 800;
	this->video.height = 600;
	this->window = new sf::RenderWindow(sf::VideoMode(video), "Wordle",sf::Style::Default);
	this->window->setFramerateLimit(60);

}

Wordle::Wordle() {

	this->initVariables();
	this->initWindow();

}

Wordle::~Wordle() {

	delete this->window;

}

//Accessors
const bool Wordle::running() const {

	return this->window->isOpen();

}

const bool Wordle::getEndGame() const
{
	return this->endGame;

}

void Wordle::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {

		switch (this->ev.type) {

		case sf::Event::Closed:

			this->window->close();
			break;

		case sf::Event::KeyPressed:

			if (this->ev.key.code == sf::Keyboard::Escape) {

				this->window->close();
				break;

			}

		}

	}

}

void Wordle::update() {

	this->pollEvents(); //order very important

	if (this->endGame == false) {

	}

	//End game condition
	if (this->endGame == true) {

		this->endGame = true;

	}

}

void Wordle::render() {

	this->window->clear();

	this->window->display();

}

void Wordle::gameLoop() {

	while (running() && !getEndGame()) {


		update();


		render();

	}

}