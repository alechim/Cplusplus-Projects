// Question 6: Determine Prime Number (Input)
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int input = 0;
    bool isPrime = true;

    // Prompt for Input
    do
    {
        cout << "Enter a positive integer: ";
        cin >> input;
        if(cin.fail() || input < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else
            break;
    } while(true);

    // Calculations
    if (input == 1) 
        isPrime = false; 
    else if (input == 2)
        isPrime = true;   
    else if (input % 2 == 0)
        isPrime = false;  
    else
    {
        int upperBound = static_cast<int>(sqrt(input)); 
        for (int i = 3; i <= upperBound; i += 2)  
        {
            if (input % i == 0)
            {
                isPrime = false;
                break;  // Exit early if we find a divisor
            }
        }
    }

    // Display Results
    if (isPrime)
        cout << input << " is a prime number." << endl;
    else
        cout << input << " is not a prime number." << endl;

    return 0;
}