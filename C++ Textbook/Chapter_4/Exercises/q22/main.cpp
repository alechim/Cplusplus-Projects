// Question 22: Determine Prime Numbers 
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int primeIntegers[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int num = 0;
    bool isPrime = true;
    bool firstSeen = false; 

    // Prompt for Input
    do
    {
        cout << "Enter a positive integer between 1-1000: ";
        cin >> num;
        if(cin.fail() || num < 1 || num > 1000)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value between 1 and 1000." << endl;
        } else
            break;
    } while(true);
    
    // Calculation
    for(int i = 0; i < 11; i++)
    {
        // Already one of the 11 prime integers stored in array
        if(num == primeIntegers[i])
            break;

        // If not divisible by all 11 prime numbers -> prime
        if(num % primeIntegers[i] != 0)
            continue;       // Next iteration
        else
        {
            // Makes sure output happens once and boolean value changes once
            if(!firstSeen)
            {
                firstSeen = true;
                isPrime = false;
                cout << "The number " << num << " is not a prime number and can be divided by: ";
            }
            cout << primeIntegers[i] << " ";
        }
    }
    if(isPrime)
        cout << "The number " << num << " is a prime number.";
    cout << endl;

    return 0;
}