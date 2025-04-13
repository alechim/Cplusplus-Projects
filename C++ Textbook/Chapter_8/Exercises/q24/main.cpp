// Question 24: 20 x 20 Board Neighbor Peaks
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Function Prototypes
void generateArray(int[][20]);
void displayArray(int[][20]);
void findPeak(int[][20], int [][2], int [][2]);

int main()
{
    int neighborArray[20][20];
    int minimumPeak[20][2], maximumPeak[20][2];

    // Initialize minimum and maximum peak arrays
    for(int i = 0; i < 20; i++)
    {
        minimumPeak[i][0] = -1;
        minimumPeak[i][1] = -1;
        maximumPeak[i][0] = -1;
        maximumPeak[i][1] = -1;
    }

    // Seed the random number generator
    srand(time(0));

    // Generate, Display and Find Peaks of the Array
    generateArray(neighborArray);
    displayArray(neighborArray);
    findPeak(neighborArray, minimumPeak, maximumPeak);

    // Display Results
    cout << endl << "+" << setw(89) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Minimum Peaks:" << setw(75) << " |" << endl;
    cout << "+" << setw(89) << setfill('-') << "" << "+" << endl << setfill(' ') << "| ";
    int minCount = 0;
    for(int i = 0; i < 20; i++)
    {
        if(minimumPeak[i][0] != -1) 
        {
            if(minCount % 3 == 0 && i != 0)
                cout << "| ";

            cout << left << setw(29) << "Position (" + to_string(minimumPeak[i][0]) + ", " + to_string(minimumPeak[i][1]) + ") = " + to_string(neighborArray[minimumPeak[i][0]][minimumPeak[i][1]]);
            minCount++;

            if(minCount % 3 == 0)
                cout << " |" << endl;
        }
    }
    if(minCount % 3 != 0)
        cout << setw((3 - (minCount % 3)) * 29) << "" << " |" << endl;

    cout << "+" << setw(89) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Maximum Peaks:" << setw(74) << "" << "|" << endl;
    cout << "+" << setw(89) << setfill('-') << "" << "+" << endl << setfill(' ') << "| ";
    int maxCount = 0;
    for(int i = 0; i < 20; i++) 
    {
        if(maximumPeak[i][0] != -1) 
        {   
            if(maxCount % 3 == 0 && i != 0)
                cout << "| ";

            cout << left << setw(29) << "Position (" + to_string(maximumPeak[i][0]) + ", " + to_string(maximumPeak[i][1]) + ") = " + to_string(neighborArray[maximumPeak[i][0]][maximumPeak[i][1]]);
            maxCount++;

            if(maxCount % 3 == 0)
                cout << " |" << endl;
        }
    }
    if(maxCount % 3 != 0)
        cout << setw((3 - (maxCount % 3)) * 29) << "" << " |" << endl;
    cout << "+" << setw(89) << setfill('=') << "" << "+" << endl << setfill(' ');

    return 0;
}

// Function Definitions
/**
 * generateArray: Fills a 20x20 array with random integers from 1 to 20
 * @param int array[][20] - The 2D array to fill with random values
 */
void generateArray(int array[][20])
{
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            array[i][j] = rand() % 20 + 1;
}

/**
 * displayArray: Displays a 20x20 array in a formatted table
 * @param int array[][20] - The 2D array to display
 */
void displayArray(int array[][20])
{
    for(int i = 0; i < 20; i++)
        cout << "+====";
    cout << "+" << endl;

    for(int i = 0; i < 20; i++)
    {
        cout << "| ";
        for(int j = 0; j < 20; j++)
            cout << setw(2) << array[i][j] << " | ";
        cout << endl;
        if(i != 19)
        {
            for(int j = 0; j < 20; j++)
                cout << "+----";
            cout << "+" << endl;
        }
    }

    for(int i = 0; i < 20; i++)
        cout << "+====";
    cout << "+" << endl;
}

/**
 * findPeak: Locates all minimum and maximum peaks in a 20x20 array
 * @param int array[][20] - The 2D array to search for peaks
 * @param int minimum[][2] - Array to store coordinates of minimum peaks
 * @param int maximum[][2] - Array to store coordinates of maximum peaks
 */
void findPeak(int array[][20], int minimum[][2], int maximum[][2])
{
    int nearRow[8] = {-1 , -1, -1, 0, 0, 1, 1, 1};
    int nearCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int minCount = 0, maxCount = 0, neighbors = 0;
    int minIndex = 0, maxIndex = 0;

    // Traverse 2-D array
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
        {
            // Initialize the counters to 0
            minCount = 0;
            maxCount = 0;
            neighbors = 0;

            // Check through the near arrays
            for(int k = 0; k < 8; k++)
            {
                int checkRow = i + nearRow[k];
                int checkCol = j + nearCol[k];

                if(checkRow >= 0 && checkRow < 20 && checkCol >= 0 && checkCol < 20)
                {
                    neighbors++;
                    if(array[checkRow][checkCol] > array[i][j])
                        minCount++;
                    else if(array[checkRow][checkCol] < array[i][j])
                        maxCount++;
                }
            }
            if(minCount == neighbors && minIndex < 20)
            {
                minimum[minIndex][0] = i;
                minimum[minIndex][1] = j;
                minIndex++;
            }
            else if(maxCount == neighbors && maxIndex < 20)
            {
                maximum[maxIndex][0] = i;
                maximum[maxIndex][1] = j;
                maxIndex++;
            }
        }
}