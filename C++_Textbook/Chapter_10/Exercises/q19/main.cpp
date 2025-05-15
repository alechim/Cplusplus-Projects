// Question 19: Calculate Retirement Funds in Account
#include <iostream>
#include <iomanip>
#include "retirementFund.h"

using namespace std;

// Function Prototypes
void promptInput(double&, string);
void promptInput(int&, string);

int main()
{
    // Variables
    double deposit = 0.0, rate = 0.0, target = 0.0;
    int noOfDeposits = 0, years = 0;
    int choice = 0;

    // Diplay and Prompt for Input
    cout << "+======= Retirement Fund Calculator =======+" << endl;
    promptInput(deposit, "| Enter the periodic deposit amount: $");
    promptInput(noOfDeposits, "| Enter the number of deposits per year: ");
    promptInput(rate, "| Enter the annual interest rate (%): ");
    promptInput(years, "| Enter the number of years: ");

    // Create the class object
    retirementFund myFund(deposit, noOfDeposits, rate / 100.0, years);

    // Display Menu for User Selection
    do
    {
        cout << "+" << setfill('=') << setw(50) << "" << "+" << endl;
        cout << "| 1. Calculate accumulated amount" << endl;
        cout << "| 2. Calculate periodic payment for a target amount" << endl;
        cout << "| 3. Update parameters" << endl;
        cout << "| 4. Exit" << endl;
        cout << "+" << setfill('=') << setw(50) << "" << "+" << endl;
        cout << "| Enter your choice: ";
        cin >> choice;

        // Validate Input
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+" << setfill('-') << setw(35) << "" << "+" << endl;
            cout << "| Invalid Input! Please enter an integer value." << endl;
            cout << "+" << setfill('-') << setw(35) << "" << "+" << endl;
            continue;
        }
        cout << "+" << setfill('-') << setw(35) << "" << "+" << endl;

        switch(choice)
        {
            case 1:
                myFund.accumulatedAmount();
                break;
            case 2:
                promptInput(target, "| Enter the target amount to accumulate: $");
                cout << "+" << setfill('-') << setw(35) << "" << "+" << endl;
                myFund.calculatePeriodicPayment(target, noOfDeposits, rate / 100.0, years);
                break;
            case 3: 
                promptInput(deposit, "| Enter the periodic deposit amount: $");
                myFund.setDeposit(deposit);

                promptInput(noOfDeposits, "| Enter the number of deposits per year: ");
                myFund.setTimesDeposit(noOfDeposits);

                promptInput(rate, "| Enter the annual interest rate (%): ");
                myFund.setInterest(rate / 100.0);

                promptInput(years, "| Enter the number of years: ");
                myFund.setYears(years);
                break;
            case 4:
                cout << "| Exiting Program... Goodbye!" << endl;
                cout << "+" << setfill('=') << setw(50) << "" << "+" << endl << endl;
                break;
            default: 
                cout << "+" << setfill('-') << setw(20) << "" << "+" << endl;
                cout << "| Invalid Input! Please enter a valid selection." << endl;
                cout << "+" << setfill('-') << setw(20) << "" << "+" << endl;
                break;
        }
    } while(choice != 4);
    
    return 0;
}

// Function Definitions
/**
 * promptInput: Gets and validates a double input from the user
 * @param double& value - Reference to the double variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(double& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else  
            break;
    } while(true);
}

/**
 * promptInput: Gets and validates an integer input from the user
 * @param int& value - Reference to the integer variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(int& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else  
            break;
    } while(true);
}