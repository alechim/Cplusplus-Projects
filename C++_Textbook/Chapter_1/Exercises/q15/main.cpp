// Question 15: Price of Pizza per square inch
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    const double PI = 3.14159;
    double radius = 0.0;
    double area = 0.0;
    double price = 0.0;
    double pricePerSquareInch = 0.0;

    while(true)
    {
        cout << "Enter the size / radius of the pizza (inches): ";
        cin >> radius;

        if(cin.fail() || radius <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a double value." << endl;
        } else
        {
            break;
        }
    }
    while(true)
    {
        cout << "Enter the price of the pizza ($): ";
        cin >> price;

        if(cin.fail() || price <= 0)
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
    area = PI * (radius * radius);
    pricePerSquareInch = price / area;

    // Display results
    cout << fixed << setprecision(2);
    cout << "The area of the pizza is " << area << " square inches." << endl;
    cout << "The total price of the pizza is $" << pricePerSquareInch << endl;

    return 0;
}