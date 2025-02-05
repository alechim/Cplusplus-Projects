// Example 1-2: Calculate Sales Tax and Price of an Item
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables (Las Vegas, NV)
    double salesTax = 0.0;
    double countySalesTax = 0.0;
    double citySalesTax = 0.0;
    double luxuryTax = 0.0;
    double salesPrice = 0.0;
    double amountDue = 0.0;
    char luxuryItem;

    // Check Inputs
    while(true)
    {
        cout << "Enter the price of the item: ";
        cin >> salesPrice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a double." << endl;
        } else 
        {
            break;
        }
    }

    // Calculate Tax
    countySalesTax = salesPrice * 0.03775;
    citySalesTax = salesPrice * 0.046;

    // Check if item is luxury
    while(true)
    {
        cout << "Is this a luxury purchase? [y/n]: ";
        cin >> luxuryItem;

        if(luxuryItem != 'y' && luxuryItem != 'n')
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
        {
            break;
        }
    }

    if(luxuryItem == 'y')
    {
        luxuryTax = salesPrice * 0.1;
    } else
    {
        luxuryTax = 0.0;
    }

    salesTax = countySalesTax + citySalesTax + luxuryTax;
    amountDue = salesPrice + salesTax;

    cout << "The Amount Due is $";
    cout << fixed << setprecision(2) << amountDue << endl;

    return 0;
}