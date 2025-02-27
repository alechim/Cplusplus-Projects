// Question 32: Greatest Common Divisor
/**
 * Euclid's Algorithm: Recursive approach; gcd(a, b)
 * - Requires a > b
 * - Time Complexity: O(log(min(a, b)))
 */
#include <iostream>

using namespace std;

// ***Function Prototypes***
void promptInput(int& value, const string prompt);
int gcd(int a, int b);

int main()
{
    // Variables
    int num1 = 0;
    int num2 = 0;
    int divisor = 0;

    // Prompt Input
    promptInput(num1, "Enter the first non-zero integer value: ");
    promptInput(num2, "Enter the second non-zero integer value: ");

    // Calculations
    if(num1 == num2)
        divisor = num1;
    else
        divisor = (num1 > num2) ? gcd(num1, num2) : gcd(num2, num1);

    // Display Results
    cout << "The greatest common denominator between " << num1 << " and " << num2 << " is " << divisor << ".\n";

    return 0;
}

// ***Functions***
void promptInput(int& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value == 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero integer value." << endl;
        } else
            break;
    } while (true);
}

int gcd(int a, int b)
{
    // Convert negative values
    a = abs(a);
    b = abs(b);

    // Case: gcd is found
    if(a % b == 0)
        return b;

    // Recursion
    return gcd(b, a % b);
}