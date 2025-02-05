// Question 1: Declare Positive, Negative, or Zero
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int number = 0;

    // Prompt for Input
    do
    {
        cout << "Please enter an integer value: ";
        cin >> number;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else
            break;
    } while (true);
    
    if(number > 0)
        cout << "The number " << number << " is positive." << endl;
    else if (number < 0)
        cout << "The number " << number << " is negative." << endl;
    else
        cout << "The number is zero." << endl;

    return 0;
}