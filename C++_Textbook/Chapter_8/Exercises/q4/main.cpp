// Question 4: Processing Test Scores
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    // Variables
    // 0: 0-24, 1: 25-49, 2: 50-74, 3: 75-99
    // 4: 100-124, 5: 125-149, 6: 150-174, 7: 175-200
    int scoreRange[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int value = 0;
    string str = "";

    // Declare and Open the File
    ifstream iFile;
    iFile.open("inData.txt");

    // Verify File is Open
    if(!iFile.is_open())
    {
        cout << "File did not open. Terminating Program..." << endl;
        return 1;
    }

    // Process Data in File
    getline(iFile, str);
    stringstream sstream(str);
    string token = "";

    while(getline(sstream >> ws, token, ','))
    {
        value = stoi(token);

        // Determine where student lies in range
        if(value >= 0 && value <= 24)
            scoreRange[0]++;
        else if(value >= 25 && value <= 49)
            scoreRange[1]++;
        else if (value >= 50 && value <= 74)
            scoreRange[2]++;
        else if (value >= 75 && value <= 99)
            scoreRange[3]++;
        else if (value >= 100 && value <= 124)
            scoreRange[4]++;
        else if (value >= 125 && value <= 149)
            scoreRange[5]++;
        else if (value >= 150 && value <= 174)
            scoreRange[6]++;
        else if (value >= 175 && value <= 200)
            scoreRange[7]++;
    }

    // Display Results
    cout << "Scores Range     Students" << endl;
    cout << left << setw(20) << "    0 - 24"   << scoreRange[0] << endl;
    cout << left << setw(20) << "   25 - 49"   << scoreRange[1] << endl;
    cout << left << setw(20) << "   50 - 74"   << scoreRange[2] << endl;
    cout << left << setw(20) << "   75 - 99"   << scoreRange[3] << endl;
    cout << left << setw(20) << "  100 - 124"  << scoreRange[4] << endl;
    cout << left << setw(20) << "  125 - 149"  << scoreRange[5] << endl;
    cout << left << setw(20) << "  150 - 174"  << scoreRange[6] << endl;
    cout << left << setw(20) << "  175 - 200"  << scoreRange[7] << endl;

    return 0;
}