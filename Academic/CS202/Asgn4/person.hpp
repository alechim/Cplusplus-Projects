#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

using namespace std;

# define NAME_LEN       100

// Person Class
class Person
{
    public:
        string name;                // Variable
        Person(){ name = ""; }      // Constructor
};

class MenuPrint
{
    public:
        void printMenu()
        {
            cout << endl << "Welcome to the Museum" << endl;
            cout << " 1. Visitor In" << endl;
            cout << " 2. Visitor Out" << endl;
            cout << " 3. Staff In" << endl;
            cout << " 4. Staff Out" << endl;
            cout << " 5. Exit" << endl;
        }
};

#endif