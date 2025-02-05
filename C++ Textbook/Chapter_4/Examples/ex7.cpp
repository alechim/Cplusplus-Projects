// Example 4-7: Calculate Weekly Wages
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double wages = 0.0;
    double rate = 0.0;
    double hours = 0.0;

    cout << fixed << showpoint << setprecision(2);
    cout << "Line 8: Enter working hours and rate: ";
    cin >> hours >> rate;

    if(hours > 40.0)
        wages = 40.0 * rate + 1.5 * rate * (hours - 40.0);
    else
        wages = hours * rate;
    
    cout << endl;
    cout << "Line 15: The wages are $" << wages << endl;

    return 0;
}