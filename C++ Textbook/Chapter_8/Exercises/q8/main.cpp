// Question 8: 1-D and 2-D Array Manipulation
/**
 * Use Cases:
 * - ./main.exe 
 * - ./main.exe (insert 20 integer values)
 */
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void inputArray(int[]);
void doubleArray(int[], int[]);
void copyAlphaBeta(int[][4], int[], int[]);
void printArray(int[]);
void printArray(int[][4]);

int main(int argc, const char* argv[])
{
    // Variables
    int alpha[20];
    int beta[20];
    int matrix[10][4];

    // Alpha Array Manipulation
    cout << "1-D Alpha Array Manipulation..." << endl;
    if(argc > 1)
    {
        for(int i = 0; i < 20 && i + 1 < argc; i++)
            alpha[i] = atoi(argv[i + 1]);

        // If we have fewer arguments than array size, fill the rest with zeros
        for(int i = argc - 1; i < 20; i++)
            alpha[i] = 0;
    } else
        inputArray(alpha);
    printArray(alpha);

    // Beta Array Manipulation
    cout << setw(16) << setfill('-') << "" << endl << setfill(' ');
    cout << "1-D Beta Array Manipulation..." << endl;
    doubleArray(alpha, beta);
    printArray(beta);

    // Matrix Array Manipulation
    cout << setw(16) << setfill('-') << "" << endl << setfill(' ');
    cout << "2-D Matrix Manipulation..." << endl;
    copyAlphaBeta(matrix, alpha, beta);
    printArray(matrix);

    return 0;
}

// Function Definitions
/**
 * inputArray: Prompts the user to input 20 numbers and stores into passed array
 * @param int alpha[] - The array to store the value
 */
void inputArray(int alpha[])
{
    cout << "Please enter 20 numbers to store in the alpha array:" << endl;
    for(int i = 0; i < 20; i++)
    {
        do
        {
            cin >> alpha[i];
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter an integer value." << endl;
            } else
                break;
        } while(true);
    }
}

/**
 * doubleArray: Initializes the elements of beta to two times the corresponding elements in alpha
 * @param int alpha[] - The array to be doubled and stored into beta
 * @param int beta[] - The array to be intialized
 */
void doubleArray(int alpha[], int beta[])
{
    for(int i = 0; i < 20; i++)
        beta[i] = alpha[i] * 2;
}

/**
 * copyAlphaBeta: Stores alpha into the first five rows of matrix and beta into the last five rows of matrix
 * @param int matrix[][4] - The two-dimensional array to be initialized
 * @param int alpha[] - The array to be stored in the first five rows
 * @param int beta[] - The array to be stored in the last five rows
 */
void copyAlphaBeta(int matrix[][4], int alpha[], int beta[])
{
    for(int r = 0; r < 10; r++)
    {
        for(int c = 0; c < 4; c++)
        {
            if(r < 5)
                matrix[r][c] = alpha[r * 4 + c];
            else  
                matrix[r][c] = beta[(r * 4 + c) - 20];
        }
    }
}

/**
 * printArray: prints any one-dimensional array of type int
 * @param int array[] - The array to be printed
 */
void printArray(int array[])
{
    for(int i = 0; i < 20; i++)
    {
        if(i == 15)
            cout << "|" << endl;
        cout << "| " << left << setw(6) << array[i] << " ";
    }
    cout << "|" << endl;
}

/**
 * printArray: prints any two-dimensional array of type int
 * @param int array[] - The array to be printed
 */
void printArray(int array[][4])
{
    for(int r = 0; r < 10; r++)
    {
        for(int c = 0; c < 4; c++)
            cout << "| " << left << setw(6) << array[r][c] << " ";
        cout << "|" << endl;
    }
}