// Question 3: Integer Values to ASCII
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int input = 0;

    // Prompt for Input
    do
    {
        cout << "Please enter a positive integer value: ";
        cin >> input;
        
        if(cin.fail() || input < 0 || input > 35)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a an integer value between 0 and 35." << endl;
        } else
            break;
    } while(true);
    
    cout << "The ASCII character for the value " << input << " is ";
    if(input > 9)
    {
        cout << static_cast<char>(input + 55);
    } else
        cout << input;
    cout << ".";

    return 0;
}