#include <iostream>
#include "illustrate.h"

using namespace std;

int illustrate::count = 0;
int illustrate::y = 0;

/**
 * illustrate::print const: 
 */
void illustrate::print() const
{
    cout << "x = " << x << ", y = " << y << ", count = " << count << endl;
}

/**
 * illustrate::setX: 
 * @param int a - 
 */
void illustrate::setX(int a)
{
    x = a;
}

/**
 * illustrate::incrementY: 
 */
void illustrate::incrementY()
{
    y++;
}

/**
 * illustrate::illustrate: 
 * @param int a - 
 */
illustrate::illustrate(int a)
{
    x = a;
}