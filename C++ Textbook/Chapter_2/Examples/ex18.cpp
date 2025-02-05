// Example 2-18: Read Strings and Numeric Data in one line
#include <iostream>

using namespace std;

int main()
{
    // Variables
    string firstName = "";
    string lastName = "";
    int age = 0;

    while(true)
    {
        cout << "Enter your name and age: ";
        cin >> firstName >> lastName >> age;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Enter 'first name' 'last name' 'age'." << endl;
        } else
        {
            break;
        }
    }

    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << endl;
    return 0;
}