#include <iostream>
#include <iomanip>
#include "bookStore.h"

using namespace std;

// Class Function Definitions - bookType
/**
 * bookType::printBook: Prints all non-empty/non-zero fields of the book in a formatted manner
 */
void bookType::printBook()
{
    cout << "+" << setw(16) << setfill('=') << "" << "+" << endl << setfill(' ');
    if(!title.empty())
        cout << "| Title: " << title << endl;
    
    if(noOfAuthors != 0)
        cout << "| Authors: " << getAuthors() << endl;
    
    if(!publisher.empty())
        cout << "| Publisher: " << publisher << endl;

    if(!ISBN.empty())
    {
        // ISBN-13 format: XXX-X-XXXXXX-XX-X
        if(ISBN.size() == 17) 
            cout << "| ISBN-13: ";
        // ISBN-10 format: X-XXXXXX-XX-X
        else if(ISBN.size() == 13)
            cout << "| ISBN-10: ";
        
        cout << getISBN() << endl;
    }

    if(price != 0.0)
        cout << fixed << showpoint << setprecision(2) << "| Price: $" << price << endl;
    
    if(copies != 0)
        cout << "| Copies: " << copies << endl;

    if(year != 0)
        cout << "| Year: " << year << endl;
    cout << "+" << setw(16) << setfill('=') << "" << "+" << endl << setfill(' ');
}

/**
 * bookType::setAuthors: Sets up to 4 authors for the book
 * @param string name1 - First author's name
 * @param string name2 - Second author's name
 * @param string name3 - Third author's name
 * @param string name4 - Fourth author's name
 */
void bookType::setAuthors(string name1, string name2, string name3, string name4)
{
    // Set authors array
    authors[0] = name1;
    authors[1] = name2;
    authors[2] = name3;
    authors[3] = name4;

    // Determine number of authors
    if(name1.empty())           noOfAuthors = 0;
    else if(name2.empty())      noOfAuthors = 1;
    else if(name3.empty())      noOfAuthors = 2;
    else if(name4.empty())      noOfAuthors = 3;
    else                        noOfAuthors = 4;
}

/**
 * bookType::getAuthors const: Returns a comma-separated list of all authors
 * @return string - Formatted string containing all authors' names
 */
string bookType::getAuthors() const
{
    if(noOfAuthors == 0)    return "No Authors.";

    string totalAuthors = authors[0];
    for(int i = 1; i < noOfAuthors; i++)
        totalAuthors += ", " + authors[i];

    return totalAuthors;
}

/**
 * bookType::setISBN: Sets and validates the ISBN number
 * @param string value - ISBN to set (must be 10 or 13 digits)
 */
void bookType::setISBN(string value)
{
    // Validate length
    if(value.empty()) 
    {
        ISBN = "";
        return;
    }

    // Validate that ISBN has 10 or 13 digits
    if(value.size() != 10 && value.size() != 13)
    {
        cout << "Error: ISBN must be 10 or 13 digits." << endl;
        ISBN = "";
        return;
    }

    // Validate that all characters are digits
    for(int i = 0; i < value.size(); i++) 
    {
        if (value[i] < '0' || value[i] > '9') 
        {
            cout << "Error: ISBN must contain only digits." << endl;
            ISBN = "";
            return;
        }
    }

    if(value.size() == 13)
        ISBN = value.substr(0, 3) + "-" + value.substr(3, 1) + "-" + value.substr(4, 6) + "-" + value.substr(10, 2) + "-" + value.substr(12, 1);
    else if(value.size() == 10)
        ISBN = value.substr(0, 1) + "-" + value.substr(1, 6) + "-" + value.substr(7, 2) + "-" + value.substr(9, 1);
}

/**
 * bookType::bookType: Default Constructor
 * @param string bookTitle - Title of the book
 * @param string author1 - First author's name
 * @param string author2 - Second author's name
 * @param string author3 - Third author's name
 * @param string author4 - Fourth author's name
 * @param string bookPub - Publisher of the book
 * @param string isbnNo - ISBN number (10 or 13 digits)
 * @param double priceNo - Price of the book
 * @param int copiesNo - Number of copies in inventory
 * @param int yearNo - Year of publication
 */
bookType::bookType(string bookTitle, string author1, string author2, string author3, string author4, string bookPub, string isbnNo, double priceNo, int copiesNo, int yearNo)
{
    setTitle(bookTitle);
    setAuthors(author1, author2, author3, author4);
    setPublisher(bookPub);
    setISBN(isbnNo);
    setPrice(priceNo);
    setCopies(copiesNo);
    setYear(yearNo);
}

// Class Function Definitions - memberType
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
 * memberType::addPurchase: Sets member array of the current index to price then increments the index
 * @param double price - The price to be stored in the array
 */
void memberType::addPurchase(double price)
{
    lastTenPrices[priceIndex] = price;
    priceIndex = (priceIndex + 1) % 10;     // Circular buffer
}

/**
 * memberType::getAveragePrices const: Calculates the average of the values within the member array
 * @return double - The average price from the array
 */
double memberType::getAveragePrices() const
{
    double sum = 0.0;
    for(int i = 0; i < 10; i++)
        sum += lastTenPrices[i];
    return sum / 10.0;
}

/**
 * memberType::resetPriceTracking: Resets the all indexes of the member array and the index of the array to 0
 */
void memberType::resetPriceTracking()
{
    for(int i = 0; i < 10; i++)
        lastTenPrices[i] = 0.0;
    priceIndex = 0;
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
    resetPriceTracking();
}