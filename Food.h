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
	int randi=0;
	int randj=0;
	float xvelocity = 0, yvelocity = 0;
		 
public:

	Food() {
		randi = rand() % 600 + 100;
		randj = rand() % 400 + 100;
		foodPosition.x = randi;
		foodPosition.y = randj;
		foodTexture.loadFromFile("rabbit.png");
		foodSprite.setTexture(foodTexture);
		foodSprite.setScale(0.85f, 0.85f);

		
	}
	

	void drawFood(sf::RenderWindow& window){
		randi = rand() % 600 + 100;
		randj = rand() % 400 + 100;
		foodPosition.x = randi;
		foodPosition.y = randj;
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

	
	int getfoodpointx()const {
		//cout << "Food: "<< foodPosition.x/10-10 << " ";
		return(foodPosition.x/10-10);
	}
	int getfoodpointy()const {
		//cout << foodPosition.y/10-10 << " \n";
		return(foodPosition.y/10-10);
	}
	void increaseVelocity() {
		xvelocity += 0.1;
		yvelocity += 0.9;
	}
	


};
