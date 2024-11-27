#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hangman.h"

using namespace std;


int main()
{
    
    srand(static_cast<unsigned>(time(NULL)));
    //init Game engine
    Game game;
    

    //Game Loop
    while (game.running() && !game.getEndGame()) {

        //update

        game.update();

        //render

        game.render();

    }

    std::cout << "Window creation" << " \n";
    return 0;

    return 0;
}