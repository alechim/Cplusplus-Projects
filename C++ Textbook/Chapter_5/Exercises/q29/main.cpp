// Question 29: Factorial
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int num = 0;

    // Prompt for Input
    do
    {
        cout << "Enter a number greater than or equal to 1: ";
        cin >> num;
        if(cin.fail() || num < 1)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a number that is greater than or equal to 1." << endl;
        } else
            break;
    } while(true);

    // Calculations and Display Results
    int factorial = 1;
    cout << "Calculating: " << num << "! = ";
    for(int i = 1; i <= num; i++)
    {
        factorial *= i;
        cout << i;
        if(i != num)
            cout << " * ";
    }
    cout << "\nThe factorial of " << num << " is " << factorial << ".\n";

    return 0;
}