// Question 9: 2-D Array Monthly Temperatures
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Global Variables
const int ROWS = 2;         // Row - 0: Highest, 1: Lowest
const int COLS = 12;        // Column - Months

// Function Prototypes
int getData(int[ROWS][COLS]);
double averageHigh(int[ROWS][COLS]);
double averageLow(int[ROWS][COLS]);
int indexHighTemp(int[ROWS][COLS]);
int indexLowTemp(int[ROWS][COLS]);
string findMonth(int);

int main()
{
    // Variables
    int temperature[ROWS][COLS];
    int highIndex = 0, lowIndex = 0;

    // Read and Verify if file has opened
    if(getData(temperature) == -1)
    {
        cout << "Error - 'monthTemp.txt' did not open." << endl;
        cout << "Terminating Program..." << endl;
        return -1;
    }

    // Calculate Average, Highest Index, and Lowest Index
    highIndex = indexHighTemp(temperature);
    lowIndex = indexLowTemp(temperature);

    // Display Results
    cout << "+ " << setw(32) << setfill('=') << "" << endl << setfill(' ');
    cout << "| Las Vegas, Nevada 2024 Temperature Report" << endl;
    cout << "+ " << setw(32) << setfill('=') << "" << endl << setfill(' ');
    cout << "| The average of the highest temperatures is " << fixed << setprecision(2) << averageHigh(temperature) << " fahrenheit." << endl;
    cout << "| The average of the lowest temperatures is " << fixed << setprecision(2) << averageLow(temperature) << " fahrenheit." << endl;
    cout << "| The highest temperature is " << temperature[0][highIndex] << " fahrenheit at index '" << highIndex << "' in " << findMonth(highIndex) << "." << endl;
    cout << "| The lowest temperature is " << temperature[1][lowIndex] << " fahrenheit at index '" << lowIndex << "' in " << findMonth(lowIndex) << "."  << endl;
    cout << "+ " << setw(32) << setfill('=') << "" << endl << setfill(' ');

    return 0;
}

// Function Definitions
/**
 * getData: Reads and stores data in the two dimensional array
 * @param int temperatures[ROWS][COLS] - The array to store the read data
 * @return int - 0: if file is read, -1: if file is not read
 */
int getData(int temperatures[ROWS][COLS])
{
    ifstream iFile;

    // Open and Validate the file
    iFile.open("monthTemp.txt");
    if(!iFile.is_open())
        return -1;
    
    // Read data from file
    for(int i = 0; iFile >> temperatures[0][i] >> temperatures[1][i] && i < 12; i++);

    // Close the file
    iFile.close();

    return 0;
}

/**
 * averageHigh: Calculates and returns the average high for the year
 * @param int highTemp[ROWS][COLS] - The array to be summed and averaged (high: 0)
 * @return double
 */
double averageHigh(int highTemp[ROWS][COLS])
{
    double sum = 0.0;
    for(int i = 0; i < COLS; i++)
        sum += highTemp[0][i];
    return sum / COLS;
}

/**
 * averageLow: Calculates and returns the average low temperature for the year
 * @param int lowTemp[ROWS][COLS] - The array to be summed and averaged (low: 1)
 * @return double
 */
double averageLow(int lowTemp[ROWS][COLS])
{
    double sum = 0.0;
    for(int i = 0; i < COLS; i++)
        sum += lowTemp[1][i];
    return sum / COLS;
}

/**
 * indexHighTemp: Returns the index of the highest high temperature in the array
 * @param int highTemp[ROWS][COLS] - The array to be traversed (high: 0) 
 * @return int 
 */
int indexHighTemp(int highTemp[ROWS][COLS])
{
    int maxIndex = 0;
    for(int i = 1; i < COLS; i++)
        if(highTemp[0][maxIndex] < highTemp[0][i])
            maxIndex = i;
    return maxIndex;
}

/**
 * indexLowTemp: Returns the index of the lowest low temperature in the array
 * @param int lowTemp[ROWS][COLS] - The array to be traversed (low: 1)
 * @return int 
 */
int indexLowTemp(int lowTemp[ROWS][COLS])
{
    int lowIndex = 0;
    for(int i = 1; i < COLS; i++)
        if(lowTemp[1][i] < lowTemp[1][lowIndex])
            lowIndex = i;
    return lowIndex;
}

/**
 * findMonth: Returns the string corresponding to the index passed
 * @param int index - The integer that determines the month
 * @return string
 */
string findMonth(int index)
{
    switch(index + 1)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9: 
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "EMPTY";
    }
}