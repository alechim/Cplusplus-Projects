// Example 10-7: Refactored 10-1 v2 Specification and Implementation Files
/**
 * Usage: 
 * - 1st: Compile implementation file `g++ -c clockTypeImp.cpp` to create object code file
 * - 2nd: Compile source code and link files by `g++ testClockClass.cpp clockTypeImp.o -o testClockClass` to create executable code file
 * - 3rd: Run executable code by `.\testClockClass`
 */
#include <iostream>
#include "clockType.h"

using namespace std;

int main()
{
    // Variables
    clockType myClock;
    clockType yourClock;
    int hours;
    int minutes;
    int seconds;

    // Set the time of myClock
    myClock.setTime(5, 4, 30);

    cout << "Line 9: myClock: ";
    myClock.printTime();
    cout << endl;

    cout << "Line 12: yourClock: ";
    yourClock.printTime();
    cout << endl;

    // Set the time of yourClock
    yourClock.setTime(5, 45, 16);

    cout << "Line 16: After setting, yourClock: ";
    yourClock.printTime();
    cout << endl;

    // Compare myClock and yourClock
    if(myClock.equalTime(yourClock))
        cout << "Line 20: Both times are equal." << endl;
    else
        cout << "Line 22: The two times are not equal." << endl;
    
    cout << "Line 23: Enter the hours, minutes, and seconds: ";
    cin >> hours >> minutes >> seconds;
    cout << endl;

    // Set the time of myClock using the value of the variables hours, minutes, and seconds
    myClock.setTime(hours, minutes, seconds);

    cout << "Line 27: New myClock: ";
    myClock.printTime();
    cout << endl;

    myClock.incrementSeconds();

    cout << "Line 31: After incrementing myClock by one second, myClock: ";
    myClock.printTime();
    cout << endl;

    // Retrieve the hours, minutes, and seconds of the object myClock
    myClock.getTime(hours, minutes, seconds);

    // Output the value of hours, minutes, and seconds
    cout << "Line 35: hours = " << hours << ", minutes = " << minutes << ", seconds = " << seconds << endl;

    return 0;
}