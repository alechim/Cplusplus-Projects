// Question 23: Buying and Selling Stocks
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Constants
    const double SERVICE_CHARGE = 0.015;
    
    // Variables
    int sharesSold = 0;
    double purchasePrice = 0.0;
    double sellingPrice = 0.0;
    double amountInvested = 0.0;
    double amountReceived = 0.0;
    double totalServiceCharge = 0.0;
    double netProfit = 0.0;

    // Prompt for input
    while(true)
    {
        cout << "Please enter the number of shares sold: ";
        if(cin >> sharesSold && sharesSold >= 0 && sharesSold == static_cast<int>(sharesSold))
        {
            cout << "Please enter the purchase price of each stock: $";
            if(cin >> purchasePrice && purchasePrice > 0)
            {
                cout << "Please enter the selling price of each stock: $";
                if(cin >> sellingPrice && sellingPrice > 0)
                {
                    break;
                }
            }
        }

        cin.clear();
        cin.ignore(40, '\n');
        cout << "Invalid Input! Please try again." << endl;
    }

    // Calculations
    amountInvested = sharesSold * purchasePrice;
    amountReceived = sharesSold * sellingPrice;
    totalServiceCharge = (amountInvested + amountReceived) * SERVICE_CHARGE;
    netProfit = amountReceived - amountInvested - totalServiceCharge;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "***************" << endl;
    cout << "* Amount Invested: $" << amountInvested << endl;
    cout << "* Total Service Charge: $" << totalServiceCharge << endl;
    if(netProfit <= 0)
    {
        cout << "* Profit Lost: -$" << -netProfit << endl;
    } else
    {
        cout << "* Profit Gained: $" << netProfit << endl;
    }
    cout << "* Amount Received After Selling: $" << (amountReceived - (amountReceived * SERVICE_CHARGE)) << endl;
    cout << "***************" << endl;

    return 0;
}