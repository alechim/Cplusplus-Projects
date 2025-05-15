// Question 3: Weight Conversion (Kilogram to Pounds)
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double weight = 0.0;
    double convertWeight = 0.0;

    // Prompt for Input
    while(true)
    {
        cout << "Please enter your weight in kilograms: ";
        cin >> weight;

        if(cin.fail() || weight <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
        {
            break;
        }
    }

    // Calculations
    convertWeight = weight * 2.2;       // 1 kilogram = 2.2 pounds

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The equivalent weight of " << weight << " kilograms is " << convertWeight << " pounds." << endl;

    return 0;
}