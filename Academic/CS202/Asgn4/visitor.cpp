#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "visitor.hpp"

using namespace std;

void Visitor::setVisitorDetails(string newName, int newAge)
{
    name = newName;
    age = newAge;
}

void Visitor::updateTheFile(Visitor *ptr, char visitorFileName[50])
{
    // Declare and Open the File
    ofstream oFile;
    oFile.open(visitorFileName, ios_base::app|ios_base::out);

    // Validate if File is Opened
    if(!oFile.is_open())
    {
        cout << "Unable to open the file." << endl;
        return;
    }

    // Display Message in File
    oFile << "VISITOR_ENTRY" << endl;
    oFile << "NAME: " << ptr->name << endl;
    oFile << "AGE: " << ptr->age << endl;
    oFile << "IN_TIME: " << ptr->inTime;
    oFile << "OUT_TIME: " << ptr->outTime << endl;

    // Close the file
    oFile.close();
}

// - Getter Functions
string Visitor::getName() const { return name; }
int Visitor::getAge() const { return age; }