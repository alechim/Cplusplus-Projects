#include <iostream>
#include <iomanip>
#include "dayType.h"

using namespace std;

int main()
{
    dayType day("Mon");

    // Output "Monday" manipulation
    day.printDay();
    cout << "| Adding 4 days to " << day.getDay() << "." << endl;
    day.addDays(4);
    day.printDay();
    cout << endl;

    // Output "Tuesday" manipulation
    day.setDay("Tues");
    day.printDay();
    cout << "| Adding 7 days to " << day.getDay() << "." << endl;
    day.addDays(7);
    day.printDay();
    cout << endl;

    // Output "Friday" manipulation
    day.setDay("Fri");
    day.printDay();
    cout << "| Subtracting 2 days from " << day.getDay() << "." << endl;
    day.addDays(-2);    // Using negative number to subtract days

    // Outputting with other class functions
    cout << "+" << setw(25) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Previous Day: " << day.getPreviousDay() << endl;
    cout << left << setw(16) << "| Current Day: " << day.getDay() << endl;
    cout << left << setw(16) << "| Next Day: " << day.getNextDay() << endl;
    cout << "+" << setw(25) << setfill('=') << "" << "+" << endl << setfill(' ');

    return 0;
}