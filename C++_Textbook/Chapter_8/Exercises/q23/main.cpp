// Question 23: Magic Square 3x3 Array
#include <iostream>
#include <ctime>

using namespace std;

// Function Prototypes
void generateArray(int[][3]);
bool checkArray(int[][3]);

int main()
{
    int magicArray[3][3];
    int count = 0;
    int limit = 1'000'000;

    // Seed the random variable
    srand(time(0));

    cout << "Generating " << limit << " arrays..." << endl;
    for(int i = 0; i < limit; i++)
    {   
        generateArray(magicArray);
        if(checkArray(magicArray))  
            count++;
    }
    cout << "Done!" << endl;
    cout << "The Array is a Magic Square " << count << " times out of " << limit << "." << endl;

    return 0;
}

// Function Definitions
/**
 * generateArray: Fills a 3x3 array with values 1-9 in random positions
 * @param int array[][3] - The 2D array to fill with random values
 */
void generateArray(int array[][3])
{
    // Initialize 2-D array to 0
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            array[i][j] = 0;

    // Fill 2-D array with values 1-9 in random positions
    int num = 1;
    while(num < 10)
    {
        int row = rand() % 3;
        int col = rand() % 3;
        if(array[row][col] == 0)
        {
            array[row][col] = num;
            num++;
        }
    }
}

/**
 * checkArray: Checks if a 3x3 array is a magic square
 * @param int array[][3] - The 2D array to check
 * @return bool - If the array is a magic square, return true. Otherwise, return false
 */
bool checkArray(int array[][3])
{
    int magicNumber = 0, sum = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            sum += array[i][j];
    magicNumber = sum / 3;

    // Calculate Rows = Magic Number
    for(int i = 0; i < 3; i++)
    {
        sum = 0;
        for(int j = 0; j < 3; j++)
            sum += array[i][j];
        if(sum != magicNumber)
            return false;
    }

    // Calculate Cols = Magic Number
    for(int j = 0; j < 3; j++)
    {
        sum = 0;
        for(int i = 0; i < 3; i++)
            sum += array[i][j];
        if(sum != magicNumber)
            return false;
    }

    // Calculate Diagonals
    if(magicNumber != (array[0][0] + array[1][1] + array[2][2]) || magicNumber != (array[0][2] + array[1][1] + array[2][0]))
        return false;

    return true;
}