// Example 8-9: Selection Sort
#include <iostream>

using namespace std;

// Function Prototype
void selectionSort(int list[], int length);

int main()
{
    // Variables
    int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16};
    int i = 0;

    // Run selectionSort
    selectionSort(list, 10);

    // Display Results
    cout << "After sorting, the list elements are: " << endl;
    for(i = 0; i < 10; i++)
        cout << list[i] << " ";
    cout << endl;

    return 0;
}

// Function Definition
void selectionSort(int list[], int length)
{
    // Variables
    int index = 0;
    int smallestIndex = 0;
    int location = 0;
    int temp = 0;

    for(index = 00; index < length - 1; index++)
    {
        smallestIndex = index;

        for(location = index + 1; location < length; location++)
            if(list[location] < list[smallestIndex])
                smallestIndex = location;
        
        temp = list[smallestIndex];
        list[smallestIndex] = list[index];
        list[index] = temp;
    }
}