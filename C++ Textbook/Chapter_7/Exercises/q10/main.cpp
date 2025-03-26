// Question 10: Calculate Spilled Oil Slick
/**
 * Assume:
 * - Oil sits on top of water in form of a circle
 * User Input:
 * - Rate at which pipe pumps oil (in gallons) per minute
 * - Thickness of Oil on top of Water
 * - Number of Days which area is covered by spilled oil
 * Calculate:
 * - Spilled Area (in kilometers)
 * - Volume of Oil (in gallons)
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function Prototypes
void promptInput(int&, const string);
void promptInput(double&, const string);

int main()
{
    // Variables
    double rate = 0.0;
    double thickness = 0.0;
    int noOfDays = 0;
    double radius = 0.0;
    double area = 0.0;
    double volume = 0.0;

    // Prompt for Input
    promptInput(rate, "Enter the rate at which the pipe pumps oil per minute (gallons): ");
    promptInput(thickness, "Enter the thickness of the oil on top of the water (millimeters): ");
    promptInput(noOfDays, "Enter the number of days which the area is covered by the spilled oil: ");

    // Calculations
    // - Convert millimeters to meters
    thickness /= 1000.0;

    // - Volume of Cylinder = Rate * Duration
    //   > Convert rate from gallons / minutes -> gallons / days 
    volume = rate * 60.0 * 24.0 * static_cast<double>(noOfDays);

    // Radius of Cylinder
    // - V = PI * r^2 * h => r = sqrt(V / (PI * h))
    radius = sqrt(volume / (M_PI * thickness));

    // Surface Area of a Circle: area = PI * r^2
    area = M_PI * pow(radius, 2.0);

    // - Convert area meters^2 to kilometers^2
    area /= 1'000'000.0;

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The spilled area of oil is " << area << " kilometers^2." << endl;
    cout << "The volume of oil on top of the water is " << volume << " gallons." << endl;

    return 0;
}

// Function Definitions
/**
 * promptInput: Collects integer input from the user with validation
 * @param int value - Reference to the integer variable where input will be stored
 * @param const string prompt - The message displayed to the user when requesting input
 */
void promptInput(int& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;

        if(cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
            break;
    } while(true);
}

/**
 * promptInput: Collects double input from the user with validation
 * @param double value - Reference to the double variable where input will be stored
 * @param const string prompt - The message displayed to the user when requesting input
 */
void promptInput(double& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        
        if(cin.fail() || value <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}