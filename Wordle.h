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

	string hiddenWord;
	int hiddenWord_len;
	int counter;
	int countForChar;

	Letter letter[6][5];
	WordDictionary wordDictionary;
	Keyboard keyboard;

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
	this->hiddenWord = wordDictionary.getRandomWord();
	this->hiddenWord_len = hiddenWord.length();
	this->counter = 0;
	this->countForChar = 0;

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

	/*cout << "\nHidden Word : " << hiddenWord << endl;
				string st;
				cout << "Enter String : "; cin >> st;*/

	cout << "Here\n";

	string* something = this->keyboard.handleInputKeyboard(this->ev);
	int* check;

	cout << "nope\n";

	if (countForChar == 5) {


		check = wordDictionary.compareWithHiddenWord(hiddenWord, hiddenWord_len, something);
		for (int j = 0; j < 5; j++) {

			this->letter[counter][j].updateLetter(check[j]);

		}

		counter++;


	}

	else {

		this->countForChar++;

	}


}

void Wordle::update() {

	this->pollEvents(); //order very important

	//if (this->endGame == false) {


			float x = 225.0;
			float y = 100.0;

			//int count;
			//cout << "count : "; cin >> count; //for chnage letter[0][i] //draw grid
			//if (count == 1){
				for (int i = 0; i < 6; i++) { //aleda function

					if (i > 0) { y += 75.0; }

					for (int j = 0; j < 5; j++) {

						if (j > 0) { x += 75.0; }

						this->letter[i][j].initRectangle(x,y);

					}

					x = 225.0;
				}

					y = 100.0;

			//}

					/*cout << "\nHidden Word : " << hiddenWord << endl;
					string st;
					cout << "Enter String : "; cin >> st;*/

					/*cout << "Here\n";

					string* something = this->keyboard.handleInputKeyboard(ev);
					int* check;

					cout << "nope\n";

					if (countForChar == 5) {

						
						check = wordDictionary.compareWithHiddenWord(hiddenWord, hiddenWord_len, something);
						for (int j = 0; j < 5; j++) {

							this->letter[counter][j].updateLetter(check[j]);

						}

						counter++;


					}

					else {

						this->countForChar++;

					}*/


	//}

	//int random = rand() % 3;

	//if (this->endGame == false) {

		
	//}

	if (this->endGame == false) {

		this->wordDictionary.updateText();

	}

	//End game condition
	if (this->endGame == true || counter >=6) {

		this->endGame = true;

	}

}

void Wordle::render() {

	this->window->clear();

	for (int i = 0; i < 6; i++) { // you have creat logic around here so that it doesn't get affected

		for (int j = 0; j < 5; j++) {

			this->letter[i][j].renderLetter(*this->window);

		}

	}

	this->wordDictionary.renderText(*this->window);

	this->window->display();

}

void Wordle::gameLoop() {

	while (running() && !getEndGame()) {


		update();


		render();

	}

}


//basically input tab tak lete rahein gay jab tak humara count = 5 to nahi hojata hai
//backspace and enter ko bhi handle karna hai kisi tareekay se what are the possiblities for that
//enter ke saath aik check lag jaye aur counter decrements with backspace but theri is one thing that i have to do is very important have to cater it for every like
//har input mein woh charachter aye and correct word also is their loop to check that the word exits or not usi mein dalein gay hum
//some edge case when you repeat the word