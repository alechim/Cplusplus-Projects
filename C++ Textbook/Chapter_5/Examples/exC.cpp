// Example 5-C: Looped Sums
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Variables
    ifstream inFile;
    int i = 0;
    int j = 0;
    int sum = 0;
    int num = 0;

    inFile.open("C_Data.txt");
    
    for(i = 1; i <= 3; i++)
    {
        sum = 0;
        for(j = 1; j <= 4; j++)
        {
            inFile >> num;
            cout << num << " ";
            sum = sum + num;
        }
        cout << "sum = " << sum << endl;
    }

    return 0;
}