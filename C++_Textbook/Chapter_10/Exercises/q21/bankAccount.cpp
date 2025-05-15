#include <iostream>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

// Initialize Static Variable
int bankAccount::nextAccountNumber = 1000;

/**
 * bankAccount::printAccount: Prints the information of the bank account
 */
void bankAccount::printAccount()
{
    cout << "+===== " << accountType << "'s Account =====+" << endl;
    cout << left << setw(18) << "| Name: " << accountName << endl;
    cout << left << setw(18) << "| Account #: " << accountNumber << endl;
    cout << left << setw(18) << "| Balance: " << "$" << fixed << showpoint << setprecision(2) << accountBalance << endl;
    cout << left << setw(18) << "| Interest Rate: " << fixed << showpoint << setprecision(2) << interestRate << "%" << endl;
    cout << "+" << setfill('=') << setw(22 + accountType.size()) << "" << "+" << endl << setfill(' ');
}

/**
 * bankAccount::bankAccount: Default Constructor
 * @param string name - The name of the account
 * @param string type - The type of account (checking/saving)
 * @param double balance - The balance amount of the account
 * @param double rate - The interest rate of the account
 */
bankAccount::bankAccount(string name, string type, double balance, double rate)
{
    setAccountName(name);
    accountNumber = nextAccountNumber++;
    setAccountType(type);
    setAccountBalance(balance);
    setInterestRate(rate);
}