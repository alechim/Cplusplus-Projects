// Example 5-3: Revenue Selling Cookies
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    string name = "";
    int numOfVolunteers = 0;
    int numOfBoxesSold = 0;
    int totalNumOfBoxesSold = 0;
    int counter = 0;
    double costOfOneBox = 0.0;

    cout << fixed << showpoint << setprecision(2);
    cout << "Line 14: Enter the number of volunteers: ";
    cin >> numOfVolunteers;
    cout << endl;

    while(counter < numOfVolunteers)
    {
        cout << "Line 21: Enter the volunteer's name and the number of boxes sold: ";
        cin >> name >> numOfBoxesSold;
        cout << endl;
        totalNumOfBoxesSold = totalNumOfBoxesSold + numOfBoxesSold;
        counter++;
    }

    cout << "Line 27: The total number of boxes sold: " << totalNumOfBoxesSold << endl;
    cout << "Line 28: Enter the cost of one box: ";
    cin >> costOfOneBox;
    cout << endl;
    cout << "Line 31: The total money made by selling cookies: $" << totalNumOfBoxesSold * costOfOneBox << endl;

    if(counter != 0)
        cout << "Line 31: The average number of boxes sold by each volunteer: " << totalNumOfBoxesSold / counter << endl;
    else
        cout << "Line 35: No input." << endl;

    return 0;
}