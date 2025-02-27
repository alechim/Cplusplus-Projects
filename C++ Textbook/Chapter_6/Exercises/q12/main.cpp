// Question 12: Calculate Mean and Standard Deviation
#include <iostream>
#include <cmath>

using namespace std;

// ***Function Prototypes***
double mean(double num[]);
double standDeviation(double num[], double mean);

int main()
{
    // Variables
    double x[5];

    // Prompt for Input
    do
    {
        cout << "Enter 5 numbers: ";
        for(int i = 0; i < 5; i++)
            cin >> x[i];
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 5 double values." << endl;
        } else
            break;
    } while(true);
    
    // Display Results
    cout << "The mean of the 5 numbers is " << mean(x) << ".\n";
    cout << "The standard deviation of the 5 numbers is " << standDeviation(x, mean(x)) << ".\n";

    return 0;
}

// ***Functions***
double mean(double num[5])
{
    return ((num[0] + num[1] + num[2] + num[3] + num[4]) / 5.0);
}

double standDeviation(double num[], double mean)
{
    double numerator = 0.0;
    for(int i = 0; i < 5; i++)
        numerator += pow((num[i] - mean), 2.0);
    return sqrt(numerator / 5.0);
}