// Example 2-4: Inches to Feet
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int inches = 0;
    int convertFeet = 0;
    int convertInch = 0;

    while(true)
    {
        cout << "Enter the number of inches to convert: ";
        cin >> inches;
    
        if(cin.fail() || inches < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else 
        {
            break;
        }
    }

    // Calculations
    convertFeet = inches / 12;
    convertInch = inches % 12;

    // Display Results
    cout << "-----" << endl;
    cout << inches << " inches converts to: ";
    cout << convertFeet << " ft and " << convertInch << " inches." << endl;

    return 0;
}