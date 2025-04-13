// Question 14: Selection Sort Algorithm + Two Sum
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void selectionSort(int[], int);
void twoSum(int array[], int length);

int main()
{
    // Variables
    const int SIZE = 50;
    int array[SIZE];
    char choice = ' ';

    // Prompt for choice
    do
    {
        cout << "Would you like to autofill array? [y/n]: ";
        cin >> choice;
        if(cin.fail() || (choice != 'y' && choice != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter either 'y' or 'n'." << endl;
        } else
            break;
    } while(true);
    
    // Fill Array based on prior choice
    if(choice == 'y')
        for(int i = 0; i < SIZE; i++)
            array[i] = i + 1;
    else
        // Prompt for Array Input
        do
        {
            cout << "Please enter 50 integer values: ";
            for(int i = 0; i < SIZE; i++)
                cin >> array[i];
            
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter 50 integer values." << endl;
            } else
                break;
        } while(true);
    
    // Perform Selection Sort
    selectionSort(array, SIZE);

    // Find Sum Pairs
    twoSum(array, SIZE);

    return 0;
}

// Function Definitions
/**
 * selectionSort: Sorts an array in ascending order using the selection sort algorithm
 * @param int array[] - The array to be sorted
 * @param int length - The length of the array
 */
void selectionSort(int array[], int length)
{   
    int smallestIndex = 0;
    for(int i = 0; i < length - 1; i++)
    {
        smallestIndex = i;
        for(int j = i + 1; j < length; j++)
            if(array[j] < array[smallestIndex])
                smallestIndex = j;
        swap(array[smallestIndex], array[i]);
    }
}

/**
 * twoSum: Finds all pairs of numbers in the array that sum to another number in the array
 * @param int array[] - The sorted array to search for sum pairs
 * @param int length - The length of the array
 */
void twoSum(int array[], int length)
{
    int count = 0;
    const int COLUMNS = 6;      // Number of results per row
    const int RANGE = 1000;     // Assumes numbers in array range 0-1000
    bool exists[RANGE] = {false};
    
    // Initializes boolean array to determine numbers that exist in array
    for(int i = 0; i < length; i++)
        exists[array[i]] = true;

    cout << "Finding Two Sum Pairs...\n";
    cout << "=============================================\n";
    
    for(int i = 0; i < length; i++)
        for(int j = i; j < length - i; j++)
        {
            int sum = array[i] + array[j];
            if(sum <= RANGE && exists[sum])
            {
                cout << setw(3) << array[i] << " + " << setw(3) << array[j] << " = " << setw(3) << sum;
                count++;

                // Determine whether to end the line or add spacing
                if(count % COLUMNS == 0)
                    cout << endl;
                else
                    cout << "    ";  // Add space between entries
            }
        }
    
    // Ensure we end with a newline
    if(count % COLUMNS != 0)
        cout << endl;

    cout << "=============================================\n";
    if(count == 0)
        cout << "No Pairs Found...\n";
    else
        cout << "Total Pairs Found: " << count << endl;
}