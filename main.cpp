#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wordle.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(static_cast<unsigned int>(time(NULL)));
    
    Wordle* wordle = new Wordle;
    wordle->gameLoop();
    delete wordle;
    wordle = NULL;

    

    return 0;

}