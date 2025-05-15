// Question 3: Detect # of Vowels
/**
 * Use Case:
 * - ./main <input>
 * - ./main
 *   > Prompt <input>
 */
#include <iostream>
#include <string>

using namespace std;

// ***Function Prototypes***
bool isVowel(char c);

int main(int argc, char* argv[])
{
    // Variables
    string input = "";
    int vowelCount = 0;

    // Prompt for Input
    if(argc > 1)
    {    
        input = argv[1];
    }
    else{
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

    // Vowel Check
    for(size_t i = 0; i < input.length(); i++)
        if(isVowel(input[i]))
            vowelCount++;

    // Display Results
    cout << "The string \"" << input << "\" has " << vowelCount << (vowelCount == 1 ? " vowel." : " vowels.") << endl;

    return 0;
}

// ***Function***
bool isVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}