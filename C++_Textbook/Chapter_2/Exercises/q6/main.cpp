// Question 6: Display a Short Message based on Input
#include <iostream>

using namespace std;

int main()
{
    // Variables
    string name = "";
    double studyHours = 0.0;

    // Prompt for Input
    while(true)
    {
        cout << "Please enter your name and the amount of hours of studying: ";
        cin >> name >> studyHours;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a string and double value. 'name' 'hours'." << endl;
        } else
        {
            break;
        }
    }

    // Display Message
    cout << "Hello, " << name << "! On Saturday, you need to study " << studyHours << " hours for the exam." << endl;

    return 0;
}