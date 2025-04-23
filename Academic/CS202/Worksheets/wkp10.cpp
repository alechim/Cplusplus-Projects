#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

int main()
{
    // Variables
    double salary = 5500.00;
    double raise = 0.0;

    try
    {
        cout << "Please enter a value for raise: ";
        cin >> raise;

        if(raise < 0)
            throw runtime_error("Negative raise values are not allowed!");

        cout << fixed << showpoint << setprecision(2);
        cout << "Salary Increase: " << salary * (1 + raise / 100) << endl;
    }
    catch(const runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}