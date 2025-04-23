// Question 5: Provided temporary Class Program
#include <iostream>
#include <iomanip>
#include "temporary.h"

using namespace std;

// Function Prototypes
void promptInput(string&, string);
void promptInput(double&, string);

int main() 
{
    // Variables - Class Objects
    temporary object1;
    temporary object2("rectangle", 12.75, 6.25);
    temporary object3("circle", 9.25, 0.0);
    temporary object4("cylinder", 4.75, 8.0);

    // Variables
    string name = "";
    double num1 = 0.0;
    double num2 = 0.0;

    // Prompt and Validate Input - Object 1
    // Use setters to initialize Object 1
    cout << "+=== Valid Objects: (rectangle, circle, sphere, cylinder) ===+" << endl;
    promptInput(name, "| Enter the name of the object: ");
    object1.setDescription(name);
    promptInput(num1, "| Enter the first value of the object: ");
    object1.setFirst(num1);
    promptInput(num2, "| Enter the second value of the object: ");
    object1.setSecond(num2);
    cout << "+" << setw(60) << setfill('=') << "" << "+" << endl << setfill(' ');

    cout << fixed << showpoint << setprecision(2) << endl;

    // Output Object 2 instance variables using getters
    cout << "+==== Object 2 ====+" << endl;
    cout << "| Object Name: " << object2.getDescription() << endl;
    cout << "| Object's First Value: " << object2.getFirst() << endl;
    cout << "| Object's Second Value: " << object2.getSecond() << endl;
    cout << "+==================+" << endl << endl;

    // Output Object 3 instance variables using get() and local variables
    object3.get(name, num1, num2);
    cout << "+==== Object 3 ====+" << endl;
    cout << "| Object Name: " << name << endl;
    cout << "| Object's First Value: " << num1 << endl;
    cout << "| Object's Second Value: " << num2 << endl;
    cout << "+==================+" << endl << endl;

    // Outputs all the class objects
    object1.print();
    object2.print();
    object3.print();
    object4.print();
    
    // Set to an invalid shape and prints object
    object1.set("triangle", 7.85, 0);
    object1.print();

    return 0;
}

// Function Definitions
/**
 * promptInput: Gets and validates a string input from the user
 * @param string& value - Reference to the string variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(string& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a valid string value." << endl;
        } else
            break;
    } while(true);
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
        if(cin.fail() || value < 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        } else
            break;
    } while(true);
}