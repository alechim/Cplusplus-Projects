#include <iostream>

using namespace std;

double circle(double);

int main()
{
    // Variables
    double radius = 0.0;
    double circumference = 0.0;

    cout << "Enter the radius: ";
    cin >> radius;

    circumference = circle(radius);

    cout << "Circumference: " << circumference << endl;

    return 0;
}

double circle (double radiusCalc)
{
    // Variables
    const double PI = 3.141592653589;
    double circumferenceCalc = 0.0;

    circumferenceCalc = 2 * PI * radiusCalc;

    return circumferenceCalc;
}
