// Question 21: Determine Prime Numbers, Prime Factors, and Composite Numbers
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function Prototypes
void initializePrimes(int[]);
bool checkPrime(int[], int);
void findPrimeFactors(int[], int);
void findComposites(int[], int);

int main()
{
    // Variables
    int primeNumbers[1230];
    int value = 0;

    initializePrimes(primeNumbers);

    cout << "+" << setw(32) << setfill('=') << "" << endl << setfill(' ');
    // Prompt and Validate Input
    do
    {
        cout << "| Please enter an integer value between 2 and 100,000,000: ";
        cin >> value;

        if(cin.fail() || value < 2 || value > 100'000'000)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| Invalid Input! Please enter an integer value between 2 and 100,000,000." << endl;
        } else
            break;
    } while(true);

    cout << "+" << setw(32) << setfill('-') << "" << endl << setfill(' ');
    if(checkPrime(primeNumbers, value))
        cout << "| This value is a prime number." << endl;
    else
    {
        cout << "| This value is not a prime number." << endl;
        findPrimeFactors(primeNumbers, value);
        findComposites(primeNumbers, value);
    }
    cout << "+" << setw(32) << setfill('=') << "" << endl << setfill(' ');

    return 0;
}

// Function Definitions
/**
 * initializePrimes: Populates an array with the first 1230 prime numbers
 * @param int primes[] - Array to be filled with prime numbers
 */
void initializePrimes(int primes[])
{
    bool isPrime = true;
    int index = 1, count = 3;
    primes[0] = 2;
    while(index < 1230)
    {
        if(count % 2 == 0)
            isPrime = false;
        else
        {
            for(int i = 3; i <= static_cast<int>(sqrt(count)); i += 2)
                if(count % i == 0)
                {
                    isPrime = false;
                    break;
                }
        }
        if(isPrime)
        {
            primes[index] = count;
            index++;
        }

        count++;
        isPrime = true;
    }
}

/**
 * checkPrime: Determines if a given value is a prime number
 * @param int primes[] - Array of pre-calculated prime numbers
 * @param int value - The number to check for primality
 * @return bool - If value is prime, return true. Otherwise, return false
 */
bool checkPrime(int primes[], int value)
{
    // If within list -> return true
    // If prime number <= sqrt(value) && value is divisible by prime number -> return false 
    for(int i = 0; i < 1230; i++)
    {
        if(primes[i] == value)
            return true;
        if((primes[i] <= static_cast<int>(sqrt(value)) && value % primes[i] == 0))
            return false;
    }

    return true;
}

/**
 * findPrimeFactors: Lists all prime numbers that divide the given value
 * @param int primes[] - Array of pre-calculated prime numbers
 * @param int value - The composite number to find factors for
 */
void findPrimeFactors(int primes[], int value)
{
    cout << "| Prime Factors for " << value << ": ";
    for(int i = 0; i < 1230; i++)
    {
        if(primes[i] >= value)
            break;
        // If value is divisible by prime
        if(value % primes[i] == 0)
            cout << primes[i] << " ";
    }
    cout << endl;
}

/**
 * findComposites: Expresses a composite number as a product of its prime factors
 * @param int primes[] - Array of pre-calculated prime numbers
 * @param int value - The composite number to factorize
 */
void findComposites(int primes[], int value)
{
    bool firstFactor = true;
    int index = 0;

    cout << "| Product of Prime Numbers for Composite " << value << ": ";
    while(index < 1230) 
    {
        if(value % primes[index] == 0)
        {
            // Make sure format is displayed correctly
            if(firstFactor) 
            {
                cout << primes[index];
                firstFactor = false;
            } else 
                cout << " x " << primes[index];
            
            // Divide the value by the prime factor
            value /= primes[index];
        } else 
            index++;
    }   
    cout << endl;
}