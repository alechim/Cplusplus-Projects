// Example 6-1: Predefined Functions
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int num = 0;
    double firstNum = 0.0;
    double secondNum = 0.0;
    char ch = 'T';

    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "Line 12: Is " << ch << " a lowercase letter? " << islower(ch) << endl;
    cout << "Line 13: Uppercase a is " << static_cast<char>(toupper('a')) << endl;
    
    cout << "Line 14: 4.5 to the power 6.0 = " << pow(4.5, 6.0) << endl;
    
    cout << "Line 15: Enter two decimal numbers: "; 
    cin >> firstNum >> secondNum;
    cout << endl;

    cout << "Line 18: " << firstNum << " to the power of " << secondNum << " = " << pow(firstNum, secondNum) << endl;

    cout << "Line 19: 5.0 to the power of 4 = " << pow(5.0, 4) << endl;

    firstNum = firstNum + pow(3.5, 7.2);
    cout << "Line 21: firstNum = " << firstNum << endl;

    num = -32;
    cout << "Line 23: Absolute value of " << num << " = " << abs(num) << endl;

    cout << "Line 24: Square root of 28.00 = " << sqrt(28.00) << endl;

    return 0;
}