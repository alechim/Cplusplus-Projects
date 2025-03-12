#include <iostream>

using namespace std;

// Function Prototypes
int larger(int, int);
string larger (string, string);

int main()
{
    // Variables
    char c;   
    int num1 = 0;
    int num2 = 0;
    int largeNum = 0;
    string str1 = "";
    string str2 = "";
    string largeStr = "";

    // Prompt Input
    cout << "Please select i/I/S/s: ";
    cin >> c;

    if (c == 'i' || c == 'I')
    {
        cout << "Please enter two integers: ";
        cin >> num1 >> num2;

        largeNum = larger(num1, num2);

        cout << "Largest Integer: " << largeNum << endl;
    }

    if (c == 's' || c == 'S')
    {
        cout << "Please enter two strings: ";
        cin >> str1 >> str2;

        largeStr = larger(str1, str2);

        cout << "Largest String: " << largeStr << endl;
    }

    return 0;
}

// Function Definitions
int larger(int numOne, int numTwo)
{
    int large = 0;

    if(numOne > numTwo)
        large = numOne;
    else 
        large = numTwo;

    return large;
}

string larger (string strOne, string strTwo)
{
    string large = "";

    if (strOne > strTwo)
        large = strOne;
    else 
        large = strTwo;

    return large;
}
