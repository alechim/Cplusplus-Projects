// Example 10-9: Refactored Example 6-4 using Specification and Implementation Files
/** 
 * Usage: 
 * - 1st: Object Code File `g++ -c dieImp.cpp`
 * - 2nd: Executable Code File `g++ ex9.cpp dieImp.o -o ex9`
 * - 3rd: Run executable `.\ex9`
 */
#include <iostream>
#include "die.h"

using namespace std;

int main()
{
    die die1;
    die die2;

    cout << "Line 8: die1: " << die1.getNum() << endl;
    cout << "Line 9: die2: " << die2.getNum() << endl;

    die1.roll();
    cout << "Line 11: After rolling die1: " << die1.getNum() << endl;
    
    die2.roll();
    cout << "Line 13: After rolling die2: " << die2.getNum() << endl;

    cout << "Line 14: The sum of the numbers rolled by the dice is: " << die1.getNum() + die2.getNum() << endl;

    die1.roll();
    die2.roll();

    cout << "Line 17: After again rolling, the sum of the numbers rolled is: " << die1.getNum() + die2.getNum() << endl;

    return 0;
}