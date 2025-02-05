// Example 1-1: Perimeter and Area of a Rectangle
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int length = 0; 
    int width = 0;
    int perimeter = 0; 
    int area = 0;

    // Take Inputs
    while(true)
    {
        cout << "Enter Length: ";
        cin >> length;

        // Error Check
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer." << endl;
        } else 
        {
            break;
        }
    }

    // Take Inputs
    while(true)
    {
        cout << "Enter Width: ";
        cin >> width;

        // Error Check
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer." << endl;
        } else 
        {
            break;
        }
    }

    // Calculate Perimeter and Area
    perimeter = 2 * (length + width);
    area = length * width;

    // Display Output
    cout << "The perimeter is: " << perimeter << endl;
    cout << "The area is: " << area << endl;

    return 0;
}