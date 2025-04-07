// Question 12: Analyzing Runner Data using Parallel Arrays
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function Prototypes
int readFile(string[], double[][7]);
void storeData(string[], double[][7]);
double totalMiles(double[][7], int);
double averageMiles(double[][7], int);

int main()
{
    string runnerName[5];
    double milesDay[5][7];

    // Input File
    cout << "Reading the file..." << endl;
    if(readFile(runnerName, milesDay) == -1)
    {
        cout << "Error - Could not open the file 'runnerData.txt'." << endl;
        cout << "Terminating the Program..." << endl; 
        return -1;
    }

    // Output File
    cout << "Outputting to 'modifiedData.out'..." << endl;
    storeData(runnerName, milesDay);

    cout << "Completed. Terminating Program..." << endl;

    return 0;
}

// Function Definitions
/**
 * readFile: Reads and Validates the file that contains the runners names and their mile data
 * @param string name[] - The 1-D array to store the 5 names of the runner
 * @param double miles[][7] - The 2-D parallel array to store the runner's mile data
 * @return int
 */
int readFile(string name[], double miles[][7])
{
    ifstream iFile;

    // Open and Validate File
    iFile.open("runnerData.txt");
    if(!iFile.is_open())
        return -1;
    
    // Read the data from file
    for(int i = 0; i < 5; i++)
    {
        iFile >> name[i];
        for(int j = 0; j < 7; j++)
            iFile >> miles[i][j];
    }

    // Close the file
    iFile.close();

    return 0;
}

/**
 * storeData: Stores the runnerName and miles array into a new output file
 * @param string name[] - The 1-D array containing the 5 names of the runner
 * @param double miles[][7] - The 2-D parallel array containing the runner's mile data
 */
void storeData(string name[], double miles[][7])
{
    ofstream oFile;

    oFile.open("modifiedData.out");

    oFile << fixed << showpoint << setprecision(2);
    oFile << left << setw(15) << "Runner Names" << setw(51) << "| Miles Each Day" << "| Total Miles" << " | Average Miles" << endl;
    oFile << setw(100) << setfill('=') << "" << endl << setfill(' ');
    for(int i = 0; i < 5; i++)
    {
        oFile << left << setw(14) << name[i] << " | ";
        for(int j = 0; j < 7; j++)
            oFile << setw(6) << miles[i][j] << " ";
        oFile << "| " << left << setw(11) << totalMiles(miles, i) << " | " << averageMiles(miles, i) << endl; 
    }

    oFile.close();
}

/**
 * totalMiles: Calculates the sum of the miles from the passed array
 * @param double miles[][7] - The 2-D array containing the miles data
 * @param int index - The index of the runner's data to be processed
 * @return double
 */
double totalMiles(double miles[][7], int index)
{
    double sum = 0.0;
    for(int i = 0; i < 7; i++)
        sum += miles[index][i];
    return sum;
}

/**
 * averageMiles: Calculates the average of the miles from the passed array
 * @param double miles[][7] - The 2-D array containing the miles data
 * @param int index - The index of the runner's data to be processed
 * @return double
 */
double averageMiles(double miles[][7], int index)
{
    return totalMiles(miles, index) / 7.0;
}