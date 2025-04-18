#include <iostream>
#include "integerManipulation.h"

// Class Function Definitions
/**
 * integerManipulation::setNum: 
 * @param long long n - 
 */
void integerManipulation::setNum(long long n)
{
    num = n;
}

/**
 * integerManipulation::getNum: 
 * @return long long - 
 */
long long integerManipulation::getNum()
{
    return num;
}

/**
 * integerManipulation::reverseNum: 
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
 * integerManipulation::classifyDigits
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
 * integerManipulation::getEvensCount: 
 * @return int - 
 */
int integerManipulation::getEvensCount()
{
    return evensCount;
}

/**
 * integerManipulation::getOddsCount: 
 * @return int - 
 */
int integerManipulation::getOddsCount()
{
    return oddsCount;
}

/**
 * integerManipulation::getZerosCount: 
 * @return int - 
 */
int integerManipulation::getZerosCount()
{
    return zerosCount;
}

/**
 * integerManipulation::sumDigits: 
 * @return int - 
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
 * integerManipulation::integerManipulation: 
 * @param long long n - 
 */
integerManipulation::integerManipulation(long long n)
{
    num = n;
    revNum = 0;
    evensCount = 0;
    oddsCount = 0;
    zerosCount = 0;
}