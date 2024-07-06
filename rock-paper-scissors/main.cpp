#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Game
{
    public:
    static void startGame()
    {
        srand(static_cast<unsigned int>(time(0)));
        do
        {
            int userChoice = getUserChoice();
            int computerChoice = getComputerChoice();
            displayChoices(userChoice, computerChoice);
            determineWinner(userChoice, computerChoice);
        } while (playAgain());
    }

    private:
    static int getUserChoice()
    {
        cout << "Enter your choice: \n1 for Rock, \n2 for Paper, \n3 for Scissors" << endl;
        int choice;
        while (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a valid choice: \n1 for Rock, \n2 for Paper, \n3 for Scissors" << endl;
        }
        return choice;
    }

    static int getComputerChoice()
    {
        return rand() % 3 + 1;
    }

    static void displayChoices(int userChoice, int computerChoice)
    {
        string choices[] = {"Rock", "Paper", "Scissors"};
        cout << "You chose     : " << choices[userChoice - 1] << endl;
        cout << "Computer chose: " << choices[computerChoice - 1] << endl;
    }

    static void determineWinner(int userChoice, int computerChoice)
    {
        if (userChoice == computerChoice)
        {
            cout << "It's a tie!" << endl;
        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                (userChoice == 2 && computerChoice == 1) ||
                (userChoice == 3 && computerChoice == 2))
        {
            cout << "You win!" << endl;
        }
        else
        {
            cout << "You lose!" << endl;
        }
    }

    static bool playAgain()
    {
        cout << "Do you want to play again? \n1 for Yes, \n2 for No" << endl;
        int choice;
        while (!(cin >> choice) || choice < 1 || choice > 2)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a valid choice: \n1 for Yes, \n2 for No" << endl;
        }
        return choice == 1;
    }
};

int main()
{
    Game::startGame();
    return 0;
}
