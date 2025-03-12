/**
 * Alec Him, 2001543593, CS135 1009, Lab 7
 * Description: Generate a Triangle from a file
 * Input: ./a.out < triangle.txt OR Get-Content triangle.txt | ./a.out
 * Output: Generated Triangle
 */
#include <iostream>

using namespace std;

// Function Prototypes
void triangle(char, int);

int main()
{
    // Variables
    char s = ' ';
    int dimension = 0;
    int count = 0;

    cin >> s;
    cin >> dimension;

    while(cin)
    {
        if(count == 0)
        {
            cout << "Shape: " << s << endl;
            cout << "Dimension: " << dimension << endl;
        }
        while(count <= dimension)
        {
            triangle(s, count);
            count++;
        }

        cin >> s;
        cin >> dimension;
        count = 0;
        cout << endl;
    }

    return 0;
}

// Function Definitions
void triangle(char s, int characterCount)
{
    for(int i = 0; i <= characterCount; i++)
        cout << s;
    cout << endl;
}