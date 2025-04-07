// Question 6: Grade T/F Quizzes
/**
 * Notes: 
 * - Question meant for a dataset of more than 150 students
 * - Test only has 20 questions
 * - Test only has 'T', 'F', or ' ' marked
 *   > No need for verification for studentID or answers
 */
/**
 * Point Distribution:
 * > Correct Answer - 2 points
 * > Wrong Answer - 1 point
 * > No Answer - 0 points
 * Grade Distribution:
 * > A: 100 - 90
 * > B: 89.99 - 80
 * > C: 79.99 - 70
 * > D: 69.99 - 60
 * > F: 59.99 - 50
 */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function Prototypes
void outputFile(ofstream&, string, char[21], int);
int gradeQuestions(char[21], char[21]);

int main()
{
    // Variables
    string studentID = "";
    char answerKey[21];         // Needs to be index '21' for null terminator to exist at end of c-string
    char answers[21];
    int testScore = 0;
    ifstream iFile;
    ofstream oFile;

    // Open and Verify Files
    iFile.open("testEntries.txt");
    if(!iFile.is_open())
    {
        cout << "Error - 'testEntries.txt' did not open." << endl;
        return -1;
    }
    oFile.open("gradedEntries.out");
    if(!oFile.is_open())
    {
        cout << "Error - 'gradedEntries.out' did not open." << endl;
        return -1;
    }

    // Read the answer key and key ID
    iFile >> studentID;
    iFile >> answerKey;

    // Output the header
    oFile << left << setw(15) << "Student ID" << setw(26) << "Students Answers" << setw(16) << "Test Score" << "Grade" << endl;
    oFile << setw(64) << setfill('=') << "" << endl << setfill(' ');

    // Process the entire file
    while(iFile >> studentID)
    {
        iFile.get(); // Consume the space after student ID
        iFile.get(answers, 21); // Read exactly 20 characters including spaces
        testScore = gradeQuestions(answerKey, answers);
        outputFile(oFile, studentID, answers, testScore);
    }

    // Close the files
    iFile.close();
    oFile.close();

    return 0;
}

// Function Definitions
/**
 * outputFile - function to organize and determine the student's grade then outputs to a file
 * @param ofstream& oFile - the file to be outputted to
 * @param string studentID - the student's verified ID associated with the test
 * @param char answers[20] - the c-string that contains the student's answers
 * @param int testScore - the score that was calculated based on the student's answers
 */
void outputFile(ofstream& oFile, string studentID, char answers[20], int testScore)
{
    // Max Score: 40
    char grade = ' ';
    // Converts to percentage to be determined by switch statement
    int percentage = static_cast<double>(testScore) / 40 * 10;
    switch(percentage)
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
        default:
            grade = 'F';
    }
    oFile << left << setw(15) << studentID << setw(26) << answers << setw(16) << testScore << grade << endl;
}

/**
 * gradeQuestions - function to compare the answerKey to the answers
 * @param char answerKey[20] - The c-string that contains the correct answers
 * @param char answers[20] - The c-string that contains the student's answers
 */
int gradeQuestions(char answerKey[20], char answers[20])
{
    int score = 0;

    // Compare answers to answerKey
    // - 2: correct, 1: incorrect, 0: blank
    for(int i = 0; i < 20; i++)
    {
        if(answerKey[i] == answers[i])
            score += 2;
        else if(answers[i] == ' ')
            score += 0;
        else
            score += 1;
    }

    return score;
}   