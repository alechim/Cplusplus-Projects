// Question 8: Salary Calculator
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    const int SECRET = 11;
    const double RATE = 12.50;
    int num1 = 0;
    int num2 = 0;
    int newNum = 0;
    string name = "";
    double hoursWorked = 0.0;
    double wages = 0.0;

    // Prompt user for two integer values
    while(true)
    {
        cout << "Please enter two integer values: ";
        cin >> num1 >> num2;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter integer values. 'num1' 'num2'." << endl;
        } else
        {
            break;
        }
    }

    // Display and newNum calculations
    cout << "The value of num1 = " << num1 << " and the value of num2 = " << num2 << "." << endl;

    newNum = (num1 * 2) + num2;
    cout << "The current value of newNum = " << newNum << "." << endl;

    newNum += SECRET;
    cout << "The updated value of newNum = " << newNum << "." << endl;

    // Prompt user for last name
    while(true)
    {
        cout << "Please enter your last name: ";
        cin >> name;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a string value." << endl;
        } else
        {
            break;
        }
    }

    // Prompt for hours worked
    while(true)
    {
        cout << "Please enter your hours worked (0-70): ";
        cin >> hoursWorked;

        if(cin.fail() || (hoursWorked <= 0 && hoursWorked > 70))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a double value between 0 and 70." << endl;
        } else
        {
            break;
        }
    }

    wages = RATE * hoursWorked;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "Name: " << name << endl;
    cout << "Pay Rate: $" << RATE << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Salary: $" << wages << endl;

    return 0;
}