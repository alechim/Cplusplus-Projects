// Question 13: Calculate Average Scores and Grades with 3 Parallel Arrays
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

// Function Prototypes
int readFile(string[], int[][5]);
void storeData(string[], int[][5]);
double averageTestScore(int[][5], int);
double averageClassScore(int[][5], int);
char determineGrade(int);

int main()
{
    // Variables
    string studentNames[10];
    int testScores[10][5];
    
    // Input File
    cout << "Reading the file..." << endl;
    if(readFile(studentNames, testScores) == -1)
    {
        cout << "Error - Could not open the file 'runnerData.txt'." << endl;
        cout << "Terminating the Program..." << endl; 
        return -1;
    }

    // Output File
    cout << "Outputting to 'gradedTests.out'..." << endl;
    storeData(studentNames, testScores);

    cout << "Completed. Terminating Program..." << endl;

    return 0;
}

// Function Definitions
/**
 * readFile: Reads student names and test scores from a file
 * @param string names[] - Array to store student names
 * @param int scores[][5] - 2D array to store test scores for each student
 * @return int - Returns 0 if successful, -1 if file could not be opened
 */
int readFile(string names[], int scores[][5])
{
    ifstream iFile;

    // Open and Validate File is Open
    iFile.open("testScores.txt");
    if(!iFile.is_open())
        return -1;
    
    // Process Data
    for(int i = 0; i < 10; i++)
    {
        iFile >> names[i];
        for(int j = 0; j < 5; j++)
            iFile >> scores[i][j];
    }
    
    // Close the File
    iFile.close();
    
    return 0;
}

/**
 * storeData: Writes formatted student data to an output file
 * @param string names[] - Array containing student names
 * @param int scores[][5] - 2D array containing test scores for each student
 */
void storeData(string names[], int scores[][5])
{
    ofstream oFile;

    // Open the file
    oFile.open("gradedTests.out");

    // Header
    oFile << left << setw(16) << "Student Name" << "| " << setw(30) << "Test Scores" << "| " << setw(10) << "Average Scores" << " | Final Grade" << endl;
    oFile << setw(80) << setfill('=') << "" << endl << setfill(' ');
    
    // Display 
    for(int i = 0; i < 10; i++)
    {
        oFile << left << setw(16) << names[i] << "| ";
        for(int j = 0; j < 5; j++)
            oFile << setw(5) << scores[i][j] << " ";

        double average = averageTestScore(scores, i);
        oFile << "| " << setw(15) << average << "| " << determineGrade(round(average)) << endl;
    }
    oFile << setw(80) << setfill('=') << "" << endl << setfill(' ');
    oFile << left << setw(16) << "Class Average   | ";
    for(int j = 0; j < 5; j++)
        oFile << setw(5) << averageClassScore(scores, j) << " ";
    oFile << endl;

    // Close the File
    oFile.close();
}

/**
 * averageTestScore: Calculates the average test score for a specific student
 * @param int scores[][5] - 2D array containing all student test scores
 * @param int index - Row index for the student whose average is being calculated
 * @return double - The calculated average score for the specified student
 */
double averageTestScore(int scores[][5], int index)
{
    double sum = 0.0;
    for(int j = 0; j < 5; j++)
        sum += scores[index][j];
    return sum / 5.0;
}

/**
 * averageClassScore: Calculates the class average for a specific test
 * @param int scores[][5] - 2D array containing all student test scores
 * @param int index - Column index for the test whose class average is being calculated
 * @return double - The calculated class average for the specified test
 */
double averageClassScore(int scores[][5], int index)
{
    int sum = 0.0;
    for(int i = 0; i < 10; i++)
        sum += scores[i][index];
    return sum / 10.0;
}

/**
 * determineGrade: Converts a numeric average to a letter grade
 * @param int average - The numeric average to convert
 * @return char - The corresponding letter grade (A, B, C, D, or F)
 */
char determineGrade(int average)
{
    switch(average / 10)
    {
        case 10:
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        case 5:
        default:
            return 'F';
    }
}