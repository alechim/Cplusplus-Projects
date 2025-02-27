// Question 4: Sphere Surface Area and Volume
#include <iostream>
#include <cmath>

using namespace std;

// ***Globals***
const double PI = 3.14159;

int main()
{
    // Variables
    double radius = 0.0;

    // Prompt for Input
    do {
        cout << "Enter the radius of the sphere: ";
        cin >> radius;
        if(cin.fail() || radius <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else  
            break;
    } while(true);

    // Calculations and Display Results
    cout << "The square root of PI = " << sqrt(PI) << endl;
    cout << "The surface area of the sphere = " << (4.0 * PI * pow(radius, 2.0)) << endl;
    cout << "The volume of the sphere = " << ((4.0 / 3.0) * PI * pow(radius, 3.0)) << endl;

    return 0;
}