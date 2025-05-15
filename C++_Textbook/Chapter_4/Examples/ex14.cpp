// Example 4-14: Additional Charge on Suitcase
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double suitcaseDimension = 0.0;
    double suitcaseWeight = 0.0;
    double additionalCharges = 0.0;

    // Prompt User Input
    cout << fixed << showpoint << setprecision(2);
    cout << "Line 10: Enter suitcase dimensions (length + width + depth) in inches: ";
    cin >> suitcaseDimension;
    cout << endl;
    
    cout << "Line 13: Enter suitcase weight in pounds: ";
    cin >> suitcaseWeight;
    cout << endl;

    if(suitcaseDimension > 108 || suitcaseWeight > 50)
        additionalCharges = 50.00;
    
    cout << "Line 18: Additional suitcase charges: $" << additionalCharges << endl;

    return 0;
}