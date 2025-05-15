// Example 1-3: Calculate Monthly Paycheck
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double baseSalary = 0.0;
    int noOfServiceYears = 0;
    int totalSales = 0;
    int bonus = 0;
    double additionalBonus = 0.0;
    double payCheck = 0.0;

    // Check Inputs
    while(true)
    {
        cout << "Please enter your base salary: ";
        cin >> baseSalary;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a double value." << endl;
        } else 
        {
            break;
        }
    }
    while(true)
    {
        cout << "Please enter your service years: ";
        cin >> noOfServiceYears;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else 
        {
            break;
        }
    }

    // Calculate Bonus | n <= 5: $10 & n > 5: $20 
    if(noOfServiceYears <= 5)
    {
        bonus = 10 * noOfServiceYears;
    } else {
        bonus = 20 * noOfServiceYears;
    }

    while(true)
    {
        cout << "Enter your total amount of sales: ";
        cin >> totalSales;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else 
        {
            break;
        }
    }

    if(totalSales < 5000)
    {
        additionalBonus = totalSales * (0.03);
    } else 
    {
        additionalBonus = totalSales * (0.06);
    }

    payCheck = baseSalary + bonus + additionalBonus;
    cout << "Your paycheck is $";
    cout << fixed << setprecision(2) << payCheck << endl;

    return 0;
}