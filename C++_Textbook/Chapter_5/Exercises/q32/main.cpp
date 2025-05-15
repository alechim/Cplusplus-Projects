// Question 31: Approximate the value of e (2nd Formula)
// Test Program for n = 3, 5, 10, 50, and 100
/**
 * Given Formula:
 * - 2 + 1/(1 + 1)/(2 + 2)/(3 + 3).../(n - 1) + ((n - 1) / (n + n))
 * - Value of e (9th decimal) = 2.718281827
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int num = 0;
    double approx = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter one of the following numbers: (3, 5, 10, 50, 100): ";
        cin >> num;
        if(cin.fail() || (num != 3 && num != 5 && num != 10 && num != 50 && num != 100))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 3, 5, 10, 50, or 100." << endl;
        } else
            break;
    } while(true);
    
    // Initialize the denominator
    approx = static_cast<double>(num + num);
    // Build the continued fraction iteratively from the inside
    for (int i = num - 1; i >= 1; i--)
        approx = i + (static_cast<double>(i) / approx);
    // Final Calculation
    approx = 2.0 + (1.0 / approx);

    // Display Results
    cout << fixed << showpoint << setprecision(9);
    cout << "The value of e to nine decimal places is e = 2.718281827" << endl;
    cout << "The calculated approximate value of e = " << approx << endl;

    return 0;
}