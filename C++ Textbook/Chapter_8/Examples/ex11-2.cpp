// Example 8-11_2: Two-Dimensional Array Processing Functions
#include <iostream>
#include <iomanip>

using namespace std;

// Global Constant Variables
const int ROWS = 4;
const int COLS = 4;

// Function Prototypes
void initializeArray(int[][COLS]);
void printArray(int[][COLS]);
void fillArray(int[][COLS]);
void sumByRow(int[][COLS]);
void sumByColumn(int[][COLS]);
void largestElementByRow(int [][COLS]);
void largestElementByColumn(int [][COLS]);

int main()
{
    int matrix[ROWS][COLS];
    
    cout << "Initializing the array with zeros:" << endl;
    initializeArray(matrix);
    printArray(matrix);
    cout << endl;
    
    cout << "Enter " << ROWS * COLS << " integers to fill the 4x4 array:" << endl;
    fillArray(matrix);
    
    cout << "\nThe array you entered is:" << endl;
    printArray(matrix);
    cout << endl;
    
    cout << "Sum of each row:" << endl;
    sumByRow(matrix);
    cout << endl;
    
    cout << "Sum of each column:" << endl;
    sumByColumn(matrix);
    cout << endl;
    
    cout << "Largest element in each row:" << endl;
    largestElementByRow(matrix);
    cout << endl;
    
    cout << "Largest element in each column:" << endl;
    largestElementByColumn(matrix);

    return 0;
}

// Function Definitions
void initializeArray(int matrix[][COLS])
{
    for(int row = 0; row < ROWS; row++)
        for(int col = 0; col < COLS; col++)
            matrix[row][col] = 0;
}

void printArray(int matrix[][COLS])
{
    for(int row = 0; row < ROWS; row++)
    {    
        for(int col = 0; col < COLS; col++)
            cout << setw(5) << matrix[row][col] << " ";
        cout << endl;
    }    
}

void fillArray(int matrix[][COLS])
{
    for(int row = 0; row < ROWS; row++)
        for(int col = 0; col < COLS; col++)
            cin >> matrix[row][col];
}

void sumByRow(int matrix[][COLS])
{
    int sum = 0;
    for(int row = 0; row < ROWS; row++)
    {
        sum = 0;

        for(int col = 0; col < COLS; col++)
            sum = sum + matrix[row][col];
        
        cout << "Sum of row " << row + 1 << " = " << sum << endl;
    }
}

void sumByColumn(int matrix[][COLS])
{
    int sum = 0;
    for(int col = 0; col < COLS; col++)
    {
        sum = 0;

        for(int row = 0; row < ROWS; row++)
            sum = sum + matrix[row][col];
        
        cout << "Sum of column " << col + 1 << " = " << sum << endl;
    }
}

void largestElementByRow(int matrix[][COLS])
{
    int largest = 0;

    for(int row = 0; row < ROWS; row++)
    {
        largest = matrix[row][0];

        for(int col = 1; col < COLS; col++)
            if(matrix[row][col] > largest)
                largest = matrix[row][col];

        cout << "The largest element in row " << row + 1 << " = " << largest << endl;
    }
}

void largestElementByColumn(int matrix[][COLS])
{
    int largest = 0;

    for(int col = 0; col < COLS; col++)
    {
        largest = matrix[0][col];

        for(int row = 1; row < ROWS; row++)
            if(matrix[row][col] > largest)
                largest = matrix[row][col];

        cout << "The largest element in column " << col + 1 << " = " << largest << endl;
    }
}