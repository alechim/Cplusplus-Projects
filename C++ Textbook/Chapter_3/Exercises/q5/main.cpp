// Question 5: Pay Increase Program
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    ifstream iFile;
    ofstream oFile;
    string firstName = "";
    string lastName = "";
    double salary = 0.0;
    double payIncrease = 0.0;

    // Open the files
    iFile.open("Ch3_Ex5Data.txt");
    oFile.open("Ch3_Ex5Output.dat");

    oFile << fixed << showpoint << setprecision(2);
    while(true)
    {
        // Base Case
        if(!(iFile >> firstName >> lastName >> salary >> payIncrease))
        {
            break;
        }
        oFile << firstName << " " << lastName << " " << salary + (salary * (payIncrease / 100)) << endl;
    }

    // Close the files
    iFile.close();
    oFile.close();

    return 0;
}