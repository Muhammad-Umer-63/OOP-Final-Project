#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class WordDictionary {

private:

	string* easy;
	string* medium;
	string* hard;
	string* history;
	string* total_history;

	sf::Font font;
	sf::Text letter_text;

	void initVariables();
	void populateArrays();
	void initFont();
	void initText();




public:

	WordDictionary();
	~WordDictionary();

	void updateText();
	void renderText();

};

void WordDictionary::initVariables() {

	this->easy = new string[100];
	this->medium = new string[100];
	this->hard = new string[100];
	this->history = NULL;
	this->total_history = NULL;

}

void WordDictionary::populateArrays()
{

	


}

void WordDictionary::initFont()
{

	this->font.loadFromFile("");

}

void WordDictionary::initText()
{


}

WordDictionary::WordDictionary() {
	
	this->initVariables();
	this->populateArrays();

}

WordDictionary::~WordDictionary() {

	delete[] easy; easy = NULL;
	delete[] medium; medium = NULL;
	delete[] hard; hard = NULL;
	delete[] history; history = NULL;
	delete[] total_history; total_history = NULL;

}

void WordDictionary::updateText()
{


}

void WordDictionary::renderText()
{


}
