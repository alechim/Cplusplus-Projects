// Example 3-4: Predefined Functions
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Global Constants
const double PI = 3.1416;

int main()
{
    // Variables
    double sphereRadius = 0.0;
    double sphereVolume = 0.0;
    double point1X = 0.0;
    double point1Y = 0.0;
    double point2X = 0.0;
    double point2Y = 0.0;
    double distance = 0.0;
    string str = "";

    cout << "Line 14: Enter the radius of the sphere: ";
    cin >> sphereRadius;
    cout << endl;

    sphereVolume = (4 / 3) * PI * pow(sphereRadius, 3);

    cout << "Line 18: The volume of the sphere is: " << sphereVolume << endl << endl;
    cout << "Line 19: Enter the coordinates of two points in the X-Y plane: ";
    cin >> point1X >> point1Y >> point2X >> point2Y;
    cout << endl;

    distance = sqrt(pow(point2X - point1X, 2) + pow(point2Y - point1Y, 2));

    cout << "Line 23: The distance between the points (" << point1X << ", " << point1Y << ") and (" << point2X << ", " << point2Y << ") is: " << distance << endl << endl;

    str = "Programming with C++";

    cout << "Line 25: The number of characters, " << "including blanks, in \n           \"" << str << "\" is: " << str.length() << endl;

    return 0;
}