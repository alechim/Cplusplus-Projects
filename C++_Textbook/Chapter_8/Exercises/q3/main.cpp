// Question 2: Find the Last Occurrence of Largest Element in an Array
/**
 * Use Cases:
 * - ./main.exe 
 * - ./main.exe (insert 10 integer values)
 */
#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
    // Variables
    const int ARRAY_SIZE = 10;
    int array[ARRAY_SIZE];
    int largestIndex = 0;

    // Prompt for Input
    if(argc > 1)
    {
        for(int i = 0; i < ARRAY_SIZE && i + 1 < argc; i++)
            array[i] = atoi(argv[i + 1]);

        // If we have fewer arguments than array size, fill the rest with zeros
        for(int i = argc - 1; i < ARRAY_SIZE; i++)
            array[i] = 0;
    }
    else
    {
        cout << "Please enter " << ARRAY_SIZE << " values for the array:" << endl;
        for(int i = 0; i < ARRAY_SIZE; i++)
            cin >> array[i];
    }

    // Find smallest value and index
    for(int i = 1; i < ARRAY_SIZE; i++)
    {
        if(array[i] > array[largestIndex])
            largestIndex = i;
    }

    // Display Results
    cout << "The largest value in the array is '" << array[largestIndex] << "' and the index is '" << largestIndex << "'." << endl;

    return 0;
}