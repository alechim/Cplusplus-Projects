#ifndef PART_TIME_EMPLOYEE_H
#define PART_TIME_EMPLOYEE_H

#include "personType.h"

class partTimeEmployee: public personType
{
    public:
        void print() const;
        // Function to output the first name, last name, and the wages.
        // Postcondition: Outputs firstName, lastName, wages are $$$$.$$

        double calculatePay() const;
        // Function to calculate and return the wages.
        // Postcondition: Pay is calculated and returned.

        void setNameRateHours(std::string first, std::string last, double rate, double hours);
        // Function to set the first name, last name, payRate, and hoursWorked according to the parameters.
        // Postcondition: firstName = first; lastName = last; payRate = rate; hoursWorked = hours;

        partTimeEmployee(std::string first = "", std::string last = "", double rate = 0.0, double hours = 0.0);
        // Constructor with parameters
        // Sets the first name, last name, payRate, and hoursWorked according to the parameters. If no value is specified, the default values are assumed.
        // Postcondition: firstName = first; lastName = last; payRate = rate; hoursWorked = hours;

    private:
        double payRate;         // Variable to store the pay rate
        double hoursWorked;     // Variable to store the hours worked
};

#endif