// Question 3: Refactored Telephone Digits
/**
 * - Allow Uppercase and Lowercase Letters
 * - Output Error Message on Invalid Input
 */
#include <iostream>

using namespace std;

int main()
{
    // Variables
    char letter = ' ';
    int digit = 0;
    int num = 0;

    cout << "Program to convert uppercase letters to their corresponding telephone digits." << endl;
    cout << "To stop the program enter #." << endl;

    cout << "Enter a letter [a-z, A-Z]: ";
    cin >> letter;
    cout << endl;

    // Uppercase - 'A': 0 - 25
    // Lowercase - 'A': 32 - 57
    while (letter != '#')
    {
        cout << "Letter: " << letter;
        cout << ". Corresponding telephone digit: ";

        num = static_cast<int>(letter) - static_cast<int>('A');

        if(0 <= num && num < 26)
        {
            digit = (num / 3) + 2;
            if((num / 3 == 6) || (num / 3 == 7) && (num % 3 == 0))
                digit = digit - 1;
            if(digit > 9)
                digit = 9;
            cout << digit << endl;
        } else if(32 <= num && num < 58)
        {
            num -= 32;
            digit = (num / 3) + 2;
            if((num / 3 == 6) || (num / 3 == 7) && (num % 3 == 0))
                digit = digit - 1;
            if(digit > 9)
                digit = 9;
            cout << digit << endl;
        } else
            cout << "Invalid Input! Please enter a char value [a-z, A-Z]." << endl;

        cout << "\nEnter another uppercase letter to find its corresponding telephone digit." << endl;
        cout << "To stop the program enter #." << endl;

        cout << "Enter a letter: ";
        cin >> letter;
        cout << endl;
    }

    return 0;
}