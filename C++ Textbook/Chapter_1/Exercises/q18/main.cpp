// Question 18: Lawn Services Bill
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int area = 0;
    int noOfFertilizer = 0;
    int noOfTrees = 0;
    double mowingCost = 0.0;
    double fertilizingCost = 0.0;
    double plantingCost = 0.0;
    double bill = 0.0;

    while(true)
    {
        cout << "Please enter the area of the lawn to be mowed (square yards): ";
        cin >> area;

        if(cin.fail() || area <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else
        {
            break;
        }
    }
    // $35.00 per 5,000 square yards
    mowingCost = ceil(static_cast<double>(area) / 5000.0) * 35.00;

    while(true)
    {
        cout << "Please enter the number of items to be fertilized: ";
        cin >> noOfFertilizer;

        if(cin.fail() || noOfFertilizer <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else
        {
            break;
        }
    }
    // $30.00 per application
    fertilizingCost = 30.00 * noOfFertilizer;

    while(true)
    {
        cout << "Please enter the number of trees to be planted: ";
        cin >> noOfTrees;

        if(cin.fail() || noOfTrees <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else
        {
            break;
        }
    }
    // $50.00 per tree
    plantingCost = 50.00 * noOfTrees;
    bill = mowingCost + fertilizingCost + plantingCost;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "The bill is $" << bill << "." << endl;

    return 0;
}