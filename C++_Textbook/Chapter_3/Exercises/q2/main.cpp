// Exercise 2: Volume and Surface Area of a Cylinder
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Constants
const double PI = 3.14159;

int main()
{
    // Variables
    double height = 0.0;
    double radius = 0.0;

    // Prompt for Input
    cout << "Enter the height of the cylinder: ";
    cin >> height;
    cout << "Enter the radius of the cylinder: ";
    cin >> radius;

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "Volume of the cylinder = " << PI * pow(radius, 2.0) * height << endl;
    cout << "Surface area: " << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0) << endl;

    return 0;
}