// Question 2: Student Test Score Struct
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Structs
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Function Prototypes
void readData(ifstream&, studentType[], int);
void calculateGrade(studentType[], int);
int findHighestScore(studentType[], int);
void outputStudents(ofstream&, studentType[], int);
void outputTopScorers(ofstream&, studentType[], double, int);

int main()
{
    // Variables
    const int NO_OF_STUDENTS = 20;
    studentType students[NO_OF_STUDENTS];
    int highestScore = 0.0;
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

    // Output Results
    calculateGrade(students, NO_OF_STUDENTS);
    outputStudents(oFile, students, NO_OF_STUDENTS);
    highestScore = findHighestScore(students, NO_OF_STUDENTS);
    outputTopScorers(oFile, students, highestScore, NO_OF_STUDENTS);

    // Close the output file
    oFile.close();

    return 0;
}

// Function Definitions
/**
 * readData: 
 * @param ifstream& iFile - 
 * @param studentType students[] - 
 */
void readData(ifstream& iFile, studentType students[], int totalStudents)
{
    for(int i = 0; i < totalStudents; i++)
        iFile >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
}

/**
 * calculateGrade: 
 * @param studentType students[] - 
 */
void calculateGrade(studentType students[], int totalStudents)
{
    for(int i = 0; i < totalStudents; i++)
    {
        switch(students[i].testScore / 10)
        {
            case 10:
            case 9:
                students[i].grade = 'A';
                break;
            case 8:
                students[i].grade = 'B';
                break;
            case 7:
                students[i].grade = 'C';
                break;
            case 6:
                students[i].grade = 'D';
                break;
            case 5:
            default:
                students[i].grade = 'F';
        }
    }
}

/**
 * findHighestScore: sequential search to find the max value
 * @param studentType students[] - 
 * @return int - 
 */
int findHighestScore(studentType students[], int totalStudents)
{
    int maxIndex = 0;
    for(int i = 1; i < totalStudents; i++)
        if(students[maxIndex].testScore < students[i].testScore)
            maxIndex = i;
    return students[maxIndex].testScore;
}

/**
 * outputStudents: 
 * @param ofstream& oFile - 
 * @param studentType students[] - 
 */
void outputStudents(ofstream& oFile, studentType students[], int totalStudents)
{
    oFile << left << setw(23) << "Student Names" << setw(16) << "Test Scores" << "Grade" << endl;
    oFile << setw(47) << setfill('=') << "" << endl << setfill(' ');
    for(int i = 0; i < totalStudents; i++)
        oFile << left << setw(27) << students[i].studentLName + " " + students[i].studentFName << setw(13) << students[i].testScore << " " << students[i].grade << endl;
    oFile << setw(47) << setfill('=') << "" << endl << setfill(' ');
}

/**
 * outputTopScorers: 
 * @param ofstream& oFile - 
 * @param studentType students[] - 
 * @param double topScore - 
 */
void outputTopScorers(ofstream& oFile, studentType students[], double topScore, int totalStudents)
{
    oFile << "Top Scorers (Highest Score: " << topScore << "):" << endl;
    for(int i = 0; i < totalStudents; i++)
        if(students[i].testScore == topScore)
            oFile << "- " << students[i].studentLName << ", " << students[i].studentFName << endl;
}