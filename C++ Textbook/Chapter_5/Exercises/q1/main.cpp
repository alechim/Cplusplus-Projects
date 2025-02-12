// Question 1: Sum of Individual Digits
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int num = 0;
    int sum = 0;
    int tmp = 0;
    bool isNegative = false;

    do
    {
        cout << "Enter an integer value: ";
        cin >> num;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else
            break;
    } while(true);
    
    if(num < 0)
    {
        isNegative = true;
        num *= -1;
    }

    tmp = num;
    // Calculation
    do
    {
        sum = sum + tmp % 10;
        tmp = tmp / 10;
    } while(tmp > 0);
    
    // Display Results
    cout << "The sum of the individual digits of the number "; 
    if(isNegative)
        cout << "-";
    cout << num << " is ";
    if(isNegative)
        cout << "-";
    cout << sum << endl;

    return 0;
}