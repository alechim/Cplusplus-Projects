// Example 6-4: Dice Rolling
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ***Function Prototypes***
int rollDice(int num);

int main()
{
    cout << "The number of times the dice are rolled to get the sum 10 = " << rollDice(10) << endl;
    cout << "The number of times the dice are rolled to get the sum 6 = " << rollDice(6) << endl;

    return 0;
}

// ***Functions***
int rollDice(int num)
{
    // Variables
    int die1 = 0;
    int die2 = 0;
    int sum = 0;
    int rollCount = 0;

    srand(time(0));

    do {
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        sum = die1 + die2;
        rollCount++;
    } while(sum != num);

    return rollCount;
}