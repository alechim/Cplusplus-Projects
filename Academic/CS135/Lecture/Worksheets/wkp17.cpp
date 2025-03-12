#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Variables
    string file = "wksheet17.txt";
    ifstream iFile;
    double num = 0.0;
    double avg = 0.0;
    double sum = 0.0;
    int count = 0;
    double num2[100];

    iFile.open(file);

    if(!iFile.is_open())
        cout << "Error - File Did Not Open" << endl;
    
    for(int i = 0; !iFile.eof(); i++)
    {
        iFile >> num;
        if (!iFile.eof())
        {
            num2[i] = num;
            sum += num2[i];
            count++;
        } else 
        {
            avg = sum / count;
            cout << "Average is " << avg << endl;
        }
    }

    return 0;
}