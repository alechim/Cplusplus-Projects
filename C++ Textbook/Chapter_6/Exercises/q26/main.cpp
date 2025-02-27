// Question 26: Calculate Inflation Rates
#include <iostream>
#include <iomanip>

using namespace std;

// ***Function Prototypes***
void promptInput(double& price1, double& price2, double& price3);
double calcInflation(double x, double y);
void displayResults(double rate, const string prompt);

int main()
{
    // Variables
    double p1 = 0.0;
    double p2 = 0.0;
    double p3 = 0.0;
    double rate1 = 0.0;
    double rate2 = 0.0;

    // Prompt for Input
    promptInput(p1, p2, p3);

    // Year 1 to Year 2
    rate1 = calcInflation(p3, p2);      
    displayResults(rate1, "The inflation rate from Year 2 to Year 1 is ");

    // Current to Year 1
    rate2 = calcInflation(p2, p1);
    displayResults(rate2, "The inflation rate from Year 1 to the current year is ");

    return 0;
}

// ***Functions***
void promptInput(double& price1, double& price2, double& price3)
{
    do
    {
        cout << "Enter the price of a product now, one year ago, and two years ago: ";
        cin >> price1 >> price2 >> price3;
        if(cin.fail() || price1 < 0.0 || price2 < 0.0 || price3 < 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter three non-zero positive double values." << endl;
        } else
            break;
    } while(true);
}

double calcInflation(double x, double y)
{
    return (x - y) / y;
}

void displayResults(double rate, const string prompt)
{
    cout << prompt;
    
    if(rate == 0)
        cout << "the same";
    else
        cout << ((rate > 0) ? "increasing" : "decreasing");

    cout << fixed << showpoint << setprecision(2);
    cout << " at a rate of " << abs(rate * 100.0) << "%.\n";
}