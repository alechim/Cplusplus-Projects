// Question 12: Seconds to Time
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int time = 0;
    int tmp = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    // Prompt for Input
    while(true)
    {
        cout << "Please enter the elapsed time in seconds: ";
        cin >> time;

        if(cin.fail() || time < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else
        {
            break;
        }
    }

    // Calculations
    tmp = time;
    hours = tmp / 3600;
    tmp %= 3600;
    minutes = tmp / 60;
    seconds = tmp % 60;

    cout << "The elapsed time is " << time << " seconds, and the time is ";
    cout << setw(2) << setfill('0') << hours << ":" 
         << setw(2) << setfill('0') << minutes << ":" 
         << setw(2) << setfill('0') << seconds << "." << endl; 

    return 0;
}