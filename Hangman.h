#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
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

    //Game Logic

    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    //Game Objects
    //not gonna use as far
    vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    void initVariables();
    void initWindow();
    void initEnemies();

public:

    //const and destructor
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Functions

    void spawnEnemy();

    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();

    void renderEnemies();
    void render();

};

//private fun
void Game::initVariables() {

    this->window = nullptr;

    //GameLogic
    this->points = 0;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;


}


void Game::initWindow() {

    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game-1", sf::Style::Default);
    this->window->setFramerateLimit(60); 
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f,10.f); //zero zero default //ZERO ZERO is top left of screen not middle
    this->enemy.setSize(sf::Vector2f(100.f, 100.f)); //ulta grid top +ve x axis and botton +ve y axis
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);

}

Game::Game() {

    this->initVariables();
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

//Functions

void Game::spawnEnemy()
{
   
    /* returns void
    
        spawns enemies and sets their colors and positions
        - sets a random position 
        - sets a random color
        - adds enemy to the vector

    */

    this->enemy.setPosition(

        static_cast<float> (rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), /* minus take is liye toh window ke andar hi rahe*/
        //static_cast<float> (rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y)) // y not random top se hi aye ga ofcourse
        0.f
    );

    this->enemy.setFillColor(sf::Color::Green);

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

    bool deleted = false;

    for (int i = 0; i < this->enemies.size(); i++) { //auto for loop

        this->enemies[i].move(0.f, 1.f);// takes x and y scalke factor 10 toh 10 frames chalte hai

        //check if clicked upon
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {

                deleted = true;

                //gain points
                this->points += 10.f;

            }

        }

        //if enemies is past screen it deletes // you should delete only once
        if (this->enemies[i].getPosition().y > this->window->getSize().y) {

            deleted = true;

        }

        if (deleted) {

            this->enemies.erase(this->enemies.begin() + i);

        }

    }

}



void Game::update() { //update game logic close your eyes

    this->pollEvents(); //order very important

    this->updateMousePositions();
    
    this->updateEnemies();

}


void Game::renderEnemies()
{
    //Rendering all the enemies
    for (auto& e : this->enemies) { //auto for loop

        this->window->draw(e);

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
    this->renderEnemies();


    this->window->display();

}

