// Question 27: Conical Paper Cup Problem
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    double circleRadius = 0.0;
    double x = 0.0;
    double r = 0.0;
    double h = 0.0;
    double maxVolume = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter the radius of the circular waxed paper: ";
        cin >> circleRadius;
        if(cin.fail() || circleRadius <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    x = sqrt((4.0 * pow(M_PI, 2.0)) / 3.0) * circleRadius;
    r = (2.0 * M_PI * circleRadius - x) / (2.0 * M_PI);
    h = sqrt(pow(circleRadius, 2.0) - pow(r, 2.0));
    maxVolume = (1.0 / 3.0) * M_PI * pow(r, 2.0) * h;
    
    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The length of the removed sector is " << x << " cm.\n";
    cout << "The radius of the cone base is " << r << " cm.\n";
    cout << "The height of the cone is " << h << " cm.\n";
    cout << "The maximum volume of the cup is " << maxVolume << " cubic cm.\n";

    return 0;
}