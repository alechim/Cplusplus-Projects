// Question 15: Calculate Windchill Factor
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ***Function Prototypes***
double windChillFactor(double V, double T);
void promptInput(double& value, const string prompt);

int main()
{
    // Variables
    double windSpeed = 0.0;
    double temperature = 0.0;

    // Prompt for Input
    promptInput(windSpeed, "Enter the wind speed in miles per hour: "); 
    promptInput(temperature, "Enter the temperature in degrees Fahrenheit: "); 

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The windchill factor is " << windChillFactor(windSpeed, temperature) << " degrees Fahrenheit.\n";

    return 0;
}

// ***Functions***
double windChillFactor(double V, double T)
{
    return 35.74 + 0.6215 * T - 35.75 * pow(V, 0.16) + 0.4275 * T * pow(V, 0.16);
}

void promptInput(double& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        cout << endl;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}