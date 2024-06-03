#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class RockPaperScissors 
{
public:
    // Constructor
    RockPaperScissors() 
    {
        srand(static_cast<unsigned int>(time(0)));
    }

    void playGame() 
    {
        do 
        {
            displayMenu();
            int userChoice = getUserChoice();
            int computerChoice = getComputerChoice();
            displayChoice(userChoice, true);
            displayChoice(computerChoice, false);
            determineWinner(userChoice, computerChoice);
        } while (playAgain());
    }

private:
    // Constants for choices
    static const int ROCK = 1;
    static const int PAPER = 2;
    static const int SCISSORS = 3;

    void displayMenu() const 
    {
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "Enter your choice: ";
    }

    int getUserChoice() const 
    {
        int choice;
        cin >> choice;
        while (choice < ROCK || choice > SCISSORS) 
        {
            cout << "Invalid choice. Enter 1-3: ";
            cin >> choice;
        }
        return choice;
    }

    int getComputerChoice() const 
    {
        return rand() % 3 + 1;
    }

    void displayChoice(int choice, bool isUser) const {
        string player = isUser ? "You" : "Computer";
        switch (choice) {
            case ROCK:
                cout << player << " chose rock." << endl;
                break;
            case PAPER:
                cout << player << " chose paper." << endl;
                break;
            case SCISSORS:
                cout << player << " chose scissors." << endl;
                break;
            default:
                break;
        }
    }

    void determineWinner(int userChoice, int computerChoice) const 
    {
        bool userWin = ((userChoice == ROCK && computerChoice == SCISSORS) ||
         (userChoice == PAPER && computerChoice == ROCK) ||
         (userChoice == SCISSORS && computerChoice == PAPER));
                   
        if (userChoice == computerChoice) 
        {
            cout << "It's a tie!" << endl;
        } 
        else if (userWin) 
        {
            cout << "You win!" << endl;
        } 
        else 
        {
            cout << "You lose!" << endl;
        }
    }

    bool playAgain() const 
    {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return choice == 'y' || choice == 'Y';
    }
};

int main() 
{
    RockPaperScissors game;
    game.playGame();
    return 0;
}
