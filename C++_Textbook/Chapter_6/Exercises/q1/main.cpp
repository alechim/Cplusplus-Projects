// Question 1: Refactored Palindrome & Make File
#include <iostream>
#include <string>

using namespace std;

// ***Function Prototype***
bool isPalindrome(string str);

int main(int argc, char* argv[])
{
    // Variables
    string input = "";

    // Prompt for Input
    if(argc > 1)
        input = argv[1];
    else
    {
        cout << "Enter a string: ";
        getline(cin, input);
    }

    // Input Validation
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(40, '\n');
        cout << "Invalid Input! Program Terminating..." << endl;
        return 1;
    }

    if(isPalindrome(input))
        cout << "The string \"" << input << "\" is a palindrome." << endl;
    else
        cout << "The string \"" << input << "\" is not a palindrome." << endl;

    return 0;
}

// ***Function***
// Refactor: Ignore cases (uppercase + lowercase)
bool isPalindrome(string str)
{
    for(size_t i = 0; i < str.length() / 2; i++)
        if(tolower(str[i]) != tolower(str[str.length() - 1 - i]))
            return false;
    
    return true;
}