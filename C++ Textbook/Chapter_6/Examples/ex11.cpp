// Example 6-11: Triangle of Stars
#include <iostream>

using namespace std;

// ***Function Prototypes***
void printStars(int blanks, int starsInLine);

int main()
{
    // Variables
    int noOfLines = 0;      // var to store the number of lines
    int counter = 0;        // for loop control variable
    int noOfBlanks = 0;     // var to store the number of blanks

    cout << "Enter the number of star lines (1 to 20) to be printed: ";
    cin >> noOfLines;

    while(noOfLines < 0 || noOfLines > 20)
    {
        cout << "Enter the number of star lines (1 to 20) to be printed: ";
        cin >> noOfLines;
    }

    cout << endl << endl;
    noOfBlanks = 30;

    for(counter = 1; counter <= noOfLines; counter++)
    {
        printStars(noOfBlanks, counter);
        noOfBlanks--;
    }

    return 0;
}

// ***Functions***
void printStars(int blanks, int starsInLine)
{
    int count = 0;
    // Print the number of blanks before the stars in a line
    for(count = 1; count <= blanks; count++)
        cout << ' ';
    // Print the number of stars with a blank between stars
    for(count = 1; count <= starsInLine; count++)
        cout << " *";
    cout << endl;
}