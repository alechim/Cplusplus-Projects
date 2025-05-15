// Question 16: Least Amount Accepted for a Car
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double carCost = 0.0;

    // Prompt Input
    while(true)
    {
        cout << "Please enter the cost of the car ($): ";
        cin >> carCost;

        if(cin.fail() || carCost <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a double value." << endl;
        } else 
        {
            break;
        }
    }

    // Calculations
    double dealerCost = carCost * 0.85;
    double offer = dealerCost + 500;

    cout << fixed << setprecision(2) << "The least amount the dealer will accept is $" << offer << endl;

    return 0;
}