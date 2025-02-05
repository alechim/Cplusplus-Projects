// Question 11: Reduce the Size of a Candy Bar
/**
 * Let s be the scaling factor to apply to length and width
 * Calculation:
 * - New Volume = (l * s) * (w * s) * h
 *   > New Volume = (l * w * h) * s^2 
 * - New Volume = Original Volume * Reduction
 *   > (l * w * h) * s^2 = (l * w * h) * (1 - Percentage)
 *   > s = sqrt(1 - Percentage)
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int length = 0;
    int width = 0;
    int height = 0;
    int percent = 0;
    double percentage = 0.0;
    double scale = 0.0;

    // Prompt for Input
    do
    {
        cout << "Please enter the length of the candy bar: ";
        cin >> length;
        if(cin.fail() || length <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the width of the candy bar: ";
        cin >> width;
        if(cin.fail() || width <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the height of the candy bar: ";
        cin >> height;
        if(cin.fail() || height <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the percentage to reduce the volume of the candy bar: ";
        cin >> percent;
        if(cin.fail() || percent <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }
        break;
    } while (true);

    // Calculations
    percentage = static_cast<double>(percent) / 100;
    scale = sqrt(1 - percentage);

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "==========" << endl;
    cout << "The original size of the candy bar is " << length << " x " << width << " x " << height << "." << endl;
    cout << "The new size of the candy bar after a " << percent << "% reduction is " << length * scale << " x " << width * scale << " x " << height << "." << endl;
    cout << "==========" << endl;
    cout << "The original volume of the candy bar is " << length * width * height << "." << endl;
    cout << "The new volume of the candy bar is " << (length * scale) * (width * scale) * height << "." << endl;
    cout << "==========" << endl;

    return 0;
}