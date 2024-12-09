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

class Category {

private:

	sf::Font uiFont;
	sf::Text uiText;
	sf::Text historyText;
	sf::Text historyWord;
	sf::Text Length_text;

	string* easy;
	string* medium;
	string* hard;
	string* history;
	string* totalHistory;

	int history_len;
	int recent_word_len;
	int score;
	int counter;
	int lives;

	int previous_word_total_len;

	void initVariables();
	void initFont();
	void initText();
	void populateArrays();


public:

	Category();
	~Category();

	string getRandomWord();
	void initHistory(int);

	bool compareWithHiddenWord(string, int, string);
	bool compareWithHistory(string);
	void storeInHistory(string, int);
	string* getHistory();
	int getCurrentHistoryLen();
	bool checkIfWordHasMatchedTillEnd(string*);
	void initTotalHistory(string*);

	void setSomeSizeLen(int);
	int getSomeSizeLen();

	void setLives(int);

	void updateText();
	void renderText(Screen& s1);

};

void Category::initVariables() {

	this->easy = new string[100];
	this->medium = new string[100];
	this->hard = new string[100];
	this->populateArrays();
	this->history = NULL;
	this->history_len = 0;
	this->recent_word_len = 0;
	this->totalHistory = NULL;
	this->score = 0;
	this->counter = 0;
	this->previous_word_total_len = 0;
	this->lives = 7;

}

void Category::initFont() {

	if (!this->uiFont.loadFromFile("Fonts/Roboto-Bold.ttf")) {

		cout << "ERROR::GAME::INITFONTS::Failed to load Font!" << endl;

	}

}

void Category::initText() {

	this->uiText.setFont(this->uiFont);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("Points:0\nLives:7");
	this->uiText.setOrigin(sf::Vector2f(-650.f, -10.f)); //why ulta?? //Position 
	this->uiText.setCharacterSize(24);

	this->historyText.setFont(this->uiFont);
	this->historyText.setCharacterSize(23);
	this->historyText.setFillColor(sf::Color::White);
	this->historyText.setString("Guess The Word:");
	this->historyText.setOrigin(sf::Vector2f(-450.f, -150.f)); //why ulta?? //Position 
	this->historyText.setCharacterSize(23);

	this->historyWord.setFont(this->uiFont);
	this->historyWord.setCharacterSize(24);
	this->historyWord.setFillColor(sf::Color::White);
	this->historyWord.setString("");
	this->historyWord.setOrigin(sf::Vector2f(-500.f, -200.f)); //why ulta?? //Position 
	this->historyWord.setCharacterSize(23);
	
	this->Length_text.setFont(this->uiFont);
	this->Length_text.setCharacterSize(24);
	this->Length_text.setFillColor(sf::Color::Yellow);
	this->Length_text.setString("");
	this->Length_text.setOrigin(sf::Vector2f(-50.f, -100.f)); //why ulta?? //Position 
	this->Length_text.setCharacterSize(23);

}

void Category::populateArrays() {

	string easy_words[100] = { "dog", "cat", "mouse", "ball", "fish", "apple", "sun", "moon", "star", "tree",
										"car", "bird", "shoe", "hat", "house", "book", "pen", "cup", "phone", "door",
										"chair", "clock", "frog", "plane", "boat", "cake", "glass", "key", "lamp", "milk",
										"ring", "wall", "floor", "road", "grass", "beach", "shirt", "table", "plate", "bread",
										"water", "river", "horse", "sheep", "goat", "duck", "train", "flower", "leaf", "cloud",
										"drum", "piano", "guitar", "sugar", "salt", "pepper", "lemon", "lime", "orange", "grape",
										"peach", "plum", "kiwi", "pear", "berry", "melon", "fig", "cherry", "candy", "jelly",
										"honey", "juice", "coffee", "tea", "paper", "card", "box", "basket", "bag", "rope",
										"iron", "wood", "brick", "stone", "stick", "bell", "horn", "fan", "light", "egg",
										"fork", "knife", "spoon", "bowl", "soap", "towel", "candle", "bucket", "ladder", "map"
	};

	string medium_words[100] = { "quantum", "entropy", "symmetry", "calculus", "neutron", "electron", "proton", "molecule", "photon", "algorithm",
										"cryptography", "metamorphosis", "photosynthesis", "relativity", "thermodynamics", "supernova", "constellation", "paradox", "hyperbole", "synesthesia",
										"onomatopoeia", "catalyst", "euphoria", "dystopia", "utopia", "eschatology", "millenarianism", "apocalypse", "revelation", "eschaton",
										"armageddon", "deconstruction", "structuralism", "avant-garde", "surrealism", "cubism", "abstract", "expressionism", "pointillism", "fauvism",
										"constructivism", "suprematism", "vorticism", "precisionism", "magic realism", "neoclassicism", "romanticism", "realism", "naturalism", "impressionism",
										"symbolism", "existentialist", "philosophy", "metaphysics", "ontology", "hermeneutics", "semiotics", "aesthetics", "phenomenology", "dialectics",
										"synecdoche", "metonymy", "chiaroscuro", "anachronism", "euphemism", "oxymoron", "poetic", "allegory", "epistemology", "existentialism",
										"monotheism", "pantheon", "sacred", "transcendence", "divine", "sacrifice", "covenant", "liturgical", "hallowed", "paradigm",
										"cosmology", "anthropology", "sociology", "biochemistry", "astrophysics", "microbiology", "neurobiology", "psychotherapy", "cognitive", "phenotype",
										"archaeology", "linguistics", "etymology", "syntax", "grammar", "lexicon", "semantics", "phonology", "pragmatics", "dialect"
	};


	string hard_words[100] = { "neuroscience", "psychoanalysis", "existentialism", "phenomenology", "dialectical", "determinism", "utilitarianism", "epistemological", "axiological", "ontological",
										"deconstructionism", "empirical", "methodological", "phenotypic", "hermeneutical", "paradigmatic", "quantitative", "qualitative", "substantive", "functionalism",
										"structuralism", "postmodernism", "poststructuralism", "constructivism", "positivism", "romanticism", "materialism", "idealism", "naturalism", "reductionism",
										"essentialism", "pragmatism", "instrumentalism", "voluntarism", "humanitarianism", "transcendentalism", "synecdoche", "dialectic", "existentialist", "epistemic",
										"metaethical", "teleological", "descriptive", "prescriptive", "aestheticism", "utilitarian", "deontological", "axiomatic", "holistic", "systematic",
										"philosophical", "symbiotic", "synthetic", "abstracted", "contextual", "referential", "phenomenological", "ecological", "evolutionary", "ontogenetic",
										"philological", "etymological", "morphological", "phonological", "semantic", "pragmatic", "syntactical", "dialectical", "holistic", "materialistic",
										"sociological", "anthropological", "biological", "psychological", "neurological", "cybernetic", "computational", "algorithmic", "technological", "mechanical",
										"systematic", "statistical", "geometrical", "arithmetical", "numerical", "topological", "combinatorial", "probabilistic", "analytic", "synthetic" "combinatorial", "probabilistic", "analytic", "synthetic",
										"heuristic","epigenetic","symmetrical","dialecticism","conceptualism","categorical","ontogenesis"
	};

	for (int i = 0; i < 100; i++) {

		this->easy[i] = easy_words[i];
		this->medium[i] = medium_words[i];
		this->hard[i] = hard_words[i];

	}

}

Category::Category() {

	this->initVariables();
	this->initFont();
	this->initText();

}

Category::~Category() {

	delete[] easy; easy = NULL;
	delete[] medium; medium = NULL;
	delete[] hard; hard = NULL;
	delete[] history; history = NULL;
	delete[] totalHistory; totalHistory = NULL;

}

string Category::getRandomWord() {

	int index = rand() % 100;
	
	if (counter >= 5) {

		int option = (rand() % 3) + 1;

		if (option == 1) {

			return this->easy[index];

		}

		else if (option == 2) {

			return this->medium[index];

		}

		else if (option == 3) {

			return hard[index];

		}

	}

	this->counter++;
	return easy[index];

}

void Category::initHistory(int size) {

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

bool Category::compareWithHiddenWord(string hiddenWord, int size, string word)
{

	int index = 0;

	this->setSomeSizeLen(size);

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

bool Category::compareWithHistory(string word) // for used word
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

void Category::storeInHistory(string word, int index)
{

	//cout << "Index : " << index << endl;
	this->history[index] = word[0];

}

string* Category::getHistory()
{

	return history;

}

int Category::getCurrentHistoryLen()
{

	//cout << "His Len : ::::" << history_len << endl;
	return history_len;

}

bool Category::checkIfWordHasMatchedTillEnd(string* hiddenWord)
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

void Category::initTotalHistory(string* word)
{

	if (this->totalHistory != NULL) {

		int len = recent_word_len + 3;

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

		this->totalHistory[len - 2] = " ";

		cout << "\nTotal History : ";

		for (int i = 0; i < len; i++) {

			cout << totalHistory[i] << " ";

		}

		cout << endl;

	}

	else {

		int len = recent_word_len + 2;

		this->totalHistory = new string[len];

		for (int i = 0; i < history_len; i++) {

			this->totalHistory[i] = this->history[i];

		}

		this->totalHistory[len - 1] = " ";

		for (int i = 0; i < history_len; i++) {

			cout << totalHistory[i];

		}

		cout << endl;
	}

}

void Category::setSomeSizeLen(int size)
{

	this->previous_word_total_len = size;

}

int Category::getSomeSizeLen() {

	return this->previous_word_total_len;

}

void Category::setLives(int lives)
{

	this->lives = lives;

}

void Category::updateText() {

	stringstream ui;
	stringstream his;
	stringstream words;
	stringstream length_ss;

	ui << "Points : " << this->score << "\n" << "Lives : " << this->lives << "\n";
	this->uiText.setString(ui.str());

	string* hit = getHistory();

	//cout << "Size :->-> " << getCurrentHistoryLen() << endl;

	for (int i = 0; i < getCurrentHistoryLen(); i++) {

		cout << hit[i] << " ";

	}

	cout << endl;

	his << "Guess The Word " << endl << endl;
	this->historyText.setString(his.str());
	his.clear();

	for (int i = 0; i < getCurrentHistoryLen(); i++) {

		words << hit[i] << " ";

	}
	this->historyWord.setString(words.str());
	words.clear();
	
	length_ss << "Current Word Length : " << getSomeSizeLen() << endl;
	this->Length_text.setString(length_ss.str());
	length_ss.clear();

}

void Category::renderText(Screen& s1) {

	s1.drawText(this->uiText);
	s1.drawText(this->historyText);
	s1.drawText(this->historyWord);
	s1.drawText(this->Length_text);

}