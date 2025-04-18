#include <iostream>
#include <ctime>
#include "die.h"

using namespace std;

// Class Function Definitions
/**
 * die::die: 
 */
die::die()
{
    num = 1;
    srand(time(0));
}

/**
 * die::roll: 
 */
void die::roll()
{
    num = rand() % 6 + 1;
}

/**
 * die::getNum const: 
 */
int die::getNum() const
{
    return num;
}