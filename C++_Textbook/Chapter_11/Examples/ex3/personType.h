#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

#include <string>

class personType
{
    public:
        /**
         * Function to output the first name and last name in the form firstName lastName
         */
        void print() const;

        /**
         * Function to set firstName and lastName according to the parameters
         * Postcondition: firstName = first; lastName = last;
         */
        void setName(std::string first, std::string last);

        /**
         * Function to return the first name. 
         * Postcondition: The value of firstName is returned.
         */
        std::string getFirstName() const;

        /**
         * Function to return the last name. 
         * Postcondition: The value of lastName is returned.
         */
        std::string getLastName() const;

        /**
         * Constructor
         * Sets firstName and lastName according to the parameters. 
         * The default values of the parameters are null strings.
         * Postcondition: firstName = first; lastName = last;
         */
        personType(std::string first = "", std::string last = "");
        
    private:
        std::string firstName;       // Variable to store the first name
        std::string lastName;        // Variable to store the last name
};

#endif