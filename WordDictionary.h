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
	sf::Text historyText;

	string* easy;
	string* medium;
	string* hard;
	string* history;
	string* totalHistory;

	int history_len;
	int recent_word_len;
	int score;

	void initVariables();
	void initFont();
	void initText();
	void populateArrays();

public:

	WordDictionary();
	~WordDictionary();

	string getRandomWord();
	void initHistory(int); //size

	bool compareWithHiddenWord(string, int, string);
	bool compareWithHistory(string);
	void storeInHistory(string, int);
	string* getHistory();
	int getCurrentHistoryLen();
	bool checkIfWordHasMatchedTillEnd(string*);
	void initTotalHistory(string*);

	void updateText();
	void renderText(sf::RenderTarget&);

};

void WordDictionary::initVariables() {

	this->easy = new string[100];
	this->medium = new string[100];
	this->hard = new string[100];
	this->populateArrays();
	this->history = NULL;
	this->history_len = 0;
	this->recent_word_len = 0;
	this->totalHistory = NULL;
	this->score = 0;


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
	this->uiText.setString("Points:0\nLives:7");
	this->uiText.setOrigin(sf::Vector2f(-700.f, 1.f)); //why ulta?? //Position 
	this->uiText.setCharacterSize(24);

	this->historyText.setFont(this->uiFont);
	this->historyText.setCharacterSize(24);
	this->historyText.setFillColor(sf::Color::Red);
	this->historyText.setString("Guess The Word:");
	this->historyText.setOrigin(sf::Vector2f(-400.f, -150.f)); //why ulta?? //Position 
	this->historyText.setCharacterSize(24);

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
	delete[] history; history = NULL;
	delete[] totalHistory; totalHistory = NULL;

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

void WordDictionary::initHistory(int size) {

	if (history != NULL) {

		delete[] history;

		//cout << "Size : " << size << endl;

		this->history_len = size;

		this->history = new string[size];
		for (int i = 0; i < size; i++) {

			history[i] = "_";

		}

	}

	else {

		//cout << "Size : " << size << endl;

		this->history_len = size;
		this->history = new string[size];
		for (int i = 0; i < size; i++) {

			history[i] = "_";

		}

	}

}

bool WordDictionary::compareWithHiddenWord(string hiddenWord, int size, string word)
{

	int index = 0;
	bool checkIfWordExists = false;

	if (!compareWithHistory(word)) {

		for (int i = 0; i < size; i++) {

			//checkIfWordExists = false;

			if (hiddenWord[i] == word[0]) {

				index = i;

				storeInHistory(word, index);
				this->score += 1;
				cout << "\nScore : " << this->score << endl;
				checkIfWordExists = true;

			}

		}

	}

	else {

		checkIfWordExists = true; //juggad //still ain't right
		this->score -= 2;
		return checkIfWordExists;

	}

	if (!checkIfWordExists) { this->score -= 2; cout << "\nScore : " << this->score << endl; } //incorrect guess
	return checkIfWordExists;

}

bool WordDictionary::compareWithHistory(string word) // for used word
{

	for (int i = 0; i < history_len; i++) {

		if (word == history[i]) {

			this->score -= 1;
			cout << "\nScore : " << this->score << endl;
			return true;

		}

	}

	return false;

}

void WordDictionary::storeInHistory(string word, int index)
{

	//cout << "Index : " << index << endl;
	this->history[index] = word[0];

}

string* WordDictionary::getHistory()
{

	return history;

}

int WordDictionary::getCurrentHistoryLen()
{

	//cout << "His Len : ::::" << history_len << endl;
	return history_len;

}

bool WordDictionary::checkIfWordHasMatchedTillEnd(string* hiddenWord)
{

	for (int i = 0; i < history_len; i++) {

		if (hiddenWord[i] != history[i]) {

			return false;

		}

	}

	this->recent_word_len += history_len;
	this->initTotalHistory(this->history);

	cout << "\nYour Won\n";
	return true;

}

void WordDictionary::initTotalHistory(string* word)
{

	if (this->totalHistory != NULL) {

		int len = recent_word_len + 1;

		string* temp = new string[len];

		cout << "fook : ";

		for (int i = 0; i < recent_word_len - history_len; i++) {

			cout << totalHistory[i];
			temp[i] = this->totalHistory[i];

		}

		cout << endl;

		delete[] totalHistory;
		totalHistory = temp;

		cout << "what : ";
		for (int i = 0; i < len; i++) {

			cout << totalHistory[i];

		}
		cout << endl;

		cout << "\nskip\n";

		cout << "siup : ";

		for (int i = 0; i < history_len; i++) {

			cout << totalHistory[i] << " ";
			this->totalHistory[recent_word_len - history_len + i + 1] = this->history[i];

		}

		cout << endl;

		this->totalHistory[len - 1] = " ";

		cout << "\nTotal History : ";

		for (int i = 0; i < len; i++) {

			cout << totalHistory[i] << " ";

		}

		cout << endl;

	}

	else {

		this->totalHistory = new string[this->recent_word_len + 1];

		for (int i = 0; i < history_len; i++) {

			this->totalHistory[i] = this->history[i];

		}

		this->totalHistory[recent_word_len] = " ";

		for (int i = 0; i < history_len; i++) {

			cout << totalHistory[i];

		}

		cout << endl;
	}

}

void WordDictionary::updateText() {

	stringstream ui;
	stringstream his;

	ui << "Points : " << this->score << "\n" << "Lives : " << "\n";
	this->uiText.setString(ui.str());

	string* hit = getHistory();

	//cout << "Size :->-> " << getCurrentHistoryLen() << endl;

	for (int i = 0; i < getCurrentHistoryLen(); i++) {

		cout << hit[i] << " ";

	}

	cout << endl;

	his << "    Guess The Word " << endl << endl;

	for (int i = 0; i < getCurrentHistoryLen(); i++) {

		his << hit[i] << " ";

	}


	this->historyText.setString(his.str());
	his.clear();

}

void WordDictionary::renderText(sf::RenderTarget& target) {

	target.draw(this->uiText);
	target.draw(this->historyText);

}