// Question 2: Sort Numbers from Least to Greatest
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int numArray[3];
    int tmp = 0;

    // Prompt for Input
    do
    {
        cout << "Please enter 3 integer values: ";
        cin >> numArray[0] >> numArray[1] >> numArray[2];
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 3 integer values." << endl;
        } else
            break;
    } while(true);

    // Sort Array
    if(numArray[1] > numArray[2])
        swap(numArray[1], numArray[2]);
    if(numArray[0] > numArray[1])
        swap(numArray[0], numArray[1]);
    if(numArray[1] > numArray[2])
        swap(numArray[1], numArray[2]);

    // Display Results
    cout << "The sorted numbers in ascending order is: ";
    for(int i = 0; i < 3; i++)
        cout << numArray[i] << " ";
    cout << endl;

    return 0;
}