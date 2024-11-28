
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Snake.h"
#include"Food.h"
using namespace std;


    


class SnakeGame {
private:
    Snake s1;
    Food  f1;
    int dx = 1, dy = 0;
   
public:
    sf::Vector2f foodcoord;
    sf::Vector2f headcoord;
    SnakeGame() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
        window.setFramerateLimit(30);

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
      
            window.clear();
            s1.drawGridForSnake(window);
            f1.drawFood(window);
            s1.updateGridForFood(f1.getfoodpointx(), f1.getfoodpointy());

            s1.drawSnake(window);

            checkcollision();
            window.display();
        }
    }

    

    void getfoodpositionfromfood() {
        foodcoord.x = f1.getfoodpointx();
        foodcoord.y = f1.getfoodpointy();
       
      
    }

    void getheadpositionfromsnake() {
        headcoord.x = s1.getheadpositionx();
        headcoord.y = s1.getheadpositiony();
    }
    

    void checkcollision() {
        getfoodpositionfromfood();
        getheadpositionfromsnake();
    sf::Vector2i headGridPos = sf::Vector2i( headcoord.x,headcoord.y);

    sf::Vector2i foodGridPos;
    foodGridPos.x = foodcoord.x;
    foodGridPos.y = foodcoord.y;

    // Debugging output (optional)
  //  cout << "Head: (" << headGridPos.x << ", " << headGridPos.y << ") ";
    //cout << "Food: (" << foodGridPos.x << ", " << foodGridPos.y << ")" << endl;

    // Check for collision
    if (headGridPos == foodGridPos) {
        cout << "Collision detected!" << endl;
        collision();}
    }

    void collision() {
        f1.increaseVelocity();

        
    }










    
};
