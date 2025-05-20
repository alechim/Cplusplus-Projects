#ifndef COURSE_TYPE_H
#define COURSE_TYPE_H

#include <string>

class courseType
{
    public:
        void setCourseInfo(std::string cName, std::string cNo, int credits);
        // Function to set the course information.
        // The course information is set according to the parameters.
        // Postcondition: courseName = cName; courseNo = cNo; courseCredits = credits;

        void print(std::ostream& outF);
        // Function to print the course information.
        // This function sends the course information to the output device specified by the parameter outF.
        // If the actual parameter to this function is the object cout, then the output is shown on the standard output device.
        // If the actual parameter is an ofstream variable, say outFile, then the output goes to the file specified by outFile.

        int getCredits();
        // Function to return the credit hours.
        // Postcondition: The value of courseNo is returned.

        std::string getCourseNumber();
        // Function to return the course name.
        // Postcondition: The value of courseName is returned.

        std::string getCourseName();
        // Function to return the course name.
        // Postcondition: The value of courseName is returned.

        courseType(std::string cName = "", std::string cNo = "", int credits = 0);
        // Constructor
        // The object is initialized according to the parameters.
        // Postcondition: courseName = cName; courseNo = cNo; courseCredits = credits;
    private:
        std::string courseName;     // Variable to store the course name
        std::string courseNo;       // Variable to store the course number
        int courseCredits;          // Variable to store the credit hours
};

#endif