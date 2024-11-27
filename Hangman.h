#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <sstream> //string stream
#include <istream>
#include <ostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


using namespace std;

//class Hangman {
//
//private:
//
//	string easyWords[100] = { "Hello" };
//	string mediumWords[100] = {};
//	string hardWords[100] = {};
//
//
//
//};



/* game acts as the game engine */

class Game {

private:

    //Variables
    //window
    sf::RenderWindow* window; //we are aggregating cuz can be used by many different classes aswell
    sf::Event ev; //not a pointer no need to initialize it
    sf::VideoMode videoMode;

    //Mouse Positions
    sf::Vector2i mousePosWindow; //take save rahe value
    sf::Vector2f mousePosView;

    //Resources

    sf::Font font;

    //Text
    sf::Text uiText;

    //Game Logic

    bool endGame;
    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;

    //Game Objects
    //not gonna use as far
    vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    void initVariables();
    void initWindow();
    void initFonts();
    void initText();
    void initEnemies();

public:

    //const and destructor
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;
    const bool getEndGame() const;

    //Functions

    void spawnEnemy();

    void pollEvents();
    void updateMousePositions();
    void updateText();
    void updateEnemies();
    void update();

    void renderText(sf::RenderTarget& target); //you don't always have to render to window 
    void renderEnemies(sf::RenderTarget& target); //good habbit
    void render();

};

//private fun
void Game::initVariables() {

    this->window = nullptr;
   
    //GameLogic
    this->endGame = false;
    this->points = 0;
    this->health = 10;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->mouseHeld = false;


}


void Game::initWindow() {

    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game-1", sf::Style::Default);
    this->window->setFramerateLimit(60); 
}

void Game::initFonts()
{

    if (this->font.loadFromFile("Fonts/Roboto-Bold.ttf")) {

        cout << "ERROR::GAME::INITFONTS::Failed to load Font!" << endl;
    }

}

void Game::initText()
{

    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");

}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f,10.f); //zero zero default //ZERO ZERO is top left of screen not middle
    this->enemy.setSize(sf::Vector2f(10.f, 10.f)); //ulta grid top +ve x axis and botton +ve y axis
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(1.f);

}

Game::Game() {

    this->initVariables();
    this->initFonts();
    this->initText();
    this->initWindow();
    this->initEnemies();

}

Game::~Game() {


    delete this->window;

}

//Accessor

const bool Game::running() const {

    return this->window->isOpen();

}

const bool Game::getEndGame() const
{
    return this->endGame;

}

//Functions

void Game::spawnEnemy()
{
   
    /* returns void
    
        spawns enemies and sets their types, colors. Spawns at positions randomly.
        - sets a random type (diff).
        - sets a random position 
        - sets a random color
        - adds enemy to the vector

    */

    this->enemy.setPosition(

        static_cast<float> (rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), /* minus take is liye toh window ke andar hi rahe*/
        //static_cast<float> (rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y)) // y not random top se hi aye ga ofcourse
        0.f
    );

    //Randomize enemy type

    int type = rand() % 5;

    switch (type) {

    case 0:

        this->enemy.setScale(sf::Vector2f(1.f, 1.f));
        this->enemy.setFillColor(sf::Color::Magenta);
        break;

    case 1:

        this->enemy.setScale(sf::Vector2f(5.f, 5.f));
        this->enemy.setFillColor(sf::Color::Blue);
        break;
    
    case 2:

        this->enemy.setScale(sf::Vector2f(10.f, 10.f));
        this->enemy.setFillColor(sf::Color::Cyan);
        break;

    case 3:

        this->enemy.setScale(sf::Vector2f(15.f, 15.f));
        this->enemy.setFillColor(sf::Color::Red);
        break;

    case 4:

        this->enemy.setScale(sf::Vector2f(20.f, 20.f));
        this->enemy.setFillColor(sf::Color::Green);
        break;

    default:

        this->enemy.setScale(sf::Vector2f(25.f, 25.f));
        this->enemy.setFillColor(sf::Color::Yellow);

        break;

    }

    //spawn enemy
    this->enemies.push_back(this->enemy); //vectors mein yeh sare agaye hain



    //Remove enemies at the end of screen

}

void Game::pollEvents() {

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

inline void Game::updateMousePositions()
{

    /*
    
        return void

        updates the mouse positions:
            Mouse Position relative to the window (vectoe 2i)
    
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);


}

void Game::updateText()
{

    stringstream ss;
    ss << "Points : " << this->points << endl << "Health : " << this->health << endl;

    this->uiText.setString(ss.str());

}

void Game::updateEnemies()
{

    /*

       return void

       updates the enemy spawn timmer and spawns the enemies
       when the total amount of enemies is smaller than the maximum
       Moves the enemies downwards
       Removes enemies at the edge of screen

   */

   //updating timmer for enemy spawning 
    if (this->enemies.size() < this->maxEnemies) {

        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {

            //spawn the enemy and reset the timmer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;

        }

        else {

            this->enemySpawnTimer += 1.f;
        }

    }

    //Moving and updating enemies
    for (int i = 0; i < this->enemies.size(); i++) { //auto for loop

        bool deleted = false;

        this->enemies[i].move(0.f, 5.f);// takes x and y scalke factor 10 toh 10 frames chalte hai mov in y axis

        if (this->enemies[i].getPosition().y > this->window->getSize().y) {

            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1; //enemy reaches bottom of screen
            cout << "Health : " << this->health << endl;
        } //this is gonna delete the enemy


    }


    //check if clicked upon

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //this is game tactic/control

        if (this->mouseHeld == false) {

            this->mouseHeld = true;
            bool deleted = false;

            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++) { //deleted better check than breaks

                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {

                    //Gain Points

                    if(this->enemies[i].getFillColor() == sf::Color::Magenta)
                        this->points += 10;
                    else if(this->enemies[i].getFillColor() == sf::Color::Blue)
                        this->points += 7;
                    else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
                        this->points += 5;
                    else if (this->enemies[i].getFillColor() == sf::Color::Red)
                        this->points += 3;
                    else if (this->enemies[i].getFillColor() == sf::Color::Green)
                        this->points += 2;
                    else if (this->enemies[i].getFillColor() == sf::Color::Yellow)
                        this->points += 1;

                    cout << "Points : " << this->points << endl;


                    deleted = true; //delete here

                    this->enemies.erase(this->enemies.begin() + i);


                }

            }

        }

    }
    // aik dafa click kiya hoga toh chale ga zaroori nahi ke chale kahin aur se
    else {

        this->mouseHeld = false;

    }
}



void Game::update() { //update game logic close your eyes

    this->pollEvents(); //order very important

    if (this->endGame == false) {

        this->updateMousePositions();

        this->updateText();

        this->updateEnemies();
    }

    //End game condition
    if (this->health <= 0) {

        this->endGame = true;

    }

}


void Game::renderText(sf::RenderTarget& target)
{

    target.draw(this->uiText);

}


void Game::renderEnemies(sf::RenderTarget& target)
{
    //Rendering all the enemies
    for (auto& e : this->enemies) { //auto for loop

        target.draw(e);

    }

}

void Game::render() { //open your eyes visual

    /*
    
        calliing very necessary in this
        be sure that their ain't no error
        @return void

        -clears old frame
        -renders objects
        -display frame in window

        renders the game objects
    */

    this->window->clear();

    //Draw game objects
    this->renderEnemies(*this->window);

    this->renderText(*this->window);

    this->window->display();

}

