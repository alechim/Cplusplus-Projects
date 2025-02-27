// Example 6-5: Fibonacci Number
#include <iostream>

using namespace std;

// ***Function Prototypes***
int nthFibonacciNum(int first, int second, int position);

int main()
{
    // Variables
    int firstFibonacciNum = 0;
    int secondFibonacciNum = 0;
    int nthFibonacci = 0;

    cout << "Enter the first two Fibonacci numbers: ";
    cin >> firstFibonacciNum >> secondFibonacciNum;
    cout << endl;
    cout << "The first two Fibonacci numbers are " << firstFibonacciNum << " and " << secondFibonacciNum << endl;

    cout << "Enter the positiong of the desired Fibonacci numbers: ";
    cin >> nthFibonacci;
    cout << endl;
    cout << "The Fibonacci number at position " << nthFibonacci << " is " << nthFibonacciNum(firstFibonacciNum, secondFibonacciNum, nthFibonacci) << endl;

    return 0;
}

// ***Functions***
int nthFibonacciNum(int first, int second, int nthFibNum)
{
    // Variables
    int current = 0;
    int counter = 0;

    switch(nthFibNum)
    {
        case 1:
            current = first;
            break;
        case 2:
            current = second;
            break;
        default:
            counter = 3;
            while(counter <= nthFibNum)
            {
                current = second + first;
                first = second;
                second = current;
                counter++;
            }
            break;
    }

    return current;
}