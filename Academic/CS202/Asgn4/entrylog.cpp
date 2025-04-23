#include "entrylog.hpp"
#include "visitor.hpp"
#include "staff.hpp"
#include "person.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

// Visitor.h
// - Constructor
entrylog::entrylog()
{
    headptr_staff = new Staff[100];
    headptr_visitor = new Visitor[100];

    staff_index = 0;
    visitor_index = 0;

    admin_username = "admin";
    admin_password = "welcome123";
    staff_password = "staff123";

    strcpy(visitor_file_name, "visitor_log.txt");
    strcpy(staff_file_name, "staff_log.txt");

    tempPass = "";
    tempName = "";
    found = false;
}

// - Destructor
entrylog::~entrylog()
{
    delete[] headptr_visitor;
    delete[] headptr_staff;
}

void entrylog::visitorIn()
{
    // Check if we've reached maximum capacity
    if(visitor_index >= 100) 
    {
        cout << "Maximum visitor capacity reached!" << endl;
        return;
    }

    Visitor& currentVisitor = headptr_visitor[visitor_index];

    // Prompts and Validates Input - Name
    do
    {
        cout << "Please enter the visitor name: ";
        getline(cin >> ws, currentVisitor.name);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid name." << endl;
        } else
            break;
    } while(true);
    
    // Prompts and Validates Input - Age
    do
    {
        cout << "Please enter the visitor's age: ";
        cin >> currentVisitor.age;

        if(cin.fail() || currentVisitor.age <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid age." << endl;
        } else
            break;
    } while(true);
    
    // Record entry time
    time_t now = time(0);
    char *dt = ctime(&now);
    snprintf(currentVisitor.inTime, 100, "%s", dt);

    // Increment Visitor Count
    visitor_index++;

    // Display current visitors in the museum
    for(int i = 0; i < visitor_index; i++)
        cout << "Visitor-" << i + 1 << ": " << headptr_visitor[i].name << " (Age: " << headptr_visitor[i].age << ")" << endl;
    cout << endl;
}

void entrylog::visitorOut()
{
    if(visitor_index == 0)
    {
        cout << "No visitors to check out." << endl;
        return;
    }

    // Prompt and Validate Input
    do
    {
        cout << "Please enter the visitor name: ";
        getline(cin >> ws, tempName);
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid name." << endl;
        } else
            break;
    } while(true);

    // Check if name exists in database
    int tempIndex = -1;
    found = false;
    for(int i = 0; i < visitor_index; i++)
    {
        if(tempName == headptr_visitor[i].name)
        {
            found = true;
            tempIndex = i;
            break;
        }
    }

    if(!found)
    {
        cout << "Error: Entered visitor name is not found in the visitor-in list. Please try again." << endl;
        return;
    }

    // Record outTime
    time_t now = time(0);
    char *dt = ctime(&now);
    char vote = ' ';

    snprintf(headptr_visitor[tempIndex].outTime, 100, "%s", dt);
    headptr_visitor[tempIndex].updateTheFile(headptr_visitor, visitor_file_name);

    // Prompt and Validate Input - Art Room Vote
    cout << "Please give the votes for below rooms/objects: " << endl;
    do
    {
        cout << "Do you like the Art Rooms (y/n): ";
        cin >> vote;
        if(cin.fail() || (vote != 'y' && vote != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
            break;
    } while(true);

    if(vote == 'y')
        winCount.artRoom++;
    
    // Prompt and Validate Input - Science Room Vote
    vote = ' ';
    do
    {
        cout << "Do you like the Science Rooms (y/n): ";
        cin >> vote;
        if(cin.fail() || (vote != 'y' && vote != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
            break;
    } while(true);
    
    if(vote == 'y')
    winCount.scienceRoom++;
    
    // Prompt and Validate Input - Historic Objects Room Vote
    vote = ' ';
    do
    {
        cout << "Do you like the Historic Objects Rooms (y/n): ";
        cin >> vote;
        if(cin.fail() || (vote != 'y' && vote != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
            break;
    } while(true);
    
    if(vote == 'y')
        winCount.historicObject++;

    // Remove the found tempIndex and shift array
    for(int i = tempIndex; i < visitor_index - 1; i++)
        headptr_visitor[i] = headptr_visitor[i + 1];

    visitor_index--;
    cout << endl << "** Thank you for coming! **" << endl;
}

void entrylog::staffIn()
{
    // Check if there are a maximum amount of staff
    if(staff_index >= 100)
    {
        cout << "Maximum staff capacity reached!" << endl;
        return;
    }

    Staff& currentStaff = headptr_staff[staff_index];

    // Prompt and Validate Input - Name
    do
    {
        cout << "Please enter the staff name: ";
        getline(cin >> ws, headptr_staff[staff_index].name);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid name." << endl;
        } else
            break;
    } while(true);
    
    // Prompt and Validate Input - Password
    do
    {
        cout << "Enter the staff password: ";
        cin >> tempPass;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid password." << endl;
        } else
            break;
    } while(true);

    // Verify if entered password is correct
    if(tempPass == staff_password)
        found = true;
    else
    {
        cout << "Wrong Staff Password!!! Data entry incomplete..." << endl << endl;
        return;
    }

    // Record entry time
    time_t now = time(0);
    char *dt = ctime(&now);
    snprintf(currentStaff.inTime, 100, "%s", dt);

    // Increment Staff Count
    staff_index++;

    // Display current staff in the museum
    for(int i = 0; i < staff_index; i++)
        cout << "Staff-" << i + 1 << ": " << headptr_staff[i].name << endl;
    cout << endl;
}

void entrylog::staffOut()
{
    if(staff_index == 0)
    {
        cout << "No staff to check out." << endl;
        return;
    }

    // Prompt and Validate Input - Name
    do
    {
        cout << "Please enter the staff name: ";
        getline(cin >> ws, tempName);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid name." << endl;
        } else
            break;
    } while(true);

    // Check if name exists in database
    int tempIndex = -1;
    found = false;
    for(int i = 0; i < staff_index; i++)
    {
        if(tempName == headptr_staff[i].name)
        {
            found = true;
            tempIndex = i;
            break;
        }
    }

    if(!found)
    {
        cout << "Error: Entered staff name is not found in the staff-in list. Please try again." << endl;
        return;
    }

    // Record out time
    time_t now = time(0);
    char *dt = ctime(&now);
    snprintf(headptr_staff[tempIndex].outTime, 100, "%s", dt);
    headptr_staff[tempIndex].updateTheFile(headptr_staff, staff_file_name);

    // Remove the found tempIndex and shift array
    for(int i = tempIndex; i < staff_index; i++)
        headptr_staff[i] = headptr_staff[i + 1];
    
    staff_index--;
    cout << endl << "** You have been properly clocked out. **" << endl;
}

bool entrylog::exitMain()
{
    // Prompt and Validate Input - Admin Username
    do
    {
        cout << "Please enter the admin username: ";
        getline(cin >> ws, tempName);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid username." << endl;
        } else
            break;
    } while(true);
    
    // Verify inputted username
    if(tempName == admin_username)
        found = true;
    else
    {
        cout << "Wrong Admin Username!!!" << endl;
        return false;
    }

    // Prompt and Validate Input - Admin Password
    do
    {
        cout << "Please enter the admin password: ";
        getline(cin, tempPass);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Invalid Input! Please enter a valid password." << endl;
        } else
            break;
    } while(true);
    
    // Verify inputted password
    if(tempPass == admin_password)
        found = true;
    else
    {
        cout << "Wrong Admin Password!!!" << endl;
        return false;
    }

    // Show details of visitors and staff who are still-in
    // - Reprompt Menu if all the visitors are not out (Should not exit program until all visitors are out)
    // - Even if staff is in, there should not be any restriction to exit the program
    for(int i = 0; i < visitor_index; i++)
        cout << "Visitor (" << headptr_visitor[i].name << ") is inside." << endl;

    for(int i = 0; i < staff_index; i++)
        cout << "Staff (" << headptr_staff[i].name << ") is inside." << endl;

    if(visitor_index == 0)
        return true;
    else
    {
        cout << "There are still " << visitor_index << " visitor(s) within the Museum." << endl;
        return false;
    }
}