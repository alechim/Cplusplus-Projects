/** 
 * Alec Him, 2001543593, CS135 1009, Lab 13
 * Description: Refactored Lab 12 using a struct
 * Input: home.txt, away.txt, play_by_play.txt
 * Output: Player Statistics (Ordered by Height)
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Global Variables
const int WIDTH = 10;       // width of printed table's columns

struct basketballPlayer
{
    string firstName = "", lastName = "";
    int att2s = 0, md2s = 0;
    int att3s = 0, md3s = 0;
    int attFTs = 0, mdFTs = 0;
    int height = 0; // in cm
    int points = 0;
};

// Function Prototypes
void readRoster(basketballPlayer[], int&, string&);
int toCentimeters(int, int);
int getIndex(basketballPlayer[], int, string, string);
void recordPlay(basketballPlayer&, string, string);
void openFin(ifstream&, string);
void outputOnePlayer(basketballPlayer);
void printHeader(string, int);
void outputChar(int, char);
int tallyPoints(basketballPlayer[], int);
void bubbleSort(basketballPlayer[], int);

int main()
{
    // Constant Variables
    const int MAX_ROSTER_SIZE = 20;

    // Variables - Away Team
    basketballPlayer awayTeam[MAX_ROSTER_SIZE];
    int awayTeamRosterSize = 0;
    int awayTeamScore = 0;
    string awayTeamName = "";

    // Variables - Home Team
    basketballPlayer homeTeam[MAX_ROSTER_SIZE];
    int homeTeamRosterSize = 0;
    int homeTeamScore = 0;
    string homeTeamName = "";

    // Variables
    ifstream fin;
    string first = "", last = "", attempt = "", shot = "";

    readRoster(awayTeam, awayTeamRosterSize, awayTeamName);
    readRoster(homeTeam, homeTeamRosterSize, homeTeamName);

    openFin(fin, "Enter Play-by-Play file name: ");

    while(fin >> first)
    {
        fin >> last;
        fin >> attempt;
        getline(fin, shot);
        int i = getIndex(awayTeam, awayTeamRosterSize, first, last);

        if (i >= 0)
            recordPlay(awayTeam[i], attempt, shot);
        else 
        {
            i = getIndex(homeTeam, homeTeamRosterSize, first, last);
            if (i >= 0)
                recordPlay(homeTeam[i], attempt, shot);
            else 
                cout << "Error: " << first << " " << last << " is not on any team\n";
        }
    }

    // Close the file
    fin.close();

    awayTeamScore = tallyPoints(awayTeam, awayTeamRosterSize);
    homeTeamScore = tallyPoints(homeTeam, homeTeamRosterSize);

    bubbleSort(awayTeam, awayTeamRosterSize);
    bubbleSort(homeTeam, homeTeamRosterSize);
    cout << endl;

    printHeader(awayTeamName, awayTeamScore);
    for (int i = 0; i < awayTeamRosterSize; i++)
        outputOnePlayer(awayTeam[i]);

    printHeader(homeTeamName, homeTeamScore);
    for (int i = 0; i < homeTeamRosterSize; i++)
        outputOnePlayer(homeTeam[i]);

    return 0;
}

// Function Definitions
/**
 * Preconditions:
 * - input file uses LF (Unix) line endings
 * - 1st line of input file contains the team name
 * - following lines contain <= MAX_ROSTER_SIZE amount of player data
 * - player data is in the format <first name> <last name> <height>
 * - <height> is in the format <feet tall>' <additional inches tall>"
 * Postconditions:
 * - sets team roster size by reference
 * - sets team name by reference
 * - sets player first names, last names, and heights by reference
 */
void readRoster(basketballPlayer team[], int& rosterSize, string& teamName)
{
    // Variables
    int feet = 0, inches = 0;
    rosterSize = 0;

    // Declare and open the file
    ifstream fin;
    openFin(fin, "Enter team roster file name: ");

    getline(fin, teamName);
    while(fin >> team[rosterSize].firstName)
    {
        fin >> team[rosterSize].lastName;
        fin >> feet;
        fin.ignore(1, ' ');
        fin >> inches;
        fin.ignore(1, ' ');
        team[rosterSize].height = toCentimeters(feet, inches);
        rosterSize++;
    }

    // Close the file
    fin.close();
}

/**
 * Precondition:
 * - size correctly reflects the lengths of all the array
 * Postcondition:
 * - returns the position of the player in the array based on their name
 * - returns -1 if the player is not in the array
 */
int getIndex(basketballPlayer team[], int size, string first, string last)
{
    for(int i = 0; i < size; i++)
        if(first == team[i].firstName && last == team[i].lastName)
            return i;
    return -1;
}

/**
 * Precondition:
 * - fin is an unopened input file stream
 * Postcondition:
 * - prompts for the name of an input file, until it's valid
 */
void openFin(ifstream& fin, string prompt)
{
    // Variables
    string fileName = "";

    do 
    {
        cout << prompt;
        cin >> fileName;
    
        fin.open(fileName.c_str());
    
        if (!fin.is_open())
            cout << "Error: unable to open " << fileName << endl << endl;
    } while(!fin.is_open());

    cout << fileName << " opened\n" << endl;
}

/**
 * Postcondition:
 * - prints a player's formatted stats to console output
 */
void outputOnePlayer(basketballPlayer player)
{
    cout << setw(WIDTH * 2) << left << player.firstName + " " + player.lastName;
    cout << right;
    cout << setw(WIDTH) << player.height;
    cout << setw(WIDTH) << to_string(player.md2s) + "-" + to_string(player.att2s);
    cout << setw(WIDTH) << to_string(player.md3s) + "-" + to_string(player.att3s);
    cout << setw(WIDTH) << to_string(player.mdFTs) + "-" + to_string(player.attFTs);
    cout << setw(WIDTH) << player.points;
    cout << endl;
}

/**
 * Postcondition:
 * - prints banner to console output
 */
void printHeader(string teamName, int teamScore)
{
    cout << endl;
    cout << teamName << " " << teamScore << endl;
    outputChar(WIDTH * 7, '-');
    cout << endl;
    cout << setw(WIDTH * 2) << left << "PLAYERS";
    cout << right;
    cout << setw(WIDTH) << "HT";
    cout << setw(WIDTH) << "FG";
    cout << setw(WIDTH) << "3PT";
    cout << setw(WIDTH) << "FT";
    cout << setw(WIDTH) << "PTS";
    cout << endl;
    outputChar(WIDTH * 7, '-');
    cout << endl;
}

/**
 * Precondition:
 * - size correctly reflects the lengths of all the array
 * Postcondition:
 * - sorts the team using heights as the keys
 */
void bubbleSort(basketballPlayer team[], int size)
{
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(team[j].height < team[j + 1].height)
                swap(team[j], team[j + 1]);
}

/**
 * Precondition:
 * - i is a valid index to the array
 * Postcondition:
 * - adjusts the i'th element of the array
 */
void recordPlay(basketballPlayer& player, string attempt, string shot)
{
    if(shot == " Dunk." || shot == " Layup." || shot == " Jumper." || shot == " Two Point Tip Shot.")
    {
        player.att2s += 1;
        if(attempt == "made")
        {
            player.md2s += 1;
            player.points += 2;
        }

    }

    if(shot == " Three Point Jumper.")
    {
        player.att3s += 1;
        if(attempt == "made")
        {
            player.md3s += 1;
            player.points += 3;
        }
    }

    if(shot == " Free Throw.")
    {
        player.attFTs += 1;

        if(attempt == "made")
        {
            player.mdFTs += 1;
            player.points += 1;
        }
    }
}

/**
 * Postcondition:
 * - returns the centimeter equivalent of feet + inches
 */
int toCentimeters(int feet, int inches)
{
    return ((feet * 12) + inches) * 2.54;
}

/**
 * Postcondition:
 * - inserts count amount of c's to console output
 */
void outputChar(int count, char c)
{
    for(int i = 0; i < count; i++)
        cout << c; 
}

/**
 * Precondition:
 * - size correctly reflects the length the array
 * Postcondition:
 * - returns the sum of size elements of the array
 */
int tallyPoints(basketballPlayer team[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += team[i].points;

    return sum;
}
