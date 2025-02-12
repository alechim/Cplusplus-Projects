// Question 2: Approximate PI Calculation
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double PI = 0.0;
    long i = 0;
    long n = 0;

    // Prompt for Input
    do
    {
        cout << "Enter the value of n: ";
        cin >> n;
        cout << endl;
        if(cin.fail() || n <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else 
            break;
    } while(true);
    
    for(i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            PI = PI + (1.0 / (2 * i + 1));
        else
            PI = PI - (1.0 / (2 * i + 1));
    }
    PI *= 4.0;

    cout << fixed << setprecision(15);
    cout << endl << "PI = " << PI << endl;

    return 0;
}