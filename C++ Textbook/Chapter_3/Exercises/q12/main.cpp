// Question 12: Shortest Distance between Two Moving Vehicles
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int carX = 0;
    int carY = 0;
    double convertHours = 0.0;
    double hours = 0.0;
    double minutes = 0.0;
    double distanceX = 0.0;
    double distanceY = 0.0;
    double shortestDistance = 0.0;

    // Prompt for Input
    do
    {
        cout << "Please enter the average speed of the 1st car (mph): ";
        cin >> carX;
        if(cin.fail() || carX <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }
        
        cout << "Please enter the average speed of the 2nd car (mph): ";
        cin >> carY;
        if(cin.fail() || carY <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the elapsed time (hours:minutes): ";
        cin >> hours >> minutes;
        if(cin.fail() || hours < 0 || minutes < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two positive double values." << endl;
            continue;
        }
        break;
    } while (true);

    // Calculations
    convertHours = hours + (minutes / 60.0);
    distanceX = carX * convertHours;
    distanceY = carY * convertHours;
    shortestDistance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

    // Display Results
    cout << "The first car travels " << distanceX << " miles driving an average speed of " << carX << " mph." << endl;
    cout << "The second car travels " << distanceY << " miles driving an average speed of " << carY << " mph." << endl;
    cout << "Both cars travel for " << hours << " hours and " << minutes << " minutes." << endl;
    cout << "The shortest distance between both cars is " << shortestDistance << " miles." << endl;

    return 0;
}