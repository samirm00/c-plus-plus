#ifndef GUESSGAME_H
#define GUESSGAME_H

class GuessGame
{
public:
    void startGame();

private:
    int getUserGuess();
    int getRandomGuess(int min, int max);
    void checkGuess(int userGuess, int randomGuess);
    bool playAgain();
};

#endif 

