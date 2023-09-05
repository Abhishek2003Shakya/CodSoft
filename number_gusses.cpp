
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0; // Initialize userGuess
    int attempts = 0;

    cout << "************************** Welcome to the Number Guessing Game **************************" << endl;
    bool playAgain = true; // Use a more descriptive variable name

    while (playAgain) {
        int start;
        cout<<"You want to play Number Guessing Game?"<<endl;
        cout<<"1. Yes"<<endl<<"2. No"<<endl;
        cin>>start;

        if (start != 1) {
            playAgain = false;
            break; // Exit the loop if the user chooses not to play
        }

        // Reset variables for a new game
        attempts = 0;
        randomNumber = rand() % 100 + 1;

        while (userGuess != randomNumber) {
            cout<<"Enter your guess (between 1 and 100): ";
            cin>>userGuess;
            attempts++;

            if (userGuess < 1 || userGuess > 100) {
                cout<<"Please enter a valid guess between 1 and 100."<<endl;
            } else if (userGuess < randomNumber) {
                cout<<"Your guess is low! Try again."<<endl;
            } else if (userGuess > randomNumber) {
                cout<<"Your guess is high! Try again."<<endl;
            } else {
                cout<<"Nice! You guessed the number " <<randomNumber <<" in " <<attempts <<" attempts." <<endl;
                break;
            }
        }

        cout<<"Do you want to play again?"<<endl;
        cout<<"1. Yes"<<endl<<"2. No"<<endl;
        cin>>start;

        if (start != 1) {
            playAgain = false; // Exit the loop if the user chooses not to play again
        }
    }

    return 0;
}
