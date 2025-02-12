// Question 13: Collatz Conjecture Generator
// Question 14: Refactored: Added Max Value Found
/**
 * Given:
 * - a_0 = x
 *   > If even, a_(n+1) = a_n / 2
 *   > If odd, a_(n+1) = 3 * a_n + 1
 * - a_k = 1
 * Test Cases:
 * - x: 75, 111, 678, 732, 873, 2048, 65535
 * - Ex:
 *   > x = 75, then k = 14
 */
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int x = 0;
    int a = 0;
    int k = 0;
    int max = 0;

    // Prompt for Input
    do
    {
        cout << "Enter a non-zero positive integer value for x: ";
        cin >> x;
        if(cin.fail() || x <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
            break;
    } while(true);

    // Calculations and Display Results
    a = x;  // a_0 = x
    cout << "\nCollatz Sequence for x = " << x << ":\n";
    cout << "[ ";
    while(a != 1)
    {
        cout << a << ", "; 
        // Ternary Operator
        a = (a % 2 == 0) ? a / 2 : 3 * a + 1;
        if(max < a)
            max = a;
        k++;
    }
    cout << 1 << " ]" << endl; // Print final '1' properly formatted
    cout << "Total steps (k) to reach 1: " << k << endl;
    cout << "The max value in x is " << max << endl;

    return 0;
}