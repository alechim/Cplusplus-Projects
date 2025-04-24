#include <iostream>
#include "personType.h"

using namespace std;

// Class Function Definitions
/**
 * personType::print const: Displays the full name (first, middle, and last)
 */
void personType::print() const
{
    cout << firstName << " " << ((middleName == "") ? "" : middleName + " ") << lastName << endl;
}

/**
 * personType::checkFirstName: Determines whether two class objects firstName variables are equal to each other
 * @param const personType& otherPerson - The class object to be compared to
 * @returns bool - true if both first names are equal to each other. Otherwise, false.
 */
bool personType::checkFirstName(const personType& otherPerson)
{
    return firstName == otherPerson.firstName;
}

/**
 * personType::checkLastName: Determines whether two class objects lastName variables are equal to each other
 * @param const personType& otherPerson - The class object to be compared to
 * @returns bool - true if both last names are equal to each other. Otherwise, false.
 */
bool personType::checkLastName(const personType& otherPerson)
{
    return lastName == otherPerson.lastName;
}

/**
 * personType::setName: Updates the private instance variables in the object
 * @param string first - The variable to update firstName in the class
 * @param string middle - The variable to update middleName in the class
 * @param string last - The variable to update lastName in the class
 */
void personType::setName(string first, string middle, string last)
{
    firstName = first;
    middleName = middle;
    lastName = last;
}

/**
 * personType::personType: Constructor with 3 parameters
 * @param string first - The variable to initialize firstName in the class object
 * @param string middle - The variable to initialize middleName in the class object
 * @param string last - The variable to initialize lastName in the class object
 */
personType::personType(string first, string middle, string last)
{
    setName(first, middle, last);
}