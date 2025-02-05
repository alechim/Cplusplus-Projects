// Question 9: Volume of Cylinder to Cube
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int radius = 0;
    int height = 0;
    double volume = 0.0;
    double side = 0.0;

    // Prompt for Input
    do
    {
        cout << "Please enter the radius of the cylinder: ";
        cin >> radius;
        if(cin.fail() || radius <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the height of the cylinder: ";
        cin >> height;
        if(cin.fail() || height <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }
        break;
    } while(true);
    
    // Calculations
    volume = M_PI * pow(radius, 2) * height;        // Cylinder Volume
    // Cube Volume: V = s^3 -> s = cube_root(V)
    side = cbrt(volume);

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The cylinder's volume is: " << volume << "." << endl;
    cout << "The side of the cube with the cylinder's volume is: " << side << "." << endl;

    return 0;
}