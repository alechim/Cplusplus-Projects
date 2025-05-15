// Question 11: Refactored Fibonacci Program
// - Include Input Validation
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int previous1 = 0;
    int previous2 = 0;
    int current = 0;
    int counter = 0;
    int nthFibonacci = 0;

    // firstNum <= secondNum && both are non-negative
    do
    {
        cout << "Enter the first two Fibonacci numbers: ";
        cin >> previous1 >> previous2;
        cout << endl;
        if(cin.fail() || previous1 > previous2 || previous1 < 0 || previous2 < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two positive integer values where the first value is less than the second one." << endl;
        } else
            break;
    } while(true);
    cout << "The first two Fibonacci numbers are " << previous1 << " and " << previous2 << endl;
    
    // Valid value for nthFibonacci position
    do
    {
        cout << "Enter the position of the desired Fibonacci number: ";;
        cin >> nthFibonacci;    
        cout << endl;
        if(cin.fail() || nthFibonacci <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero integer value." << endl;
        } else
            break;
    } while(true);

    if(nthFibonacci == 1)
        current = previous1;
    else if(nthFibonacci == 2)
        current = previous2;
    else
    {
        counter = 3;
        while(counter <= nthFibonacci)
        {
            current = previous2 + previous1;
            previous1 = previous2;
            previous2 = current;
            counter++;
        }   // End While
    }   // End Else

    cout << "The Fibnonacci number at position " << nthFibonacci << " is " << current << endl;

    return 0;
}