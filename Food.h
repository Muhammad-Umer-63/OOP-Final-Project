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
	sf::Texture bonusTexture;
	sf::Sprite bonusSprite;
	sf::Vector2f bonusPosition;
	int randi=0;
	int randj=0;
	float xvelocity = 0, yvelocity = 0;
		 
public:

	int score;


	Food() {

		score = 0;
		randi = rand() % 500 + 150;
		randj = rand() % 400 + 150;
		foodPosition.x = randi;
		foodPosition.y = randj;
		foodTexture.loadFromFile("rabbit.png");
		//foodTexture.loadFromFile("flag.jpeg");
		foodSprite.setTexture(foodTexture);
		foodSprite.setScale(0.85f, 0.85f);
		//foodSprite.setScale(0.07f, 0.07f);
		bonusTexture.loadFromFile("bonus.jpeg");
		bonusSprite.setTexture(bonusTexture);
		bonusSprite.setScale(0.2f,0.2f);
		bonusPosition.x = 450;
		bonusPosition.y = 450;


		
	}
	

	void drawFood(sf::RenderWindow& window){
		if (foodPosition.x > 700-20 || foodPosition.x < 100) {
			xvelocity *= -1;
		}
		if (foodPosition.y > 500-20 || foodPosition.y < 100) {
			yvelocity *= -1;
		}

		//foodPosition.x += xvelocity;
        //foodPosition.y += yvelocity;
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
		randi = 320;
		randj = 320;
		xvelocity += 0.1;
		yvelocity += 0.1;
	}
	void repositionFood() {
		int randi = rand() % 500 + 120;
		int randj = rand() % 300 + 120;
		foodPosition.x = randi;
		foodPosition.y = randj;

		xvelocity = 0.5f;  
		yvelocity = 0.5f;  
	}

	void bonus(sf::RenderWindow& window) {
		bonusPosition.x = randi;
		bonusPosition.y = randj;
		bonusSprite.setPosition(bonusPosition.x, bonusPosition.y); 
			window.draw(bonusSprite);
	}

	int getbonuspointx()const {
		//cout << "bonus: "<< bonusPosition.x/10-10 << " ";
		return(bonusPosition.x / 10 - 10);
	}
	int getbonuspointy()const {
		//cout << bonusPosition.y/10-10 << " \n";
		return(bonusPosition.y / 10 - 10);
	}
};
