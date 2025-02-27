// Question 23: Count lowercase vowels & Makefile
#include <iostream>
#include <string>

using namespace std;

// ***Function Prototypes***
void isVowel(char c, int& count);

int main()
{
    // Variables
    int vowelCount = 0;
    string input = "";
    
    // Prompt for Input
    do
    {
        cout << "Enter a string: ";
        getline(cin, input);
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a string value." << endl;
        } else
            break;
    } while(true);
    
    for(size_t i = 0; i < input.length(); i++)
        isVowel(input[i], vowelCount);

    cout << "The number of lowercase vowels in the string \"" << input << "\" is " << vowelCount << ".\n";

    return 0;
}

// ***Functions***
void isVowel(char c, int& count)
{   
    switch(c)
    {    
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            count++;
            break;
        default:
            break;
    }
}