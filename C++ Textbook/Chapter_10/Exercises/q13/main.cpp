// Question 13: memberType Class Program
#include <iostream>
#include "memberType.h"

using namespace std;

int main()
{
    cout << "===== Member Management System Demo =====" << endl << endl;
    
    // Create a member using the default constructor with parameters
    memberType member1("Alice Johnson", "123456", 5, 125.75);
    
    cout << "Member 1 Details:" << endl;
    member1.printMember();
    cout << endl;
    
    // Create a member using default constructor with no parameters
    memberType member2;
    
    // Use setter methods to populate member2
    member2.setName("Bob Smith");
    member2.setID("789012");
    member2.setBooksPurchased(3);
    member2.setAmountSpent(87.50);
    
    cout << "Member 2 Details:" << endl;
    member2.printMember();
    cout << endl;
    
    // Demonstrate validation in setter methods
    cout << "Testing validation features:" << endl;
    
    memberType member3("Charlie Davis", "", 0, 0.0);
    
    cout << "Trying to set invalid ID (contains letters): " << endl;
    member3.setID("12A34");
    cout << "Current ID: " << member3.getID() << endl << endl;
    
    cout << "Trying to set valid ID: " << endl;
    member3.setID("54321");
    cout << "Current ID: " << member3.getID() << endl << endl;
    
    cout << "Trying to set invalid booksPurchased (negative value): " << endl;
    member3.setBooksPurchased(-5);
    cout << "Current books purchased: " << member3.getBooksPurchased() << endl << endl;
    
    cout << "Trying to set invalid amountSpent (negative value): " << endl;
    member3.setAmountSpent(-25.50);
    cout << "Current amount spent: $" << member3.getAmountSpent() << endl << endl;
    
    // Update member information
    cout << "Updating Member 1..." << endl;
    member1.setBooksPurchased(member1.getBooksPurchased() + 2);  // Add 2 more books
    member1.setAmountSpent(member1.getAmountSpent() + 45.99);    // Add to amount spent
    
    cout << "Member 1 Updated Details:" << endl;
    member1.printMember();
    cout << endl;
    
    return 0;
}