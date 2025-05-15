// Example 5-A: Fibonacci Number
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

    cout << "Enter the first two Fibonacci numbers: ";
    cin >> previous1 >> previous2;
    cout << endl;
    cout << "The first two Fibonacci numbers are " << previous1 << " and " << previous2 << endl;
    
    cout << "Enter the position of the desired Fibonacci number: ";;
    cin >> nthFibonacci;    
    cout << endl;

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