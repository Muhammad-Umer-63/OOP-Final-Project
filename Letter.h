#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream> //string stream
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Letter {

private: //numbers according to array to choose color

	sf::RectangleShape rectangle;

	float x_pos;
	float y_pos;
	
	int count_X;
	int count_Y;

	int row;

	void initVariables();
	

public:

	void initRectangle(float, float);

	Letter();
	~Letter();

	void updateLetter(int);
	void renderLetter(sf::RenderTarget&);


};

void Letter::initVariables() {

	this->x_pos = 0;
	this->y_pos = 0;

	this->count_X = 1;
	this->count_Y = 1;

	this->row = 0;
}

void Letter::initRectangle(float x_pos, float y_pos)
{

	this->x_pos = x_pos;
	this->y_pos = y_pos;

	this->rectangle.setSize(sf::Vector2f(50.f, 50.f));//important
	this->rectangle.setPosition(sf::Vector2f(this->x_pos, this->y_pos));
	this->rectangle.setScale(sf::Vector2f(1.f, 1.f));

}

Letter::Letter() {

	this->initVariables();
	//this->initRectangle();

}

Letter::~Letter()
{


}

void Letter::updateLetter(int i)  //use this for coloring
{

	cout << "Value: " << i << endl;

	/*if (this->count_X <= 5) {

		this->x_pos += 50;
		this->count_X++;
		this->rectangle.setPosition(this->x_pos,this->y_pos);

	}

	else {

		this->x_pos = 250.0;
		this->y_pos += 100.0;
		this->count_X = 0;
		this->count_Y++;
		this->rectangle.setPosition(this->x_pos, this->y_pos);


	}*/

	//int r = rand() % 3; // yup have to do something here // aik array lo gay aur uske saath aap kaam karo ge you have to basically give some numbers based on correctness of that and do that

		for (int j = 0; j < 5; j++) { //changing eveyr single rectangle //should i make rectangle for each box?

			if (i == 0) {

				this->rectangle.setFillColor(sf::Color{149,165,166});
			}

			else if (i == 1) {


				this->rectangle.setFillColor(sf::Color::Yellow);
			}

			else if (i == 2) {

				this->rectangle.setFillColor(sf::Color::Green);

			}

		}

	//this->row++;

}

void Letter::renderLetter(sf::RenderTarget& target)
{

	target.draw(this->rectangle);

}
