// Example 8-11: Two-Dimension Arrays as Parameters to Functions
#include <iostream>
#include <iomanip>

using namespace std;

// Global Constant Variables
const int ROWS = 6;
const int COLS = 5;

// Function Prototypes
void printMatrix(int [][COLS], int);
void sumRows(int [][COLS], int);
void largestInRows(int [][COLS], int);

int main()
{
    int board[ROWS][COLS] = 
    {
        {17, 8, 24, 10, 28},
        {9, 20, 16, 55, 90},
        {25, 45, 35, 8, 78},
        {5, 0, 96, 45, 38},
        {76, 30, 8, 14, 28},
        {9, 60, 55, 62, 10}
    };

    printMatrix(board, ROWS);
    cout << endl;

    sumRows(board, ROWS);
    cout << endl;

    largestInRows(board, ROWS);

    return 0;
}

// Function Definitions
void printMatrix(int matrix[][COLS], int noOfRows)
{
    for(int row = 0; row < noOfRows; row++)
    {
        for(int col = 0; col < COLS; col++)
            cout << setw(5) << matrix[row][col] << " ";
        cout << endl;
    }
}

void sumRows(int matrix[][COLS], int noOfRows)
{
    int sum = 0;

    for(int row = 0; row < noOfRows; row++)
    {
        sum = 0;

        for(int col = 0; col < COLS; col++)
            sum = sum + matrix[row][col];

        cout << "Sum of row " << row + 1 << " = " << sum << endl;
    }
}

void largestInRows(int matrix[][COLS], int noOfRows)
{
    int largest = 0;

    for(int row = 0; row < noOfRows; row++)
    {
        largest = matrix[row][0];

        for(int col = 1; col < COLS; col++)
            if(largest < matrix[row][col])
                largest = matrix[row][col];
        
        cout << "The largest element of row " << row + 1 << " = " << largest << endl;
    }
}