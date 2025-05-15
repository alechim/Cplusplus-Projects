// Question 19: Convert Change to Pennies
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int change[3];  // Quarters, Dimes, Nickels
    int pennies;

    while(true)
    {
        cout << "Please enter the number of quarters, dimes, and nickels: ";
        cin >> change[0] >> change[1] >> change[2];

        if(cin.fail() || change[0] < 0 || change[1] < 0 || change[2] < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 3 positive integer values." << endl;
            cout << "Correct Usage: 'quarters' 'dimes' 'nickels'" << endl;
        } else
        {
            break;
        }
    }
    
    pennies = (change[0] * 25) + (change[1] * 10) + (change[2] * 5);

    cout << "There are " << change[0] << " Quarters, " << change[1] << " Dimes, and " << change[2] << " Nickels." << endl;
    cout << "The change in pennies is " << pennies << "." << endl;

    return 0;
}