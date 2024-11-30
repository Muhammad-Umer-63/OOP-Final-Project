#pragma once
#include "SFML/Graphics.hpp"
#include "Food.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Snake {
private:
    int cellLength = 10;
    int cellWidth = 10;

    sf::Vertex line1[2], line2[2], line3[2], line4[2]; 

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

        snakeBody.loadFromFile("snake111.png");
        snakeBodySprite.setTexture(snakeBody);
        snakeBodySprite.setScale(0.4f, 0.4f);

        snakeHead.loadFromFile("SnakeHead.png");
        //snakeHead.loadFromFile("gerlunsaab.jpg");
        snakeHeadSprite.setTexture(snakeHead);
        snakeHeadSprite.setScale(0.4f, 0.4f);
        //snakeHeadSprite.setScale(0.07f, 0.07f);



        for (int i = 0; i < snakeSize; ++i) {
            snakePositionsXY[0][i] = 100 + i * cellLength;
            snakePositionsXY[1][i] = 200;
            snakeArray[i] = (i == snakeSize - 1) ? snakeHeadSprite : snakeBodySprite;
        }

        line1[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red);
        line1[1] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Blue);

        line2[0] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Red);
        line2[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);

        line3[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red);
        line3[1] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Blue);

        line4[0] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Red);
        line4[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);

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


    void drawSnake(sf::RenderWindow& window) {
        /*     cout << "Grid after update:" << endl;
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
            window.draw(snakeArray[i]);
        }
    }

    void drawGridForSnake(sf::RenderWindow& window) const {
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.draw(line3, 2, sf::Lines);
        window.draw(line4, 2, sf::Lines);
    }

    int getHeadPositionX() const {
        return snakePositionsXY[0][snakeSize - 1] / cellLength - 10;
    }

    int getHeadPositionY() const {
        return snakePositionsXY[1][snakeSize - 1] / cellWidth - 10;
    }
    void setHeadPositionaftercollision(){
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

