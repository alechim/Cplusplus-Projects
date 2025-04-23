#ifndef STAFF_H
#define STAFF_H

#include "person.hpp"

class Staff : public Person
{
    public:
        // Variables
        char inTime[100];
        char outTime[100];

        // Functions
        void updateTheFile(Staff *ptr, char staffFileName[50]);
        void setStaffDetails(string name);
        string getName() const;
};

#endif