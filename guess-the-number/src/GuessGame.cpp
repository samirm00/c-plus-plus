#include "GuessGame.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void GuessGame::startGame()
{
    do
    {
        int min = 1;
        int max = 100;
        int randomGuess = getRandomGuess(min, max);
        int userGuess;
        do
        {
            userGuess = getUserGuess();
            checkGuess(userGuess, randomGuess);
        } while (userGuess != randomGuess);
    } while (playAgain());

    cout << "Thanks for playing!" << endl;
}

int GuessGame::getUserGuess()
{
    int guess;
    cout << "Enter your guess between 1 and 100: ";
    cin >> guess;
    while (cin.fail() || guess < 1 || guess > 100) 
    {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Enter a number between 1 and 100: ";
        cin >> guess;
    }
    return guess;
}

int GuessGame::getRandomGuess(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GuessGame::checkGuess(int userGuess, int randomGuess)
{
    if (userGuess == randomGuess)
    {
        cout << "You guessed correctly!" << endl;
    }
    else if (userGuess < randomGuess)
    {
        cout << "Your guess is too low!" << endl;
    }
    else
    {
        cout << "Your guess is too high!" << endl;
    }
}

bool GuessGame::playAgain()
{
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    while (response != 'y' && response != 'n') 
    {
        cout << "Invalid input. Do you want to play again? (y/n): ";
        cin >> response;
    }
    return response == 'y';
}
