#include <SFML/Graphics.hpp>
//#include "C:\Users\DELL\OneDrive\Desktop\OOP PROJECT\Final Project GameBOY\Snake.h"
#include<iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
    window.setFramerateLimit(60);

    sf::RectangleShape bermudaRectangle;
    bermudaRectangle.setFillColor(sf::Color::Magenta);
    sf::Vector2f rectangleposition(350, 350);
    bermudaRectangle.setPosition(rectangleposition);
    bermudaRectangle.setSize(sf::Vector2f(100, 100));
    float xvelocity = 3, yvelocity = 3;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { //escape button key say window close hogi
            window.close();
        }

        if (rectangleposition.x > 800 - 100 || rectangleposition.x < 0) {
            xvelocity *= -1;
        }
        if (rectangleposition.y > 600 - 100 || rectangleposition.y < 0) {
            yvelocity *= -1;
        }


        rectangleposition.x += xvelocity;
        rectangleposition.y += yvelocity;

        bermudaRectangle.setPosition(rectangleposition.x, rectangleposition.y);






        window.clear();
        window.draw(bermudaRectangle);
        window.display();
    }

    return 0;
}