// Question 23: Average, Below, and Highest Test Scores
/** 
 * Given:
 * - Student Names and Test Scores
 * - 10 Students, 1 Test Score
 * Solve:
 * - Calculate average test scores
 * - Print names of all students whose test scores are below average test score
 * - Determine highest test score
 * - Print names of all students whose test scores are the same as the highest test score
 */
/**
 * Algorithm:
 * - Open and read from file
 * - Find the max test score
 * - Calculate average of students and overall class
 * - Store and compare student averages to class average
 * - Find any student that has a test score that matches the highest
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // Variables
    vector<string> fullName, belowAverage, sameHighest;
    vector<double> testScores;
    string firstName = "";
    string lastName = "";
    double classAverage = 0.0;
    double highestScore = 0.0;
    double testScore = 0.0;
    double sum = 0.0;

    // Open the file
    ifstream iFile;
    string fileName = "mainIn.txt";
    iFile.open(fileName);

    while(iFile >> firstName >> lastName)
    {
        fullName.push_back(firstName + " " + lastName);
        iFile >> testScore;
        testScores.push_back(testScore);

        sum += testScore;
        if(testScore > highestScore)
            highestScore = testScore;
        testScore = 0.0;
    }
    classAverage = sum / 10;

    for(int i = 0; i < 10; i++)
    {
        // If their test score is below average, store name in vector for display later
        if(classAverage > testScores[i])
            belowAverage.push_back(fullName[i]);
        
        if(highestScore == testScores[i])
            sameHighest.push_back(fullName[i]);
    }

    // Display Results
    cout << "-----" << endl;
    cout << fixed << setprecision(2);
    cout << "The class average of the test is " << classAverage << endl;
    cout << "The highest score of the test is " << highestScore << endl;
    cout << "-----" << endl;
    cout << "The students who scored below average are: ";
    for(int i = 0; i < belowAverage.size(); i++)
    {    
        cout << belowAverage[i];
        if(!(i + 1 == belowAverage.size()))
            cout << ", ";
    }
    cout << endl << "-----" << endl;
    cout << "The students who scored the highest are: ";
    for(int i = 0; i < sameHighest.size(); i++)
    {    
        cout << sameHighest[i];
        if(!(i + 1 == sameHighest.size()))
            cout << ", ";
    }
    cout << endl << "-----" << endl;

    // Close the file
    iFile.close();

    return 0;
}