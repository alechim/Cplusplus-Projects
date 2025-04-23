#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "staff.hpp"

using namespace std;

void Staff::updateTheFile(Staff *ptr, char staffFileName[50])
{
    // Declare and Open the File
    ofstream oFile;
    oFile.open(staffFileName, ios_base::app|ios_base::out);

    // Validate if File is Opened
    if(!oFile.is_open())
    {
        cout << "Unable to open the file." << endl;
        return;
    }

    // Display Message in File
    oFile << "STAFF_ENTRY" << endl;
    oFile << "NAME: " << ptr->name << endl;
    oFile << "IN_TIME: " << ptr->inTime;
    oFile << "OUT_TIME: " << ptr->outTime << endl;

    // Close the file
    oFile.close();
}

// - Setter and Getter
void Staff::setStaffDetails(string newName) { name = newName; }
string Staff::getName() const { return name; }