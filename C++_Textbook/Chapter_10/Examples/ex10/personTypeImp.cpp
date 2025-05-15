// Example 10-10: Person's Name Specification and Implementation Files
#include <iostream>
#include "personType.h"

using namespace std;

// Class Function Definitions
/**
 * personType::print const: Displays the full name (first and last)
 */
void personType::print() const
{
    cout << firstName << " " << lastName;
}

/**
 * personType::setName: Updates the private instance variables in the object
 * @param string first - The variable to update firstName in the class
 * @param string last - The variable to update lastName in the class
 */
void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

/**
 * personType::getFirstName const: Returns the firstName private variable of the class
 * @return string - firstName
 */
string personType::getFirstName() const
{
    return firstName;
}

/**
 * personType::getLastName const: Returns the lastName private variable of the class
 * @return string - lastName
 */
string personType::getLastName() const
{
    return lastName;
}

/**
 * personType::personType: Constructor with 2 parameters
 * @param string first - The variable to initialize firstName in the class object
 * @param string last - The variable to initialize lastName in the class object
 */
personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}