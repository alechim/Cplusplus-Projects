// Question 16: swimmingPool Class Program
#include <iostream>
#include <iomanip>
#include "swimmingPool.h"

using namespace std;

// Function Prototypes
void promptInput(double&, string);

int main()
{
    // Variables
    double length = 0.0, width = 0.0, depth = 0.0, fillRate = 0.0, drainRate = 0.0;
    char select = ' ';

    // Prompt User for Variables for Class Object
    cout << "+" << setw(24) << setfill('=') << "" << "+" << endl;
    promptInput(length, "| Please enter the length of the swimming pool in feet: ");
    promptInput(width, "| Please enter the width of the swimming pool in feet: ");
    promptInput(depth, "| Please enter the depth of the swimming pool in feet: ");
    promptInput(fillRate, "| Please enter the rate at which water fills into the pool (gallons per minute): ");
    promptInput(drainRate, "| Please enter the rate at which water drains from the pool (gallons per minute): ");
    cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << endl;

    // Initialize Class Object
    swimmingPool pool = swimmingPool(length, width, depth, fillRate, drainRate);

    do
    {
        // Display Menu and Prompt User
        cout << endl << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
        pool.displayWater();
        cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
        cout << "| [F/f] Fill Pool" << endl;
        cout << "| [D/d] Drain Pool" << endl;
        cout << "| [Q/q] Quit Program" << endl;
        cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
        cout << "| Please enter one of the selections: ";
        cin >> select;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
            cout << "| Invalid Input! Please enter a 'char' value." << endl;
            cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
            continue;
        }

        switch(tolower(select))
        {
            case 'f':
                pool.determineTimeFill();
                break;
            case 'd':
                pool.determineTimeDrain();
                break;
            case 'q':
                cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
                cout << "| Exiting Program... Goodbye!" << endl;
                cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
                break;
            default:
                cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
                cout << "| Invalid Input! Please enter a valid selection option." << endl;
                cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
        }
    } while(tolower(select) != 'q');
    
    return 0;
}

/**
 * promptInput: Gets and validates a double input from the user
 * @param double& value - Reference to the double variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(double& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < 0.001)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| Invalid Input! Please enter a non-zero positive double value." << endl;
            cout << "+" << setw(24) << setfill('-') << "" << "+" << endl;
        } else
            break;
    } while(true);
}