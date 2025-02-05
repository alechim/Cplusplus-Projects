// Question 24: Length of a Wire (Rectangle)
/**
 * Given:
 * - Length of a Picture Frame = 1.5 * Width of Picture Frame
 * Calculations:
 * - Length of a Wire (Perimeter) = 2 * (Length + Width)
 * - Perimeter = 2 * (1.5 * Width + Width)
 * - Perimeter = 2 * (2.5 * Width)
 * - Perimeter = 5 * Width
 * - Width = Perimeter / 5
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double lengthWire = 0.0;
    double lengthFrame = 0.0;
    double widthFrame = 0.0;

    // Prompt for input
    while(true)
    {
        cout << "Please enter the length of the wire: ";
        cin >> lengthWire;

        if(cin.fail() || lengthWire <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero double value." << endl;
        } else
        {
            break;
        }
    }

    // Calculations
    widthFrame = lengthWire / 5;
    lengthFrame = 1.5 * widthFrame;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "The length of the picture frame is " << lengthFrame << " and the width is " << widthFrame << "." << endl;

    return 0;
}