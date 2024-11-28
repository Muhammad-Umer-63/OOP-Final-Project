#include<iostream>
#include"Snake.h"
#include"Food.h"
using namespace std;






class SnakeGame {
private:
    Snake s1;
    Food f1;
    int dx = 1, dy = 0;

public:
    SnakeGame() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
        window.setFramerateLimit(30);
        int(&grid)[60][40] = s1.getGrid();

        // Place initial food
        f1.placeFood(grid);

        sf::Clock clock;
        float moveDelay = 0.2f;  // Delay in seconds between snake movements
        float elapsedTime = 0.0f;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
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
                s1.moveSnake(dx, dy);  // Pass current direction to moveSnake
                elapsedTime = 0.0f;   // Reset elapsed time
            }
       //     if (grid[s1.getHeadX()][s1.getHeadY()] == 2) {
       //         // Handle collision logic, e.g., grow snake and place new food
       //         f1.placeFood(grid);
       //     }
            window.clear();
            s1.drawGridForSnake(window);
            f1.drawFood(window);
            s1.drawSnake(window);

       //     collision();
            window.display();
        }
    }


    void collision() {
        // Get snake head and food positions
        sf::Vector2f snakeHeadPos = s1.getHeadPosition();
        sf::Vector2f foodPos = f1.getFoodPosition();

        // Check collision (distance within a certain threshold)
        float distance = sqrt(pow(snakeHeadPos.x - foodPos.x, 2) + pow(snakeHeadPos.y - foodPos.y, 2));
        if (distance < 10) { // 10 is a threshold, adjust based on your sprite sizes
            // Handle collision logic, e.g., increase score, reposition food
            cout << "Collision Detected!" << endl;
        }
    }

};
