#ifndef PRIME_FACTORIZATION_H
#define PRIME_FACTORIZATION_H

#include "integerManipulation.h"

class primeFactorization: public integerManipulation
{
    public:
        void factorization();
        // Function to output the prime factorization of num.
        // Postcondition: Prime factorization of num is printed.

        primeFactorization(long long n = 0);
        // Constructor with a default parameter.
        // The instance variables of the base class are set according to the parameters and the array first125000Primes is created.
        // Postcondition: num = n; revNum = 0; evensCount = 0; oddsCount = 0; zerosCount = 0; first125000Primes = first 125000 prime numbers.

    private:
        long long first125000Primes[125000];
        void first125000PrimeNum(long long list[], int length);
        // Function to determine and store the first 125000 prime integers.
        // Postcondition: The first 125000 prime numbers are determined and stored in the array first125000Primes.
};

#endif