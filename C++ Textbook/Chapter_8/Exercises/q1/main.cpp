// Question 1: Array Manipulation
// - First 25 components - Square of the index variable
// - Last 25 components - Three times of the index variable
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int indexSize = 50;
    double alpha[indexSize];

    // Process the Array
    for(int i = 0; i < indexSize; i++)
    {
        if(i < 25)
            alpha[i] = sqrt(i);
        else
            alpha[i] = 3 * i;
    }

    // Display Array
    for(int i = 0; i < indexSize; i++)
    {
        if(i % 10 == 0)
            cout << endl;
        if(alpha[i] == static_cast<int>(alpha[i]))
            cout << setw(7) << static_cast<int>(alpha[i]) << " ";
        else
            cout << fixed << showpoint << setprecision(2) << setw(7) << alpha[i] << " ";
    }
    cout << endl << endl;

    return 0;
}