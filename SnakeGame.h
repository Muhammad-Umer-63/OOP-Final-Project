
#include "SFML/Graphics.hpp"
#include"SFML/Audio/Music.hpp"
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
    int lives = 5+1;
    sf::Vector2f foodcoord;
    sf::Vector2f headcoord;
    float moveDelay = 0.1f;
    sf::Texture Gameover;
    sf::Sprite GameoverSprite;
    bool isBonusActive = true;  // Tracks if the bonus is active
    sf::Clock bonusClock;        // Tracks time for bonus appearance
    float bonusDuration = 5.0f;  // Bonus lasts for 5 seconds
    sf::Texture Backgroundimage;
    sf::Sprite BackgroundSprite;
    sf::Vertex line1[2], line2[2], line3[2], line4[2];

    
public:
     

    SnakeGame() {
        line1[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::White);
        line1[1] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Blue);

        line2[0] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Red);
        line2[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);

        line3[0] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red);
        line3[1] = sf::Vertex(sf::Vector2f(100, 500), sf::Color::Blue);

        line4[0] = sf::Vertex(sf::Vector2f(700, 100), sf::Color::Red);
        line4[1] = sf::Vertex(sf::Vector2f(700, 500), sf::Color::Blue);
        Gameover.loadFromFile("gameover.jpg");
        GameoverSprite.setTexture(Gameover);
        GameoverSprite.setScale(0.8f, 0.3f);
        GameoverSprite.setPosition(100,100);

        Backgroundimage.loadFromFile("background.jpg");
        BackgroundSprite.setTexture(Backgroundimage);
        BackgroundSprite.setPosition(0, 0);

        sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Project by 23i-0754 & 23i-0006");
        window.setFramerateLimit(60);
        sf::SoundBuffer buffer;
        buffer.loadFromFile("scam_1992.ogg");
        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();

        sf::SoundBuffer zohaib;
        zohaib.loadFromFile("zohaibfirst.ogg");
        sf::Sound ZohaibSound;
        ZohaibSound.setBuffer(zohaib);

        sf::SoundBuffer wrrgya;
        wrrgya.loadFromFile("turrgaye.ogg");
        sf::Sound wrrgyasound;
        wrrgyasound.setBuffer(wrrgya);




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
                elapsedTime = 0.001f;   
            }

            if (!isBonusActive && f1.score != 0 && f1.score % 5 == 0) {
                s1.updateGridForBonus(f1.getbonuspointx(), f1.getbonuspointy());
                f1.bonus(window);
                isBonusActive = true;  
                bonusClock.restart(); 
            }

            if (isBonusActive && bonusClock.getElapsedTime().asSeconds() >= bonusDuration) {
                isBonusActive = false;  
            }

            window.clear();
            window.draw(BackgroundSprite);
            drawGridForSnake(window);
            f1.drawFood(window);
            s1.updateGridForFood(f1.getfoodpointx(), f1.getfoodpointy());

            s1.drawSnake(window);
            outofbound(window,wrrgyasound,sound);

            checkcollision(window, ZohaibSound, wrrgyasound,sound);
           
            window.display();
        }
    }
    /////////////////////////////////////////////////////////
    void checkcollision(sf::RenderWindow& window, sf::Sound& sound1, sf::Sound& sound2,sf::Sound& sound3) {
        getfoodpositionfromfood();
        getheadpositionfromsnake();
        
        if (headcoord.x >= f1.getfoodpointx() && headcoord.y >= f1.getfoodpointy() && headcoord.x <= f1.getfoodpointx()+1 && headcoord.y <= f1.getfoodpointy()+1) {
            cout << "Collision detected! ....Score:" << f1.score << endl;
            collision(window, sound1,sound3);

        }
        if (s1.selfCollision()) { 
            f1.score -= 1,--lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(window,sound2,sound3);
        }

        //if (headcoord.x == f1.getbonuspointx() && headcoord.y == f1.getbonuspointy()) {
        //    cout << "\n\n\nbonus collided\n\n\n";
          //  f1.score += 5;
        //}
        if (isBonusActive && headcoord.x == f1.getbonuspointx() && headcoord.y == f1.getbonuspointy()) {
            isBonusActive = false;  // Deactivate bonus after collision
            std::cout << "\n\n\nBonus collided\n\n\n";
            f1.score += 5;
        }

    }


    void outofbound(sf::RenderWindow& window,sf::Sound& sound1,sf::Sound& sound3 ) {
        
        if (headcoord.x <= 0.5) {
            --lives;
            cout << "lives: " << lives << endl;
            if(lives<=0)outoflives(window,sound1,sound3);
            s1.setHeadPositionaftercollision();
            
        }
        else if (headcoord.x >= 58) {
            --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(window,sound1,sound3);
            s1.setHeadPositionaftercollision();

         }
        else if (headcoord.y<=0) {
            --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(window,sound1,sound3);
            s1.setHeadPositionaftercollision();

            }
        else if (headcoord.y>=39) {
            --lives;
            cout << "lives: " << lives << endl;
            if (lives <= 0)outoflives(window,sound1,sound3);
            s1.setHeadPositionaftercollision();


        }

    }
    void collision(sf::RenderWindow& window,sf::Sound& sound1,sf::Sound& sound3) {
        sound1.play();
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
  
    void outoflives(sf::RenderWindow& window, sf::Sound& sound1,  sf::Sound& sound3) {
        std::cout << "\nYOU ARE OUT OF LIVES\n";
        sound3.pause();
        sound1.play();
        window.clear();
        window.draw(GameoverSprite);
        window.display();

        sf::Clock pauseClock;
        while (pauseClock.getElapsedTime().asSeconds() < 4.0f) {
        }

        window.close();

    }

    void drawGridForSnake(sf::RenderWindow& window) const {
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.draw(line3, 2, sf::Lines);
        window.draw(line4, 2, sf::Lines);
    }

};
