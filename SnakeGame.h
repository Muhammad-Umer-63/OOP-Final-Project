#pragma once
#include<iostream>
#include"Food.h"
#include"Snake.h"
using namespace std;

class SnakeGame {
private:
    Snake s1;
    Food f1;
    int dx = 0, dy = 0;



public:
    SnakeGame() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
        window.setFramerateLimit(150);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { //escape button key say window close hogi
                    window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    s1.moveSnake(0, 1), dx = 0, dy = 1;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    s1.moveSnake(0, -1), dx = 0, dy = -1;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    s1.moveSnake(1, 0), dx = 1, dy = 0;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    s1.moveSnake(-1, 0), dx = -1, dy = 0;
            }
            window.clear();
            //window.draw(bermudaRectangle);
            s1.drawGridForSnake(window);
            s1.moveSnake(dx, dy);
            f1.drawFood(window);
            s1.drawSnake(window);
            f1.drawFood(window);
            
            window.display();
        }
    }




};







