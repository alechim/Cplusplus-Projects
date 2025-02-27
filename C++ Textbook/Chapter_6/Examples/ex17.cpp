// Example 6-17: Menu-Driven Program
#include <iostream>

using namespace std;

// ***Globals***
const double CONVERSION = 2.54;
const int INCHES_IN_FOOT = 12;
const int CENTIMETERS_IN_METER = 100;

// ***Function Prototypes***
void showChoices();
void feetAndInchesToMetersAndCent(int f, int in, int& mt, int& ct);
void metersAndCentToFeetAndInches(int mt, int ct, int &f, int& in);

int main()
{
    // Variables
    int feet = 0;
    int inches = 0;
    int meters = 0;
    int centimeters = 0;
    int choice = 0;

    // Prompt for Input
    do
    {
        showChoices();
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                cout << "Enter feet and inches: ";
                cin >> feet >> inches;
                cout << endl;
                feetAndInchesToMetersAndCent(feet, inches, meters, centimeters);
                cout << feet << " feet(foot), " << inches << " inch(es) = " << meters << " meter(s), " << centimeters << " centimeter(s)." << endl;
            case 2:
                cout << "Enter meters and centimeters: ";
                cin >> meters >> centimeters;
                cout << endl;
                metersAndCentToFeetAndInches(meters, centimeters, feet, inches);
                cout << meters << " meter(s), " << centimeters << " centimeter(s) = " << feet << " feet(foot), " << inches << " inch(es)." << endl;
                break;
            case 99:
                break;
            default:
                cout << "Invalid Input." << endl;
        }
    } while(choice != 99);
    
    return 0;
}

// ***Functions***
void showChoices()
{
    cout << "Enter--" << endl;
    cout << "1: To convert from feet and inches to meters and centimeters." << endl;
    cout << "2: To convert from meters and centimeters to feet and inches." << endl;
    cout << "99: To quit the program." << endl;
}

void feetAndInchesToMetersAndCent(int f, int in, int& mt, int &ct)
{
    int inches = 0;
    inches = f * INCHES_IN_FOOT + in;
    ct = static_cast<int>(inches * CONVERSION);
    mt = ct / CENTIMETERS_IN_METER;
    ct = ct % CENTIMETERS_IN_METER;
}

void metersAndCentToFeetAndInches(int mt, int ct, int &ft, int &in)
{
    int centimeters;
    centimeters = mt * CENTIMETERS_IN_METER + ct;
    in = static_cast<int>(centimeters / CONVERSION);
    ft = in / INCHES_IN_FOOT;
    in = in % INCHES_IN_FOOT;
}