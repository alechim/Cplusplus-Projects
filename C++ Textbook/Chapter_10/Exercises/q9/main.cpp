// Question 9: Refactored clockType Class Program with Inline Functions
#include <iostream>
#include "clockType.h"

using namespace std;

int main() 
{
    cout << "===== ClockType Class Demonstration =====" << endl << endl;
    
    // Test constructor and printTime
    cout << "Testing constructor and printTime:" << endl;
    clockType myClock(10, 25, 30);
    cout << "Clock initialized to 10:25:30 - Current time: ";
    myClock.printTime();
    cout << endl << endl;
    
    // Test setTime and getTime
    cout << "Testing setTime and getTime:" << endl;
    myClock.setTime(14, 45, 15);
    int hours, minutes, seconds;
    myClock.getTime(hours, minutes, seconds);
    cout << "After setTime(14, 45, 15), getTime returns: " << hours << ":" << minutes << ":" << seconds << endl;
    cout << "Current time: ";
    myClock.printTime();
    cout << endl << endl;
    
    // Test increment functions
    cout << "Testing increment functions:" << endl;
    cout << "Original time: ";
    myClock.printTime();
    cout << endl;
    
    myClock.incrementSeconds();
    cout << "After incrementSeconds(): ";
    myClock.printTime();
    cout << endl;
    
    myClock.incrementMinutes();
    cout << "After incrementMinutes(): ";
    myClock.printTime();
    cout << endl;
    
    myClock.incrementHours();
    cout << "After incrementHours(): ";
    myClock.printTime();
    cout << endl << endl;
    
    // Test time comparison
    cout << "Testing equality comparison:" << endl;
    clockType clock1(12, 30, 45);
    clockType clock2(12, 30, 45);
    clockType clock3(9, 15, 0);
    
    cout << "Clock1: ";
    clock1.printTime();
    cout << endl;
    
    cout << "Clock2: ";
    clock2.printTime();
    cout << endl;
    
    cout << "Clock3: ";
    clock3.printTime();
    cout << endl;
    
    cout << "Clock1 equals Clock2: " << (clock1.equalTime(clock2) ? "Yes" : "No") << endl;
    cout << "Clock1 equals Clock3: " << (clock1.equalTime(clock3) ? "Yes" : "No") << endl << endl;
    
    // Test time calculations
    cout << "Testing time calculations:" << endl;
    clockType dayClock(10, 15, 30);
    cout << "For time ";
    dayClock.printTime();
    cout << ":" << endl;
    cout << "Elapsed time today: " << dayClock.elapsedTime() << " seconds" << endl;
    cout << "Remaining time today: " << dayClock.remainingTime() << " seconds" << endl << endl;
    
    // Test difference between clocks
    cout << "Testing time difference:" << endl;
    clockType firstClock(14, 30, 15);
    clockType secondClock(10, 20, 5);
    
    cout << "Time 1: ";
    firstClock.printTime();
    cout << endl;
    
    cout << "Time 2: ";
    secondClock.printTime();
    cout << endl;
    
    cout << "Difference between times (h:m:s): ";
    firstClock.differenceTime(secondClock);
    cout << endl;
    
    // Test setter functions with overflow
    cout << "Testing setter functions with overflow:" << endl;
    clockType overflowClock(0, 0, 0);
    cout << "Initial time: ";
    overflowClock.printTime();
    cout << endl;
    
    overflowClock.setSeconds(125);  // 2 minutes and 5 seconds
    cout << "After setSeconds(125): ";
    overflowClock.printTime();
    cout << endl;
    
    overflowClock.setMinutes(65);   // 1 hour and 5 minutes
    cout << "After setMinutes(65): ";
    overflowClock.printTime();
    cout << endl;
    
    overflowClock.setHours(25);     // 1 hour (wrapped around 24)
    cout << "After setHours(25): ";
    overflowClock.printTime();
    cout << endl;
    
    return 0;
}