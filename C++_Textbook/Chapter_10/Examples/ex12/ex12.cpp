// Example 10-12: Multi-file Static Variable Illustration
/** 
 * Usage: 
 * - 1st: Object Code File `g++ -c illustrate.cpp`
 * - 2nd: Executable Code File `g++ ex12.cpp illustrate.o -o ex12`
 * - 3rd: Run executable `.\ex12`
 */
#include <iostream>
#include "illustrate.h"

using namespace std;

int main()
{
    illustrate illusObject1(3);
    illustrate illusObject2(5);

    illustrate::incrementY();
    illustrate::count++;
    illusObject1.print();
    illusObject2.print();

    cout << "Line 12: ***Increment y using illusObject1***" << endl;

    illusObject1.incrementY();
    illusObject1.setX(8);
    illusObject1.print();
    illusObject2.print();

    cout << "Line 17: ***Increment y using illusObject2***" << endl;

    illusObject2.incrementY();
    illusObject2.setX(23);
    illusObject1.print();
    illusObject2.print();

    return 0;
}