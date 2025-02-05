// Question 6: Calculate Volume
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double volume = 0.0;
    double mass = 0.0;
    double density = 0.0;

    // Prompt for Input
    do
    {
        cout << "Please enter the mass of the object in grams: ";
        cin >> mass;
        if(cin.fail() || mass <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Please enter the density of the object in grams per cubic centimeters: ";
        cin >> density;
        if(cin.fail() || density <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        } 
        break;
    } while(true);

    // Calculate and Display Results
    volume = mass / density;
    cout << fixed << showpoint << setprecision(2);
    cout << "The volume of the shape with a mass of " << mass << " grams and density of " << density << " grams per cubic centimeters is " << volume << " cubic centimeters." << endl;

    return 0;
}