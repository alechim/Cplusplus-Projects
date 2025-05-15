// Question 16: Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Variables
    int num = 0;
    int guess = 0;
    bool isGuessed = false;
    int count = 0;
    int diff = 0;

    // Seed Time
    srand(time(0));
    num = rand() % 100;

    // ==== GAME ====
    while(count != 5)
    {
        // Prompt for Input
        cout << "\n=====\n";
        cout << "| Guess [" << count + 1 << "/" << "5] - ";
        cout << "Enter an integer greater than or equal to 0 and less than 100: ";
        cin >> guess;
        cout << "=====\n";
        // Validation
        if(cin.fail() || guess < 0 || guess >= 100)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Guess Again!" << endl;
            continue;
        }

        diff = abs(num - guess);
        // Increment Count after Validation
        count++;

        // Output Results
        if(diff == 0)
        {
            cout << "You guessed the correct number! You Win!" << endl;
            cout << "=====\n";
            isGuessed = true;
            break;
        } else if(diff >= 50 && guess > num)
            cout << "Your guess is very high. Guess Again!" << endl;
        else if(diff >= 50 && guess < num)
            cout << "Your guess is very low. Guess Again!" << endl;
        else if(diff >= 30 && guess > num)
            cout << "Your guess is high. Guess Again!" << endl;
        else if(diff >= 30 && guess < num)
            cout << "Your guess is low. Guess Again!" << endl;
        else if(diff >= 15 && guess > num)
            cout << "Your guess is moderately high. Guess Again!" << endl;
        else if(diff >= 15 && guess < num)
            cout << "Your guess is moderately low. Guess Again!" << endl;
        else if(guess > num)
            cout << "Your guess is somewhat high. Guess Again!" << endl;
        else if(guess < num)
            cout << "Your guess is somewhat low. Guess Again!" << endl;
    }   // End While

    // Lose Message
    if(!isGuessed)
    {
        cout << "\n=====\n";
        cout << "Sorry, You Lose!" << endl;
        cout << "The correct number was " << num << endl;
        cout << "=====\n";
    }

    return 0;
}