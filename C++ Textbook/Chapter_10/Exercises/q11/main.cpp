// Question 11: Refactored personType Class Program
#include <iostream>
#include "personType.h"

using namespace std;

int main() 
{
    cout << "===== PersonType Class Demonstration =====" << endl << endl;
    
    // Test constructor and print function
    cout << "Testing constructor and print function:" << endl;
    personType person1("John", "Robert", "Doe");
    cout << "Person 1: ";
    person1.print();
    cout << endl;
    
    // Test setName function
    cout << "Testing setName function:" << endl;
    personType person2("Jane", "", "Smith");
    cout << "Before setName - Person 2: ";
    person2.print();
    
    person2.setName("Jane", "Marie", "Smith");
    cout << "After setName - Person 2: ";
    person2.print();
    cout << endl;
    
    // Test name comparison functions
    cout << "Testing name comparison functions:" << endl;
    personType person3("John", "Michael", "Williams");
    personType person4("John", "Robert", "Brown");
    personType person5("Mary", "Elizabeth", "Williams");
    
    cout << "Person 3: ";
    person3.print();
    cout << "Person 4: ";
    person4.print();
    cout << "Person 5: ";
    person5.print();
    cout << endl;
    
    // Check first names
    cout << "First name comparison results:" << endl;
    cout << "Person 3 and Person 4 have the same first name: " 
         << (person3.checkFirstName(person4) ? "Yes" : "No") << endl;
    cout << "Person 3 and Person 5 have the same first name: " 
         << (person3.checkFirstName(person5) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Check last names
    cout << "Last name comparison results:" << endl;
    cout << "Person 3 and Person 4 have the same last name: " 
         << (person3.checkLastName(person4) ? "Yes" : "No") << endl;
    cout << "Person 3 and Person 5 have the same last name: " 
         << (person3.checkLastName(person5) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Test with different combinations of names
    cout << "Testing with different name combinations:" << endl;
    
    personType emptyPerson("", "", "");
    cout << "Empty person: ";
    emptyPerson.print();
    
    personType noMiddleName("Alice", "", "Johnson");
    cout << "Person without middle name: ";
    noMiddleName.print();
    
    personType longNames("Christopher", "Alexander", "Williamson");
    cout << "Person with longer names: ";
    longNames.print();
    cout << endl;

    return 0;
}