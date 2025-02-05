// Example 3-13: Setw Function
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int miles = 245;
    int speed = 55;
    double hours = 35.45;
    double error = 3.7564;

    cout << fixed << showpoint;
    cout << "123456789012345678901234567890" << endl;

    cout << setw(5) << miles << endl;
    
    cout << setprecision(2);

    cout << setw(5) << miles << setw(5) << speed << setw(6) << hours << setw(7) << error << endl << endl;
    cout << setw(5) << speed << setw(5) << miles << setw(4) << hours << setw(7) << error << endl << endl;
    cout << setw(2) << miles << setw(6) << hours << setw(7) << error << endl << endl;
    cout << setw(2) << miles << setw(7) << "error" << error << endl;

    return 0;
}