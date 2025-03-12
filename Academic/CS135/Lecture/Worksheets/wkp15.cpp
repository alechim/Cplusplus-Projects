#include <iostream>

using namespace std;

// Function Prototypes
void readValues (double&, double&);
double multiply (double, double);

int main()
{
    // Variables
    double value1 = 0.0;
    double value2 = 0.0;
    double calc = 0.0;

    // Read Input and Calculate
    readValues (value1, value2);
    calc = multiply(value1, value2);

    // Display Results
    cout << value1 << " * " << value2 << " = " << calc << endl;

    return 0;
}

// Function Definitions
void readValues (double& frstValue, double& scndValue)
{
    cout << "Enter two numbers: ";
    cin >> frstValue >> scndValue;
}

double multiply (double valueOne, double valueTwo)
{
    return valueOne * valueTwo;
}
