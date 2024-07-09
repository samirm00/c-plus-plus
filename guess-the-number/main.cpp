#include <iostream>
#include <cstdlib>
#include <ctime>
#include "src/GuessGame.h"

int main()
{
    // Seed the random number generator
    srand(time(0));
    GuessGame game;
    game.startGame();
    return 0;
}
