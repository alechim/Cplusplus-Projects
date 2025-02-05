// Example 1-5: Average Test Scores and Grade
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // Variables
    double testScores[5];
    vector<double> totalAverage;
    string firstName = "";
    string lastName = "";
    double classAverage = 0.0;
    double sum = 0.0;
    double average = 0.0;
    int intAverage = 0;
    char grade = ' ';

    // Open files
    ifstream iFile;
    ofstream oFile;
    string fileName = "ex5in.txt";
    string exportName = "ex5out.txt";
    iFile.open(fileName);
    oFile.open(exportName);

    cout << "Processing Data..." << endl;

    while(true)
    {
        // Base Case
        if(!(iFile >> firstName >> lastName))
            break;  // Exit loop if reading fails (EOF / malformed input)

        // Initialize Line
        oFile << fixed << showpoint << setprecision(2);
        oFile << "-----" << endl;
        // Output student name
        oFile << "Student Name: " << firstName << " " << lastName << endl;
        
        // Initialize and gather sum
        sum = 0;
        for(int i = 0; i < 5; i++)
        {
            iFile >> testScores[i];
            sum += testScores[i];
        }

        // Calculate and Gather Average
        average = sum / 5;
        totalAverage.push_back(average);
        oFile << "Test Scores: ";
        for(int i = 0; i < 5; i++)
            oFile << setw(6) << testScores[i] << " ";
        oFile << endl;
        oFile << "Average Score: " << setw(6) << average << endl;

        intAverage = static_cast<int>(average);
        switch(intAverage / 10)
        {
            case 0: case 1: case 2: case 3: case 4: case 5:
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
        }
        oFile << "Grade is " << grade << endl;
    }

    sum = 0;
    // Calculate class average
    for(int i = 0; i < totalAverage.size(); i++)
        sum += totalAverage[i];
    classAverage = sum / totalAverage.size();

    oFile << "-----" << endl;
    oFile << "Class Average: " << classAverage << endl;

    cout << "Done!" << endl;

    // Close files
    iFile.close();
    oFile.close();

    return 0;
}