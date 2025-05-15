// Question 7: Prime Numbers and Twin Primes in Range
/**
 * Time Complexity: O(n*sqrt(n))
 * Inputs: 
 * - Lower Bound and Outer Bound less than 1,000,000,000
 * Outputs:
 * - Sum of all the prime numbers between two integers.
 * - Output all the twin primes (difference between two primes is 2 or -2)
 * - Output # of twin primes between two integers.
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int num1 = 0;
    int num2 = 0;
    bool isPrime = true;
    int sumPrime = 0;
    int twinCount = 0;
    int lastPrime = 0;

    // Prompt for Input
    do
    {
        cout << "Enter two positive integer values with num1 < num2 and both numbers are less than 1,000,000,000: ";
        cin >> num1 >> num2;
        if(cin.fail() || num1 < 0 || num2 < 0 || num2 <= num1 || num1 > 1'000'000'000 || num2 > 1'000'000'000)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two positive integer values with num1 < num2 and both numbers are less than 1,000,000,000." << endl;
        } else
            break;
    } while(true);
    cout << endl;

    // Calculations
    for(int i = num1; i <= num2; i++)
    {
        if (i == 0 || i == 1) 
            isPrime = false; 
        else if(i == 2)
        {
            sumPrime += i;
            lastPrime = i;
            isPrime = true;
        }
        else if (i % 2 == 0)
            isPrime = false;  
        else
        {
            for(int j = 3; j <= static_cast<int>(sqrt(i)); j += 2)
            {
                if(i % j == 0)
                {   
                    isPrime = false;
                    break;
                }
            }
            if(isPrime)
            {
                sumPrime += i;
                if(i - 2 == lastPrime)
                {
                    twinCount++;
                    if(twinCount == 1)
                    {
                        cout << "==========\n";
                        cout << "The existing twin primes are: ";
                    } else
                        cout << ", ";
                    cout << "(" << lastPrime << ", " << i << ")";
                }
                lastPrime = i;
            }
        }

        // Reinitialize boolean
        isPrime = true;
    }
    cout << "\n==========\n";
    cout << "There is " << twinCount << (twinCount == 1 ? " twin prime " : " twin primes ") << "between the range of " << num1 << " - " << num2 << ".\n";
    cout << "The sum of all primes is " << sumPrime << ".\n";
    cout << "==========\n\n";

    return 0;
}