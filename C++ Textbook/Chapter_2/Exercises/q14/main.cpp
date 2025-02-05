// Question 14: Calculate Hard Drive space
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int storage = 0;
    long long int byteStorage = 0;
    double storageConvert = 0.0;
    long long int byteConvert = 1073741824;   // 1024GB = 1,073,741,824 Bytes 

    while(true)
    {
        cout << "Please enter the listed storage space (GB): ";
        cin >> storage;

        if(cin.fail() || storage <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero integer value." << endl;
        } else
        {
            break;
        }
    }

    // Calculations
    byteStorage = static_cast<long long int>(storage) * 1000000000;
    storageConvert = static_cast<double>(byteStorage) / byteConvert;

    // Display Results
    cout << "The manufacturer's storage listed is " << storage << " GB." << endl;
    cout << "The actual storage capacity is " << fixed << setprecision(2) << storageConvert << " GB." << endl;

    return 0;
}