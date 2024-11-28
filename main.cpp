#include <SFML/Graphics.hpp>
//#include "C:\Users\DELL\OneDrive\Desktop\OOP GITHUB\Snake.h"
//#include"C:\Users\DELL\OneDrive\Desktop\OOP GITHUB\include\SFML\Audio\Music.hpp"
#include"SnakeGame.h"
#include<iostream>
using namespace std;

int main(){
    

    srand(static_cast<unsigned int>(time(0)));
    int selection;
    cout << "enter 1 if you wanna play snake game: ";
    cin >> selection;
    if (selection == 1) {
        SnakeGame Game1;
    }


    return 0;
}
   
  
   
   /* sf::RectangleShape bermudaRectangle;
    bermudaRectangle.setFillColor(sf::Color::Magenta);
    sf::Vector2f rectangleposition(200, 150);
    bermudaRectangle.setPosition(rectangleposition);
    bermudaRectangle.setSize(sf::Vector2f(100, 100));
    float xvelocity = 3, yvelocity = 3;
    */
   /* while (window.isOpen())
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
                s1.moveSnake(0,1),dx=0,dy=1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                s1.moveSnake(0, -1), dx = 0, dy = -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                s1.moveSnake(1,0), dx = 1, dy = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                s1.moveSnake(-1, 0), dx = -1, dy = 0;
        }
       

       /* if (rectangleposition.x > 600 - 100 || rectangleposition.x < 200) {
            xvelocity *= -1;
        }
        if (rectangleposition.y > 450 - 100 || rectangleposition.y < 150) {
            yvelocity *= -1;
        }

        rectangleposition.x += xvelocity;
        rectangleposition.y += yvelocity;
        
        bermudaRectangle.setPosition(rectangleposition.x, rectangleposition.y);
     */

      /*    *
        window.clear();
        //window.draw(bermudaRectangle);
        s1.drawGridForSnake(window);
        s1.moveSnake(dx, dy);
        f1.drawFood(window);
        s1.drawSnake(window);
        f1.drawFood(window);

        window.display();
    }
    */
    
