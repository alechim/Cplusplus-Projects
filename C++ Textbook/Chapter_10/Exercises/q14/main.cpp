// Question 14: Simulated Bookstore using bookType and memberType Classes
// - Two types of customers
//   > $10 yearly membership & 5% discount on each book
//   > Regular Customer
// - For every 11th book a member buys, the bookstore takes the average of the total amount of the last 10 books purchased,
//   applies the discount, and then resets the total to 0.
#include <iostream>
#include <iomanip>
#include "bookStore.h"

using namespace std;

// Function Prototypes
void displayBooks(bookType[], int);
void addBook(bookType[], int&);
void displayMembers(memberType[], int);
void addMember(memberType[], int&);
void processPurchase(bookType[], int, memberType[], int);
void printReceipt(bool, string, string, int, double, double);

int main()
{
    // Variables
    bookType books[1000];
    memberType members[500];
    int bookIndex = 0, memberIndex = 0;
    int choice = 0;

    // Initialize some books in the array
    books[0] = bookType("The Great Gatsby", "F. Scott Fitzgerald", "", "", "", "Scribner", "9780743273565", 15.99, 10, 1925);
    books[1] = bookType("To Kill a Mockingbird", "Harper Lee", "", "", "", "Harper Perennial", "9780060935467", 12.99, 15, 1960);
    books[2] = bookType("1984", "George Orwell", "", "", "", "Signet Classic", "9780451524935", 9.99, 20, 1949);
    bookIndex = 3;

    // Initialize one member
    members[0] = memberType("John Doe", "001", 0, 0.0);
    memberIndex = 1;

    // Menu-Driven Program
    do
    {
        // Display Menu
        cout << "+===== BOOKSTORE MANAGEMENT SYSTEM =====+" << endl;
        cout << "| 1. Display All Books" << setw(18) << "" << "|" << endl;
        cout << "| 2. Add a Book" << setw(25) << "" << "|" << endl;
        cout << "| 3. Display All Members" << setw(16) << "" << "|" << endl;
        cout << "| 4. Add a Member" << setw(23) << "" << "|" << endl;
        cout << "| 5. Process Book Purchase" << setw(14) << "" << "|" << endl;
        cout << "| 6. Exit" << setw(31) << "" << "|" << endl;
        cout << "+" << setw(39) << setfill('=') << "" << "+" << endl << setfill(' ');
        cout << "| Enter your choice: ";

        // Prompt and Validate Choice
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayBooks(books, bookIndex);
                break;
            case 2:
                addBook(books, bookIndex);
                break;
            case 3:
                displayMembers(members, memberIndex);
                break;
            case 4:
                addMember(members, memberIndex);
                break;
            case 5:
                processPurchase(books, bookIndex, members, memberIndex);
                break;
            case 6:
                cout << "+" << setw(39) << setfill('=') << "" << "+" << endl << setfill(' ');
                cout << "| Thank you for using the Bookstore Management System. Goodbye!" << endl;
                cout << "+" << setw(39) << setfill('=') << "" << "+" << endl << setfill(' ');
                break;
            default:
                cin.clear();
                cin.ignore(40, '\n');
                cout << "| Invalid Choice. Please try again." << endl;
                cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
        }
    } while(choice != 6);

    return 0;
}

// Function Definition
/**
 * displayBooks: Displays all books currently in the inventory
 * @param bookType books[] - Array of book objects to be displayed
 * @param int index - Number of books currently in the inventory
 */
void displayBooks(bookType books[], int index)
{
    cout << "+===== BOOK INVENTORY =====+" << endl;
    
    if(index == 0)
    {
        cout << "There are no books in our inventory." << endl;
        return;
    }

    for(int i = 0; i < index; i++)
    {
        cout << "| Book #" << i + 1 << ":" << endl;
        books[i].printBook();
    }
    cout << endl;
}

/**
 * addBook: Adds a new book to the inventory
 * @param bookType books[] - Array of book objects where the new book will be added
 * @param int& index - Reference to the current number of books in inventory (will be incremented)
 */
void addBook(bookType books[], int& index)
{
    // Variables
    string title, author1, author2, author3, author4, publisher, isbn;
    double price;
    int copies, year;

    cin.ignore(40, '\n');

    cout << "+===== ADD NEW BOOK =====+" << endl;
    cout << "| Enter Title: ";
    getline(cin, title);
    
    cout << "| Enter Primary Author: ";
    getline(cin, author1);
    
    cout << "| Enter Second Author (leave blank if none): ";
    getline(cin, author2);
    
    cout << "| Enter Third Author (leave blank if none): ";
    getline(cin, author3);
    
    cout << "| Enter Fourth Author (leave blank if none): ";
    getline(cin, author4);
    
    cout << "| Enter Publisher: ";
    getline(cin, publisher);
    
    cout << "| Enter ISBN: ";
    getline(cin, isbn);
    
    cout << "| Enter Price: $";
    cin >> price;
    
    cout << "| Enter Number of Copies: ";
    cin >> copies;
    
    cout << "| Enter Publication Year: ";
    cin >> year;
    
    books[index] = bookType(title, author1, author2, author3, author4, publisher, isbn, price, copies, year);
    index++;

    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Book added successfully!" << endl;
    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
}

/**
 * displayMembers: Displays all registered members in the system
 * @param memberType members[] - Array of member objects to be displayed
 * @param int index - Number of members currently registered
 */
void displayMembers(memberType members[], int index)
{
    cout << "+===== MEMBER LIST =====+" << endl;
    
    if(index == 0)
    {
        cout << "There are no members registered." << endl;
        return;
    }

    for(int i = 0; i < index; i++)
    {
        cout << "| Member #" << i + 1 << ":" << endl;
        members[i].printMember();
    }
    cout << endl;
}

/**
 * addMember: Adds a new member to the system
 * @param memberType members[] - Array of member objects where the new member will be added
 * @param int& index - Reference to the current number of members (will be incremented)
 */
void addMember(memberType members[], int& index)
{
    string name, id;

    cin.ignore(40, '\n');

    cout << "+===== ADD NEW MEMBER =====+" << endl;
    cout << "| Enter Name: ";
    getline(cin, name);
    
    cout << "| Enter ID: ";
    getline(cin, id);

    // Check if ID already exists
    for(int i = 0; i < index; i++)
        if(members[i].getID() == id)
        {
            cout << "| Error: A member with this ID already exists." << endl;
            return;
        }
    
    members[index] = memberType(name, id, 0, 0.0);
    index++;

    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Member added successfully!" << endl;
    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
}

/**
 * processPurchase: Handles the book purchase transaction
 * @param bookType books[] - Array of book objects available for purchase
 * @param int bookIndex - Number of books currently in inventory
 * @param memberType members[] - Array of member objects for verification
 * @param int memberIndex - Number of members currently registered
 */
void processPurchase(bookType books[], int bookIndex, memberType members[], int memberIndex)
{
    if(bookIndex == 0)
    {
        cout << "| No books are available for purchase." << endl;
        return;
    }

    // Variables - Choices
    int bookChoice = 0;
    int quantity = 0;
    char isMember = ' ';

    // Display Books
    for(int i = 0; i < bookIndex; i++)
        cout << "| " << i + 1 << ". " << books[i].getTitle() << " - $" << fixed << setprecision(2) << books[i].getPrice() << " (" << books[i].getCopies() << " in stock)" << endl;
    
    // Prompt for Book Choice
    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Enter book number: ";
    cin >> bookChoice;

    // Verify if selected book is valid and whether the book is in stock
    if (bookChoice < 1 || bookChoice > bookIndex) 
    {
        cout << "| Invalid book selection." << endl;
        return;
    }
    if (books[bookChoice - 1].getCopies() <= 0) 
    {
        cout << "| Sorry, this book is out of stock." << endl;
        return;
    }
    
    // Prompt for Quantity
    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Enter quantity: ";
    cin >> quantity;
    
    // Verify that the quantity selected is valid
    if (quantity <= 0 || quantity > books[bookChoice - 1].getCopies()) 
    {
        cout << "| Invalid quantity. Please check available stock." << endl;
        return;
    }

    // Calculate price of order
    double originalPrice = books[bookChoice - 1].getPrice() * quantity;

    // Prompt for whether a customer is a member
    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Are you a member at our store? (Y/N): ";
    cin >> isMember;

    // If user is not a member, print receipt of order
    // - If 'Y' is not selected, default to assume regular customer
    if(toupper(isMember) != 'Y')
    {
        printReceipt(false, "", books[bookChoice - 1].getTitle(), quantity, originalPrice, 0.0);

        // Update book inventory
        books[bookChoice - 1].setCopies(books[bookChoice - 1].getCopies() - quantity);

        return;
    }

    // Variables - Members Only
    string memberID = "";
    int index = -1;
    bool specialDiscount = false;

    // Prompt for member ID
    cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Enter member ID: ";
    cin.ignore(40, '\n');
    getline(cin, memberID);
    
    // Find the member in the system
    for(int i = 0; i < memberIndex; i++)
        if(members[i].getID() == memberID) 
        {
            index = i;
            break;
        }

    // If member index is not found, print the receipt of a regular customer
    if(index == -1) 
    {
        cout << "+" << setw(16) << setfill('-') << "" << "+" << endl << setfill(' ');
        cout << "| Member not found. Proceeding as regular customer." << endl;
        printReceipt(false, "", books[bookChoice - 1].getTitle(), quantity, originalPrice, 0.0);

        // Update book inventory
        books[bookChoice - 1].setCopies(books[bookChoice - 1].getCopies() - quantity);

        return;
    }
    
    // Apply member discount
    double finalPrice = originalPrice * (1 - 0.05);
    
    for(int i = 0; i < quantity; i++)
    {
        int currentBookNumber = members[index].getBooksPurchased() + 1 + i;

        // Check if this is an 11th book
        if(currentBookNumber % 11 == 0)
        {
            finalPrice -= members[index].getAveragePrices();
            if(finalPrice < 0) finalPrice = 0.0;
            
            cout << "| Congratulations! Book #" << currentBookNumber << " qualifies for the special 11th book discount!" << endl;
            cout << "| You received a discount of $" << fixed << setprecision(2) << members[index].getAveragePrices() << endl;
            
            // Reset tracking after applying discount
            members[index].resetPriceTracking();
        }
        
        // Add this book's price to the tracking array
        members[index].addPurchase(books[bookChoice - 1].getPrice());
    }

    // Update member's purchase history
    members[index].setBooksPurchased(members[index].getBooksPurchased() + quantity);

    // Update amount spent depending on whether a special discount was applied
    if(specialDiscount)
        members[index].setAmountSpent(finalPrice);
    else
        members[index].setAmountSpent(members[index].getAmountSpent() + finalPrice);

    // Update book inventory
    books[bookChoice - 1].setCopies(books[bookChoice - 1].getCopies() - quantity);

    // Print receipt
    printReceipt(true, members[index].getName(), books[bookChoice - 1].getTitle(), quantity, originalPrice, finalPrice);
}

/**
 * printReceipt: Prints a receipt for the completed purchase
 * @param bool isMember - Flag indicating if the customer is a member
 * @param string name - Name of the member
 * @param string title - Title of the book purchased
 * @param int quantity - Number of copies purchased
 * @param double originalPrice - Total price before any discounts
 * @param double finalPrice - Final price after applying discounts
 */
void printReceipt(bool isMember, string name, string title, int quantity, double originalPrice, double finalPrice)
{
    if(isMember)
    {
        cout << "+===== PURCHASE RECEIPT =====+" << endl;
        cout << "| Member: " << name << endl;
        cout << "| Book: " << title << endl;
        cout << "| Quantity: " << quantity << endl;
        cout << "| Original Price: $" << fixed << setprecision(2) << originalPrice << endl;
        cout << "| Final Price: $" << fixed << setprecision(2) << finalPrice << endl;
        cout << "| Thank you for your purchase!" << endl;
        cout << "+" << setw(28) << setfill('-') << "" << "+" << endl << setfill(' ');   
    } else
    {
        cout << "+===== PURCHASE RECEIPT =====+" << endl;
        cout << "| Customer: Regular (Non-Member)" << endl;
        cout << "| Book: " << title << endl;
        cout << "| Quantity: " << quantity << endl;
        cout << "| Price: $" << fixed << setprecision(2) << originalPrice << endl;
        cout << "| Thank you for your purchase!" << endl;
        cout << "+" << setw(28) << setfill('-') << "" << "+" << endl << setfill(' ');
    }
}