#include "studentType.h"

using namespace std;

// Initialize Static Variables
int studentType::topScore = 0;

// Class Function Definitions
/**
 * calculateGrade: Classifies the letter grade of a student based on their test score within the student struct array
 */
void studentType::calculateGrade()
{
    switch(testScore / 10)
    {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        case 5:
        default:
            grade = 'F';
    }
}

/**
 * findHighestScore: Sequential search to find the max test score value from the students struct array
 */
void studentType::findHighestScore()
{
    if(topScore < testScore)
        topScore = testScore;
}

/**
 * studentType::setStudentName: Updates the class variables studentFName and studentLName with passed parameters
 * @param string first - The variable to update studentFName in the class object
 * @param string last - The variable to update studentLName in the class object
 */
void studentType::setStudentName(string first, string last)
{
    studentFName = first;
    studentLName = last;
}

/**
 * studentType::setTestScore: Updates the class variable testScore with passed parameters
 * @param int value - The variable to update testScore in the class object
 */
void studentType::setTestScore(int value)
{
    testScore = value;
}

/**
 * studentType::getFirstName: Returns the variable studentFName of the class
 * @return string - studentFName of the class object
 */
string studentType::getFirstName()
{
    return studentFName;
}

/**
 * studentType::getLastName: Returns the variable studentLName of the class
 * @return string - studentLName of the class object
 */
string studentType::getLastName()
{
    return studentLName;
}

/**
 * studentType::getTestScore: Returns the variable testScore of the class
 * @return int - testScore of the class object
 */
int studentType::getTestScore()
{
    return testScore;
}

/**
 * studentType::getGrade: Returns the variable grade of the class
 * @return char - grade of the class object
 */
char studentType::getGrade()
{
    return grade;
}

/**
 * studentType::getTopScore: Returns the static variable topScore of the class
 * @return int - topScore of the class
 */
int studentType::getTopScore()
{
    return topScore;
}

/**
 * studentType::studentType: Default Constructor
 */
studentType::studentType()
{
    studentFName = "";
    studentLName = "";
    testScore = 0;
    grade = ' ';
}