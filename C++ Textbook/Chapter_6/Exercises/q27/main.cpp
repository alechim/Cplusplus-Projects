// Question 27: 
#include <iostream>
#include <string>

using namespace std;

// ***Function Prototypes***
void promptInput(int& hours, int& minutes, int choice, bool& isPM);
void displayResults(string prevTime, string convTime, int choice, bool isPM);
void convertToTwelve(int& hours, bool& isPM);
void convertToTwentyFour(int& hours, bool isPM);

int main()
{
    // Variables
    int hours = 0;
    int minutes = 0;
    int choice = 0;
    bool isPM = false;
    string prevTime = "";
    string convTime = "";

    // Prompt for Input
    do
    {
        cout << "1. 24 Hour to 12 Hour Notation" << endl;
        cout << "2. 12 Hour to 24 Hour Notation" << endl;
        cout << "3. Quit Program" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if(cin.fail() || (choice < 1 || choice > 3))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value [1-3]." << endl;
            continue;
        }
        
        if(choice == 3) 
            break;
        
        // Choice is either 1 or 2
        promptInput(hours, minutes, choice, isPM);
        prevTime = to_string(hours) + ":" + to_string(minutes);

        if(choice == 1)
            convertToTwelve(hours, isPM);
        else
            convertToTwentyFour(hours, isPM);

        convTime = to_string(hours) + ":" + to_string(minutes);
        displayResults(prevTime, convTime, choice, isPM);
        
    } while(true);
    
    return 0;
}

// ***Functions***
void promptInput(int& hours, int& minutes, int choice, bool& isPM)
{
    string AM_PM = "";
    do
    {
        if(choice == 2)
        {
            cout << "Enter the hours and minutes to be converted: ";
            cin >> hours >> minutes;
            if(cin.fail() || hours < 1 || hours > 12 || minutes < 0 || minutes > 59)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter the hours within [1-12] and minutes within [1-59]." << endl;
                continue;
            }

            cout << "Is this AM or PM? [AM/PM]: ";
            cin >> AM_PM;
            if(cin.fail() || (AM_PM != "AM" && AM_PM != "PM"))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter \"AM\" or \"PM\"." << endl;
            } 
            if(AM_PM == "PM")
                isPM = true;
        } else
        {
            cout << "Enter the hours and minutes to be converted: ";
            cin >> hours >> minutes;
            if(cin.fail() || hours < 1 || hours > 24 || minutes < 0 || minutes > 59)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter the hours within [1-24] and minutes within [1-59]." << endl;
                continue;
            }
        }
        break;
    } while (true);
}

void convertToTwelve(int& hours, bool& isPM)
{
    if(hours > 12)
    {
        isPM = true;
        hours -= 12;
    }
}

void convertToTwentyFour(int& hours, bool isPM)
{
    if(isPM)
        hours += 12;
}

void displayResults(string prevTime, string convTime, int choice, bool isPM)
{
    if(choice == 2)
        cout << "The time " << prevTime << (isPM ? " PM" : " AM") << " converted to 24-hour notation is " << convTime << endl;
    else
        cout << "The time " << prevTime << " converted to 12-hour notation is " << convTime << (isPM ? " PM" : " AM") << endl;
}