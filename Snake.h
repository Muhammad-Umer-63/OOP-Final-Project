 #pragma once
#include "SFML/Graphics.hpp"
#include"Grid.h"
#include"Food.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Snake {     //1. grid    2. snakesegments  
private:
    
    int Grid[60][40] = { 0 };
    int cellLength = 10;
    int cellWidth = 10;
    sf::Vertex line1[2];// Class attribute for line1
    sf::Vertex line2[2]; // Class attribute for line2
    sf::Vertex line3[2]; // Class attribute for line3
    sf::Vertex line4[2]; // Class attribute for line4
    sf::Texture snakeHead;
    sf::Sprite snakeHeadSprite;
    sf::Texture snakeBody;
    sf::Sprite snakeBodySprite;
    sf::Sprite snakeArray[20];
    int xcoord, ycoord;
    int snakePositionsXY[2][20];

public:
    Snake() {

        snakeBody.loadFromFile("yellowSnake.png");
        snakeBodySprite.setTexture(snakeBody);
        snakeBodySprite.setScale(1.5f, 1.5f);
        snakeHead.loadFromFile("SnakeHead.png");
        snakeHeadSprite.setTexture(snakeHead);
        snakeHeadSprite.setScale(0.4f, 0.4f);
    
        

        xcoord = 250, ycoord = 200;
        for (int i = 0; i < 20; ++i) {
            snakePositionsXY[0][i] = xcoord ; // Set initial x-coordinates
            snakePositionsXY[1][i] = ycoord;                 // Set initial y-coordinates
        }
        for (int i = 0; i < 19; ++i) {
            snakeArray[i] = snakeBodySprite;
        }
        snakeArray[19] = snakeHeadSprite;
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                Grid[i][j] = 0;
            }
        }
       



        line1[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red);
        line1[1] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Blue);

        line2[0] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Red);
        line2[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);

        line3[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red);
        line3[1] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Blue);

        line4[0] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Red);
        line4[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);


    }
    void drawGridForSnake(sf::RenderWindow& window)const {
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.draw(line3, 2, sf::Lines);
        window.draw(line4, 2, sf::Lines);

    }

    void updateGrid() {
        // Clear the grid
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                Grid[i][j] = 0; // Clear the grid
            }
        }
       
        // Update the grid based on the snake's position
        for (int i = 0; i < 10; ++i) {
            int gridX = snakePositionsXY[0][i] / 10-20; // Map x-coordinate to grid
            int gridY = snakePositionsXY[1][i] / 10-15; // Map y-coordinate to grid
            if (gridX >= 0 && gridX < 40 && gridY >= 0 && gridY < 30) {
                Grid[gridX][gridY] = 1; // Mark the grid as occupied by the snake
                //cout << i << endl;
                //cout << "gridX: " << gridX << endl;
                //cout<< "gridY: " << gridY << endl;

            }
        }
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                 //cout << Grid[i][j] << " "; // Clear the grid
              //  if (Grid[i][j] == 1)cout << "i=" << i << " ";
            }
        }

       
    }



    void moveSnake(int dx, int dy) {
        // Shift the snake's position in the array
        for (int i = 0; i < 19; ++i) {
            snakePositionsXY[0][i] = snakePositionsXY[0][i + 1];
            snakePositionsXY[1][i] = snakePositionsXY[1][i + 1];
        }

        // Update the head position
        snakePositionsXY[0][19] += dx *cellLength; // Move head by cell size in x
        snakePositionsXY[1][19] += dy *cellWidth; // Move head by cell size in y

        // Update the grid after movement
        updateGrid();
        
    }


   

    void drawSnake(sf::RenderWindow& window) {
        updateGrid(); // Update the grid before drawing
      /* for (int i = 0; i < 20; ++i) {
            cout << "Snake segment " << i << ": ("
                << snakePositionsXY[0][i] << ", "
                << snakePositionsXY[1][i] << ")" << endl;
        }

        */
     ////////////////////////////////////////////////////////////////////////////////////////////program slow hoga

         ////////////////////////////////////////////////////////////////////////////////////////////////tells k back end pr grid kaisay chal rhi

       /* cout << "Grid after update:" << endl;
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                cout << Grid[i][j] << " ";
            }
            cout << endl;
        }
        */
        

        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
              //  if (Grid[i][j] == 1) {
                   

                  

                    // Draw body segments first
                    for (int i = 0; i < 19; ++i) {
                        snakeBodySprite.setPosition(snakePositionsXY[0][i], snakePositionsXY[1][i]);
                        window.draw(snakeBodySprite);
                    }

                    // Draw head explicitly
                    snakeHeadSprite.setPosition(snakePositionsXY[0][19], snakePositionsXY[1][19]);
                    window.draw(snakeHeadSprite);

               //}
            }
        }
    }






};








   