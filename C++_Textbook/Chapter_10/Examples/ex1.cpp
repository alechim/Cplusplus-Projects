// Example 10-1: Clock Type Class
#include <iostream>

using namespace std;

// Class
class clockType
{
    public:
        void setTime(int, int, int);
        void getTime(int&, int&, int&) const;
        void printTime() const;
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        bool equalTime(const clockType&) const;
    private:
        int hr;
        int min;
        int sec;
};

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

// Class Function Definitions
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
    return(hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}