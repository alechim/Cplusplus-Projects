// Question 17: Compute Volume and Surface Area of a sphere
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    const double PI = 3.141592;
    double radius = 0.0;

    // Prompt input
    while(true)
    {
        cout << "Enter the radius of the sphere (m): ";
        cin >> radius;

        if(cin.fail() || radius <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        } else 
        {
            break;
        }
    }

    // Calculations
    double volume = (4.0 / 3.0) * PI * pow(radius, 3);
    double surfaceArea = 4.0 * PI * pow(radius, 2);

    cout << fixed << setprecision(2);
    cout << "The volume of the sphere is " << volume << " m^3." << endl;
    cout << "The surface area of the sphere is " << surfaceArea << " m^2." << endl;

    return 0;
}