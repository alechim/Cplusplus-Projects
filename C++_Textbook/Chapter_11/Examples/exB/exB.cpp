#include <iostream>
#include <fstream>
#include <string>
#include "studentType.h"

using namespace std;

// Globals
const int MAX_NO_OF_STUDENTS = 10;

// Function Prototypes
void getStudentData(ifstream&, studentType[], int);
void printGradeReports(ofstream&, studentType[], int, double);

int main()
{
    studentType studentList[MAX_NO_OF_STUDENTS];
    int noOfStudents = 0;
    double tuitionRate = 0.0;
    
    ifstream iFile;
    ofstream oFile;

    iFile.open("studentData.txt");
    if(!iFile)
    {
        cout << "The input file does not exist. Program terminating..." << endl;
        return 1;
    }

    oFile.open("studentDataOut.txt");

    iFile >> noOfStudents;      // Get the number of students
    iFile >> tuitionRate;       // Get the tuition rate

    getStudentData(iFile, studentList, noOfStudents);
    printGradeReports(oFile, studentList, noOfStudents, tuitionRate);

    return 0;
}

// Function Definitions
void getStudentData(ifstream& iFile, studentType studentList[], int numberOfStudents)
{
    // Local Variables
    string fName = "";              // Variable to store the first name
    string lName = "";              // Variable to store the last name
    int ID = 0;                     // Variable to store the student ID
    int noOfCourses = 0;            // Variable to store the number of courses
    char isPaid = ' ';              // Variable to store Y/N, that is, is tuition paid
    bool isTuitionPaid = false;     // Variable to store true/false

    string cName = "";
    string cNo = "";
    int credits = 0;

    courseType courses[6];
    char cGrades[6];

    for(int count = 0; count < numberOfStudents; count++)
    {
        iFile >> fName >> lName >> ID >> isPaid;

        if(isPaid == 'Y')
            isTuitionPaid = true;
        else
            isTuitionPaid = false;

        iFile >> noOfCourses;

        for(int i = 0; i < noOfCourses; i++)
        {
            iFile >> cName >> cNo >> credits >> cGrades[i];
            courses[i].setCourseInfo(cName, cNo, credits);
        }

        studentList[count].setInfo(fName, lName, ID, noOfCourses, isTuitionPaid, courses, cGrades);
    }
}

void printGradeReports(ofstream& oFile, studentType studentList[], int numberOfStudents, double tuitionRate)
{
    for(int count = 0; count < numberOfStudents; count++)
        studentList[count].print(oFile, tuitionRate);
}