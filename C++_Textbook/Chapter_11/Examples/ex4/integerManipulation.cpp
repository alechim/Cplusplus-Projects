#include <iostream>
#include "integerManipulation.h"

// Class Function Definitions
/**
 * integerManipulation::setNum: Updates the variable of the class with the passed parameter
 * @param long long n - The variable to update num in the class object
 */
void integerManipulation::setNum(long long n)
{
    num = n;
}

/**
 * integerManipulation::getNum: Returns the variable num of the class
 * @return long long - the num of the class object
 */
long long integerManipulation::getNum()
{
    return num;
}

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
 * integerManipulation::getEvensCount: Returns the variable evensCount of the class object
 * @return int - private instance variable, evensCount
 */
int integerManipulation::getEvensCount()
{
    return evensCount;
}

/**
 * integerManipulation::getOddsCount: Returns the variable oddsCount of the class object
 * @return int - private instance variable, oddsCount
 */
int integerManipulation::getOddsCount()
{
    return oddsCount;
}

/**
 * integerManipulation::getZerosCount: Returns the variable zerosCount of the class object
 * @return int - private instance variable, zerosCount
 */
int integerManipulation::getZerosCount()
{
    return zerosCount;
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