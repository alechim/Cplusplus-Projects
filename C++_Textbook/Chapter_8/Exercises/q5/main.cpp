// Question 5: Uppercase an Entire Character Array
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // Variables
    char input[100];

    // Prompt for Input
    do
    {
        cout << "Enter a string: ";
        cin.getline(input, 100);
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid Input! Please enter a valid string." << endl;
        } else
            break;
    } while(true);
    
    // Convert C-String to all Uppercase
    for(size_t i = 0; i < strlen(input); i++)
        input[i] = toupper(input[i]);

    // Display Result
    cout << "The string in uppercase is: " << input << endl;

    return 0;
}