#include <iostream>
#include "personalInfo.h"

using namespace std;

personalInfo::personalInfo(string first, string last, int month, int day, int year, int ID) : name(first, last), bDay(month, day, year)
{
    personID = ID;
}

void personalInfo::setPersonalInfo(string first, string last, int month, int day, int year, int ID)
{
    name.setName(first, last);
    bDay.setDate(month, day, year);
    personID = ID;
}

void personalInfo::printPersonalInfo() const
{
    name.print();
    cout << "'s date of birth is ";
    bDay.printDate();
    cout << endl;
    cout << "and personalID is " << personID;
}