// Question 24: Refactored Example 10-11
// - Added a new class function splitSum which divides into blocks and sums the values
// - Used Exercise 8-21 components to check for primes and find prime factorizations
#include <iostream>
#include <cmath>
#include <string>
#include "integerManipulation.h"

using namespace std;

int main()
{
    // Variables
    integerManipulation number;
    long long num;

    number.initializePrimes();

    // Prompt for Input - Integer Value
    do
    {
        cout << "Enter an integer: ";
        cin >> num;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else
            break;
    } while(true);

    number.setNum(num);
    number.classifyDigits();

    cout << "------" << endl;
    cout << "The number of even digits: " << number.getEvensCount() << endl;
    cout << "The number of zeros: " << number.getZerosCount() << endl;
    cout << "The number of odd digits: " << number.getOddsCount() << endl;

    // Prompt for Input - Split Sum Digits
    int split = 0;
    do
    {
        cout << "Enter the number of digits to split into blocks: ";
        cin >> split;
        if(cin.fail() || split <= 0 || split > to_string(num).size())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero integer value and less than or equal to " << to_string(num).size() << "." << endl;
        } else
            break;
    } while(true);

    cout << "The sum of " << split << "-digit blocks: " << number.splitSum(split) << endl;
    cout << "------" << endl;
    cout << "The number " << num << " is " << (!number.checkPrime() ? "not " : "") << "prime." << endl;
    number.findPrimeFactors();

    return 0;
}