// Question 10: Refactored Exercise 6-12 (Standard Deviation and Mean Calculator)
/**
 * Changes:
 * - Updated from forced 5 double values to up to 100 double values
 */
#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
double mean(double[], int);
double standDeviation(double[], double, int);

int main()
{
    // Variables
    double values[100];
    int limit = 0;

    // Prompt and Validate Input - Limit
    do
    {
        cout << "Enter a value [2-100] for the amount of numbers you would like to calculate: ";
        cin >> limit;
        if(cin.fail() || (limit < 2 && limit > 100))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value from 2 to 100." << endl;
        } else
            break;
    } while(true);
    
    // Prompt and Validate Input - Values
    do
    {
        cout << "Enter " << limit << " numbers: " << endl;
        for(int i = 0; i < limit; i++)
            cin >> values[i];
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter " << limit << " double values." << endl;
        } else
            break;
    } while(true);
    
    // Calculate and Display Results
    cout << "The mean of the " << limit << " numbers is " << mean(values, limit) << ".\n";
    cout << "The standard deviation of " << limit << " numbers is " << standDeviation(values, mean(values, limit), limit) << ".\n";

    return 0;
}

// Function Definitions
/**
 * mean: Calculate mean of the array
 * @param double num[] - The array to be summed
 * @param int limit - The number of elements in the array 
 * @return double
 */
double mean(double num[], int limit)
{
    double sum = 0.0;
    for(int i = 0; i < limit; i++)
        sum += num[i];
    return sum / limit;
}

/**
 * standDeviation: Calculate standard deviation based on passed parameters
 * @param double num[] - The array to be summed
 * @param double mean - The calculated mean of the array
 * @param int limit - The number of elements in the array 
 * @return double
 */
double standDeviation(double num[], double mean, int limit)
{
    double numerator = 0.0;
    for(int i = 0; i < limit; i++)
        numerator += pow((num[i] - mean), 2.0);
    return sqrt(numerator / limit);
}