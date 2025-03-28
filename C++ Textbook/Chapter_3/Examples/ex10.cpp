// Example 3-10: Scientific and Fixed Manipulators
#include <iostream>

using namespace std;

int main()
{
    // Variables
    double hours = 35.45;
    double rate = 15.00;
    double tolerance = 0.01000;

    cout << "hours = " << hours << ", rate = " << rate << ", pay = " << hours * rate << ", tolerance = " << tolerance << endl << endl;
    cout << scientific;
    cout << "Scientific Notation: " << endl;
    cout << "hours = " << hours << ", rate = " << rate << ", pay = " << hours * rate << ", tolerance = " << tolerance << endl << endl;

    cout << fixed;
    cout << "Fixed Decimal Notation: " << endl;
    cout << "hours = " << hours << ", rate = " << rate << ", pay = " << hours * rate << ", tolerance = " << tolerance << endl << endl;

    return 0;
}