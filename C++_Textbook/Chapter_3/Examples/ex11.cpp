// Example 3-11: Setprecision, Fixed, Showpoint
#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.14159265;

int main()
{
    // Variables
    double radius = 12.67;
    double height = 12.00;
    
    cout << fixed << showpoint;
    cout << setprecision(2) << "Line 10: setprecision(2)" << endl;
    cout << "Line 11: radius = " << radius << endl;
    cout << "Line 12: height = " << height << endl;
    cout << "Line 13: volume = " << PI * radius * radius * height << endl;
    cout << "Line 14: PI = " << PI << endl << endl;

    cout << setprecision(3) << "Line 15: setprecision(3)" << endl;
    cout << "Line 16: radius = " << radius << endl;
    cout << "Line 17: height = " << height << endl;
    cout << "Line 18: volume = " << PI * radius * radius * height << endl;
    cout << "Line 19: PI = " << PI << endl << endl;

    cout << setprecision(4) << "Line 20: setprecision(4)" << endl;
    cout << "Line 21: radius = " << radius << endl;
    cout << "Line 22: height = " << height << endl;
    cout << "Line 23: volume = " << PI * radius * radius * height << endl;
    cout << "Line 24: PI = " << PI << endl << endl;

    cout << "Line 25: " 
         << setprecision(3) << radius << ", "
         << setprecision(2) << height << ", "
         << setprecision(5) << PI << endl;

    return 0;
}