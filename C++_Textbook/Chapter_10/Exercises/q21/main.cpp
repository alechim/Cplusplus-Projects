// Question 21: bankAccount Class Program
#include <iostream>
#include <string>
#include "bankAccount.h"

using namespace std;

// Function Prototypes
void initializeCustomers(bankAccount[]);

int main()
{   
    // Values set using constructor
    bankAccount customers[10] = {
        {"John Smith", "Checking", 1500.75, 0.5},
        {"Sarah Johnson", "Savings", 5250.50, 1.25},
        {"Michael Brown", "Checking", 750.25, 0.5},
        {"Emma Wilson", "Savings", 10500.00, 1.5},
        {"Robert Garcia", "Checking", 3200.80, 0.75}
    };

    initializeCustomers(customers);

    cout << "+===== Bank Account Information =====+" << endl << endl;
    for(int i = 0; i < 10; i++)
    {
        customers[i].printAccount();
        cout << endl;
    }

    return 0;
}

// Function Definitions
/**
 * initializeCustomers: Initializes the last 5 customers using parallel arrays
 * @param bankAccount customers[] - The class object
 */
void initializeCustomers(bankAccount customers[])
{   
    // Parallel Arrays
    string name[5] = {"Lisa Chen", "David Rodriguez", "Amanda Taylor", "James Martinez", "Jennifer Thompson"};
    string type[5] = {"Savings", "Checkings", "Savings", "Checkings", "Savings"};
    double amount[5] = {7800.45, 2100.30, 4500.90, 900.15, 15000.25};
    double rate[5] = {1.35, 0.5, 1.2, 0.6, 1.75};

    // Set values for remaining customers using class setters
    for(int i = 0; i < 5; i++)
    {
        customers[i + 5].setAccountName(name[i]);
        customers[i + 5].setAccountType(type[i]);
        customers[i + 5].setAccountBalance(amount[i]);
        customers[i + 5].setInterestRate(rate[i]);
    }
}