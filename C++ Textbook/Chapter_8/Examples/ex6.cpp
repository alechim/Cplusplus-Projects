// Example 8-6: Array Processing Functions

#include <iostream>

using namespace std;

// Function Prototypes
void initializeArray(int[], int);
void fillArray(int[], int);
void printArray(const int[], int);
int sumArray(const int[], int);
int indexLargestElement(const int[], int);
void copyArray(int[], int, int[], int, int);

int main()
{
    // Variables
    const int SIZE1 = 5;
    const int SIZE2 = 8;
    int array1[SIZE1];
    int array2[SIZE2];
    
    // Testing initializeArray
    cout << "Testing initializeArray function:" << endl;
    initializeArray(array1, SIZE1);
    cout << "Array1 after initialization: ";
    printArray(array1, SIZE1);
    cout << endl << endl;
    
    // Testing fillArray
    cout << "Testing fillArray function:" << endl;
    cout << "Please enter " << SIZE1 << " integers: ";
    fillArray(array1, SIZE1);
    cout << "Array1 after filling with data: ";
    printArray(array1, SIZE1);
    cout << endl << endl;
    
    // Testing sumArray
    cout << "Testing sumArray function:" << endl;
    int sum = sumArray(array1, SIZE1);
    cout << "Sum of elements in Array1: " << sum << endl << endl;
    
    // Testing indexLargestElement
    cout << "Testing indexLargestElement function:" << endl;
    int maxIndex = indexLargestElement(array1, SIZE1);
    cout << "Index of largest element in Array1: " << maxIndex << endl;
    cout << "Value of largest element: " << array1[maxIndex] << endl << endl;
    
    // Testing copyArray
    cout << "Testing copyArray function:" << endl;
    initializeArray(array2, SIZE2);
    cout << "Array2 before copying: ";
    printArray(array2, SIZE2);
    cout << endl;
    
    // Copy from array1 starting at index 1 to array2 starting at index 2, copy 3 elements
    copyArray(array1, 1, array2, 2, 3);
    cout << "Array2 after copying 3 elements from Array1: ";
    printArray(array2, SIZE2);
    cout << endl << endl;
    
    // Testing all functions together with another example
    cout << "Testing all functions with a new array:" << endl;
    const int SIZE3 = 10;
    int array3[SIZE3];
    
    initializeArray(array3, SIZE3);
    cout << "Array3 after initialization: ";
    printArray(array3, SIZE3);
    cout << endl;
    
    // Fill only first half with user input
    cout << "Please enter " << SIZE3 / 2 << " integers for the first half: ";
    fillArray(array3, SIZE3 / 2);
    
    // Copy first half into second half
    copyArray(array3, 0, array3, SIZE3 / 2, SIZE3 / 2);
    
    cout << "Array3 after filling first half and copying to second half: ";
    printArray(array3, SIZE3);
    cout << endl;
    
    cout << "Sum of Array3: " << sumArray(array3, SIZE3) << endl;
    int largestIndex = indexLargestElement(array3, SIZE3);
    cout << "Largest element in Array3 is at index " << largestIndex;
    cout << " with value " << array3[largestIndex] << endl;
    
    return 0;
}

// Function Definitions
/**
 * initializeArray: Initialize an int array to 0
 * @param int list[] - The array to be initialized
 * @param int listSize - Specifies the number of elements to be initialized
 */
void initializeArray(int list[], int listSize)
{
    for(int index = 0; index < listSize; index++)
        list[index] = 0;
}

/**
 * fillArray: Read and store the data into an int array
 * @param int list[] - The array to have data stored in
 * @param int listSize - Specifies the number of elements to be read
 */
void fillArray(int list[], int listSize)
{
    for(int index = 0; index < listSize; index++)
        cin >> list[index];
}

/**
 * printArray: Print elements of an int array
 * @param const int list[] - The array to be printed
 * @param int listSize - Specifies the number of elements to be printed
 */
void printArray(const int list[], int listSize)
{
    for(int index = 0; index < listSize; index++)
        cout << list[index] << " ";
}

/**
 * sumArray: Find and return the sum ofe elements of an int array
 * @param const int list[] - The array to find the sum from
 * @param int listSize - Specifies the number of elements to be added
 */
int sumArray(const int list[], int listSize)
{
    int sum = 0;
    for(int index = 0; index < listSize; index++)
        sum = sum + list[index];
    
    return sum;
}

/**
 * indexLargestElement: Find and return the index of the first largest element in an int array
 * @param const int list[] - The array to be searched and returned from
 * @param int listSize - Specifies the number of elements in the array
 */
int indexLargestElement(const int list[], int listSize)
{   
    int maxIndex = 0;

    for(int index = 1; index < listSize; index++)
        if(list[maxIndex] < list[index])
            maxIndex = index;
    
    return maxIndex;
}

/**
 * copyArray: Copy some or all of the elements of one array into another array
 * @param int list1[] - The first int array to be copied from
 * @param int src - The starting position for the first array
 * @param int list2[] - The second int array to copy from the first array
 * @param int tar - The starting position for the second array
 * @param int numOfElements - Specifies the number of elements in both arrays
 */
void copyArray(int list1[], int src, int list2[], int tar, int numOfElements)
{
    for(int index = src; index < src + numOfElements; index++)
    {
        list2[tar] = list1[index];
        tar++;
    }
}