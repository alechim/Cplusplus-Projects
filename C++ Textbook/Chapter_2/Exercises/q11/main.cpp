// Question 11: Miles Driven without Refueling
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int fuelTank = 0;
    int milesPerGallon = 0;

    while(true)
    {
        cout << "Please enter the amount of gas currently stored in the fuel tank (gallons): ";
        cin >> fuelTank;
        if(cin.fail() || fuelTank <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer." << endl;
        } else
        {
            break;
        }
    }

    while(true)
    {
        cout << "Please enter the miles per gallon that can be driven: ";
        cin >> milesPerGallon;

        if(cin.fail() || milesPerGallon <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer." << endl;
        } else
        {
            break;
        }
    }

    cout << "The car can be driven without needing to be refueled " << milesPerGallon * fuelTank << " miles." << endl;

    return 0;
}