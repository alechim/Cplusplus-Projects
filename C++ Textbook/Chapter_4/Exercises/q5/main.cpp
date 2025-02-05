// Question 5: Determine Right Triangle
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int a = 0;
    int b = 0;
    int c = 0;

    do
    {
        cout << "Please enter the three sides of the triangle: ";
        cin >> a >> b >> c;
        
        if(cin.fail() || a < 0 || b < 0 || c < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 3 positive integer values." << endl;
        } else
            break;
    } while(true);
    
    // Original: c = sqrt(a^2 + b^2)
    /* Updated:
     * - Used fabs and a tolerance of 0.000001 from Exercise 4-A to consider minute floating point calculations
     */
    if(fabs(sqrt(pow(a, 2) + pow(b, 2)) - c) < 0.000001 || 
       fabs(sqrt(pow(b, 2) + pow(c, 2)) - a) < 0.000001 || 
       fabs(sqrt(pow(c, 2) + pow(a, 2)) - b) < 0.000001)
        cout << "This is a right triangle." << endl;
    else
        cout << "This is not a right triangle." << endl;

    return 0;
}