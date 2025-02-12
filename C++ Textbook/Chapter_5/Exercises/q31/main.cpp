// Question 31: Approximate the value of e (1st Formula)
// Test Program for n = 4, 8, 10, and 12
/**
 * Given Formula:
 * - 2 + 1/2! + 1/3! + ... + 1/n!
 * - Value of e (9th decimal) = 2.718281827
 */
#include <iostream>
#include <iomanip>

using namespace std;

// ***Functions***
// int factorial(int num)
int factorial(int num)
{
    int fact = 1;
    for(int i = 1; i <= num; i++)
        fact *= i;
    return fact;
}

int main()
{
    // Variables
    int num = 0;
    double approx = 2.0;

    // Prompt for Input
    do
    {
        cout << "Enter one of the following numbers: (4, 8, 10, 12): ";
        cin >> num;
        if(cin.fail() || (num != 4 && num != 8 && num != 10 && num != 12))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 4, 8, 10, or 12." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    for(double i = 2.0; i <= num; i++)
        approx += (1.0 / factorial(static_cast<double>(i)));

    // Display Results
    cout << fixed << showpoint << setprecision(9);
    cout << "The value of e to nine decimal places is e = 2.718281827" << endl;
    cout << "The calculated approximate value of e = " << approx << endl;

    return 0;
}