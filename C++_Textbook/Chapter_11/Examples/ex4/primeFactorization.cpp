#include <iostream>
#include "primeFactorization.h"

using namespace std;

void primeFactorization::factorization()
{
    bool isPrime = true;
    long long temp = integerManipulation::getNum();

    // Determine whether the number is prime
    for(int i = 0; i < 125000; i++)
    {
        if(first125000Primes[i] == temp)
            break;
        if((first125000Primes[i] * first125000Primes[i] <= temp && temp % first125000Primes[i] == 0))
            isPrime = false;
    }

    cout << temp << " is" << (isPrime ? " " : " not ") << "a prime number. Its factorization is:" << endl;

    // Find all prime factors
    bool firstFactor = true;
    cout << temp << " = ";
    for(int i = 0; i < 125000 && first125000Primes[i] * first125000Primes[i] <= temp; i++)
    {
        while(temp % first125000Primes[i] == 0)
        {
            if(!firstFactor)
                cout << " * ";
            cout << first125000Primes[i];
            firstFactor = false;
            temp = temp / first125000Primes[i];
        }
    }

    // If temp is greater than 1, it is a prime factor itself
    if(temp > 1)
    {
        if(!firstFactor)
            cout << " * ";
        cout << temp;
    }
    
    cout << endl;
}

primeFactorization::primeFactorization(long long n): integerManipulation(n)
{
    first125000PrimeNum(first125000Primes, 125000);
}

void primeFactorization::first125000PrimeNum(long long list[], int length)
{
    bool isPrime = true;
    int index = 1, count = 3;

    list[0] = 2;
    while(index < length)
    {
        if(count % 2 == 0)
            isPrime = false;
        else
        {
            for(int i = 3; i * i <= count; i += 2)
                if(count % i == 0)
                {
                    isPrime = false;
                    break;
                }
        }
        if(isPrime)
        {
            list[index] = count;
            index++;
        }

        count++;
        isPrime = true;
    }
}