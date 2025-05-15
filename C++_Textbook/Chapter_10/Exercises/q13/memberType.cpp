#include <iostream>
#include <iomanip>
#include "memberType.h"

using namespace std;

// Class Function Definitions
/**
 * memberType::printMember: Prints all non-empty/non-zero fields of the member in a formatted manner
 */
void memberType::printMember()
{
    cout << "+" << setw(16) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << ((!name.empty()) ? "| Member Name: " + name + "\n" : "");
    cout << ((!ID.empty()) ? "| Member ID: " + ID + "\n" : "");
    if(booksPurchased != 0)
        cout << "| Purchased Books: " << booksPurchased << endl;
    if(amountSpent != 0.0)
        cout << "| Amount Spent: $" << fixed << showpoint << setprecision(2) << amountSpent << endl;
    cout << "+" << setw(16) << setfill('=') << "" << "+" << endl << setfill(' ');
}

// +==== Class Setters and Getters ====+
/**
 * memberType::setID: Validates then sets the ID of the member in the class
 * @param string value - The value containing the ID
 */
void memberType::setID(string value)
{   
    // Reinitialize ID to ""
    ID = "";

    // Verify if all characters in the passed string are digits
    for(int i = 0; i < value.size(); i++)
        if(value[i] < '0' || value[i] > '9')
        {
            cout << "Error: ID must consist of only digits." << endl;
            return;
        }
    
    ID = value;
}

/**
 * memberType::setBooksPurchased: Validates then sets the booksPurchased of the member in the class
 * @param int value - The value containing the booksPurchased
 */
void memberType::setBooksPurchased(int value)
{
    // Reinitialize booksPurchased to 0
    booksPurchased = 0;

    // Verify if passed value is not a negative value.
    if(value < 0)
    {
        cout << "Error: The number of books purchased must be zero or higher." << endl;
        return;
    }

    booksPurchased = value;
}

/**
 * memberType::setAmountSpent: Validates then sets the amountSpent of the member in the class
 * @param double value - The value containing the amountSpent
 */
void memberType::setAmountSpent(double value)
{
    // Reinitialize amountSpent to 0.0
    amountSpent = 0.0;

    // Verify if passed value is not a negative value.
    if(value < 0.0)
    {
        cout << "Error: The amount spent must be zero or higher." << endl;
        return;
    }

    amountSpent = value;
}

/**
 * memberType::memberType: Default Constructor
 * @param string member - The name of the member
 * @param string memberID - The ID of the member
 * @param int books - The number of books purchased
 * @param double spent - The amount of money spent
 */
memberType::memberType(string member, string memberID, int books, double spent)
{
    setName(member);
    setID(memberID);
    setBooksPurchased(books);
    setAmountSpent(spent);
}