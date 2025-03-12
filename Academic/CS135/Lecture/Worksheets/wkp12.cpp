#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Variables
    string file = "w12Data.txt";
    ifstream iFile;
    int num1 = 0;
    int num2 = 0;

    do 
    {
        cout << "Enter filename ";
        cin >> file;

        iFile.open(file);

        if (!iFile.is_open())
            cout << "Error - File Did Not Open" << endl;
    } while(!iFile.is_open());

    while(!iFile.eof())
    {
        iFile >> num1 >> num2;

        if (iFile.fail())
        {
            iFile.clear();
            iFile.ignore(40, '\n');
            cout << "Error - line contains a letter" << endl;
        } else 
            cout << "Sum of " << num1 << " + " << num2 << " = " << num1 + num2 << endl;

        if (iFile.eof())
            cout << "End of file reached, Exiting ..." << endl;
    }

    return 0;
}
