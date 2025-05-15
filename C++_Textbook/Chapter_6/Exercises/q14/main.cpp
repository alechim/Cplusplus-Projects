// Question 14: Account Consulting Bill
#include <iostream>
#include <iomanip>

using namespace std;

// ***Function Prototypes***
double billAmount(int hourlyRate, int consultingTime, bool lowIncome);

int main()
{
    // Variables
    int hourlyRate = 0;
    int consultingTime = 0;
    char choice = ' ';

    // Prompt for Input
    do
    {
        cout << "Enter the hourly rate of consultation: ";
        cin >> hourlyRate;
        if(cin.fail() || hourlyRate <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
    do
    {
        cout << "Enter the time in minutes for consultation: ";
        cin >> consultingTime;
        if(cin.fail() || consultingTime <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
    do
    {
        cout << "Are you considered low-income, <= 25,000? [y/n]: ";
        cin >> choice;
        if(cin.fail() || (choice != 'y' && choice != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
            break;
    } while(true);
    
    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The total bill is $" << billAmount(hourlyRate, consultingTime, (choice == 'y' ? true : false));

    return 0;
}

// ***Functions***
/** 
 * - No cost if low income and consulting is less than or equal to 30 minutes
 * - No cost if not low income and consulting time is less than or equal to 20 minutes
 * - 40% of hourly rate for time over 30 minutes if low income
 * - 70% of hourly rate for time over 20 minutes if not low income
 */
double billAmount(int hourlyRate, int consultingTime, bool lowIncome)
{
    double cost = 0.0;
    if((lowIncome && consultingTime <= 30) || consultingTime <= 20)
        return 0.0;       
    else if(lowIncome)
        cost = (static_cast<double>(hourlyRate) * 0.4) * ((static_cast<double>(consultingTime) - 30.0) / 60.0);
    else
        cost = (static_cast<double>(hourlyRate) * 0.7) * ((static_cast<double>(consultingTime) - 20.0) / 60.0);
    return cost;
}