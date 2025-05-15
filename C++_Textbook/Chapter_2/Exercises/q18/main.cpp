// Question 18: Summer Job Income
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    double schoolCost = 0.0;
    double expendPercent = 0.11;
    double bondPercent = 0.25;
    double expendCost = 0.0;
    double bondCost = 0.0;
    double payRate = 15.50;
    double income = 0.0;
    double incomeTax = 0.0;
    int hoursWorked = 0;

    // Prompt for Hourly Pay
    while(true)
    {
        cout << "Please enter your hourly rate: $";
        cin >> payRate;

        if(cin.fail() || payRate <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
        {
            break;
        }
    }
    // Prompt for Hours Worked
    while(true)
    {
        cout << "Please enter your hours worked: ";
        cin >> hoursWorked;

        if(cin.fail() || hoursWorked < 0)
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
    income = payRate * hoursWorked;
    incomeTax = income - (income * 0.14);
    schoolCost = (incomeTax * 0.1) + (incomeTax * 0.01);
    bondCost = (incomeTax - schoolCost) * 0.25;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "***************" << endl;
    cout << "* Income (Before Taxes): $" << income << endl;
    cout << "* Income (After Taxes): $" << incomeTax << endl;
    cout << "* -----" << endl;
    cout << "* Cost of Clothes and Accessories: $" << schoolCost - (incomeTax * 0.01) << endl;
    cout << "* Cost of School Supplies: $" << schoolCost - (incomeTax * 0.1) << endl;
    cout << "* -----" << endl;
    cout << "* Cost of Buying Saving Bonds: $" << bondCost << endl;
    cout << "* Cost of Parents Buying Additional Bonds: $" << static_cast<int>(bondCost) * 0.50 << endl;
    cout << "***************" << endl;

    return 0;
}