// Example 2-32: Convert Length
#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const double CENTI_TO_INCH = 2.54;
const int INCH_TO_FOOT = 12;

int main()
{
    // Variables
    int feet = 0;
    int inches = 0;
    int totalInches = 0;
    double centimeters = 0.0;

    while(true)
    {
        cout << "Enter two integers. One for feet and one for inches: ";
        cin >> feet >> inches;

        if(cin.fail() || feet < 0 || inches < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two non-zero integer values. 'feet' 'inches'." << endl;
        } else 
        {
            break;
        }
    }
    totalInches = INCH_TO_FOOT * feet + inches;
    centimeters = CENTI_TO_INCH * totalInches;

    cout << fixed << setprecision(2);
    cout << feet << " feet and " << inches << " inches converts to " << centimeters << " centimeters." << endl;

    return 0;
}