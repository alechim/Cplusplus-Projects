// Question 29: Concrete Needed for a Patio
/**
 * Given:
 * - Ordered Concrete (Volume)
 * - Height
 * - Ratio
 *   > Length = Ratio * Width
 * Calculations
 * - Volume of a Rectangle = Length * Width * Height
 * - Volume of a Rectangle = Length * (Ratio * Length) * Height
 * - Length = sqrt((Volume) / Ratio * Height)
 *   > Note: Remember to convert to proper units for each variable
 *   > Volume -> Yard^3 | Thickness -> Inches
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int orderedConcrete = 0;
    double patioThickness = 0.0;
    double patioRatio = 0.0;
    double patioLength = 0.0;
    double patioWidth = 0.0;

    // Prompt for Input
    while(true)
    {
        cout << "Enter the amount of concrete to be ordered (cubic yards): ";
        cin >> orderedConcrete;
        if(cin.fail() || orderedConcrete <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Enter the thickness of the patio (inches): ";
        cin >> patioThickness;
        if(cin.fail() || patioThickness <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Enter the ratio of the patio from length to width (1:n): ";
        cin >> patioRatio;
        if(cin.fail() || patioRatio <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }
        break;
    }

    // Calculations
    orderedConcrete *= 27;      // - 1 cubic yard = 27 cubic feet 
    patioThickness /= 12;       // - 1 inch = 1/12 feet
    patioLength = sqrt((orderedConcrete) / (patioRatio * patioThickness));
    patioWidth = patioLength / patioRatio;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "***************" << endl;
    cout << "* The length of the patio is " << patioLength << " feet." << endl;
    cout << "* The width of the patio is " << patioWidth << " feet." << endl;
    cout << "***************" << endl;

    return 0;
}