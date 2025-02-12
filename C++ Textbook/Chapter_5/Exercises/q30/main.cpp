// Question 30: Approximate the value of e (Limits)
/**
 * Given Equation:
 * - lim_(n->inf)[1 + (1/n)]^n
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int min = 0;
    int max = 0;
    int count = 1;
    double approx = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter the lower bounds (min: 1): ";
        cin >> min;
        if(cin.fail() || min < 1)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value that is greater than or equal to 1." << endl;
            continue;
        }

        cout << "Enter the upper bounds (must be larger than min): ";
        cin >> max;
        if(cin.fail() || max < min)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value that is greater than the lower bounds." << endl;
        } else
            break;
    } while(true);
    
    // Calculations and Display Results
    cout << fixed << showpoint << setprecision(9);
    cout << "The value of e to nine decimal places is e = 2.718281827" << endl;
    cout << "=====" << endl;
    for(int i = min; i <= max; i += min)
    {
        approx = pow((1.0 + (1.0 / static_cast<double>(i))), static_cast<double>(i));
        cout << "Step " << count << ": " << approx << endl;
        count++;
    }

    return 0;
}