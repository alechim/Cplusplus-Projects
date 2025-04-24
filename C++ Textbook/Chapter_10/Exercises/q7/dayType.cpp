#include <iostream>
#include <iomanip>
#include "dayType.h"

using namespace std;

/**
 * dayType::printDay: Outputs the previous day, the current day, and the next day
 */
void dayType::printDay()
{
    cout << "+" << setw(25) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Previous Day: " << getPreviousDay() << endl;
    cout << left << setw(16) << "| Current Day: " << getDay() << endl;
    cout << left << setw(16) << "| Next Day: " << getNextDay() << endl;
    cout << "+" << setw(25) << setfill('=') << "" << "+" << endl << setfill(' ');
}

/**
 * dayType::addDays: Adds the number of days to the current object and sets the index to it
 * @param int value - The number of days passed the current one
 */
void dayType::addDays(int value)
{
    // Calculate the new position using modulo arithmetic
    int newIndex = (index + value) % 7;
    
    // Handle negative results by wrapping around
    if (newIndex < 0)
        newIndex += 7;
        
    index = newIndex;
}

/**
 * +==== Class Setters and Getters ====+
 */
void dayType::setDay(string day)
{
    if(day == "Sun" || day == "Sunday")
        index = 0;
    else if(day == "Mon" || day == "Monday")
        index = 1;
    else if(day == "Tues" || day == "Tuesday")
        index = 2;
    else if(day == "Wed" || day == "Wednesday")
        index = 3;
    else if(day == "Thurs" || day == "Thursday")
        index = 4;
    else if(day == "Fri" || day == "Friday")
        index = 5;
    else if(day == "Sat" || day == "Saturday")
        index = 6;
    else
        cout << "Invalid Choice." << endl;
}
string dayType::getDay() { return days[index]; }
string dayType::getPreviousDay() 
{ 
    int tmpIndex = ((index - 1 < 0) ? 6 : index - 1); 
    return days[tmpIndex];
}
string dayType::getNextDay() 
{ 
    int tmpIndex = ((index + 1 > 6) ? 0 : index + 1);
    return days[tmpIndex];
}

/**
 * dayType::dayType: Default Constructor
 * - Defaults to Sunday if none is specified
 * @param string day - The day of the week passed
 */
dayType::dayType(string day)
{
    setDay(day);
}