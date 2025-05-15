// Question 28: Apartment Problem
// Version 1: Mathematical Equation
/**
 * Calculations:
 * - P: Profit, U: Units, x: Times Rent Increases, R: Rent, I: Increased Rent C: Cost
 * - P = (U - x) * (R + Ix) - C
 *     = (UR - Rx + UIx - Ix^2) - C
 *     = -Ix^2 + (UI - R)x + UR - C
 * - Quadratic Function: Find Maximum Vertex
 *   > a^2 + b + c = 0
 *   > Since a is negative:
 *     - x = -b / 2a = -(UI - R) / 2(-I) = (UI - R) / 2I
 */
#include <iostream>
#include <iomanip>
#include <cmath>

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
    x = round((totalUnits * increaseRent - rent) / (2 * increaseRent));
    cost = (totalUnits - x) * maintainCost;
    maxProfit = -(increaseRent * pow(x, 2.0)) + (((totalUnits * increaseRent) - rent) * x) + (totalUnits * rent) - cost;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "Number of Occupied Units: " << static_cast<int>(totalUnits - x) << endl;
    cout << "Maximum Profit: $" << maxProfit << endl;

    return 0;
}