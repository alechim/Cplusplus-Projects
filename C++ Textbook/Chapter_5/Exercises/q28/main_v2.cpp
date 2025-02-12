// Question 28: Apartment Problem
// Version 2: Looping Iteratively
#include <iostream>
#include <iomanip>

using namespace std;

// *** Functions ***
// promptInput(value, prompt)
void promptInput(double& value, const string& prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}

int main()
{
    // Variables
    int totalUnits = 0;
    double rent = 0.0;
    double increaseRent = 0.0;
    double maintainCost = 0.0;
    double maxProfit = 0.0;
    double cost = 0.0;
    int x = 0;

    // Prompt for Input
    do
    {
        cout << "Enter the total amount of apartment units: ";
        cin >> totalUnits;
        if(cin.fail() || totalUnits < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else 
            break;
    } while (true);
    promptInput(rent, "Enter the amount to rent per month: $");
    promptInput(increaseRent, "Enter the amount of rent increase that causes one unit to become vacant: $");
    promptInput(maintainCost, "Enter the amount to maintain a rented unit: $");

    // Calculations
    double profit = 0.0;
    double optimalRent = 0.0;
    int optimalUnits = totalUnits;
    double revenue = 0.0;
    bool decreasing = false;    // Track profit trend
    for(int i = 0; i <= totalUnits; i++)
    {
        revenue = (totalUnits - i) * (rent + (increaseRent * i));
        cost = (totalUnits - i) * maintainCost;
        profit = revenue - cost;
        if(maxProfit < profit)
        {
            maxProfit = profit;
            optimalRent = rent + (increaseRent * i);
            optimalUnits = totalUnits - i;
        } else if (decreasing) 
            break;  // Stop early if profit declines two times in a row
        else 
            decreasing = true;  // First decline detected
    } 

    // Display Results
    cout << fixed << setprecision(2);
    cout << "Optimal Rent Price: $" << optimalRent << endl;
    cout << "Number of Occupied Units: " << optimalUnits << endl;
    cout << "Maximum Profit: $" << maxProfit << endl;

    return 0;
}