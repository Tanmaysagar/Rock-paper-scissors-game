#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

enum Choice { ROCK = 1, PAPER, SCISSORS };

Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3 + 1);
}

string choiceToString(Choice choice) {
    switch (choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return "Unknown";
    }
}

string determineWinner(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    }

    switch (userChoice) {
        case ROCK:
            return (computerChoice == SCISSORS) ? "You win!" : "Computer wins!";
        case PAPER:
            return (computerChoice == ROCK) ? "You win!" : "Computer wins!";
        case SCISSORS:
            return (computerChoice == PAPER) ? "You win!" : "Computer wins!";
        default:
            return "Invalid choice!";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    string playAgain;
    do {
        int userChoice;
        cout << "Enter your choice (1: Rock, 2: Paper, 3: Scissors): ";
        cin >> userChoice;

        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            continue;
        }

        Choice user = static_cast<Choice>(userChoice);
        Choice computer = getComputerChoice();

        cout << "You chose: " << choiceToString(user) << endl;
        cout << "Computer chose: " << choiceToString(computer) << endl;

        cout << determineWinner(user, computer) << endl;

        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;

    } while (playAgain == "yes" || playAgain == "y");

    cout << "Thank you for playing!" << endl;
    return 0;
}
