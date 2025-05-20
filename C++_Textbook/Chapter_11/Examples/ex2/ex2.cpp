// Example 11-2: boxType Inheritance and rectangleType Program
#include <iostream>
#include <iomanip>
#include "rectangleType.h"
#include "boxType.h"

using namespace std;

int main()
{
    // Variables - Rectangle Class Object
    rectangleType yard;
    double fenceCostPerFoot = 0.0;
    double fertilizerCostPerSquareFoot = 0.0;
    double length = 0.0, width = 0.0;
    double billingAmount = 0.0;

    cout << fixed << showpoint << setprecision(2);
    cout << "Line 14: Enter the length and width of the yard (in feet): ";
    cin >> length >> width;
    cout << endl;

    yard.setDimension(length, width);

    cout << "Line 18: Enter the cost of fence (per foot): $";
    cin >> fenceCostPerFoot;
    cout << endl;

    cout << "Line 21: Enter the cost of fertilizer (per square foot): $";
    cin >> fertilizerCostPerSquareFoot;
    cout << endl;

    billingAmount = yard.perimeter() * fenceCostPerFoot + yard.area() * fertilizerCostPerSquareFoot;

    cout << "Line 25: Amount due: $" << billingAmount << endl << endl;

    // Variables - Box Class Object
    boxType package;
    double height = 0.0;
    double wrappingCostPerSquareFeet = 0.0;

    cout << "Line 29: Enter the length, width, and height of the package (in feet): ";
    cin >> length >> width >> height;
    cout << endl;

    package.setDimension(length, width, height);

    cout << "Line 33: Enter the cost (25 to 50 cents) of wrapping per square foot: ";
    cin >> wrappingCostPerSquareFeet;
    cout << endl;

    billingAmount = wrappingCostPerSquareFeet * package.area() / 100.0;

    if(billingAmount < 1.00)
        billingAmount = 1.00;
    
    // Added epsilon value to round up to correct cost
    cout << "Line 39: Amount due: $" << (billingAmount + 0.001) << endl;

    return 0;
}