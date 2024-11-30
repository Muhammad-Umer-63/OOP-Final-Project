#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hangman.h"

using namespace std;

int main()
{
    
    srand(static_cast<unsigned>(time(NULL)));

    //init Game engine
    Hangman* hangman = new Hangman;
    hangman->gameLoop();
    delete hangman;
    hangman = NULL;

    return 0;
}