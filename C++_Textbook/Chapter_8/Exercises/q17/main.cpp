// Question 17: Compute Employee Weekly Pay and Average Salary + Data Manipulation
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// Function Prototypes
int readFile(string[], double[][3]);
void calculateWeeklyPay(double[][3]);
void findTopEmployees(string[], double[][3]);
void displayData(string[], double[][3]);
double findAverage(double[][3]);

int main()
{
    // Variables
    string lastNames[10];
    // Column - 0: Hours, 1: Hourly Pay, 2: Weekly Pay
    double employeeData[10][3] = {0, 0, 0};
    double averagePay = 0.0;

    // Open and Read the Input File
    if(readFile(lastNames, employeeData) == -1)
    {
        cout << "Error - Could not open the file 'employees.txt'." << endl;
        cout << "Terminating the Program..." << endl; 
        return -1;
    }

    // Data Manipulation and Display Results
    calculateWeeklyPay(employeeData);
    displayData(lastNames, employeeData);
    findTopEmployees(lastNames, employeeData);

    return 0;
}

// Function Definitions
/**
 * readFile: Reads employee data from a file into arrays
 * @param string names[] - Array to store employee last names
 * @param double data[][3] - 2D array to store hours worked, hourly rate, and weekly pay 
 * @return int - Returns 0 if successful, -1 if file could not be opened
 */
int readFile(string names[], double data[][3])
{
    ifstream iFile;

    // Open and Validate File
    iFile.open("employees.txt");
    if(!iFile.is_open())
        return -1;

    // Process the data
    for(int i = 0; i < 10; i++)
        iFile >> names[i] >> data[i][0] >> data[i][1];
    
    // Close the file
    iFile.close();

    return 0;
}

/**
 * calculateWeeklyPay: Calculates weekly pay for each employee including overtime
 * @param double data[][3] - 2D array containing employee data
 */
void calculateWeeklyPay(double data[][3])
{
    for(int i = 0; i < 10; i++)
    {
        int hours = round(data[i][0]);
        // If hours > 40, hours > 40 is 1.5 times hourly rate
        data[i][2] = (hours <= 40) ? (hours * data[i][1]) : ((40 * data[i][1]) + ((hours - 40) * data[i][1] * 1.5));
    }
}

/**
 * findTopEmployees: Identifies and displays employees with above average weekly pay
 * @param string names[] - Array of employee last names
 * @param double data[][3] - 2D array containing employee data and weekly pay 
 */
void findTopEmployees(string names[], double data[][3])
{
    double average = findAverage(data);

    cout << "Average Weekly Pay: $" << fixed << showpoint << setprecision(2) << average << endl;
    // Display employees whose weekly pay is the same as the average or greater
    cout << "Top Employees: ";
    for(int i = 0; i < 10; i++)
        if(average <= data[i][2])
            cout << names[i] << " | ";
    cout << endl << setw(56) << setfill('=') << "" << endl << setfill(' ') << endl;
}

/**
 * displayData: Formats and displays all employee information in a table
 * @param string names[] - Array of employee last names
 * @param double data[][3] - 2D array containing hours worked, hourly rate, and weekly pay
 */
void displayData(string names[], double data[][3])
{
    // Header
    cout << endl << left << setw(14) << "Last Names" << setw(16) << "Hours Worked" << setw(14) << "Hourly Rate" << "Weekly Pay" << endl;
    cout << setw(56) << setfill('=') << "" << endl << setfill(' ');

    // Information
    for(int i = 0; i < 10; i++)
    {
        cout << left << setw(14) << names[i] << setw(16) << static_cast<int>(data[i][0]);
        cout << fixed << showpoint << setprecision(2);
        cout << "$" << setw(13) << data[i][1] << "$" << data[i][2] << endl;
    }
    cout << setw(56) << setfill('=') << "" << endl << setfill(' ');
}

/**
 * findAverage: Calculates the average weekly pay of all employees
 * @param double data[][3] - 2D array containing employee data where data[i][2] is weekly pay
 * @return double - The average weekly pay across all employees
 */
double findAverage(double data[][3])
{
    double sum = 0.0;

    // Find average weekly pay
    for(int i = 0; i < 10; i++)
        sum += data[i][2];

    return sum / 10.0;
}