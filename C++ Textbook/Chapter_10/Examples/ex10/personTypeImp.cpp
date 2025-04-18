// Example 10-10: Person's Name Specification and Implementation Files
#include <iostream>
#include "personType.h"

using namespace std;

// Class Function Definitions
/**
 * personType::print const: 
 */
void personType::print() const
{
    cout << firstName << " " << lastName;
}

/**
 * personType::setName: 
 * @param string first - 
 * @param string last - 
 */
void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

/**
 * personType::getFirstName const: 
 * @return string - 
 */
string personType::getFirstName() const
{
    return firstName;
}

/**
 * personType::getLastName const: 
 * @return string - 
 */
string personType::getLastName() const
{
    return lastName;
}

/**
 * personType::personType: constructor
 * @param string first - 
 * @param string last - 
 */
personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}