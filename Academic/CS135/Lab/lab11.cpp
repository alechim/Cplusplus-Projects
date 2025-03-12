/** 
 * Alec Him, 2001543593, CS135 1009, Lab 11
 * Description: Introduction to struct via radio frequencies and call signs
 * Input: frequency(int)
 * Output: information from station struct
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct station
{
    string callSign = "";
    double frequency = 0.0;
    string genre = "";
    string nowPlaying = "";
};

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Usage: ./a.out [RADIO_FILENAME]" << endl;
        return 0;
    }
    // Variables
    station currentStation[15];
    string fileName = argv[1];
    string junk = "";
    double freq = 0.0;

    // Declare and open the file
    ifstream iFile;
    iFile.open(fileName.c_str());

    // Verify if file exists
    if(!iFile)
    {
        cout << "No reception. Hope you have an aux cable!" << endl;
        return 0;
    }

    for (int j = 0; j < 15; j++)
    {
        getline(iFile, currentStation[j].callSign);
        iFile >> currentStation[j].frequency;
        getline(iFile, junk);
        getline(iFile, currentStation[j].genre);
        getline(iFile, currentStation[j].nowPlaying);
        getline(iFile, junk);
    }

    // Close the file
    iFile.close();

    // Prompt for Input
    cout << "Enter a frequency" << endl;
    cin >> freq;

    // Find and print out the radio station based on the given frequency
    for (int i = 0; i <= 15; i++)
    {
        if(freq == currentStation[i].frequency)
        {
            cout << "Now Playing: " << currentStation[i].nowPlaying << endl;
            cout << "Station Type: " << currentStation[i].genre << endl;
            cout << "Callsign: " << currentStation[i].callSign << endl;
            break;
        } else if(i == 15)
        {
            cout << "Nothing but Static..." << endl;
            cout << "Try Again" << endl;
            cin >> freq;
            i = 0;
        }
    }

    return 0;
}