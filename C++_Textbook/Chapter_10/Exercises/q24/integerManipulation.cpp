#include <iostream>
#include <string>
#include <cmath>
#include "integerManipulation.h"

using namespace std;

// Initialize Static Members
int integerManipulation::primeNumbers[1230] = {0};

// Class Function Definitions
/**
 * integerManipulation::reverseNum: Reverses the digit of the num in the class
 */
void integerManipulation::reverseNum()
{
    revNum = 0;
    long long temp = abs(num);
    while(temp > 0)
    {
        revNum = revNum * 10 + temp % 10;
        temp /= 10;
    }
}

/**
 * integerManipulation::classifyDigits: Determines the evens, odds, and zeros digits of the num in the class
 */
void integerManipulation::classifyDigits()
{
    long long temp = abs(num);
    int digit;

    while(temp != 0)
    {
        digit = temp - (temp / 10) * 10;
        temp = temp / 10;

        if(digit % 2 == 0)
        {
            evensCount++;
            if(digit == 0)
                zerosCount++;
        } else
            oddsCount++;
    }
}

/**
 * integerManipulation::sumDigits: Returns the sum of all the digits in the variable num of the class object
 * @return int - The sum of all the digits of num
 */
int integerManipulation::sumDigits()
{
    long long temp = num;
    int sum = 0;
    while(temp > 0)
    {
        sum = sum + temp % 10;
        temp = temp / 10;
    }

    return sum;
}

/**
 * integerManipulation::splitSum: Splits the number into blocks of n-digit numbers and calculates sum of those blocks
 * @param int n - The n-digit's to split the number into
 * @return int - The calculated sum
 */
int integerManipulation::splitSum(int n)
{
    string numStr = to_string(num);
    int sum = 0;

    while(!numStr.empty())
    {
        int digits = n < numStr.size() ? n : numStr.size();
        sum += stoi(numStr.substr(numStr.size() - digits));
        numStr.erase(numStr.size() - digits);
    }

    return sum;
}

/**
 * integerManipulation::initializePrimes: Populates an array with the first 1230 prime numbers
 */
void integerManipulation::initializePrimes()
{
    bool isPrime = true;
    int index = 1, count = 3;

    primeNumbers[0] = 2;
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
            primeNumbers[index] = count;
            index++;
        }

        count++;
        isPrime = true;
    }
}

/**
 * integerManipulation::checkPrime: Determines if a given value is a prime number
 */
bool integerManipulation::checkPrime()
{
    for(int i = 0; i < 1230; i++)
    {
        if(primeNumbers[i] == num)
            return true;
        if((primeNumbers[i] <= static_cast<int>(sqrt(num)) && num % primeNumbers[i] == 0))
            return false;
    }

    return true;
}

/**
 * integerManipulation::findPrimeFactors: Lists all prime numbers that divide the given value
 */
void integerManipulation::findPrimeFactors()
{
    cout << "Prime factors for " << num << ": ";
    for(int i = 0; i < 1230; i++)
    {
        if(primeNumbers[i] >= num)
            break;
        // If value is divisible by prime
        if(num % primeNumbers[i] == 0)
            cout << primeNumbers[i] << " ";
    }
    cout << endl;
}

/**
 * integerManipulation::integerManipulation: Constructor with parameters
 * @param long long n - The variable to intialize num in the class object
 */
integerManipulation::integerManipulation(long long n)
{
    num = n;
    revNum = 0;
    evensCount = 0;
    oddsCount = 0;
    zerosCount = 0;
}