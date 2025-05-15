// Example 8-8: Sequential Search of an Integer Array
#include <iostream>

using namespace std;

// Global Constant Variables
const int ARRAY_SIZE = 10;

// Function Prototypes
int seqSearch(const int list[], int listLength, int searchItem);

int main()
{
    // Variables
    int intList[ARRAY_SIZE];
    int number = 0;

    cout << "Line 9: Enter " << ARRAY_SIZE << " integers." << endl;
    
    for(int index = 0; index < ARRAY_SIZE; index++)
        cin >> intList[index];

    cout << endl;
    
    cout << "Line 13: Enter the number to be searched: ";
    cin >> number;
    cout << endl;

    int pos = seqSearch(intList, ARRAY_SIZE, number);

    if(pos != -1)
        cout << "Line 18: " << number << " is found at index " << pos << endl;
    else
        cout << "Line 20: " << number << " is not in the list." << endl;

    return 0;
}

// Function Definition
int seqSearch(const int list[], int listLength, int searchItem)
{
    int loc = 0;
    bool found = false;

    while(loc < listLength && !found)
        if(list[loc] == searchItem)
            found = true;
        else
            loc++;

    if(found)
        return loc;
    else
        return -1;
}