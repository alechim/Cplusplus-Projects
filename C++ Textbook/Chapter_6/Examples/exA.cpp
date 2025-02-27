// Example 6-A: Largest of Three Numbers
#include <iostream>

using namespace std;

// ***Function Prototypes***
double larger(double x, double y);
double compareThree(double x, double y, double z);

int main()
{
    // Variables
    double one = 0.0;
    double two = 0.0;

    cout << "Line 8: The larger of 5 and 10 is " << larger(5, 10) << endl;
    cout << "Line 9: Enter two numbers: ";
    cin >> one >> two;
    cout << endl;

    cout << "Line 12: The larger of " << one << " and " << two << " is " << larger(one, two) << endl;
    cout << "Line 13: The largest of 43.48, 34.00, and 12.65 is " << compareThree(43.48, 34.00, 12.65) << endl; 

    return 0;
}

// ***Functions***
double larger(double x, double y)
{
    // Variables
    double max = 0.0;
    max = (x >= y) ? x : y;
    return max;
}

double compareThree(double x, double y, double z)
{
    return larger(x, larger(y, z));
}