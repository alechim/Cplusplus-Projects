// Question 6: Cookie Box Calculator
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int numOfCookies = 0;
    int cookiePerBox = 0;
    int boxPerContainer = 0;
    int totalBox = 0;
    int totalContainer = 0;
    int leftoverCookies = 0;
    int leftoverBoxes = 0;

    // Prompt for Input
    do
    {
        cout << "Enter the total number of cookies: ";
        cin >> numOfCookies;
        if(cin.fail() || numOfCookies <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        }

        cout << "Enter the number of cookies that can fit in a box: ";
        cin >> cookiePerBox;
        if(cin.fail() || cookiePerBox <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        }

        cout << "Enter the number of cookie boxes that can fit per container: ";
        cin >> boxPerContainer;
        if(cin.fail() || boxPerContainer <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
            break;  // Exit the loop if all inputs are valid
    } while(true);
    
    // Calculations
    totalBox = numOfCookies / cookiePerBox;
    leftoverCookies = numOfCookies % cookiePerBox;
    totalContainer = totalBox / boxPerContainer;
    leftoverBoxes = totalBox % boxPerContainer;

    // Display Results
    cout << "\nTo ship " << numOfCookies << " cookies:" << endl;
    cout << "- You need " << totalBox << " boxes and " << totalContainer << " containers." << endl;
    cout << "- Leftover cookies: " << leftoverCookies << endl;
    cout << "- Leftover boxes: " << leftoverBoxes << endl;

    // Edge Case Messages
    if (totalBox == 0) {
        cout << "Note: Not enough cookies to fill a single box." << endl;
    }
    if (totalContainer == 0) {
        cout << "Note: Not enough boxes to fill a single container." << endl;
    }
    cout << endl;
    
    return 0;
}