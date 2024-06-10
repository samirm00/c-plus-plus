#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GuessingGame 
{
public:
    GuessingGame() 
    {
        srand(time(0));
    }

    void startGame() 
    {
        do
        {
            int randomNumber = generateRandomNumber();
            cout << "Welcome to the guessing game!" << endl;
            cout << "I have selected a number between 1 and 100." << endl;
            cout << "Try to guess the number." << endl;
            cout << "I will tell you if you are too high or too low." << endl;
            cout << "Good luck!" << endl;

            play(randomNumber);

        } while (askPlayAgain());
    }

private:
    int generateRandomNumber() 
    {
        return rand() % 100 + 1;
    }

    int getUserGuess() 
    {
        int userGuess;
        cout << "Enter your guess: ";
        cin >> userGuess;

        while (cin.fail() || userGuess < 1 || userGuess > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 100: ";
            cin >> userGuess;
        }

        return userGuess;
    }

    void play(int randomNumber) 
    {
        bool correctGuess = false;

        while (!correctGuess) 
        {
            int userGuess = getUserGuess();
            correctGuess = checkGuess(userGuess, randomNumber);
        }
    }

    bool checkGuess(int userGuess, int randomNumber) 
    {
        if (userGuess == randomNumber) 
        {
            cout << "Congratulations! You guessed the correct number!" << endl;
            return true;
        } 
        else if (userGuess < randomNumber) 
        {
            cout << "Too low! Try again." << endl;
        } 
        else 
        {
            cout << "Too high! Try again." << endl;
        }
        return false;
    }

    bool askPlayAgain() 
    {
        char response;
        cout << "Do you want to play again? (y/n): ";
        cin >> response;

        while (cin.fail() || (response != 'y' && response != 'n')) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> response;
        }

        return response == 'y';
    }
};

int main() 
{
    GuessingGame game;
    game.startGame();

    return 0;
}
