#include <iostream>
#include <iomanip>
#include "bookType.h"

using namespace std;

// Class Function Definitions
/**
 * bookType::printBook: Prints all non-empty/non-zero fields of the book in a formatted manner
 */
void bookType::printBook()
{
    if(!title.empty())
        cout << "Title: " << title << endl;
    
    if(noOfAuthors != 0)
        cout << "Authors: " << getAuthors() << endl;
    
    if(!publisher.empty())
        cout << "Publisher: " << publisher << endl;

    if(!ISBN.empty())
    {
        // ISBN-13 format: XXX-X-XXXXXX-XX-X
        if(ISBN.size() == 17) 
            cout << "ISBN-13: ";
        // ISBN-10 format: X-XXXXXX-XX-X
        else if(ISBN.size() == 13)
            cout << "ISBN-10: ";
        
        cout << getISBN() << endl;
    }

    if(price != 0.0)
        cout << fixed << showpoint << setprecision(2) << "Price: $" << price << endl;
    
    if(copies != 0)
        cout << "Copies: " << copies << endl;

    if(year != 0)
        cout << "Year: " << year << endl;
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