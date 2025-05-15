// Question 21: Date to Day Number of the Year
#include <iostream>

using namespace std;

int main()
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayNumber = 0;
    bool isLeapYear = false;
    int month = 0;
    int day = 0;
    int year = 0;

    // Prompt for Input
    do
    {
        cout << "Enter the month, day, and year: ";
        cin >> month >> day >> year;
        if(cin.fail() || month <= 0 || day <= 0 || year <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 3 non-zero positive integer values." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    if((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
        isLeapYear = true;
    
    for(int i = 0; i < month; i++)
    {
        if(i == 2 && month > 2 && isLeapYear)
            dayNumber += days[i] + 1;
        else if(i + 1 == month)
            dayNumber += day;
        else
            dayNumber += days[i];
    }

    // Display Results
    cout << "The date " << month << "-" << day << "-" << year << " converted to the day number of the year is " << dayNumber << ".\n";

    return 0;
}