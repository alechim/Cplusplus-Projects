// Question 30: Power Station Problem
/**
 * Algorithm:
 * - L >= U -> landLength = 0.0 b/c Underwater Traversal is cheaper
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// ***Function Prototypes***
void promptInput(double& value, const string prompt);
void displayResults(const double landLength, const double waterLength, const double totalCost);

int main()
{
    // Variables
    double width = 0.0;
    double distance = 0.0;
    double landCost = 0.0;
    double waterCost = 0.0;
    double landLength = 0.0;

    // Prompt for Input
    promptInput(width,  "Enter the width of the river (miles): ");
    promptInput(distance, "Enter the distance between the power station and factory downstream (miles): ");
    promptInput(landCost, "Enter the cost of the power line on land per foot: $");
    promptInput(waterCost, "Enter the cost of the power line under water per foot: $");

    // Calculations
    // - Convert miles to feet
    width *= 5280.0;
    distance *= 5280.0; 

    if(landCost < waterCost)
    {
        double denominator = sqrt(pow(waterCost, 2.0) - pow(landCost, 2.0));
        landLength = (denominator > 0) ? distance - ((landCost * width) / denominator) : distance;
    }
    double waterLength = sqrt(pow((distance - landLength), 2.0) + pow(width, 2.0));
    double totalCost = (landCost * landLength) + (waterCost * waterLength);

    // Display Results
    displayResults(landLength, waterLength, totalCost);

    return 0;
}

// ***Functions***
void promptInput(double& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        } else
            break;
    } while (true);
}

void displayResults(const double landLength, const double waterLength, const double totalCost)
{
    cout << fixed << showpoint << setprecision(2);
    cout << setfill('=') << setw(20) << "=" << endl;
    cout << "The length of the power line on land is " << landLength << " feet." << endl;
    cout << "The length of the power line underwater is " << waterLength << " feet." << endl;
    cout << "The total cost of the power line connection is $" << totalCost << endl;
    cout << setfill('=') << setw(20) << "=" << endl;
 }