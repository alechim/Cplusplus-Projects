// Question 25: Menu-Driven Fitness Center Membership
/**
 * Discounts:
 * - 30% - senior citizen
 * - 15% - paid 12+ months
 * - 20% each session - 5 < training sessions paid
 */
#include <iostream>
#include <iomanip>

using namespace std;

// ***Function Prototypes***
void promptInput(int& value, const string prompt);
void promptInput(char& value, const string prompt);
void displayInfo(double membership, double sessions);
double calculateCost(double membership, double sessions, double discount, double sessionDiscount, double noOfMonths, double noOfSessions);

int main()
{
    // Variables
    int months = 0;
    int noOfSessions = 0;
    int select = 0;
    char choice = ' ';

    // Membership & Session Cost Variables
    double mCost = 50.0;
    double sCost = 20.0;

    // Prompt for Input
    do
    {
        cout << "1: Display Info" << endl;
        cout << "2: Enter Information" << endl;
        cout << "3: Quit Menu" << endl;
        cout << "Enter selection: ";
        cin >> select;
        if(cin.fail() || (select < 1 || select > 3))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a valid choice [1-3]." << endl;
            continue;
        } 
        if(select == 1)
            displayInfo(mCost, sCost);
        else if(select == 2)
        {
            promptInput(choice, "Are you a senior-citizen? [y/n]: ");
            promptInput(months, "Enter the number of months you would like to purchase: ");
            promptInput(noOfSessions, "Enter the number of personal training sessions you would like to purchase: ");
            
            double discount = (choice == 'y') ? 0.3 : 0.0;
            discount += (months >= 12) ? 0.15 : 0.0;
            double sessionDiscount = (noOfSessions > 5) ? 0.20 : 0.0;
            
            // Display Results
            cout << "=====\n";
            cout << fixed << showpoint << setprecision(2);
            cout << "Total Cost: $" << calculateCost(mCost, sCost, discount, sessionDiscount, months, noOfSessions) << endl;
            cout << "=====\n";
        } else
            break;
    } while(true);
    
    return 0;
}

// ***Functions***
void promptInput(char& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || (value != 'y' && value != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
            break;
    } while (true);
}

void promptInput(int& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else
            break;
    } while (true);
}

void displayInfo(double membership, double sessions)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "=====\n";
    cout << "Monthly Cost: $" << membership << endl;
    cout << "Personal Training Session Cost: $" << sessions << endl;
    cout << "=====\n";
}

double calculateCost(double mCost, double sCost, double d, double sD, double months, double sessions)
{
    double membershipCost = (static_cast<double>(months) * mCost) * (1 - d);
    double sessionCost = (static_cast<double>(sessions) * sCost) * (1 - sD);
    return membershipCost + sessionCost;
}