// Question 20: Refactored Example 8-7
// - Allows the user to store the distance traveled at the desired times

#include <iostream>
#include <iomanip>

using namespace std;

// Global Constant Variables
const int SIZE = 6;

// Function Prototypes
void getData(double list[], int times[], int length);
void averageSpeedOverTimeInterval(double list[], int length, double avgSpeed[], int times[]);
double maxAvgSpeed(double avgSpeed[], int length);
double minAvgSpeed(double avgSpeed[], int length);
void print(double list[], int length, double avgSpeed[], int times[]);

int main()
{
    // Variables
    int timeIntervals[SIZE] = {10, 16, 20, 30, 38, 45};
    double distanceTraveled[SIZE];
    double averageSpeed[SIZE];

    cout << fixed << showpoint << setprecision(2);

    getData(distanceTraveled, timeIntervals, SIZE);
    averageSpeedOverTimeInterval(distanceTraveled, SIZE, averageSpeed, timeIntervals);
    print(distanceTraveled, SIZE, averageSpeed, timeIntervals);

    cout << "Maximum Average Speed: " << maxAvgSpeed(averageSpeed, SIZE) << endl;
    cout << "Minimum Average Speed: " << minAvgSpeed(averageSpeed, SIZE) << endl;

    return 0;
}

// Function Definitions
/**
 * getData: Collects distance traveled data from the user for each time interval
 * @param double list[] - Array to store the distance traveled values
 * @param int times[] - Array containing the time interval values
 * @param int length - Size of the arrays
 */
void getData(double list[], int times[], int length)
{
    cout << "Enter the total distance traveled after every shown interval of time." << endl;

    for(int index = 0; index < length; index++)
    {
        cout << "Enter total distance traveled at time " << times[index] << " units: ";
        cin >> list[index];
        cout << endl;
    }
}

/**
 * averageSpeedOverTimeInterval: Calculates the average speed between consecutive time intervals
 * @param double list[] - Array containing the distance traveled values
 * @param int length - Size of the arrays
 * @param double avgSpeed[] - Array to store the calculated average speeds
 * @param int times[] - Array containing the time interval values
 */
void averageSpeedOverTimeInterval(double list[], int length, double avgSpeed[], int times[])
{
    for(int index = 0; index < length - 1; index++)
        avgSpeed[index] = (list[index + 1] - list[index]) / (times[index + 1] - times[index]);
}

/**
 * maxAvgSpeed: Finds the maximum average speed from the calculated speeds
 * @param double avgSpeed[] - Array containing the calculated average speeds
 * @param int length - Size of the array
 * @return double - The maximum average speed
 */
double maxAvgSpeed(double avgSpeed[], int length)
{
    double max = avgSpeed[0];

    for(int index = 1; index < length - 1; index++)
        if(avgSpeed[index] > max)
            max = avgSpeed[index];
    
    return max;
}

/**
 * minAvgSpeed: Finds the minimum average speed from the calculated speeds
 * @param double avgSpeed[] - Array containing the calculated average speeds
 * @param int length - Size of the array
 * @return double - The minimum average speed
 */
double minAvgSpeed(double avgSpeed[], int length)
{
    double min = avgSpeed[0];

    for(int index = 1; index < length - 1; index++)
        if(avgSpeed[index] < min)
            min = avgSpeed[index];
    
    return min;
}

/**
 * print: Displays the time, distance traveled, and average speed in a formatted table
 * @param double list[] - Array containing the distance traveled values
 * @param int length - Size of the arrays
 * @param double avgSpeed[] - Array containing the calculated average speeds
 * @param int times[] - Array containing the time interval values
 */
void print(double list[], int length, double avgSpeed[], int times[])
{
    cout << setw(7) << " Time " << setw(20) << "Distance Traveled " << setw(10) << "Average Speed / Time Interval" << endl;
    cout << setw(5) << 0 << setw(14) << list[0] << setw(6) << " " << setw(10) << 0 << "   [0, 0]  " << endl;
    for(int index = 1; index < length; index++)
        cout << setw(5) << times[index - 1] << setw(14) << list[index] << setw(6) << " " << setw(10) << avgSpeed[index - 1] << "   [" << times[index - 1] << ", " << times[index] << "]" << endl;
}