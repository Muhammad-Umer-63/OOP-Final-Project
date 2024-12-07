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
	int endCounter;
	bool endCheck;

	string hiddenWord;
	int hiddenWord_len;
	int counter;
	int countForChar;

	Letter letter[6][5];
	WordDictionary wordDictionary;
	Keyboard keyboard;

	void initVariables();
	void initWindow();
	void drawGrid();

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
	cout << "\n" << hiddenWord << "\n";
	this->hiddenWord_len = hiddenWord.length();
	this->counter = 0;
	this->countForChar = 0;
	this->endCounter = 0;

}

void Wordle::initWindow(){

	this->video.width = 800;
	this->video.height = 600;
	this->window = new sf::RenderWindow(sf::VideoMode(video), "Wordle",sf::Style::Default);
	this->window->setFramerateLimit(60);

}

void Wordle::drawGrid()
{

	float x = 225.0;
	float y = 100.0;

	for (int i = 0; i < 6; i++) { //aleda function

		if (i > 0) { y += 75.0; }

		for (int j = 0; j < 5; j++) {

			if (j > 0) { x += 75.0; }
			this->letter[i][j].initRectangle(x, y);

		}

		x = 225.0;
	}

	y = 100.0;

}

Wordle::Wordle() {

	this->initVariables();
	this->initWindow();
	this->drawGrid();

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
	int* check = 0;

	while (this->window->pollEvent(this->ev)) {

		if (this->ev.type == sf::Event::Closed) {

			cout << "\nCross Pressed\n";
			this->window->close();

		}

		else if (this->ev.type == sf::Keyboard::Escape) {

			cout << "\nEscape Pressed\n";
			this->window->close();

		}

		this->keyboard.handleInputKeyboard(this->ev);
		cout << "\nboool : " << keyboard.isInputComplete() << endl; //this check stays true i think that may be the case why this is happening //change back to false

		
		string* something = this->keyboard.getInputArray();
		string word;

		for (int i = 0; i < 5; i++) {

			cout << "Something : " << something[i] << endl;
			word += something[i];

		}

		if (this->keyboard.checkIFKeyIsPressed(this->keyboard.getKey())) {

			wordDictionary.updateText(word, this->keyboard.getKey());
			this->keyboard.resetKey();

		}



		//this->wordDictionary.renderText(*this->window);
		cout << "\nword: " << word;

		if (keyboard.isInputComplete()) {

			cout << "What : " << endl;

			check = wordDictionary.compareWithHiddenWord(hiddenWord, hiddenWord_len, word);
			cout << "\nCHECK : \n";

			for (int i = 0; i < 5; i++) {

				cout << check[i] << " ";

			}

			cout << endl;

				for (int j = 0; j < 5; j++) {

					this->letter[counter][j].updateLetter(check[j]); 
					cout << "Counter : " << counter << " J : " << j << endl;
					cout << "LOOP Counter : " << counter << endl;

				}

				cout << "\nCHECK non : \n";

				for (int i = 0; i < 5; i++) {

					cout << check[i] << " ";

				}

				cout << endl;


				for (int i = 0; i < 5; i++) {

					if (check[i] != 2) {
						
						break;
						
					}

					else {

						this->endCounter++;

					}

				}

				counter++;
				this->keyboard.resetInput();

		}

		cout << "\nEnd Counter : " << this->endCounter << endl;

		if (this->endCounter == 5) {

			this->endCheck = true;
			this->endGame = true;
			break;

		}

	}

	if(check != NULL){

		delete[] check;

	}

}

void Wordle::update() { //also rendeer it with ttaht

	this->pollEvents(); //order very important

	if (this->endCheck == true && counter < 6) {

		cout << "\nYOU WON\n";
		this->endGame = true;

	}


	//End game condition
	if (this->endGame == true || counter >= 6) {

		this->endGame = true;

	}

}

void Wordle::render() {

	this->window->clear();

	for (int i = 0; i < 6; i++) { // you have create logic around here so that it doesn't get affected

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