/**
 * Alec Him, 2001543593, CS135 1009, Lab 8
 * Description: Exponential Function
 * Input: Base Number and Exponent Number
 * Output: Result of Exponential Calculation
 */
#include <iostream>

using namespace std;

// Function Prototypes
double calc(int, int);

int main()
{
    // Variables
    int base = 0;
    int exp = 0;
    double sum = 0.0;

    // Prompt for Input
    do
    {
        cout << "Base: ";
        cin >> base;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Non-integer number detected - Please try again." << endl;
        } else
            break;
    } while(true);

    do
    {
        cout << "Exponent: ";
        cin >> exp;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Non-integer number detected - Please try again." << endl;
        } else
            break;
    } while(true);

    sum = calc(base, exp);
    cout << base << "^" << exp << " is " << sum << endl;

    return 0;
}

// Function Definitions
double calc(int baseCalc, int expCalc)
{
    double total = 1.0;
    
    if(expCalc == 0)
        total = 1;
    else 
    {
        for(int i = 0; i < abs(expCalc); i++)
            total *= baseCalc;
        if(expCalc < 0)
            total = 1 / total;    
    }

    return total;
}