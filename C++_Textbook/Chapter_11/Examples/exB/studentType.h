#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H

#include "courseType.h"
#include "personType.h"

class studentType: public personType
{
    public:
        void setInfo(string fName, string lName, int ID, int noOfCourses, bool isTPaid, courseType courses[], char courseGrades[]);
        // Function to set the student's information.
        // Postcondition: The member variables are set according to the parameters.

        void print(ostream& outF, double tuitionRate);
        // Function to print the student's grade report.
        // If the member variable, isTuitionPaid is true, the grades are shown, otherwise three stars are printed.
        // If the actual parameter corresponding to outF is the object cout, then the output is shown on the standard output device.
        // If the actual parameter corresponding to outF is an ofstream object, say outFile, then the output goes to the file specified by outFile.
        
        studentType();
        // Default constructor
        // The member variables are initialized.

        int getHoursEnrolled();
        // Function to return the credit hours a student is enrolled in.
        // Postcondition: The number of credit hours is calculated and returned.

        double getGpa();
        // Function to return return the tuition fees.
        // Postcondition: The billing amount is calculated and returned.

        double billingAmount(double tuitionRate);
        // Function to return the tuition fees.
        // Postcondition: The billing amount is calculated and returned.
    private:
        void sortCourses();
        // Function to sort the courses.
        // Postcondition: The array coursesEnrolled is sorted. For each courses, its grade is stored in the array coursesGrade.
        //                Therefore, when the array coursesEnrolled is sorted, the corresponding entries in the array coursesGrade are adjusted.
        int sId;                            // Variable to store the student ID
        int numberOfCourses;                // Variable to store the number of course
        bool isTuitionPaid;                 // Variable to indicate whether the tuition is paid
        courseType coursesEnrolled[6];      // Array to store the courses
        char coursesGrade[6];               // Array to store the courses grades
};

#endif