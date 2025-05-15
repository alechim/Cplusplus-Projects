#include <iostream>
#include "clockType.h"

using namespace std;

// Class Function Definitions
/**
 * clockType::clockType: Constructor with all 3 parameters
 * @param int hours - The hours of the clock
 * @param int minutes - The minutes of the clock
 * @param int seconds - The seconds of the clock
 */
clockType::clockType(int hours, int minutes, int seconds)
{
    setTime(hours, minutes, seconds);
}

/**
 * clockType::setTime: Checks for valid values of parameters and if out of range, initializes to 0
 * @param int hours - The hours of the clock
 * @param int minutes - The minutes of the clock
 * @param int seconds - The seconds of the clock
 */
void clockType::setTime(int hours, int minutes, int seconds)
{
    hr = (0 <= hours && hours < 24) ? hours : 0;
    min = (0 <= minutes && minutes < 60) ? minutes : 0;
    sec = (0 <= seconds && seconds < 60) ? seconds : 0;
}

/**
 * clockType::getTime: Returns the values of hr, min, and sec into the referenced variables passed
 * @param int& hours - The hours of the clock
 * @param int& minutes - The minutes of the clock
 * @param int& seconds - The seconds of the clock
 */
void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

/**
 * clockType::printTime: Display the clock time in the format hh:mm:ss
 */
void clockType::printTime() const
{
    cout << ((hr < 10) ? "0" + to_string(hr) : to_string(hr)) << ":";
    cout << ((min < 10) ? "0" + to_string(min) : to_string(min)) << ":";
    cout << ((sec < 10) ? "0" + to_string(sec) : to_string(sec));
}

/**
 * clockType::incrementSeconds: Increments the class instance variable sec and calls incrementMinutes when sec > 59
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
 * clockType::incrementMinutes: Increments the class instance variable min and calls incrementHours when min > 59
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
 * clockType::incrementHours: Increments the class instance variable hr and resets hr to 0 when hr > 23
 */
void clockType::incrementHours()
{
    hr++;
    if(hr > 23)
        hr = 0;
}

/**
 * clockType::equalTime: Determines whether two class objects of clock are equal to each other in terms of hours, minutes and seconds
 * @param const clockType& otherClock - The class object to be compared to
 * @return bool - true if hr, sec, and min from both class objects are equal. Otherwise, false
 */
bool clockType::equalTime(const clockType& otherClock) const
{
    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

/**
 * clockType::elapsedTime: Converts the elapsed time of the day of a clock into seconds
 * @return int - the elapsed time in seconds
 */
int clockType::elapsedTime() { return ((hr * 3600) + (min * 60) + sec); }

/**
 * clockType::remainingTime: Converts the remaining time of the day of a clock into seconds
 * @return int - the remaining time in seconds
 */
int clockType::remainingTime() { return ((24 * 3600) - ((hr * 3600) + (min * 60) + sec)); }

/**
 * clockType::differenceTime: Determines and outputs how far apart in time two clocks are and outputs the time in the form hr:min:sec
 * @param const clockType& otherClock - The class object to be compared to
 */
void clockType::differenceTime(const clockType& otherClock)
{
    cout << abs(hr - otherClock.hr) << ":" << abs(min - otherClock.min) << ":" << abs(sec - otherClock.sec) << endl;
}

/**
 * clockType::setSeconds: Allows seconds of the clock to be set and handles overflow
 * @param int value - The seconds of the clock
 */
void clockType::setSeconds(int value)
{
    if(value < 60)
        sec = value;
    else
    {
        sec = value % 60;
        for(int i = 0; i < value / 60; i++)
            incrementMinutes();
    }
}

/**
 * clockType::setMinutes: Allows minutes of the clock to be set and handles overflow
 * @param int value - The minutes of the clock
 */
void clockType::setMinutes(int value)
{
    if(value < 60)
        min = value;
    else
    {
        min = value % 60;
        for(int i = 0; i < value / 60; i++)
            incrementHours();
    }
}

/**
 * clockType::setHours: Allows hours of the clock to be set and handles overflow
 * @param int value - The hours of the clock
 */
void clockType::setHours(int value)
{
    if(value < 24)
    {
        hr = value;
    } else
        hr = value / 24;
}