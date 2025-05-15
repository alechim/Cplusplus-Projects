// Question 1: Refactored 9-2 with Class Object
#include <iostream>
#include <iomanip>
#include <fstream>
#include "studentType.h"

using namespace std;

// Function Prototypes
void readData(ifstream&, studentType[], int);
void outputStudents(ofstream&, studentType[], int);
void outputTopScorers(ofstream&, studentType[], int);

int main()
{
    // Variables
    const int NO_OF_STUDENTS = 20;
    studentType students[NO_OF_STUDENTS];
    ifstream iFile;
    ofstream oFile;

    // Open the input file
    iFile.open("studentData.txt");

    // Verify if the input file is opened
    if(!iFile)
    {
        cout << "Error - Unable to open input file 'studentData.txt'." << endl;
        return 1;
    }

    // Read all data from the input file
    readData(iFile, students, NO_OF_STUDENTS);

    // Close the input file
    iFile.close();

    // Open the output file
    oFile.open("gradedStudents.txt");

    for(int i = 0; i < 20; i++)
    {
        students[i].calculateGrade(); 
        students[i].findHighestScore(); 
    }

    // Output Results
    outputStudents(oFile, students, NO_OF_STUDENTS);
    outputTopScorers(oFile, students, NO_OF_STUDENTS);

    // Close the output file
    oFile.close();

    return 0;
}

// Function Definitions
/**
 * readData: Reads student data from an input file into an array of students
 * @param ifstream& iFile - Reference to the input file stream
 * @param studentType students[] - Array of student class objects
 */
void readData(ifstream& iFile, studentType students[], int totalStudents)
{
    // Variables
    string first = "", last = "";
    int score = 0;

    for(int i = 0; i < totalStudents; i++)
    {
        // Read data from file and store in class objects
        iFile >> first >> last >> score;
        students[i].setStudentName(first, last);
        students[i].setTestScore(score);

        // Reinitialize variables
        first = "";
        last = "";
        score = 0;
    }
}

/**
 * outputStudents: Saves the students data to an output file
 * @param ofstream& oFile - Reference to the output file stream
 * @param studentType students[] - Array of student structures
 */
void outputStudents(ofstream& oFile, studentType students[], int totalStudents)
{
    oFile << left << setw(23) << "Student Names" << setw(16) << "Test Scores" << "Grade" << endl;
    oFile << setw(47) << setfill('=') << "" << endl << setfill(' ');
    for(int i = 0; i < totalStudents; i++)
        oFile << left << setw(27) << students[i].getFirstName() + " " + students[i].getLastName() << setw(13) << students[i].getTestScore() << " " << students[i].getGrade() << endl;
    oFile << setw(47) << setfill('=') << "" << endl << setfill(' ');
}

/**
 * outputTopScorers: Saves the names of the students that have the same test score as the highest test score to an output file
 * @param ofstream& oFile - Reference to the output file stream
 * @param studentType students[] - Array of student structures
 * @param double topScore - The highest test score found within the entire array
 */
void outputTopScorers(ofstream& oFile, studentType students[], int totalStudents)
{
    oFile << "Top Scorers (Highest Score: " << students[0].getTopScore() << "):" << endl;
    for(int i = 0; i < totalStudents; i++)
        if(students[i].getTestScore() == students[0].getTopScore())
            oFile << "- " << students[i].getLastName() << ", " << students[i].getFirstName() << endl;
}