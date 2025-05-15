// Question 13: Find Weighted Average of Test Scores
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double testScore = 0.0;
    double weightedTestScore = 0.0;
    double weightedAverage = 0.0;

    // Open the file
    ifstream iFile;
    string fileName = "mainIn.txt";
    iFile.open(fileName);
    
    while(iFile >> testScore >> weightedTestScore)
        weightedAverage += testScore * weightedTestScore;

    cout << "The weighted average is " << fixed << setprecision(2) << weightedAverage << endl;

    // Close the file
    iFile.close();

    return 0;
}