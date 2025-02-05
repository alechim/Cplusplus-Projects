// Question 10: Round up the sum of double values
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    double values[5];
    double sum = 0.0;
    
    for(int i = 0; i < 5; i++)
    {
        while(true)
        {
            cout << "Enter the score for Test " << i + 1 << ": ";
            cin >> values[i];

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
        sum += values[i];
    }

    cout << "The sum of the doubles is " << sum << "." << endl;
    cout << "The rounded value of the sum of doubles is " << round(sum) << "." << endl;

    return 0;
}