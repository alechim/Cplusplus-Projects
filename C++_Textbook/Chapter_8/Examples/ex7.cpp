// Example 8-7: Calculate Average Speed given Distance Traveled
#include <iostream>
#include <iomanip>

using namespace std;

// Global Constant Variables
const int SIZE = 6;

// Function Prototypes
void getData(double list[], int length);
void averageSpeedOverTimeInterval(double list[], int length, double avgSpeed[]);
double maxAvgSpeed(double avgSpeed[], int length);
double minAvgSpeed(double avgSpeed[], int length);
void print(double list[], int length, double avgSpeed[]);

int main()
{
    // Variables
    double distanceTraveled[SIZE];
    double averageSpeed[SIZE];

    cout << fixed << showpoint << setprecision(2);

    getData(distanceTraveled, SIZE);
    averageSpeedOverTimeInterval(distanceTraveled, SIZE, averageSpeed);
    print(distanceTraveled, SIZE, averageSpeed);

    cout << "Maximum Average Speed: " << maxAvgSpeed(averageSpeed, SIZE) << endl;
    cout << "Minimum Average Speed: " << minAvgSpeed(averageSpeed, SIZE) << endl;

    return 0;
}

// Function Definitions
void getData(double list[], int length)
{
    cout << "Enter the total distance traveled after every 10 units of time." << endl;

    for(int index = 0; index < length; index++)
    {
        cout << "Enter total distance traveled at time " << index * 10 << " units: ";
        cin >> list[index];
        cout << endl;
    }
}

void averageSpeedOverTimeInterval(double list[], int length, double avgSpeed[])
{
    for(int index = 0; index < length - 1; index++)
        avgSpeed[index] = (list[index + 1] - list[index]) / 10;
}

double maxAvgSpeed(double avgSpeed[], int length)
{
    double max = avgSpeed[0];

    for(int index = 1; index < length - 1; index++)
        if(avgSpeed[index] > max)
            max = avgSpeed[index];
    
    return max;
}

double minAvgSpeed(double avgSpeed[], int length)
{
    double min = avgSpeed[0];

    for(int index = 1; index < length - 1; index++)
        if(avgSpeed[index] < min)
            min = avgSpeed[index];
    
    return min;
}

void print(double list[], int length, double avgSpeed[])
{
    cout << setw(7) << " Time " << setw(20) << "Distance Traveled " << setw(10) << "Average Speed / Time Interval" << endl;
    cout << setw(5) << 0 << setw(14) << list[0] << setw(6) << " " << setw(10) << 0 << "   [0, 0]  " << endl;
    for(int index = 1; index < length; index++)
        cout << setw(5) << index * 10 << setw(14) << list[index] << setw(6) << " " << setw(10) << avgSpeed[index - 1] << "   [" << (index - 1) * 10 << ", " << index * 10 << "]" << endl;
}