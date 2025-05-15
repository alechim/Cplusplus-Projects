// Question 5: Area and Circumference of a Circle
#include <iostream>

using namespace std;

int main()
{
    // Variables
    const double PI = 3.14;
    double radius = 0.0;
    double area = 0.0;
    double circumference = 0.0;

    while(true)
    {
        cout << "Enter the radius: ";
        cin >> radius;

        if(cin.fail() || radius <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero double value." << endl;
        } else
        {
            break;
        }
    }

    // Calculations
    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    // Display Results
    cout << "Area = " << area << endl;
    cout << "Circumference = " << circumference << endl;

    return 0;
}