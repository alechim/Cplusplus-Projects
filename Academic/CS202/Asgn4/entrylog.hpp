#ifndef ENTRYLOG_H
#define ENTRYLOG_H

#include "staff.hpp"
#include "visitor.hpp"
#include <time.h>
#include <fstream>

using namespace std;

class entrylog
{
    private:
        // Staff Info
        Staff *headptr_staff;
        int staff_index;
        string staff_password;
        char staff_file_name[50];

        // Visitor Info
        char visitor_file_name[50];
        Visitor *headptr_visitor;
        int visitor_index;
        int age;
        char vote;                  // While Visitor-Out Selection of Choice as Vote

        // Admin Info
        string admin_password;
        string admin_username;
        string tempName;            // Identifier for Name Verification of Admin

        // Identifiers in Common for Entries in and out
        bool found;
        string tempPass;
        string name;
    public:
        Review winCount;    // Composition
        entrylog();         // Default Constructor
        ~entrylog();        // Destructor - To deallocate memory heap

        // Function Definitions
        void visitorIn();
        void visitorOut();
        void staffIn();
        void staffOut();
        bool exitMain();
};

#endif