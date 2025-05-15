#include <iostream>
#include <ctime>
#include "die.h"

using namespace std;

// Class Function Definitions
/**
 * die::die: Default Constructor
 * - Seeds the random number generator
 */
die::die()
{
    num = 1;
    srand(time(0));
}

/**
 * die::roll: Generates a number between 1-6
 */
void die::roll()
{
    num = rand() % 6 + 1;
}