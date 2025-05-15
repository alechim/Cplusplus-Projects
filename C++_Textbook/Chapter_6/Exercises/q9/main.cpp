// Question 9: Reverse Digit
#include <iostream>

using namespace std;

// ***Function Prototypes***
int reverseDigit(int num);

int main()
{
    // Variables
    int num = 0;

    // Prompt for Input
    do
    {
        cout << "Enter an integer value: ";
        cin >> num;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else
            break;
    } while(true);
    
    // Display Results
    cout << "The number " << num << " reversed is " << (num < 0 ? "-" : "") << reverseDigit(num) << ".\n";

    return 0;
}

// ***Functions***
int reverseDigit(int num)
{
    int reverse = 0;
    num = abs(num);
    while(num > 0)
    {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return reverse;
}