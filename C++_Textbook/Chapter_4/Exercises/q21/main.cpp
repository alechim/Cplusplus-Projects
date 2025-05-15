// Question 21: X-Y Plane Line
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    // Prompt for Input
    do
    {
        cout << "Enter the first point on the x-y plane (x1, y1): ";
        cin >> x1 >> y1;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 2 integer values." << endl;
            continue;
        }

        cout << "Enter the second point on the x-y plane (x2, y2): ";
        cin >> x2 >> y2;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 2 integer values." << endl;
        } else
            break;
    } while(true);
    
    // Conditionals
    if(x1 == x2)
        cout << "The line is vertical, x = " << x1 << "." << endl;
    else if(y1 == y2)
        cout << "The line is horizontal. y = " << y1 << "." << endl;
    else 
    {
        // Calculations
        double m = static_cast<double>(y2 - y1) / static_cast<double>(x2 - x1);
        double b = static_cast<double>(y1) - (m * static_cast<double>(x1));

        // Display Results
        cout << fixed << setprecision(2);
        if(m > 0)
            cout << "The line is increasing, ";
        else
            cout << "The line is decreasing, ";

        if (b == 0)
            cout << "y = " << m << "x." << endl;
        else if (b > 0)
            cout << "y = " << m << "x + " << b << "." << endl;
        else
            cout << "y = " << m << "x - " << -b << "." << endl;
    }

    return 0;
}