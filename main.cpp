#include <SFML/Graphics.hpp>

//#include "C:\Users\DELL\OneDrive\Desktop\OOP PROJECT\Final Project GameBOY\Snake.h"
#include <iostream>
using namespace std;

int main()
{

    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "Hangman"); //VideoMode Size of window
    window.setFramerateLimit(60);
   // we have to create a loop
   //will hold info about an event

    sf::Font open_sans;
    //open_sans.loadFromFile(/*path in quotes*/); //have to download all the time

    sf::Text my_text;
    my_text.setFont(open_sans);
    my_text.setString("Hello World");
    my_text.setPosition(300, 400);
    my_text.setFillColor(sf::Color::Green);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) //different events ko manage karnay ke liye takay unk clash na aye event union?
        {
            if (event.type == sf::Event::Closed) {

                window.close();
                
            }
        }


        window.clear();
        window.draw(my_text);
        window.display();

    }

    //before drawing always be sure to clear the window otherwise you will drawon what ever their is left behind
    //inside loop very important three funstions

    cout << "Window creation" << " \n";
    return 0;

}