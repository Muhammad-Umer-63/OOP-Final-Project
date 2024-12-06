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

class WordDictionary {

private:

	sf::Font uiFont;
	sf::Text uiText;
	sf::Text txt1;
	sf::Text txt2;
	sf::Text txt3;
	sf::Text txt4;
	sf::Text txt5;
	sf::Text txt6;

	string* easy;
	string* medium;
	string* hard;

	int counter;

	void initVariables();
	void initFont();
	void initText();
	void populateArrays();

public:

	WordDictionary();
	~WordDictionary();

	string getRandomWord();

	int* compareWithHiddenWord(string, int, string);
	bool checkWithFullWordList(string);

	void updateText(string);
	void renderText(sf::RenderTarget&);

};

void WordDictionary::initVariables() {

	this->easy = new string[100];
	this->medium = new string[100];
	this->hard = new string[100];
	this->populateArrays();
	this->counter = 0;
	
}

void WordDictionary::initFont() {

	if (!this->uiFont.loadFromFile("Fonts/Roboto-Bold.ttf")) {

		cout << "ERROR::GAME::INITFONTS::Failed to load Font!" << endl;

	}

}

void WordDictionary::initText() {

	this->uiText.setFont(this->uiFont);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("");
	this->uiText.setOrigin(sf::Vector2f(-300.f, -250.f)); //why ulta?? //Position 
	this->uiText.setCharacterSize(24);

	this->txt1.setFont(this->uiFont);
	this->txt1.setCharacterSize(24);
	this->txt1.setFillColor(sf::Color::Black);
	this->txt1.setString("");
	this->txt1.setOrigin(sf::Vector2f(-242.f, -110.f)); //why ulta?? //Position 
	this->txt1.setCharacterSize(24);
	
	this->txt2.setFont(this->uiFont);
	this->txt2.setCharacterSize(24);
	this->txt2.setFillColor(sf::Color::Black);
	this->txt2.setString("");
	this->txt2.setOrigin(sf::Vector2f(-242.f, -185.f)); //why ulta?? //Position 
	this->txt2.setCharacterSize(24);

	this->txt3.setFont(this->uiFont);
	this->txt3.setCharacterSize(24);
	this->txt3.setFillColor(sf::Color::Black);
	this->txt3.setString("");
	this->txt3.setOrigin(sf::Vector2f(-242.f, -260.f)); //why ulta?? //Position 
	this->txt3.setCharacterSize(24);

	this->txt4.setFont(this->uiFont);
	this->txt4.setCharacterSize(24);
	this->txt4.setFillColor(sf::Color::Black);
	this->txt4.setString("");
	this->txt4.setOrigin(sf::Vector2f(-242.f, -335.f)); //why ulta?? //Position 
	this->txt4.setCharacterSize(24);

	this->txt5.setFont(this->uiFont);
	this->txt5.setCharacterSize(24);
	this->txt5.setFillColor(sf::Color::Black);
	this->txt5.setString("");
	this->txt5.setOrigin(sf::Vector2f(-242.f, -410.f)); //why ulta?? //Position 
	this->txt5.setCharacterSize(24);

	this->txt6.setFont(this->uiFont);
	this->txt6.setCharacterSize(24);
	this->txt6.setFillColor(sf::Color::Black);
	this->txt6.setString("");
	this->txt6.setOrigin(sf::Vector2f(-242.f, -585.f)); //why ulta?? //Position 
	this->txt6.setCharacterSize(24);

}

void WordDictionary::populateArrays() {

	string easy_words[100] = {
								"apple", "grape", "lemon", "chair", "table", "spoon", "light", "plant", "beach", "brick",
								"stick", "cloud", "piano", "paper", "shirt", "horse", "candy", "train", "floor", "clock",
								"glass", "honey", "house", "knife", "mango", "melon", "ocean", "pouch", "sheet", "stamp",
								"stone", "torch", "vapor", "wagon", "water", "whale", "bench", "bread", "broom", "chalk",
								"crown", "flask", "frame", "glove", "grill", "jelly", "lemon", "logic", "metal", "plant",
								"plate", "pouch", "ruler", "scale", "sheep", "shirt", "spade", "spoon", "stack", "sugar",
								"tiger", "vowel", "watch", "zebra", "brush", "clamp", "creek", "dough", "entry", "flake",
								"grape", "hatch", "input", "kiosk", "lemon", "maple", "ninja", "oasis", "piano", "quote",
								"robin", "scarf", "trump", "union", "vital", "wheat", "xerox", "yield", "zebra", "glide",
								"zebra", "truck", "stone", "fruit", "cloud", "brick", "honey", "river", "bread", "shirt"
	};

	string medium_words[100] = {
								"alpha", "basic", "chaos", "delta", "ether", "flame", "glory", "heavy", "input", "joker",
								"karma", "lunar", "magic", "neuro", "optic", "pluto", "quake", "realm", "solar", "terra",
								"ultra", "vapor", "waste", "xenon", "yield", "zebra", "amber", "bison", "circe", "disco",
								"ember", "flask", "gecko", "hydra", "icily", "jumpy", "kappa", "loyal", "macho", "needy",
								"optic", "plaza", "quest", "raven", "savvy", "talon", "urban", "vivid", "waxen", "xeric",
								"yacht", "zephyr", "acute", "bluff", "civic", "dizzy", "evoke", "fiery", "gleam", "hymen",
								"ivory", "joker", "kinda", "lofty", "moray", "noble", "oaken", "prism", "quilt", "rapid",
								"yacht", "zesty", "amber", "black", "cloud", "drive", "exact", "fiery", "glare", "hyper",
								"tiger", "vowel", "watch", "zebra", "brush", "clamp", "creek", "dough", "entry", "flake",
								"sneak", "trick", "ultra", "vexed", "woozy", "xenon", "yummy", "zippy", "beast", "cliff"
	};

	string hard_words[100] = {
								"axiom", "beast", "clerk", "dense", "event", "fiber", "grasp", "hover", "inset", "juror",
								"known", "logic", "money", "nerve", "ocean", "prism", "queen", "risky", "stack", "tower",
								"urban", "vital", "water", "xerox", "yummy", "zonal", "acorn", "brisk", "clone", "drift",
								"emery", "flare", "grind", "hatch", "input", "jolly", "kinky", "latch", "mirth", "noble",
								"octal", "pulse", "quark", "relax", "sprig", "truth", "under", "vogue", "wafer", "xerox",
								"yacht", "zesty", "amber", "black", "cloud", "drive", "exact", "fiery", "glare", "hyper",
								"ionic", "jumpy", "kinda", "lunar", "metal", "noise", "optic", "plaza", "quilt", "realm",
								"shock", "torch", "ultra", "vivid", "whale", "xeric", "yield", "zebra", "baker", "chaos",
								"axiom", "mirth", "proxy", "prism", "vocal", "neuro", "quant", "optix", "juror", "leach",
								"tweak", "glyph", "mimic", "latch", "quark", "nerve", "vivid", "xenon", "zesty", "brisk"
	};


	for (int i = 0; i < 100; i++) {

		this->easy[i] = easy_words[i];
		this->medium[i] = medium_words[i];
		this->hard[i] = hard_words[i];

	}

}

WordDictionary::WordDictionary() {

	this->initVariables();
	this->initFont();
	this->initText();

}

WordDictionary::~WordDictionary() {

	delete[] easy; easy = NULL;
	delete[] medium; medium = NULL;
	delete[] hard; hard = NULL;
	
}

string WordDictionary::getRandomWord() {

	int index = rand() % 100;
	//int option = (rand() % 3) + 1;

	/*if (option == 1) {

		return this->easy[index];

	}

	else if (option == 2) {

		return this->medium[index];

	}

	else if (option == 3) {

		return hard[index];

	}*/

	return easy[index];

}

int* WordDictionary::compareWithHiddenWord(string hiddenWord, int size ,string word)
{
	this->checkWithFullWordList(word);

	int index = 0;
	bool checkIfNotWordExists = false;
	//int colorArray[5]; // have to use dynamic memory here;

	int* colorArray = new int[5];

	cout << "\nSiuu\n";

	cout << "Word : " << word << endl;

		for (int i = 0; i < size; i++) {

			bool checkIfNotWordExists = false;

			for (int j = 0; j < size; j++) {


				if (word[i] == hiddenWord[j]) {

					if (i == j) {

						colorArray[i] = 2;
						checkIfNotWordExists = true;

					}

					else if(i != j){

						colorArray[i] = 1;
						checkIfNotWordExists = true;

					}

				}

			}

			if (!checkIfNotWordExists) {

				colorArray[i] = 0;

			}

		}


	for (int i = 0; i < 5; i++) {

		cout << colorArray[i];

	}
	cout << endl;

	return colorArray; //why is it returning garbage?
}


bool WordDictionary::checkWithFullWordList(string word)
{
	
	for (int i = 0; i < 100; i++) {

		for (int j = 0; j < 5; j++) {

			if (word == this->easy[i]) {

				return true;

			}

		}

	}
	
	cout << "Word Doesn't Exists in Inventory: ";
	return false;

}

void WordDictionary::updateText(string alpha) {

	stringstream his;

	if (counter == 0) {

		his << alpha[0] << "\t\t   " << alpha[1] << "\t\t  " << alpha[2] << "\t\t   " << alpha[3] << "\t\t  " << alpha[4] << endl << endl; //this correct use some counter to clear this thing
		this->txt1.setString(his.str());
		his.clear();

	}

	else if (counter == 1) {

		his << alpha[0] << "\t\t   " << alpha[1] << "\t\t  " << alpha[2] << "\t\t   " << alpha[3] << "\t\t  " << alpha[4] << endl << endl; //this correct use some counter to clear this thing
		this->txt2.setString(his.str());
		his.clear();

	}

	else if (counter == 2) {

		his << alpha[0] << "\t\t   " << alpha[1] << "\t\t  " << alpha[2] << "\t\t   " << alpha[3] << "\t\t  " << alpha[4] << endl << endl; //this correct use some counter to clear this thing
		this->txt3.setString(his.str());
		his.clear();

	}

	else if (counter == 3) {

		his << alpha[0] << "\t\t   " << alpha[1] << "\t\t  " << alpha[2] << "\t\t   " << alpha[3] << "\t\t  " << alpha[4] << endl << endl; //this correct use some counter to clear this thing
		this->txt4.setString(his.str());
		his.clear();

	}

	else if (counter == 4) {

		his << alpha[0] << "\t\t   " << alpha[1] << "\t\t  " << alpha[2] << "\t\t   " << alpha[3] << "\t\t  " << alpha[4] << endl << endl; //this correct use some counter to clear this thing
		this->txt5.setString(his.str());
		his.clear();

	}

	else if (counter == 5) {

		his << alpha[0] << "\t\t   " << alpha[1] << "\t\t  " << alpha[2] << "\t\t   " << alpha[3] << "\t\t  " << alpha[4] << endl << endl; //this correct use some counter to clear this thing
		this->txt6.setString(his.str());
		his.clear();

	}

	counter++;
}

void WordDictionary::renderText(sf::RenderTarget& target) {

	target.draw(this->uiText);
	target.draw(this->txt1);
	target.draw(this->txt2);
	target.draw(this->txt3);
	target.draw(this->txt4);
	target.draw(this->txt5);
	target.draw(this->txt6);

}