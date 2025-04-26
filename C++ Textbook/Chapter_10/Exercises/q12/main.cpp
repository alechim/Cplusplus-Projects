#include <iostream>
#include "bookType.h"

using namespace std;

int main()
{
    cout << "===== Book Management System Demo =====" << endl << endl;
    
    // Create a book with single author
    bookType book1("C++ Programming Basics", "John Smith", "", "", "", "TechPress", "1234567890", 29.99, 100, 2023);
    
    cout << "Book 1 Details:" << endl;
    book1.printBook();
    cout << endl;
    
    // Create a book with multiple authors
    bookType book2("Advanced Programming Techniques", "Jane Doe", "Mark Johnson", "Lisa Chen", "", "CodeMasters", "9876543210123", 45.50, 50, 2024);
    
    cout << "Book 2 Details:" << endl;
    book2.printBook();
    cout << endl;
    
    // Demonstrate modifying book properties
    cout << "Modifying Book 1..." << endl;
    book1.setTitle("Modern C++ Programming");
    book1.setAuthors("John Smith", "Sarah Williams", "", "");
    book1.setPrice(34.99);
    book1.setCopies(book1.getCopies() + 25);  // Add 25 more copies
    
    cout << "Book 1 Updated Details:" << endl;
    book1.printBook();
    cout << endl;
    
    // Demonstrate ISBN validation
    cout << "Testing ISBN validation:" << endl;
    
    bookType book3;
    cout << "Trying to set invalid ISBN (too short): " << endl;
    book3.setISBN("12345");
    
    cout << "Trying to set invalid ISBN (contains letters): " << endl;
    book3.setISBN("123ABC7890");
    
    cout << "Setting valid ISBN: " << endl;
    book3.setISBN("0987654321");
    cout << "Valid ISBN set: " << book3.getISBN() << endl;
    
    return 0;
}