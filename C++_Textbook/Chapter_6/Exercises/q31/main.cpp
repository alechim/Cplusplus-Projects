// Question 31: Pipe Problem
/**
 * Given:
 * - Length of the pipe = AB + BC = 8 / sin(theta) + 5 / cos(theta), where 0 < theta < pi / 2
     > 5 and 8 are example widths of the given problem
 * Solution I followed:
 * - YT Link: https://youtu.be/UtfmX5UZ3-o?si=Fyr3zwmO8O09L9ET
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ***Function Prototypes***
void promptInput(double& value, const string prompt);

int main()
{
    // Variables
    double hall1Width = 0.0;
    double hall2Width = 0.0;
    double pipeLength = 0.0;

    // Prompt Input
    promptInput(hall1Width, "Enter the width of the first corridor (feet): ");
    promptInput(hall2Width, "Enter the width of the second corridor (feet): ");

    // Calculations
    /**
     * From Solution Video: hall2Width = pipeLength^(2/3) * sqrt(pipeLength^(2/3) - hall1Width^(2/3)) - hall1Width^(2/3) * sqrt(pipeLength^(2/3) - hall1Width^(2/3))
     * - hall2Width = (pipeLength^(2/3) - hall1Width^(2/3)) * (sqrt(pipeLength^(2/3) - hall1Width^(2/3)))
     * - hall2Width = (pipeLength^(2/3) - hall1Width^(2/3))^1 * (pipeLength^(2/3) - hall1Width^(2/3))^(1/2)
     * - (hall2Width)^(2/3) = [(pipeLength^(2/3) - hall1Width^(2/3))^(3/2)]^(2/3)
     * - hall2Width^(2/3) = pipeLength^(2/3) - hall1Width^(2/3)
     * - pipeLength^(2/3) = hall2Width^(2/3) + hall1Width^(2/3)
     * - [pipeLength^(2/3)]^(3/2) = (hall2Width^(2/3) + hall1Width^(2/3))^(3/2)
     * - pipeLength = (hall2Width^(2/3) + hall1Width^(2/3))^(3/2)
     */
    pipeLength = pow(pow(hall2Width, 2.0 / 3.0) + pow(hall1Width, 2.0 / 3.0), 3.0 / 2.0);

    // Display Results
    cout << "The maximum length of the pipe that can be carried around the corner is approximately " << round(pipeLength) << " feet long.\n";

    return 0;
}

// ***Functions***
void promptInput(double& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while (true);
}