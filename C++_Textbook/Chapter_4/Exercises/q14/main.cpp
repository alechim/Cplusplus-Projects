// Question 14: Airport Parking Fee
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double parkingFee = 0.0;
    double hours = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter the amount of hours parked (0-24): ";
        cin >> hours;
        if(cin.fail() || hours < 0.0 || hours > 24.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a double value between 0 and 24." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    if(0.0 <= hours && hours <= 3.0)
        parkingFee = 5;
    else if(3.0 < hours && hours <= 9.0)
        parkingFee = 6 * static_cast<int>(hours + 1);
    else if(9.0 < hours && hours <= 24.0)
        parkingFee = 60;

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The parking fee to be paid is $" << parkingFee << "." << endl;

    return 0;
}