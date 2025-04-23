#include <iostream>
#include "wkp4Def.hpp"

using namespace std;

/**
 * myClass::myClass: Default constructor
 */
myClass::myClass() 
{
    num1 = 0;
    num2 = 0;
}

/**
 * myClass::myClass: Constructor with parameters
 * - Postcondition: num1 = x & num2 = y
 * @param int x -
 * @param int y - 
 */
myClass::myClass(int x, int y)
{
    num1 = x;
    num2 = y;
}

/**
 * myClass::print() const: Function to output the values of num1 and num2
 */
void myClass::print() const
{
    cout << "First Number: " << num1 << endl;
    cout << "Second Number: " << num2 << endl;
}

/**
 * myClass::set: Function to set the values of num1 and num2.
 * @param int x - The value to be stored in num1
 * @param int y - The value to be stored in num2
 * Postcondition: num1 = x & num2 = y
 */
void myClass::set(int x, int y)
{
    num1 = x;
    num2 = y;
}

/**
 * myClass::compute: Function to return a value as follow:
 * - If x > 0, return (num1 + num2) / x;
 * - Otherwise, return num1 - num2 + x;
 * @param int x - 
 * @return int - 
 */
int myClass::compute(int x)
{
    if (x > 0)
        return (num1 + num2) / x;
    else if (x < 0)
        return num1 - num2 + x;
        
    return x;
}

/**
 * myClass::equal: Function to determine if both numbers are equal to each other
 * @return bool - 1: if num1 == num2, else 0
 */
bool myClass::equal()
{
    return num1 == num2;
}