#include <iostream>

using namespace std;

// Function Prototypes
void readChars(int, char data[25], int);
void printReverse(char data[25], int);

int main()
{
    // Variables
    int charCount = 0;
    char data[25] = {'a', '1', 'b', '2', 'c', '3', 'd', '4', 'e', '5', 'f', '6', 'g', '7', 'h', '8', 'i', '9', 'j', '1', 'k', '2', 'l', '3', 'm'};

    readChars(25, data, charCount);

    return 0;
}

// Function Definitions
void readChars(int max, char data[25], int count)
{
    cout << "How many chars: ";
    cin >> count;

    if(max < count)
        cout << "Error - Max Chars 25" << endl;
    else
    {
        for(int i = 0; i < count; i++)
            cout << data[i] << ' ';
        cout << endl;
    }

    printReverse(data, count);
}

void printReverse(char data[], int count)
{
    for(int i = count - 1; i >= 0; i--)
        cout << data[i] << " ";
    cout << endl;
}
