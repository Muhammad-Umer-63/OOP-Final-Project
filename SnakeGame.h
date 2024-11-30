
#include "SFML/Graphics.hpp"
#include "Food.h"
#include"Snake.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

class SnakeGame {
private:
    Snake s1;
    Food f1;
    int dx = 1, dy = 0;

public:
    sf::Vector2f foodcoord;
    sf::Vector2f headcoord;
    float moveDelay = 0.1f; 

    SnakeGame() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
        window.setFramerateLimit(60);

        sf::Clock clock;
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
                s1.moveSnake(dx, dy);  
                elapsedTime = 0.0f;   
            }

            window.clear();
            s1.drawGridForSnake(window);
            f1.drawFood(window);
            s1.updateGridForFood(f1.getfoodpointx(), f1.getfoodpointy());

            s1.drawSnake(window);
            outofbound();

            checkcollision(window);
            if (f1.score!=0 && f1.score % 5 == 0) {
                s1.updateGridForBonus(f1.getbonuspointx(), f1.getbonuspointy());
                f1.bonus(window);
            }
            
            window.display();
        }
    }

    void checkcollision(sf::RenderWindow& window) {
        getfoodpositionfromfood();
        getheadpositionfromsnake();
        
        if (headcoord.x >= f1.getfoodpointx() && headcoord.y >= f1.getfoodpointy() && headcoord.x <= f1.getfoodpointx()+1 && headcoord.y <= f1.getfoodpointy()+1) {
            cout << "Collision detected! ....Score:" << f1.score << endl;
            collision(window);

        }
        if (s1.selfCollision()) { f1.score -= 1; }

        if (headcoord.x == f1.getbonuspointx() && headcoord.y == f1.getbonuspointy()) {
            cout << "\n\n\nbonus collided\n\n\n";
            f1.score += 5;
        }


    }


    void outofbound() {
        if (headcoord.x <= 0.5) {
            s1.setHeadPositionaftercollision();
            
        }
        else if (headcoord.x >= 58) {
            s1.setHeadPositionaftercollision();

         }
        else if (headcoord.y<=0) {
            s1.setHeadPositionaftercollision();

            }
        else if (headcoord.y>=39) {
            s1.setHeadPositionaftercollision();


        }

    }
    void collision(sf::RenderWindow& window) {
        f1.repositionFood(); 
        f1.increaseVelocity();  
        s1.growSnake();
        f1.score++; 
       
        
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
   
};
