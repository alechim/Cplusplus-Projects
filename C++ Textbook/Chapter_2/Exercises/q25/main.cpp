// Question 25: Length of a Wire (Circle)
/**
 * Calculations:
 * - Length of a Wire (Circumference) = 2 * PI * radius
 * - radius = Circumference / (2 * PI)
 * - area = PI * (radius)^2
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Constants
    const double PI = 3.1416;

    // Variables
    double lengthWire = 0.0;
    double area = 0.0;
    double radius = 0.0;

    while(true)
    {
        cout << "Please enter the length of the wire: ";
        cin >> lengthWire;

        if(cin.fail() || lengthWire <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero double value." << endl;
        } else
        {
            break;
        }
    }

    // Calculations
    radius = lengthWire / (2 * PI);
    area = PI * pow(radius, 2);

    // Display Results
    cout << fixed << setprecision(2);
    cout << "The radius of the circle is: " << radius << endl;
    cout << "The area of the circle is: " << area << endl;

    return 0;
}