// Question 4: Message to Phone Number
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    // Variables
    string input = "";
    string message = "";
    int digit[7];
    int num = 0;

    cout << "Enter a telephone number expressed in letters: ";
    getline(cin, input);
    cout << endl;

    // Input Validation
    for (int i = 0; i < input.size(); i++) 
    {
        if (isalpha(input[i])) {
            message += input[i];
        } else if (input[i] != ' ') { // Allow spaces but no other characters
            cout << "Invalid Input, message must be composed of letters. Program Terminating..." << endl;
            return 1;
        }
    }

    cout << "\nThe telephone number is: ";
    // Only translate the first 7 letters to digits
    for(int i = 0; i < 7 && i < message.size(); i++)
    {
        // Convert lowercase to uppercase if needed
        message[i] = toupper(message[i]);
        num = static_cast<int>(message[i]) - static_cast<int>('A');

        // Calculate the corresponding digit
        digit[i] = (num / 3) + 2;
        if((num / 3 == 6) || ((num / 3 == 7) && (num % 3 == 0)))
            digit[i] = digit[i] - 1;
        if(digit[i] > 9)
            digit[i] = 9;
        
        if(i == 3)
            cout << "-";
        cout << digit[i];
    }
    cout << endl;

    return 0;
}