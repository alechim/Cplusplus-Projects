// Question 11: Sum of ASCII values from a string
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int sum = 0;
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

    // Convert chars of string to integer and store in sum
    for(int i = 0; i < input.length(); i++)
        sum += static_cast<int>(input[i]);

    // Display Results
    cout << "The sum of the string '" << input << "' is " << sum << "." << endl;

    return 0;
}