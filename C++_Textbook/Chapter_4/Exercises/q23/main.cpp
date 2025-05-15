// Question 23: TV Screen Size
/**
 * Given:
 * - Ratios (Length to Width)
 *   > Traditional - 4:3
 *     - Length = (3/4) * Width
 *   > LCD - 16:9
 * Calculations:
 * - x: length, y: width, z: diagonal
 * - Traditional
 *   > x^2 + y^2 = z^2
 *   > x^2 + ((4/3)x)^2 = z^2
 *   > x^2 + 16/9 * x^2 = z^2
 *   > 25/9 * x^2 = z^2
 *   > x = sqrt(z^2 * 9/25)
 *   > x = z * 3/5
 *   > y = z * 4/5
 * - LCD
 *   > x^2 + y^2 = z^2
 *   > x^2 + ((16/9)x)^2 = z^2
 *   > x^2 + 256/81 * x^2 = z^2
 *   > 337/81 * x^2 = z^2
 *   > x = sqrt(z^2 * 81/337)
 *   > x = z * 9/sqrt(337)
 *   > y = z * 16/sqrt(337)
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    string choice = "";
    double diagonal = 0.0;
    double length = 0.0;
    double width = 0.0;
    double area = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter the length of the diagonal of the TV in inches: ";
        cin >> diagonal;
        if(cin.fail() || diagonal <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Enter the type of the TV's screen length (Traditional/LCD): ";
        cin >> choice;
        if(cin.fail() || (choice != "Traditional" && choice != "LCD"))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'Traditional' or 'LCD'." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    if(choice == "Traditional")
    {
        length = diagonal * (3.0/5.0);
        width = diagonal * (4.0/5.0);
    } else
    {
        length = diagonal * (9.0 / sqrt(337.0));
        width = diagonal * (16.0 / sqrt(337.0));
    }
    area = length * width;

    // Display Results
    cout << fixed << setprecision(2);
    cout << choice << " TV measurements: " << endl;
    cout << "Length: " << length << " inches." << endl;
    cout << "Width: " << width << " inches." << endl;
    cout << "Area: " << area << " inches^2." << endl;

    return 0;
}