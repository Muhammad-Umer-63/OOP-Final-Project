#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "SoundSystem.h"
#include "Screen.h"

using namespace std;

class LeaderBoard {

private:

    int highscore;
    string filename;

public:

    LeaderBoard() {

        highscore = 0;
        filename = "highscore.txt";
        loadHighScore();

    }
    void updateHighScore(int newScore) {

        if (newScore > highscore) {
            highscore = newScore;
            saveHighScore();
        }

    }
    void saveHighScore() {
        ofstream fout(filename);
        if (fout.is_open()) {
            fout << highscore;
            fout.close();
        }
    }
    void loadHighScore() {
        ifstream fin(filename);
        if (fin.is_open()) {
            fin >> highscore;
            fin.close();
        }

    }
    int getHighScore()const { return highscore; }
};


class Game {
protected:
    int scores;
   // InputClass* input1;
    SoundSystem hitSound;
    SoundSystem music;
    //Screen s1;
    ofstream fout;
    LeaderBoard leaderboard;

public:

    Game(){
    
        this->scores = 0;
        //this->hitSound;

    }

    virtual ~Game(){}
    
   // Game(InputClass* input) : input1(input), score(0) {}


    virtual void StartGame(Screen& s1) = 0;
       
    void PlayhitSound(sf::SoundBuffer& buffer) {
      
        this->hitSound.playSound(buffer);
        //this->hitSound.play();
        
    }

    void PlayMusic(const string& filename) {

        music.playMusic(filename);
        //m1.play();

    }

    void stopMusic(const string& filename) {

        music.stopMusic(filename);

    }

    //char GetInput(char key) {
    //    return input1->mapKey(key);
   // }

    

    void EndGame() {
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////

class Food {
private:
    sf::Texture foodTexture;
    sf::Sprite foodSprite;
    sf::Vector2f foodPosition;
    sf::Texture bonusTexture;
    sf::Sprite bonusSprite;
    sf::Vector2f bonusPosition;
    int randi = 0;
    int randj = 0;
    float xvelocity = 0, yvelocity = 0;

public:

    int score;


    Food() {

        score = 0;
        randi = rand() % 500 + 150;
        randj = rand() % 300 + 150;
        foodPosition.x = randi;
        foodPosition.y = randj;
        //foodTexture.loadFromFile("rabbit.png");
        foodTexture.loadFromFile("Sprites/Snake Sprites/flag.jpeg");
        foodSprite.setTexture(foodTexture);
        //foodSprite.setScale(0.85f, 0.85f);
        foodSprite.setScale(0.07f, 0.07f);
        bonusTexture.loadFromFile("Sprites/Snake Sprites/bonus.jpeg");
        bonusSprite.setTexture(bonusTexture);
        bonusSprite.setScale(0.2f, 0.2f);
        bonusPosition.x = 450;
        bonusPosition.y = 450;

    }

    int getScore() {

        return score;

    }

    void drawFood(Screen& screen) {
        if (foodPosition.x > 700 - 20 || foodPosition.x < 100) {
            xvelocity *= -1;
        }
        if (foodPosition.y > 500 - 20 || foodPosition.y < 100) {
            yvelocity *= -1;
        }
        if (score >= 5)foodPosition.x += xvelocity, foodPosition.y += yvelocity;

        foodSprite.setPosition(foodPosition.x, foodPosition.y);
        screen.drawSprite(foodSprite);

    }


    int getfoodpointx()const {
        //cout << "Food: "<< foodPosition.x/10-10 << " ";
        return(foodPosition.x / 10 - 10);
    }
    int getfoodpointy()const {
        //cout << foodPosition.y/10-10 << " \n";
        return(foodPosition.y / 10 - 10);
    }
    void increaseVelocity() {
        randi = 320;
        randj = 320;
        xvelocity += 0.1;
        yvelocity += 0.1;
    }
    void repositionFood() {
        int randi = rand() % 500 + 120;
        int randj = rand() % 300 + 120;
        foodPosition.x = randi;
        foodPosition.y = randj;

        xvelocity = 0.5f;
        yvelocity = 0.5f;
    }

    void bonus(Screen& screen) {
        bonusPosition.x = randi;
        bonusPosition.y = randj;
        bonusSprite.setPosition(bonusPosition.x, bonusPosition.y);
        screen.drawSprite(bonusSprite);
    }

    int getbonuspointx()const {
        //cout << "bonus: "<< bonusPosition.x/10-10 << " ";
        return(bonusPosition.x / 10 - 10);
    }
    int getbonuspointy()const {
        //cout << bonusPosition.y/10-10 << " \n";
        return(bonusPosition.y / 10 - 10);
    }
};

//hahaha siuuuuuu

//////////////////////////////////////////////////////////////////////////////////////////////
class Snake {
private:
    int cellLength = 10;
    int cellWidth = 10;


    sf::Texture snakeHead;
    sf::Sprite snakeHeadSprite;
    sf::Texture snakeBody;
    sf::Sprite snakeBodySprite;

    int** Grid;
    int gridWidth = 60, gridHeight = 40;

    int** snakePositionsXY;
    sf::Sprite* snakeArray;
    int snakeSize;
    int maxSnakeSize;

public:
    Snake() {

        Grid = new int* [gridWidth];
        for (int i = 0; i < gridWidth; ++i) {
            Grid[i] = new int[gridHeight] {0};
        }


        maxSnakeSize = 50;
        snakeSize = 5;
        snakePositionsXY = new int* [2];
        snakePositionsXY[0] = new int[maxSnakeSize];
        snakePositionsXY[1] = new int[maxSnakeSize];

        snakeArray = new sf::Sprite[maxSnakeSize];

        snakeBody.loadFromFile("Sprites/Snake Sprites/snake111.png");
        snakeBodySprite.setTexture(snakeBody);
        snakeBodySprite.setScale(0.4f, 0.4f);

        //snakeHead.loadFromFile("SnakeHead.png");
        snakeHead.loadFromFile("Sprites/Snake Sprites/gerlunsaab.jpg");
        snakeHeadSprite.setTexture(snakeHead);
        //snakeHeadSprite.setScale(0.4f, 0.4f);
        snakeHeadSprite.setScale(0.05f, 0.05f);



        for (int i = 0; i < snakeSize; ++i) {
            snakePositionsXY[0][i] = 100 + i * cellLength;
            snakePositionsXY[1][i] = 200;
            snakeArray[i] = (i == snakeSize - 1) ? snakeHeadSprite : snakeBodySprite;
        }



        updateGrid();
    }

    
    void updateGrid() {
        for (int i = 0; i < gridWidth; ++i) {
            for (int j = 0; j < gridHeight; ++j) {
                Grid[i][j] = 0;
            }
        }

        for (int i = 0; i < snakeSize; ++i) {
            int gridX = snakePositionsXY[0][i] / cellLength - 10;
            int gridY = snakePositionsXY[1][i] / cellWidth - 10;
            if (i < snakeSize - 1) {
                Grid[gridX][gridY] = 1;
            }
            else {
                Grid[gridX][gridY] = 2;
            }
        }
    }
    void updateGridForFood(int dx, int dy) {
        Grid[dx][dy] = 3;
        // cout <<"food: " << dx << " " << dy << " ";
        // cout << Grid[dx][dy+1] << " " << Grid[dx][dy-1]<<" " << Grid[dx + 1][dy] <<" " << Grid[dx - 1][dy] << endl;

    }
    void updateGridForBonus(int dx, int dy) {
        Grid[dx][dy] = 4;
        // cout <<"food: " << dx << " " << dy << " ";
        // cout << Grid[dx][dy+1] << " " << Grid[dx][dy-1]<<" " << Grid[dx + 1][dy] <<" " << Grid[dx - 1][dy] << endl;

    }

    void moveSnake(int dx, int dy) {
        for (int i = 0; i < snakeSize - 1; ++i) {
            snakePositionsXY[0][i] = snakePositionsXY[0][i + 1];
            snakePositionsXY[1][i] = snakePositionsXY[1][i + 1];
        }

        snakePositionsXY[0][snakeSize - 1] += dx * cellLength;
        snakePositionsXY[1][snakeSize - 1] += dy * cellWidth;
        updateGrid();
    }

    void growSnake() {
        if (snakeSize < maxSnakeSize) {
            for (int i = snakeSize; i > 0; --i) {
                snakePositionsXY[0][i] = snakePositionsXY[0][i - 1];
                snakePositionsXY[1][i] = snakePositionsXY[1][i - 1];
                snakeArray[i] = snakeArray[i - 1];
            }

            snakePositionsXY[0][0] = snakePositionsXY[0][1];
            snakePositionsXY[1][0] = snakePositionsXY[1][1];
            snakeArray[0] = snakeBodySprite;
            snakeSize++;

            updateGrid();
        }
    }


    void drawSnake(Screen& screen) {
        /*sa   cout << "Grid after update:" << endl;
      for (int i = 0; i < 40; ++i) { // Rows (height, second index)
          for (int j = 0; j < 60; ++j) { // Columns (width, first index)
              if (Grid[j][i] == 1)cout << "#"<<" ";
              else if (Grid[j][i] == 2)cout << "O"<<" ";
              else if (Grid[j][i] == 3)cout << "F" << " ";
              else if (Grid[j][i]==4)cout<<"B"<<" ";
              else { cout << "." << " "; }
          }
          cout << endl; // Move to the next row after printing a row
      }*/

        for (int i = 0; i < snakeSize; ++i) {
            snakeArray[i].setPosition(snakePositionsXY[0][i], snakePositionsXY[1][i]);
            screen.drawSprite(snakeArray[i]);
        }
    }



    int getHeadPositionX() const {
        return snakePositionsXY[0][snakeSize - 1] / cellLength - 10;
    }

    int getHeadPositionY() const {
        return snakePositionsXY[1][snakeSize - 1] / cellWidth - 10;
    }
    void setHeadPositionaftercollision() {
        snakePositionsXY[0][snakeSize - 1] = 400;
        snakePositionsXY[1][snakeSize - 1] = 300;

    }
    bool selfCollision() {
        if (snakeSize > 5) {
            for (int i = 0; i < snakeSize - 1; ++i) {
                if (snakePositionsXY[0][snakeSize - 1] == snakePositionsXY[0][i] &&
                    snakePositionsXY[1][snakeSize - 1] == snakePositionsXY[1][i]) {
                    std::cout << "SELF COLLISION DETECTED!" << std::endl;
                    setHeadPositionaftercollision();
                    return true;
                }
            }
        }
        return false;
    }






};
////////////////////////////////////////////////////////////////////////////////
class SnakeGame : public Game {
private:
    Snake s1;
    Food f1;
    int dx = 1, dy = 0;
    int lives = 5 + 1;
    sf::Vector2f foodcoord;
    sf::Vector2f headcoord;
    float moveDelay = 0.1f;
    sf::Texture Gameover;
    sf::Sprite GameoverSprite;
    // bool isBonusActive = true;  // Tracks if the bonus is active
    sf::Clock bonusClock;        // Tracks time for bonus appearance
    float bonusDuration = 5.0f;  // Bonus lasts for 5 seconds
    sf::Texture Backgroundimage;
    sf::Sprite BackgroundSprite;
    sf::Vertex line1[2], line2[2], line3[2], line4[2];
    sf::SoundBuffer zohaib1;
    sf::Sound ZohaibSound;
    sf::SoundBuffer wrrgya;
    sf::Sound wrrgyasound;
    sf::SoundBuffer boundary;
    sf::Sound boundarysound;

    sf::Font font;
    sf::Text score_text;
    sf::Text lives_text;

    bool endGame;
    int soundCounter;
    string backMusic;


public:
    virtual void StartGame(Screen& screen) override{
    
       
        sf::Clock clock;
        float elapsedTime = 0.0f;

        while (screen.isOpen() && !getEndGame()) {
            
            sf::Event event;
            while (screen.window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    screen.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    screen.close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    if (dx != 0 && dy != -1)
                        dx = 0, dy = 1;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    if (dx != 0 && dy != 1)
                        dx = 0, dy = -1;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    if (dx != -1 && dy != 0)
                        dx = 1, dy = 0;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    if (dx != 1 && dy != 0)
                        dx = -1, dy = 0;
            }

            elapsedTime += clock.restart().asSeconds();

            if (elapsedTime >= moveDelay) {
                s1.moveSnake(dx, dy);
                elapsedTime = 0.001f;
            }

            if (f1.score != 0 && f1.score % 5 == 0) {
                s1.updateGridForBonus(f1.getbonuspointx(), f1.getbonuspointy());
                f1.bonus(screen);
                bonusClock.restart();
            }
            


            screen.clear();

            screen.drawSprite(BackgroundSprite);
            drawGridForSnake(screen);
            f1.drawFood(screen);
            s1.updateGridForFood(f1.getfoodpointx(), f1.getfoodpointy());
            this->updateScore();
            this->updateText();

            s1.drawSnake(screen);
            outofbound(screen);

            this->renderText(screen);
            checkcollision(screen);

           screen.display();


        }
    
    }
  
    void initScore() {

        scores = 0;

    }

    int getScore() {

        return scores;

    }

    void updateScore() {

        scores = f1.getScore();
        cout << "\nScores : " << scores << endl;

    }

    
    void initFont() {

        if (!this->font.loadFromFile("Fonts/Roboto-Bold.ttf")) {

            cout << "ERROR::GAME::INITFONTS::Failed to load Font!" << endl;

        }

    }


    void initText() {

        this->score_text.setFont(this->font);
        this->score_text.setCharacterSize(20);
        this->score_text.setFillColor(sf::Color::White);
        this->score_text.setOrigin(sf::Vector2f(-675.f, -20.f));
        this->score_text.setString("Points : 0");

        this->lives_text.setFont(this->font);
        this->lives_text.setCharacterSize(20);
        this->lives_text.setFillColor(sf::Color::Red);
        this->lives_text.setOrigin(sf::Vector2f(-675.f, -50.f));
        this->lives_text.setString("Lives : 5");

    }




    SnakeGame(Screen& screen) {

        line1[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::White);
        line1[1] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Blue);

        line2[0] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Red);
        line2[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);

        line3[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red);
        line3[1] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Blue);

        line4[0] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Red);
        line4[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);
        Gameover.loadFromFile("Sprites/Snake Sprites/gameover.jpg");
        GameoverSprite.setTexture(Gameover);
        GameoverSprite.setScale(0.8f, 0.3f);
        GameoverSprite.setPosition(100, 100);

        Backgroundimage.loadFromFile("Sprites/Snake Sprites/background.jpg");
        BackgroundSprite.setTexture(Backgroundimage);
        BackgroundSprite.setPosition(0, 0);

        zohaib1.loadFromFile("Sound/hit.ogg");
        ZohaibSound.setBuffer(zohaib1);

        wrrgya.loadFromFile("Sound/turrgaye.ogg");
        wrrgyasound.setBuffer(wrrgya);

        boundary.loadFromFile("Sound/boundary.ogg");
        boundarysound.setBuffer(boundary);
        
        this->endGame = false;

        this->initScore();
        this->initFont();
        this->initText();

        this->backMusic = "Sound/scam_1992.ogg";
        this->PlayMusic(this->backMusic);

        this->soundCounter = 0;

       
    }
    const bool getEndGame() const { return this->endGame; }

    void checkcollision(Screen& screen) {
        getfoodpositionfromfood();
        getheadpositionfromsnake();

        if (headcoord.x >= f1.getfoodpointx() && headcoord.y >= f1.getfoodpointy() && headcoord.x <= f1.getfoodpointx() + 1 && headcoord.y <= f1.getfoodpointy() + 1) {
            cout << "Collision detected! ....Score:" << f1.score << endl;
            collision(screen);

        }
        if (s1.selfCollision()) {
            f1.score -= 1, --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(screen);
        }

        //if (headcoord.x == f1.getbonuspointx() && headcoord.y == f1.getbonuspointy()) {
        //    cout << "\n\n\nbonus collided\n\n\n";
          //  f1.score += 5;
        //}
        /*if (headcoord.x == f1.getbonuspointx() && headcoord.y == f1.getbonuspointy()) {
            cout << "\n\n\nBonus collided\n\n\n";
            f1.score += 5;
        }*/

    }


    void outofbound(Screen& screen) {

        if (headcoord.x <= 0.5) {
            PlayhitSound(boundary);
            --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(screen);
            s1.setHeadPositionaftercollision();

        }
        else if (headcoord.x >= 58) {
            PlayhitSound(boundary);
            --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(screen);
            s1.setHeadPositionaftercollision();

        }
        else if (headcoord.y <= 0) {
            PlayhitSound(boundary);
            --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(screen);
            s1.setHeadPositionaftercollision();

        }
        else if (headcoord.y >= 39) {
            PlayhitSound(boundary);
            --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(screen);
            s1.setHeadPositionaftercollision();


        }

    }
    void collision(Screen& screen) {

        PlayhitSound(zohaib1);
        f1.repositionFood();
        f1.increaseVelocity();
        s1.growSnake();
        f1.score++;
        leaderboard.updateHighScore(f1.score);
        cout << "Highest score:" << leaderboard.getHighScore() << endl;

        if (moveDelay > 0.05f) {
            moveDelay -= 0.01f;
        }
    }

    void getfoodpositionfromfood() {
        foodcoord.x = f1.getfoodpointx();
        foodcoord.y = f1.getfoodpointy();
    }

    void getheadpositionfromsnake() {
        headcoord.x = s1.getHeadPositionX();
        headcoord.y = s1.getHeadPositionY();
    }

    void outoflives(Screen& screen) {
        std::cout << "\nYOU ARE OUT OF LIVES\n";
        this->stopMusic(this->backMusic);
        PlayhitSound(wrrgya);
        screen.clear();
        screen.drawSprite(GameoverSprite);
        screen.display();

        sf::Clock pauseClock;
        while (pauseClock.getElapsedTime().asSeconds() < 4.0f) {
        }

       // screen.close();
        this->endGame = true;
       
    }

    void drawGridForSnake(Screen& screen) const {
        screen.drawLine(line1, 2 /*sf::Lines*/);
        screen.drawLine(line2, 2 /*sf::Lines*/);
        screen.drawLine(line3, 2 /*sf::Lines*/);
        screen.drawLine(line4, 2 /*sf::Lines*/);
    }

    void updateText() {

        stringstream scr;
        stringstream liv;

        cout << "\nScores : " << scores << endl;

        scr << "Points : " << scores << "\n";
        this->score_text.setString(scr.str());
        scr.clear();

        cout << "\Lives : " << lives << endl;

        liv << "Lives : " << lives << "\n";
        this->lives_text.setString(liv.str());
        liv.clear();


    }

    void renderText(Screen& screen) {

        screen.drawText(this->score_text);
        screen.drawText(this->lives_text);
    }



};
///////////////////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

