#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function Prototypes
void rowSumCalculator(int myArray[][10], int rowCount, int colCount);
void openFile(ifstream& infile, string prompt);

int main()
{
    // Variables
    ifstream iFile;
    string inFile = "wksht19_data.txt";
    int array[7][10];
    int row = 7;
    int column = 10;

    openFile(iFile, inFile);

    if(iFile.is_open())
    {
        while(!iFile.eof())
            for(int r = 0; r < row; r++)
                for(int c = 0; c < column; c++)
                    iFile >> array[r][c];
    }

    rowSumCalculator(array, row, column);

    return 0;
}

// Function Definitions
void openFile(ifstream& iFile, string fileName)
{
    do
    {
        cout << "Enter file to process: ";
        cin >> fileName;

        iFile.open(fileName);

        if (!iFile.is_open())
            cout << "Error - \"" << fileName << "\" Did Not Open" << endl;

    } while(!iFile.is_open());
}

void rowSumCalculator(int array[][10], int row, int column)
{
    int sum = 0;

    for (int r = 0; r < row; r++){
        for (int c = 0; c < column; c++)
        {
            cout << setw(4) << array[r][c] << " ";
            sum += array[r][c];
        }

        cout << " = " << setw(4) << sum << endl;
        sum = 0;
    }
}
