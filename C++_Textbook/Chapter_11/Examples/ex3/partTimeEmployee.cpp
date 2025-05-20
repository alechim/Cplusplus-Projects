// Example 11-3: partTimeEmployee Inheritance and personType Class
#include <iostream>
#include <iomanip>
#include <string>
#include "partTimeEmployee.h"

using namespace std;

void partTimeEmployee::print() const
{
    personType::print();    // Print the name of the employee 
    cout << "'s wages are: $" << calculatePay() << endl;
}

double partTimeEmployee::calculatePay() const
{
    return (payRate * hoursWorked);
}

void partTimeEmployee::setNameRateHours(string first, string last, double rate, double hours)
{
    personType::setName(first, last);
    payRate = rate;
    hoursWorked = hours;
}

// Constructor
partTimeEmployee::partTimeEmployee(string first, string last, double rate, double hours) : personType(first, last)
{
    payRate = rate >= 0.0 ? rate : 0.0;
    hoursWorked = hours >= 0.0 ? hours : 0.0;
}