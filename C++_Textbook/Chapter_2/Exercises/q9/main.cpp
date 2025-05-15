// Average of 5 Test Scores
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double testScores[5];
    double sum = 0.0;

    for(int i = 0; i < 5; i++)
    {
        while(true)
        {
            cout << "Enter the score for Test " << i + 1 << ": ";
            cin >> testScores[i];

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
        sum += testScores[i];
    }

    cout << fixed << setprecision(2);
    cout << "The average of the 5 test scores is: " << sum / 5.0 << endl;

    return 0;
}