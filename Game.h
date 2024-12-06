#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SnakeGame.h"
using namespace std;

class Game {
private:
    int selection;
    int score;
    sf::Texture gameImage;
    sf::Sprite gameSprite;
    sf::RectangleShape snakeButton;  // Button for Snake Game
    sf::RectangleShape WordleButton;  // Button for Hangman Game
    sf::RectangleShape HangmanButton;
    

public:
    Game() {
        score = 0;
        selection = 0;
        sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
        window.setFramerateLimit(60);

        // Load background image
        if (!gameImage.loadFromFile("game.png")) {
            cout << "Failed to load game.png" << endl;
            return;
        }
        gameSprite.setTexture(gameImage);
        gameSprite.setPosition(0, 0);

        // Initialize buttons
        snakeButton.setSize(sf::Vector2f(400, 60));  // Width: 200px, Height: 50px
        snakeButton.setFillColor(sf::Color::Transparent);
        snakeButton.setPosition(200, 160);  // Position of Snake Game button

        WordleButton.setSize(sf::Vector2f(270, 50));
        WordleButton.setFillColor(sf::Color::Transparent);
        WordleButton.setPosition(260, 240);  // Position of woedle Game button

        HangmanButton.setSize(sf::Vector2f(310, 60));
        HangmanButton.setFillColor(sf::Color::Transparent);
        HangmanButton.setPosition(240, 320);

        srand(static_cast<unsigned int>(time(0)));

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Check for mouse click
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Check if mouse is over the Snake Game button
                    if (snakeButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        cout << "Snake Game selected!" << endl;
                        // Call SnakeGame constructor
                        SnakeGame snakeGame(window);
                    }

                    // Check if mouse is over the Hangman Game button
                    if (WordleButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        cout << "Wordle Game selected!" << endl;
                        // Hangman game logic goes here
                    }
                    if (HangmanButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        cout << "hangman Game selected!" << endl;
                        // Hangman game logic goes here
                    }
                }
            }

            // Clear, draw, and display
            window.clear(sf::Color::Black);  // Clear with a background color
            window.draw(gameSprite);        // Draw the background
            window.draw(snakeButton);       // Draw the Snake button
            window.draw(WordleButton); 
            window.draw(HangmanButton);
                window.display();               // Display the window
        }
    }

    void StartGame() {
        // Game starting logic
    }

    void EndGame() {
        // Game ending logic
    }
};
