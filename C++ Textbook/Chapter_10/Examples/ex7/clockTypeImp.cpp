#include <iostream>
#include "clockType.h"

using namespace std;

// Class Function Definitions
/**
 * clockType::clockType:
 */
clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
}

/**
 * clockType::clockType:
 * @param int hours - 
 * @param int minutes - 
 * @param int seconds - 
 */
clockType::clockType(int hours, int minutes, int seconds)
{
    setTime(hours, minutes, seconds);
}

/**
 * clockType::setTime: Checks for valid values of parameters and if out of range, initializes to 0
 * @param int hours - 
 * @param int minutes - 
 * @param int seconds - 
 */
void clockType::setTime(int hours, int minutes, int seconds)
{
    hr = (0 <= hours && hours < 24) ? hours : 0;
    min = (0 <= minutes && minutes < 60) ? minutes : 0;
    sec = (0 <= seconds && seconds < 60) ? seconds : 0;
}

/**
 * clockType::getTime: 
 * @param int& hours - 
 * @param int& minutes - 
 * @param int& seconds - 
 */
void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

/**
 * clockType::printTime: 
 */
void clockType::printTime() const
{
    cout << ((hr < 10) ? "0" + to_string(hr) : to_string(hr)) << ":";
    cout << ((min < 10) ? "0" + to_string(min) : to_string(min)) << ":";
    cout << ((sec < 10) ? "0" + to_string(sec) : to_string(sec));
}

/**
 * clockType::incrementSeconds: 
 */
void clockType::incrementSeconds()
{
    sec++;
    if(sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}

/**
 * clockType::incrementMinutes: 
 */
void clockType::incrementMinutes()
{
    min++;
    if(min > 59)
    {
        min = 0;
        incrementHours();
    }
}

/**
 * clockType::incrementHours: 
 */
void clockType::incrementHours()
{
    hr++;
    if(hr > 23)
        hr = 0;
}

/**
 * clockType::equalTime: 
 * @param const clockType& otherClock - 
 */
bool clockType::equalTime(const clockType& otherClock) const
{
    return(hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}