// Example 6-6: Palindrome
#include <iostream>
#include <string>

using namespace std;

// ***Function Prototype***
bool isPalindrome(string str);

int main()
{
    // Variables
    string input = "";

    cout << "Enter a string: ";
    getline(cin, input);

    if(isPalindrome(input))
        cout << "The string \"" << input << "\" is a palindrome." << endl;
    else
        cout << "The string \"" << input << "\" is not a palindrome." << endl;

    return 0;
}

// ***Function***
bool isPalindrome(string str)
{
    int length = str.length();

    for(int i = 0; i < length / 2; i++)
        if(str[i] != str[length - 1 - i])
            return false;
    
    return true;
}