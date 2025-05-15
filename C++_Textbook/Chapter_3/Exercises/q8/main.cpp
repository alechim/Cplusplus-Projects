// Question 8: Calculate Merchandise Profit
/**
 * Given
 * - Net profit of approximately 10% after expenses
 * - After markup, item is priced at 15% sale
 */
/**
 * Calculations:
 * - Expenses = salary + rent + electricity bill
 * - 10% net profit = expenses * 0.1
 * - Revenue = Expenses + Net Profit
 * - 15% Discount after markup 
 *   > Discounted Price = Price - (Price * Discount %)
 *     - Discounted Price = Price * (1 - Discount %)
 *     - Price = Discounted Price / 1 - Discount %
 *   > Cost of Item
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double merchCost = 0.0;
    double revenue = 0.0;
    double salary = 0.0;
    double rent = 0.0;
    double electricityBill = 0.0;
    double netProfit = 0.0;
    double expenses = 0.0;
    double markupPrice = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter the cost of the merchandise: $";
        cin >> merchCost;
        if(cin.fail() || merchCost <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Enter the salary of the employees: $";
        cin >> salary;
        if(cin.fail() || salary <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Enter the annual rent of the building: $";
        cin >> rent;
        if(cin.fail() || rent <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Enter the estimated electricity cost: $";
        cin >> electricityBill;
        if(cin.fail() || electricityBill <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }
        break;
    } while (true);
    
    // Calculations
    expenses = salary + rent + electricityBill;
    netProfit = expenses * 0.10;
    revenue = expenses + netProfit;
    // merchCost * (revenue / merchCost): Calculate the additional cost needed to be made from original price
    // (1 / 0.85): Increase markup to account for 15% sale
    markupPrice = merchCost * (revenue / merchCost) * (1 / 0.85);

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "***************" << endl;
    cout << "* Total Expenses: $" << expenses << endl;
    cout << "* Net Profit: $" << netProfit << endl;
    cout << "* Total Revenue Needed: $" << revenue << endl;
    cout << "* Original Merchandise Cost: $" << merchCost << endl;
    cout << "* Marked Up Price: $" << markupPrice << endl;
    cout << "* Sale Price (15% off): $" << markupPrice * 0.85 << endl;
    cout << "***************" << endl;

    return 0;
}