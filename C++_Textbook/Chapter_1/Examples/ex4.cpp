// Example 1-4: Random Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int guess = 0;
    // Seed and Generate Random Number
    srand(time(0));
    int randomNumber = rand() % 101;    // 0 to 100

    while(true)
    {   
        cout << "[0-100] Guess a number: ";
        cin >> guess;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        }

        if(guess == randomNumber)
        {
            cout << "You Guessed the Correct Number!" << endl;
            break;
        } else if(guess < randomNumber)
        {
            cout << "Your Guess is Lower than the Number. Guess Again!" << endl;
        } else if(guess > randomNumber)
        {
            cout << "Your Guess is Higher than the Number. Guess Again!" << endl;
        }
    }

    return 0;
}