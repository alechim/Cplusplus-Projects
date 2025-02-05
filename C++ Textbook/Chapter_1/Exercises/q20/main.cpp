// Question 20: ATM withdrawal
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double accountAmount = 250.0;
    double maxWithdraw = 500.0;
    double withdrawAmount = 0.0;
    double serviceCharge = 0.0;
    char select = ' ';

    while(true)
    {
        cout << fixed << setprecision(2);
        cout << "Total Amount in Account: $" << accountAmount << endl;
        
        // If acccountAmount is 0 or a negative number, user cannot withdraw money.
        if(accountAmount <= 0)
        {
            cout << "Sorry but you are unable to withdraw money at this ATM. Goodbye." << endl;
            break;
        } 
        
        cout << "You can withdraw a total of $" << maxWithdraw << " today. " << endl;
        cout << "Do you want to withdraw money? [y/n]: ";
        cin >> select;

        if(cin.fail() || (select != 'y' && select != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
            continue;
        } else if(select == 'n')
        {
            cout << "Thank you for your time. Goodbye." << endl;
            break;
        } 
        
        // Daily limit withdrawal of $500
        if(maxWithdraw <= 0.00)
        {
            cout << "Sorry, you have hit your maximum withdraw limit of $500 today. Goodbye." << endl;
            break;
        }

        // Prompt for input
        cout << "How much would you like to withdraw? $";
        cin >> withdrawAmount;

        if(cin.fail() || withdrawAmount <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        }

        // Display message of withdraw limit
        if(withdrawAmount > maxWithdraw)
        {
            cout << "You can withdraw a maximum of $500 a day, you can currently withdraw $" << maxWithdraw << " today." << endl;
            continue;
        }

        // Prompt user about service charge
        if(withdrawAmount > accountAmount)
        {
            cout << "Invalid Funds! Would you like to withdraw with a service charge of $25.00? [y/n]: ";
            cin >> select;

            if(cin.fail() || (select != 'y' && select != 'n'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
                continue;
            } else if(select == 'n')
            {
                cout << "Thank you for your time. Goodbye." << endl;
                break;
            } 
            if(withdrawAmount + 25.00 > maxWithdraw)
            {
                cout << "Sorry, but this transaction exceeds the daily maximum withdrawal of $500." << endl;
                continue;
            }
            accountAmount -= withdrawAmount + 25.00;
            maxWithdraw -= withdrawAmount + 25.00;
        }

        // 4% service charge over $300
        if(withdrawAmount > 300)
        {
            serviceCharge = (withdrawAmount - 300) * 0.04;
            if(withdrawAmount + serviceCharge > maxWithdraw)
            {
                cout << "Sorry, but this transaction exceeds the daily maximum withdrawal of $500. " << endl;
                continue;
            }
            accountAmount -= withdrawAmount + serviceCharge;
            maxWithdraw -= withdrawAmount + serviceCharge;
        } else
        {
            accountAmount -= withdrawAmount;
            maxWithdraw -= withdrawAmount;
        }
    }

    return 0;
}