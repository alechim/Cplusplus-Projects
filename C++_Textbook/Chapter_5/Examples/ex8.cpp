// Example 5-8: Student's Test Scores
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    string firstName = "";
    string lastName = "";
    double testScore = 0.0;
    char grade = ' ';
    double sum = 0.0;
    int count = 0;
    
    // Declare stream variables
    ifstream inFile;
    ofstream outFile;

    // Open input file
    inFile.open("ex8_stData.txt");

    if(!inFile)
    {
        cout << "Cannot open input file. Program terminated!" << endl;
        return 1;
    }

    // Open output file
    outFile.open("ex8_stData.out");

    outFile << fixed << showpoint << setprecision(2);
    inFile >> firstName >> lastName;
    inFile >> testScore;

    while(inFile)
    {
        sum = sum + testScore;  // Update sum
        count++;

        switch(static_cast<int>(testScore) / 10)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                grade = 'F';
                break;
            case 6:
                grade = 'D';
                break;
            case 7:
                grade = 'C';
                break;
            case 8:
                grade = 'B';
                break;
            case 9:
            case 10:
                grade = 'A';
                break;
            default:
                cout << "Invalid Score." << endl;
        }   // End Switch

        outFile << left << setw(12) << firstName << setw(12) << lastName << right << setw(4) << testScore << setw(2) << grade << endl;
        inFile >> firstName >> lastName;
        inFile >> testScore;
    }   // End While

    outFile << endl;

    if(count != 0)
        outFile << "Class Average: " << sum / count << endl;
    else
        outFile << "No Data." << endl;
    
    // Close the files
    inFile.close();
    outFile.close();

    return 0;
}