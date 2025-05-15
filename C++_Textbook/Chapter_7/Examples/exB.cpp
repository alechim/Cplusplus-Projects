// Example 7-B: Pig Latin Translator
#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
bool isVowel(char ch);
string rotate(string pStr);
string pigLatinString(string pStr);

int main()
{
    // Variables
    string str = "";

    cout << "Enter a string: ";
    cin >> str;
    cout << endl;

    cout << "The pig latin form of " << str << " is: " << pigLatinString(str) << endl;

    return 0;
}

// Function Definitions
/**
 * isVowel: returns true if a vowel is found
 * @param char ch - passed character
 * @return bool
 */
bool isVowel(char ch)
{
    switch(ch)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
        case 'Y':
        case 'y':
            return true;
        default:
            return false;
    }
}

/**
 * rotate: Removes the first character of the string and places it at the end
 * @param string pStr - parameter string
 * @return string
 */
string rotate(string pStr)
{
    string::size_type len = pStr.length();
    string rStr = "";
    rStr = pStr.substr(1, len - 1) + pStr[0];

    return rStr;
}

/**
 * pigLatinString: Converts the string to pig latin form
 * @param string pStr - parameter string
 * @return string
 */
string pigLatinString(string pStr)
{
    // Variables
    string::size_type len;
    bool foundVowel;
    string::size_type counter;

    if(isVowel(pStr[0]))
        pStr = pStr + "-way";
    else
    {
        pStr = pStr + '-';
        pStr = rotate(pStr);

        len = pStr.length();
        foundVowel = false;

        for(counter = 1; counter < len - 1; counter++)
        {
            if(isVowel(pStr[0]))
            {
                foundVowel = true;
                break;
            } else
                pStr = rotate(pStr);
        }

        if(!foundVowel)
            pStr = pStr.substr(1, len) + "-way";
        else
            pStr = pStr + "ay";
    }

    return pStr;
}