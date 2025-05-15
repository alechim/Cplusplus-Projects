// Example 10-11: Multi-file Integer Manipulation
/** 
 * Usage: 
 * - 1st: Object Code File `g++ -c integerManipulationImp.cpp`
 * - 2nd: Executable Code File `g++ ex11.cpp integerManipulationImp.o -o ex11`
 * - 3rd: Run executable `.\ex11`
 */
#include <iostream>
#include "integerManipulation.h"

using namespace std;

int main()
{
    // Variables
    integerManipulation number;
    long long num;

    // Prompt for Input
    cout << "Enter an integer: ";
    cin >> num;
    cout << endl;

    number.setNum(num);
    number.classifyDigits();

    cout << number.getNum() << "------" << endl;
    cout << "The number of even digits: " << number.getEvensCount() << endl;
    cout << "The number of zeros: " << number.getZerosCount() << endl;
    cout << "The number of odd digits: " << number.getOddsCount() << endl;
}