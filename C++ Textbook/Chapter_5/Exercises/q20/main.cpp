// Question 20: Loan Calculator
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// *** Functions ***
// promptInput(value, prompt)
void promptInput(double& value, const string& prompt)
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

int main()
{
    // Variables
    double loan = 0.0;
    double payment = 0.0;
    int months = 1;
    char select = ' ';
    double minPayment = 0.0;
    double interestRate = 0.0;
    double monthlyRate = 0.0;
    double totalInterest = 0.0;

    // Prompt for Input
    promptInput(loan, "Enter the loan amount: $");
    promptInput(interestRate, "Enter the interest per year as a percentage: ");
    do
    {
        cout << "Would you like to setup automatic payments (y/n)? ";
        cin >> select;
        if(cin.fail() || (select != 'y' && select != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
            break;
    } while(true);
    
    // Calculations 
    monthlyRate = (interestRate / 100) / 12;
    switch(select)
    {
        case 'y':
            promptInput(payment, "How much will you pay the loan back monthly? $");
            if(payment < (loan * monthlyRate))
            {
                cout << "The payment for this month is too low, the loan cannot be repaid." << endl;
                return 0;
            }
            while(loan > 0.0)
            {
                // Make sure loan does not go negative
                if (payment > (loan + (loan * monthlyRate)))
                    payment = loan + (loan * monthlyRate);
                loan -= (payment - (loan * monthlyRate));
                months++;
                totalInterest += loan * monthlyRate;
            }
            break;
        case 'n':
            double interestForMonth = 0.0;
            cout << fixed << showpoint << setprecision(2);
            while (loan > 0)  
            {
                // Calculate minimum payment (example: 2% of loan + interest)
                minPayment = (loan * 0.02) + (loan * monthlyRate);  
                cout << "Current Loan Balance: $" << loan << endl;
                cout << "Minimum Payment: $" << minPayment << endl;

                // Prompt user for payment
                promptInput(payment, "Enter your monthly payment amount: $");

                // Ensure the payment is at least the interest for the month
                if (payment < (loan * monthlyRate))
                {
                    cout << "Your payment is too low to cover the interest. The loan will never be repaid." << endl;
                    continue;  
                }

                // Calculate interest and update total interest paid
                interestForMonth = loan * monthlyRate;
                totalInterest += interestForMonth;

                // If last payment exceeds remaining loan, adjust it
                if (payment > (loan + interestForMonth))
                {
                    cout << "Your last payment is greater than the remaining loan amount + interest." << endl;
                    cout << "Loan before last payment: $" << loan << endl;
                    cout << "Last payment adjusted to: $" << (loan + interestForMonth) << endl;
                    payment = loan + interestForMonth;  
                }

                // Reduce loan balance
                loan -= (payment - interestForMonth);
                months++;
            }
            break;
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "Final Balance: $" << loan << endl;
    cout << "Loan paid off in " << months << " months." << endl;
    cout << "Total interest paid: $" << totalInterest << endl; 

    return 0;
}