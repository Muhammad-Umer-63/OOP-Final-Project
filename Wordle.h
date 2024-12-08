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
#include "Game.h"
#include "Screen.h"

using namespace std;

class Wordle : public Game{

private:

	/*sf::RenderWindow* window;*/
	/*sf::VideoMode video;*/
	sf::Event ev;

	sf::Texture background_texture;
	sf::Sprite background_sprite;

	sf::SoundBuffer thak;

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
	//void initWindow();
	void initTexture();
	void initSprite();
	void drawGrid();

public:

	Wordle(Screen& s1);
	virtual ~Wordle();

	const bool running(Screen& s1) const;
	const bool getEndGame() const;

	void pollEvents(Screen& s1);
	void renderBackground(Screen& s1);
	void update(Screen& s1);
	void render(Screen& s1);

	virtual void StartGame(Screen& s1);


};


void Wordle::initVariables() {

	//this->window = NULL;
	this->endGame = false;
	this->hiddenWord = wordDictionary.getRandomWord();
	cout << "\n" << hiddenWord << "\n";
	this->hiddenWord_len = hiddenWord.length();
	this->counter = 0;
	this->countForChar = 0;
	this->endCounter = 0;
	this->thak.loadFromFile("Sound/Wordle Sound/thak sound.ogg");

}

//void Wordle::initWindow() { //khatam
//
//	this->video.width = 800;
//	this->video.height = 600;
//	this->window = new sf::RenderWindow(sf::VideoMode(video), "Wordle", sf::Style::Default);
//	this->window->setFramerateLimit(60);
//
//}

void Wordle::initTexture()
{

	if (!this->background_texture.loadFromFile("Sprites/Wordle Sprites/wordle Background.png")) {

		cout << "\nFailed to load Background.png\n";

	}

}

void Wordle::initSprite()
{

	this->background_sprite.setTexture(this->background_texture);

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

Wordle::Wordle(Screen& s1) {

	this->initVariables();
	//this->initWindow();
	this->initTexture();
	this->initSprite();
	this->drawGrid();

}

Wordle::~Wordle() {

	//delete this->window;

}

//Accessors
const bool Wordle::running(Screen& s1) const {

	return s1.isOpen();

}

const bool Wordle::getEndGame() const
{
	return this->endGame;

}

void Wordle::pollEvents(Screen& s1)
{
	int* check = 0;

	while (s1.window.pollEvent(this->ev)) {

		/*if (this->ev.type == sf::Event::Closed) {

			cout << "\nCross Pressed\n";
			window.close();

		}*/

		/*else if (this->ev.type == sf::Keyboard::Escape) {

			cout << "\nEscape Pressed\n";
			window.close();

		}*/

		this->keyboard.handleInputKeyboard(this->ev, s1);
		cout << "\nboool : " << keyboard.isInputComplete() << endl; //this check stays true i think that may be the case why this is happening //change back to false


		string* something = this->keyboard.getInputArray();
		string word;

		for (int i = 0; i < 5; i++) {

			cout << "Something : " << something[i] << endl;
			word += something[i];

		}

		if (this->keyboard.checkIFKeyIsPressed(this->keyboard.getKey())) {

			wordDictionary.updateText(word, this->keyboard.getKey());
			this->PlayhitSound(this->thak);
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

			//yahan pe aik check lage ga

			for (int j = 0; j < 5; j++) {

				this->letter[counter][j].updateLetter(check[j]); //int ptr
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

					this->endCounter = 0;
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

	if (check != NULL) {

		delete[] check;

	}

}

void Wordle::renderBackground(Screen& s1)
{

	s1.drawSprite(this->background_sprite);

}

void Wordle::update(Screen& s1) { //also rendeer it with ttaht

	this->pollEvents(s1); //order very important

	if (this->endCheck == true && counter < 6) {

		cout << "\nYOU WON\n";
		this->endGame = true;

	}


	//End game condition
	if (this->endGame == true || counter >= 6) {

		this->endGame = true;

	}

}

void Wordle::render(Screen& s1) {

	s1.clear();

	this->renderBackground(s1);

	for (int i = 0; i < 6; i++) { // you have create logic around here so that it doesn't get affected

		for (int j = 0; j < 5; j++) {

			this->letter[i][j].renderLetter(s1);

		}

	}

	this->wordDictionary.renderText(s1);
	s1.display();

}

void Wordle::StartGame(Screen& s1){

	while (running(s1) && !getEndGame()) {

		update(s1);

		//this->window->draw(this->background_sprite);

		render(s1);

	}

}


//basically input tab tak lete rahein gay jab tak humara count = 5 to nahi hojata hai
//backspace and enter ko bhi handle karna hai kisi tareekay se what are the possiblities for that
//enter ke saath aik check lag jaye aur counter decrements with backspace but theri is one thing that i have to do is very important have to cater it for every like
//har input mein woh charachter aye and correct word also is their loop to check that the word exits or not usi mein dalein gay hum
//some edge case when you repeat the word