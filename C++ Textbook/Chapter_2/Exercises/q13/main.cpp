// Question 13: Final Price of a Product with Sales Tax and Mark Up
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    const double TAX = 0.08375;     // Las Vegas Tax: 8.375%
    const double MARKUP = 0.5;      // Markup Percentage: 50%
    double price = 0.0;
    double finalPrice = 0.0;

    // Prompt for Input
    while(true)
    {
        cout << "Enter the price of the product: $";
        cin >> price;

        if(cin.fail() || price < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        } else
        {
            break;
        }
    }

    // Calculation
    finalPrice = price * (1 + TAX + MARKUP);

    cout << "***************" << endl;
    cout << "* Original Price: $" << fixed << setprecision(2) << price << endl;
    cout << "* Sales Tax: " << noshowpoint << setprecision(3) << TAX * 100 << "%" << endl;
    cout << "* Markup: " << noshowpoint << setprecision(0) << MARKUP * 100 << "%" << endl;
    cout << "* =====" << endl;
    cout << "* Final Price: $" << fixed << showpoint << setprecision(2) << finalPrice << endl;
    cout << "* =====" << endl;
    cout << "***************" << endl;

    return 0;
}