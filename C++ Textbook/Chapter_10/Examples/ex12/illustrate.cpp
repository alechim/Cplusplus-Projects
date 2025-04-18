#include <iostream>
#include "illustrate.h"

using namespace std;

int illustrate::count = 0;
int illustrate::y = 0;

/**
 * illustrate::print const: Displays the variables of the class
 */
void illustrate::print() const
{
    cout << "x = " << x << ", y = " << y << ", count = " << count << endl;
}

/**
 * illustrate::setX: Updates the private instance variable of the class with the passed parameter
 * @param int a - The variable to update x in the class object
 */
void illustrate::setX(int a)
{
    x = a;
}

/**
 * illustrate::incrementY: Increments the static private class variable y
 */
void illustrate::incrementY()
{
    y++;
}

/**
 * illustrate::illustrate: Constructor with parameters
 * @param int a - The variable to initialize x in the class object
 */
illustrate::illustrate(int a)
{
    x = a;
}