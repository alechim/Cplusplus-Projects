// Question 7: Rounds the double value to the nearest integer
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    double a = 0.0;

    while(true)
    {
        cout << "Enter a double value: ";
        cin >> a;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a double value." << endl;
        } else
        {
            break;
        }
    }

    cout << "The rounded value of " << a << " is " << round(a) << "." << endl;

    return 0;
}