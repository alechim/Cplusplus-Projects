// Question 13: Loan Periodic Payment
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// ***Function Prototypes***
double periodicPayment(double loan, double interestRate, int monthlyPayments, int loanPeriod);
double unpaidBalance(double periodicPay, double interestRate, int monthlyPayments, int loanPeriod, int noOfPayments);
void promptInput(double& value, const string prompt);
void promptInput(int& value, const string prompt);

int main()
{
    // Variables
    double loanAmount = 0.0;
    double ratePerYear = 0.0;
    int monthlyPayments = 0;
    int loanPeriod = 0;
    int noOfPayments = 0;
    char choice = ' ';

    // Menu-driven program
    do
    {
        cout << "Do you want to run the program? [y/n]: ";
        cin >> choice;
        if(cin.fail() || (choice != 'y' && choice != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
            continue;
        } else if(choice == 'n')
            break;

        // Prompt for Input
        promptInput(loanAmount, "Enter the loan amount: $");
        promptInput(ratePerYear, "Enter the interest rate per year (%): ");
        promptInput(monthlyPayments, "Enter the number of payments in a year: ");
        promptInput(loanPeriod, "Enter the years in the loan period: ");
        promptInput(noOfPayments, "Enter the number of payments made: ");

        double interestRate = (ratePerYear / 100) / monthlyPayments;
        double perPayment = periodicPayment(loanAmount, interestRate, monthlyPayments, loanPeriod);
        cout << fixed << showpoint << setprecision(2);
        cout << "The periodic payment is $" << perPayment << ".\n";
        cout << "The unpaid balance after making " << noOfPayments << " payments is $" << unpaidBalance(perPayment, interestRate, monthlyPayments, loanPeriod, noOfPayments) << ".\n";

    } while(true);

    return 0;
}

// ***Functions***
double periodicPayment(double loan, double interestRate, int monthlyPayments, int loanPeriod)
{
    // L: loan, i: interestRate, m: monthlyPayments, t: loanPeriod
    // L = Li / 1 - (1 + i)^(-mt)
    return ((loan * interestRate) / (1 - pow((1 + interestRate), -(monthlyPayments * loanPeriod))));
}

double unpaidBalance(double periodicPay, double interestRate, int monthlyPayments, int loanPeriod, int noOfPayments)
{
    // R: periodicPay, i: interestRate, m: monthlyPayments, t: loanPeriod, k: noOfPayments
    // L' = R[(1 - (1 + i)^-(mt - k)) / i]
    return (periodicPay * ((1 - pow((1 + interestRate), -((monthlyPayments * loanPeriod) - noOfPayments))) / interestRate));
}

void promptInput(double& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        cout << endl;
        if(cin.fail() || value <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}

void promptInput(int& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        cout << endl;
        if(cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
            break;
    } while(true);
}