// Question 20: Car Salesperson Commission
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double commissionFee = 0.0;
    double commissionPercent = 0.0;
    double minSelling = 0.0;
    double maxSelling = 0.0;
    double carCost = 0.0;

    // Prompt for Commission Fee and Percentage
    while(true)
    {
        cout << "Please enter commission fee: $";
        cin >> commissionFee;

        if(cin.fail() || commissionFee < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        }

        cout << "Please enter the commission percentage: ";
        cin >> commissionPercent;

        if(cin.fail() || commissionPercent < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        } else
        {
            commissionPercent /= 100;
            break;
        }
    }

    // Prompt for Car Cost 
    while(true)
    {
        cout << "Please enter the cost of the car: $";
        cin >> carCost;

        if(cin.fail() || carCost < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        } else
        {
            break;
        }
    }

    // Prompt for Minimum and Maximum Pricing
    while(true)
    {
        cout << "Please enter the minimum amount to add to the price: $";
        cin >> minSelling;

        if(cin.fail() || minSelling < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        }

        cout << "Please enter the maximum amount to add to the price: $";
        cin >> maxSelling;
    
        if(cin.fail() || maxSelling < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        }

        if(minSelling > maxSelling)
        {
            cout << "Invalid Settings. Minimum must be less than Max." << endl;
        } else {
            break;
        }
    }

    // Display Results
    cout << fixed << setprecision(2);
    cout << "***************" << endl;
    cout << "* Minimum Selling Price: $" << minSelling + carCost << endl;
    cout << "* Maximum Selling Price: $" << maxSelling + carCost << endl;
    cout << "* Commission Range: $" << commissionFee + (minSelling * commissionPercent) << " - $" << commissionFee + (maxSelling * commissionPercent) << endl;
    cout << "***************" << endl;

    return 0;
}