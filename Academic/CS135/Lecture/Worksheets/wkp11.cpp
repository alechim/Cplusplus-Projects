#include <iostream>

using namespace std;

int main()
{
    // Variables
    double frstNum = 0.0;
    double scndNum = 0.0;

    do 
    {
        cout << "Enter two numbers: ";
        cin >> frstNum >> scndNum;

        if (cin.fail() == true)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Enter the numbers again" << endl;
        } else
            break;
    } while(true);

    cout << frstNum << " + " << scndNum << " = " << frstNum + scndNum << endl;

    return 0;
}
