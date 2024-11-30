#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream> //string stream
#include <istream>
#include <ostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace std;

class HangmanFigure {

private:

	int left;
	int top; 
	int width;
	int height;

	sf::Texture hm_texture;
	sf::Sprite hm_sprite;

	int lives;

	void initVariables();
	void initTexture();
	void initSprite();

public:

	HangmanFigure();
	~HangmanFigure();

	void updateSprite();
	void renderSprite(sf::RenderTarget&);

};

void HangmanFigure::initVariables() {

	this->left = 5;
	this->top = 0;
	this->width = 15;
	this->height = 75;
	this->lives = 7;

}


void HangmanFigure::initTexture() {

	this->hm_texture.loadFromFile("Sprites/Hangman/Hangman Sprites Final.png", sf::IntRect(this->left, this->top, this->width, this->height));

}

void HangmanFigure::initSprite() {

	this->hm_sprite.setTexture(this->hm_texture);
	this->hm_sprite.setScale(8.f, 8.f);
	this->hm_sprite.setPosition(50.0f, -225.0f);
	this->hm_sprite.rotate(.0f);

}

HangmanFigure::HangmanFigure() {

	this->initVariables();
	this->initTexture();
	this->initSprite();

}

HangmanFigure::~HangmanFigure() {}

void HangmanFigure::updateSprite(){
	
	this->left += 15;
	this->initTexture();
	hm_sprite.setTexture(this->hm_texture);
	
}

void HangmanFigure::renderSprite(sf::RenderTarget& target) {

	target.draw(this->hm_sprite);

}

class Category {

private:

	sf::Font uiFont;
	sf::Text uiText;
	sf::Text historyText;

	string* easy;
	string* medium;
	string* hard;
	string* history;

	int score;

	void initVariables();
	void initFont();
	void initText();
	void populateArrays();
	

public:

	Category();
	~Category();

	string getRandomWord();
	void initHistory(int);

	void updateText();
	void renderText(sf::RenderTarget&);

};

void Category::initVariables() {

	this->easy = new string[100];
	this->medium = new string[100];
	this->hard = new string[100];
	this->populateArrays();
	this->history = NULL;
	this->score = 0;

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
	this->uiText.setString("NONE");
	this->uiText.setOrigin(sf::Vector2f(-700.f, 1.f)); //why ulta?? //Position 
	this->uiText.setCharacterSize(24);

	this->historyText.setFont(this->uiFont);
	this->historyText.setCharacterSize(24);
	this->historyText.setFillColor(sf::Color::Red);
	this->historyText.setString("NONE");
	this->historyText.setOrigin(sf::Vector2f(-700.f, -150.f)); //why ulta?? //Position 
	this->historyText.setCharacterSize(24);

}

void Category::populateArrays() {

	std::string easy_words[100] = {		"dog", "cat", "mouse", "ball", "fish", "apple", "sun", "moon", "star", "tree",
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

	std::string medium_words[100] = {	"quantum", "entropy", "symmetry", "calculus", "neutron", "electron", "proton", "molecule", "photon", "algorithm",
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

	// 100 distinct hard words
	std::string hard_words[100] = {		"neuroscience", "psychoanalysis", "existentialism", "phenomenology", "dialectical", "determinism", "utilitarianism", "epistemological", "axiological", "ontological",
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

}


string Category::getRandomWord() {

	int index = rand() % 100;
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

	return easy[index];

}

void Category::initHistory(int size){

	if (history != NULL) {

		delete[] history;

		this->history = new string[size];
		for (int i = 0; i < size; i++) {

			history[i] = '_';

		}

	}

	else {

		this->history = new string[size];
		for (int i = 0; i < size; i++) {

			history[i] = '_';

		}

	}

}

void Category::updateText() {

	stringstream ui;
	stringstream his;

	ui << "Points : " << "\n" << "Lives : " << "\n";
	this->uiText.setString(ui.str());
 
	/*for (int i = 0; history->length(); i++) {

		his << history[i] << " ";

	}
	
	this->historyText.setString(his.str());
	his.clear();*/

}


void Category::renderText(sf::RenderTarget& target) {

		target.draw(this->uiText);
		target.draw(this->historyText);
}

class Hangman {

private:

	//Rendering Varibles
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode video;

	//class HangmanFigure

	HangmanFigure figure;

	//class Category
	Category category;

	//private variables
	bool endGame;
	string hiddenWord;
	int hiddenWord_len;

	//initializing functions
	void initVariables();
	void initWindow();




public:

	//Constructor / Destructor
	Hangman();
	virtual ~Hangman();

	//Accessors // to keep in game loop

	const bool running() const;
	const bool getEndGame() const;
	void gameLoop();


	//Events Handling
	void pollEvents();

	//Updating
	void update();

	//Rendering
	void render();

};

void Hangman::initVariables() {

	this->window = nullptr;
	this->endGame = false;
	this->hiddenWord = category.getRandomWord();
	this->hiddenWord_len = hiddenWord.length();
	this->category.initHistory(hiddenWord_len);

}


void Hangman::initWindow() {

	this->video.width = 800;
	this->video.height = 600;
	this->window = new sf::RenderWindow(sf::VideoMode(video), "Hangman", sf::Style::Default);
	this->window->setFramerateLimit(60);

}

const bool Hangman::running() const { return this->window->isOpen(); }

const bool Hangman::getEndGame() const { return this->endGame; }

Hangman::Hangman() {

	this->initVariables();
	this->initWindow();

}

Hangman::~Hangman() { delete this->window; }


void Hangman::pollEvents() {

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

}

void Hangman::update() {

	this->pollEvents(); //order very important //game management
	
	if (this->endGame == false) {

		/*int choice;
		cout << "Option : "; cin >> choice;
		if (choice == 1)
		figure.updateSprite();*/
		this->category.updateText();

	}

	//End game condition
	/*if (this->health <= 0) {

		
	}*/

}

void Hangman::render() { //open your eyes visual

	this->window->clear();

	this->figure.renderSprite(*this->window);

	this->category.renderText(*this->window);

	this->window->display();

}

void Hangman::gameLoop() {

	while (this->running() && !getEndGame()) {

		//update
		this->update();
		
		//render
		this->render();

	}

}// game logic interaction?
