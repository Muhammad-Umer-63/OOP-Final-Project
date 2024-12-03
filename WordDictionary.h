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

	void initVariables();
	void populateArrays();


public:

	WordDictionary();
	~WordDictionary();



};

void WordDictionary::initVariables() {





}





