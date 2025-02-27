// Question 18: Employee Clock In and Out
#include <iostream>
#include <string>

using namespace std;

// ***Function Prototypes***
void timeOnJob(int arvHr, int arvMin, bool arvIsAM, int depHr, int depMin, bool depIsAM);

int main()
{
    // Variables
    string employeeName = "";
    int arrivalHr = 0;
    int arrivalMin = 0;
    bool arrivalAM = 0;

    int departureHr = 0;
    int departureMin = 0;
    bool departureAM = 0;

    char response = ' ';
    char discard = ' ';
    char isAM = ' ';

    // Prompt user to run the program
    cout << "This program calculates the total time spent by an employee on the job." << endl;
    cout << "To run the program, enter (y/Y): ";
    cin >> response;
    cout << endl;
    cin.get(discard);

    while(response == 'y' || response == 'Y')
    {
        cout << "Enter employee's name: ";
        getline(cin, employeeName);
        cout << endl;

        cout << "Enter arrival hour: ";
        cin >> arrivalHr;
        cout << "Enter arrival minute: ";
        cin >> arrivalMin;
        cout << endl;
        cout << "Enter (y/Y) if arrival is before 12:00PM: ";
        cin >> isAM;
        cout << endl;

        if(isAM == 'y' || isAM == 'Y')
            arrivalAM = true;
        else
            arrivalAM = false;

        cout << "Enter departure hour: ";
        cin >> departureHr;
        cout << "Enter departure minute: ";
        cin >> departureMin;
        cout << endl;
        cout << "Enter (y/Y) if departure is before 12:00PM: ";
        cin >> isAM;
        cout << endl;

        if(isAM == 'y' || isAM == 'Y')
            departureAM = true;
        else
            departureAM = false;

        cout << employeeName << endl;
        timeOnJob(arrivalHr, arrivalMin, arrivalAM, departureHr, departureMin, departureAM);

        // Prompt user for loop
        cout << "Run program again (y/Y): ";
        cin >> response;
        cout << endl;
        cin.get(discard);
    }

    return 0;
}

void timeOnJob(int arvHr, int arvMin, bool arvIsAM, int depHr, int depMin, bool depIsAM)
{
    int arvTimeInMin = 0;
    int depTimeInMin = 0;
    int timeOnJobInMin = 0;

    arvTimeInMin = arvHr * 60 + arvMin;
    depTimeInMin = depHr * 60 + depMin;

    if ((arvIsAM == true && depIsAM == true) || (arvIsAM == false && depIsAM == false))
    {
        if (arvTimeInMin <= depTimeInMin)
        {
            timeOnJobInMin = depTimeInMin - arvTimeInMin;
            cout << "Time spent on job: " << timeOnJobInMin / 60 << " hour(s) and " << timeOnJobInMin % 60 << " minutes." << endl;
        }
        else
        {
            cout << "Invalid Input." << endl;
        }
    } 
    else if (arvIsAM == true && depIsAM == false)
    {
        timeOnJobInMin = (720 - arvTimeInMin) + depTimeInMin;
        cout << "Time spent on job: " << timeOnJobInMin / 60 << " hour(s) and " << timeOnJobInMin % 60 << " minutes." << endl;
    }
    else
    {
        cout << "Invalid Input." << endl;
    }
}