#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hangman.h"

using namespace std;

int main()
{
 
    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "Hangman",sf::Style::Default); //VideoMode Size of window
    window.setFramerateLimit(60);
   // we have to create a loop

    sf::RectangleShape rect;

    sf::Vector2f rectanglePosition(600, 350);
    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(100, 100)); //f = float, i = integer, u = unsigned int
    rect.setFillColor(sf::Color::Red);

    //sfml uses shapes top as (0,0)

    float xVelocity = 3;
    float yVelocity = 3;

    sf::Event event; 
    //basically any input you guve will be stored here and then after wards it can be used in pollEvent
    //will hold info about an event

    while (window.isOpen()) {

       

        while (window.pollEvent(event)) //different events ko manage karnay ke liye takay unk clash na aye event union?
        {

            switch (event.type)
            {

            case sf::Event::Closed:

                window.close();
                break;

            case sf::Event::KeyPressed:

                if (event.key.code == sf::Keyboard::Escape) {

                    window.close();

                }

                break;

            }

            

        }

        if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 100) xVelocity *= -1; //negative wapis jaye
        if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - 100) yVelocity *= -1;

        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity; //to move objects we have to add it to that position 
        //still only doing in back end
        rect.setPosition(rectanglePosition);

        window.clear();
        window.draw(rect);
        window.display();

    }

    //before drawing always be sure to clear the window otherwise you will drawon what ever their is left behind
    //inside loop very important three funstions

    std::cout << "Window creation" << " \n";
    return 0;

    return 0;
}