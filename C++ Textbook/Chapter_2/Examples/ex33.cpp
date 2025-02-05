// Example 2-33: Convert Change
#include <iostream>

using namespace std;

// Globals
const int HALF_DOLLARS = 50;
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

int main()
{
    // Variables
    int change = 0;
    int halfDollar = 0;
    int quarter = 0;
    int dime = 0;
    int nickel = 0;

    while(true)
    {
        cout << "Enter change in cents: ";
        cin >> change;

        if(cin.fail() || change <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero integer value." << endl;
        } else
        {
            break;
        }
    }
    cout << "The change " << change << " converts to:" << endl;
    
    // Calculations
    halfDollar = change / HALF_DOLLARS;
    change = change % HALF_DOLLARS;
    quarter = change / QUARTER;
    change = change % QUARTER;
    dime = change / DIME;
    change = change % DIME;
    nickel = change / NICKEL;
    change = change % NICKEL;

    cout << halfDollar << " half dollars, " << quarter << " quarters, " << dime << " dimes, " << nickel << " nickels, and " << change << " pennies." << endl;

    return 0;
}