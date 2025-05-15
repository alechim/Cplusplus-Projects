// Question 4: Remove Vowels from the String
#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
bool isVowel(char);
string substr(string);

int main()
{
    // Variables
    string str = "";

    // Prompt for Input
    cout << "Enter a string: ";
    cin >> str;

    // Display Results
    cout << "The string \"" << str << "\" with all vowels removed is \"" << substr(str) << "\"\n";

    return 0;
}

// Function Defintions
/**
 * isVowel: returns true if a vowel is found
 * @param char ch - passed character
 * @return bool
 */
bool isVowel(char c)
{
    switch(tolower(c))
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return true;
    }

    return false;
}

/**
 * substr: Loops through the string to remove any vowels found
 * @param string str - passed string
 * @return string
 */
string substr(string str)
{
    for(size_t i = 0; i < str.length(); i++)
        if(isVowel(str[i]))
            str.erase(i, 1);
    return str;
}