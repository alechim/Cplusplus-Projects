// Question 21: Calculate Force
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    // GRAVITY constant in dyn * cm^2 / g^2
    const long double GRAVITY = 6.67 * pow(10, -8);
    long double distance = 0.0;
    double mass1 = 0.0;
    double mass2 = 0.0;
    long double force = 0.0;

    // Prompt for Masses and Distance
    while(true)
    {
        cout << "Please enter the two masses of the objects (g): ";
        cin >> mass1 >> mass2;

        if(cin.fail() || mass1 < 0 || mass2 < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two positive double values." << endl;
            cout << "Correct Usage: 'mass1' 'mass2'" << endl;
        }

        cout << "Please enter the distance between two masses (cm): ";
        cin >> distance;

        if(cin.fail() || distance < 0)
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
    force = GRAVITY * ((mass1 * mass2) / pow(distance, 2));

    // Display Results
    cout << "The calculated force is " << force << "N." << endl;

    return 0;
}