#ifndef VISITOR_H
#define VISITOR_H

#include "person.hpp"

class Visitor : public Person 
{
    public:
        // Variables
        char inTime[100];
        char outTime[100];
        int age;
        
        // Functions
        void setVisitorDetails(string name, int age);
        void updateTheFile(Visitor*, char visitorFileName[50]);
        string getName() const;
        int getAge() const;
};

class Review
{
    public:
        // Variables
        int artRoom;
        int scienceRoom;
        int historicObject;
        
        // Constructor
        Review()
        {
            artRoom = 0;
            scienceRoom = 0;
            historicObject = 0;
        }
};

#endif