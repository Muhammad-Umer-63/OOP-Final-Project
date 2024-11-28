#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include<ctime>
#include<cstdlib>
using namespace std;



class Food {
private:
	sf::Texture foodTexture;
	sf::Sprite foodSprite;
	sf::Vector2f foodPosition;
	int x, y;
	int randi;
	int randj;
	float xvelocity = 1.5, yvelocity = 1.5;
		 
public:

	Food() {
		randi = rand() % 600 + 100;
		randj = rand() % 400 + 100;
		foodPosition.x = randi;
		foodPosition.y = randj;
		foodTexture.loadFromFile("rabbit.png");
		foodSprite.setTexture(foodTexture);
		foodSprite.setScale(1.5f, 1.5f);

		
	}
	void placeFood(int(&grid)[60][40]) {
		// Randomly place food in an empty spot
		do {
			x = rand() % 60; // Random column
			y = rand() % 40; // Random row
		} while (grid[x][y] != 0); // Ensure the spot is empty

		grid[x][y] = 2; // Update the grid with food
	}

	int getX() const { return x; }
	int getY() const { return y; }
	sf::Vector2f getFoodPosition() const {
		return foodPosition;
	}

	void drawFood(sf::RenderWindow& window){
		if (foodPosition.x > 700-20 || foodPosition.x < 100) {
			xvelocity *= -1;
		}
		if (foodPosition.y > 500-20 || foodPosition.y < 100) {
			yvelocity *= -1;
		}

		foodPosition.x += xvelocity;
		foodPosition.y += yvelocity;
		foodSprite.setPosition(foodPosition.x,foodPosition.y);
		window.draw(foodSprite);
	}


	



};
