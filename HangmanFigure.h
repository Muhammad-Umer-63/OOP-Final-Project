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

class HangmanFigure {

private:

	int left;
	int top;
	int width;
	int height;

	sf::Texture hm_texture;
	sf::Sprite hm_sprite;

	int lives;

	void initVariables();
	void initTexture();
	void initSprite();

public:

	HangmanFigure();
	~HangmanFigure();

	int handleLives();

	void updateSprite();
	void renderSprite(sf::RenderTarget&);

};

void HangmanFigure::initVariables() {

	this->left = 5;
	this->top = 0;
	this->width = 15;
	this->height = 75;
	this->lives = 7;

}


void HangmanFigure::initTexture() {

	this->hm_texture.loadFromFile("Sprites/Hangman/Hangman Sprites Final.png", sf::IntRect(this->left, this->top, this->width, this->height));

}

void HangmanFigure::initSprite() {

	this->hm_sprite.setTexture(this->hm_texture);
	this->hm_sprite.setScale(8.f, 8.f);
	this->hm_sprite.setPosition(50.0f, -225.0f);
	this->hm_sprite.rotate(.0f);

}

HangmanFigure::HangmanFigure() {

	this->initVariables();
	this->initTexture();
	this->initSprite();

}

HangmanFigure::~HangmanFigure() {}

int HangmanFigure::handleLives() { return lives; }

void HangmanFigure::updateSprite() {

	this->left += 15;
	this->lives -= 1;
	this->initTexture();
	hm_sprite.setTexture(this->hm_texture);

}

void HangmanFigure::renderSprite(sf::RenderTarget& target) {

	target.draw(this->hm_sprite);

}