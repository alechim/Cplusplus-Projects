// Question 7: Interest on Credit Card Balance
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double averageDailyBalance = 0.0;
    double netBalance = 0.0;
    double interest = 0.0;
    double payment = 0.0;
    int d1 = 0;
    int d2 = 0;

    // Prompt for Input
    do
    {
        cout << "Please enter the net balance in the account: $";
        cin >> netBalance;
        if(cin.fail() || netBalance < 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
            continue;
        }

        cout << "Please enter the payment amount made: $";
        cin >> payment;
        if(cin.fail() || payment <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Please enter the number of days in the billing cycle: ";
        cin >> d1;
        if(cin.fail() || d1 <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the number of days payment is made before the billing cycle: ";
        cin >> d2;
        if(cin.fail() || d2 <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the interest rate percentage: ";
        cin >> interest;
        if(cin.fail() || interest <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }
        break;
    } while (true);
    
    // Calculations
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    interest = averageDailyBalance * (interest / 100);

    cout << "The interest charged is $" << interest << "." << endl;

    return 0;
}