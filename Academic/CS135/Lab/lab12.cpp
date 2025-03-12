/** 
 * Alec Him, 2001543593, CS135 1009, Lab 12
 * Description: Reads three text files of basketball teams and play by play and outputs individual players statistics 
 * Input: home.txt, away.txt, play_by_play.txt
 * Output: Player Statistics (Ordered by Points)
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Global Variables
const int WIDTH = 10;       // width of printed table's columns

// Function Prototypes
void readRoster(string[], string[], int[], int&, string&);
int toCentimeters(int, int);
int getIndex(string[], string[], int, string, string);
void recordPlay(int[], int[], int[], int[], int[], int[], int[], int, string, string);
void openFin(ifstream&, string);
void outputOnePlayer(string[], string[], int[], int[], int[], int[], int[], int[], int[], int[], int);
void printHeader(string, int);
void outputChar(int, char);
int getSum(int[], int);
void bubbleSort(string[], string[], int[], int[], int[], int[], int[], int[], int[], int[], int);

int main()
{
    // Constant Variables
    const int MAX_ROSTER_SIZE = 20;

    // Variables - Away Team
    string awayTeamFirstNames[MAX_ROSTER_SIZE];
    string awayTeamLastNames[MAX_ROSTER_SIZE];
    int awayTeamHeights[MAX_ROSTER_SIZE] = {0};
    int awayTeamAtt2s[MAX_ROSTER_SIZE] = {0};
    int awayTeamMd2s[MAX_ROSTER_SIZE] = {0};
    int awayTeamAtt3s[MAX_ROSTER_SIZE] = {0};
    int awayTeamMd3s[MAX_ROSTER_SIZE] = {0};
    int awayTeamAttFTs[MAX_ROSTER_SIZE] = {0};
    int awayTeamMdFTs[MAX_ROSTER_SIZE] = {0};
    int awayTeamPoints[MAX_ROSTER_SIZE] = {0};
    int awayTeamRosterSize = 0;
    int awayTeamScore = 0;
    string awayTeamName = "";

    // Variables - Home Team
    string homeTeamFirstNames[MAX_ROSTER_SIZE];
    string homeTeamLastNames[MAX_ROSTER_SIZE];
    int homeTeamHeights[MAX_ROSTER_SIZE] = {0};
    int homeTeamAtt2s[MAX_ROSTER_SIZE] = {0};
    int homeTeamMd2s[MAX_ROSTER_SIZE] = {0};
    int homeTeamAtt3s[MAX_ROSTER_SIZE] = {0};
    int homeTeamMd3s[MAX_ROSTER_SIZE] = {0};
    int homeTeamAttFTs[MAX_ROSTER_SIZE] = {0};
    int homeTeamMdFTs[MAX_ROSTER_SIZE] = {0};
    int homeTeamPoints[MAX_ROSTER_SIZE] = {0};
    int homeTeamRosterSize = 0;
    int homeTeamScore = 0;
    string homeTeamName = "";

    // Variables
    ifstream fin;
    string first = "", last = "", attempt = "", shot = "";

    // Function Calls
    readRoster(awayTeamFirstNames, awayTeamLastNames, awayTeamHeights, awayTeamRosterSize, awayTeamName);
    readRoster(homeTeamFirstNames, homeTeamLastNames, homeTeamHeights, homeTeamRosterSize, homeTeamName);

    // Open the file
    openFin(fin, "Enter Play-by-Play file name: ");

    while(fin >> first)
    {
        fin >> last;
        fin >> attempt;
        getline(fin, shot);
        int i = getIndex(awayTeamFirstNames, awayTeamLastNames, awayTeamRosterSize, first, last);
    
        if(i >= 0)
            recordPlay(awayTeamAtt2s, awayTeamMd2s, awayTeamAtt3s, awayTeamMd3s, awayTeamAttFTs, awayTeamMdFTs, awayTeamPoints, i, attempt, shot);
        else 
        {
            i = getIndex(homeTeamFirstNames, homeTeamLastNames, homeTeamRosterSize, first, last);
            if (i >= 0)
                recordPlay(homeTeamAtt2s, homeTeamMd2s, homeTeamAtt3s, homeTeamMd3s, homeTeamAttFTs, homeTeamMdFTs, homeTeamPoints, i, attempt, shot);
            else 
                cout << "Error: " << first << " " << last << " is not on any team\n";
        }
    }

    // Close the file
    fin.close();

    awayTeamScore = getSum(awayTeamPoints, awayTeamRosterSize);
    homeTeamScore = getSum(homeTeamPoints, homeTeamRosterSize);

    bubbleSort(awayTeamFirstNames, awayTeamLastNames, awayTeamHeights, awayTeamAtt2s, awayTeamMd2s, awayTeamAtt3s, awayTeamMd3s, awayTeamAttFTs, awayTeamMdFTs, awayTeamPoints, awayTeamRosterSize);
    bubbleSort(homeTeamFirstNames, homeTeamLastNames, homeTeamHeights, homeTeamAtt2s, homeTeamMd2s, homeTeamAtt3s, homeTeamMd3s, homeTeamAttFTs, homeTeamMdFTs, homeTeamPoints, homeTeamRosterSize);
    cout << endl;

    printHeader(awayTeamName, awayTeamScore);
    for(int i = 0; i < awayTeamRosterSize; i++)
        outputOnePlayer(awayTeamFirstNames, awayTeamLastNames, awayTeamHeights, awayTeamAtt2s, awayTeamMd2s, awayTeamAtt3s, awayTeamMd3s, awayTeamAttFTs, awayTeamMdFTs, awayTeamPoints, i);
    cout << endl;

    printHeader(homeTeamName, homeTeamScore);
    for(int i = 0; i < homeTeamRosterSize; i++)
        outputOnePlayer(homeTeamFirstNames, homeTeamLastNames, homeTeamHeights, homeTeamAtt2s, homeTeamMd2s, homeTeamAtt3s, homeTeamMd3s, homeTeamAttFTs, homeTeamMdFTs, homeTeamPoints, i);

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
void readRoster(string firsts[], string lasts[], int heights[], int& rosterSize, string& teamName)
{
    // Variables
    int feet = 0, inches = 0;
    rosterSize = 0;

    // Declare and open the file
    ifstream fin;
    openFin(fin, "Enter team roster file name: ");
    
    getline(fin, teamName);
    while(fin >> firsts[rosterSize])
    {
        fin >> lasts[rosterSize];
        fin >> feet;
        fin.ignore(1, ' ');
        fin >> inches;
        fin.ignore(1, ' ');
        heights[rosterSize] = toCentimeters(feet, inches);
        rosterSize++;
    }

    // Close the file
    fin.close();
}

/**
 * Precondition:
 * - size correctly reflects the lengths of all the parallel arrays
 * Postcondition:
 * - returns the position of the player in the parallel arrays based on their name
 * - returns -1 if the player is not in the arrays
 */
int getIndex(string firstNames[], string lastNames[], int size, string first, string last)
{
    for(int i = 0; i < size; i++)
        if(first == firstNames[i] && last == lastNames[i])
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
    
        if(!fin.is_open())
            cout << "Error: unable to open " << fileName << endl << endl;
    } while(!fin.is_open());

    cout << fileName << " opened\n" << endl;
}

/**
 * Precondition:
 * - i is a valid index to the parallel arrays
 * Postcondition:
 * - prints a player's formatted stats to console output
 */
void outputOnePlayer(string firsts[], string lasts[], int heights[], int att2s[], int md2s[], int att3s[], int md3s[], int attFTs[], int mdFTs[], int points[], int i)
{
    cout << setw(WIDTH * 2) << left << firsts[i] + " " + lasts[i];
    cout << right;
    cout << setw(WIDTH) << to_string(md2s[i]) + "-" + to_string(att2s[i]);
    cout << setw(WIDTH) << to_string(md3s[i]) + "-" + to_string(att3s[i]);
    cout << setw(WIDTH) << to_string(mdFTs[i]) + "-" + to_string(attFTs[i]);
    cout << setw(WIDTH) << points[i];
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
    outputChar(WIDTH * 6, '-');
    cout << endl;
    cout << setw(WIDTH * 2) << left << "PLAYERS";
    cout << right;
    cout << setw(WIDTH) << "FG";
    cout << setw(WIDTH) << "3PT";
    cout << setw(WIDTH) << "FT";
    cout << setw(WIDTH) << "PTS";
    cout << endl;
    outputChar(WIDTH * 6, '-');
    cout << endl;
}

/**
 * Precondition:
 * - size correctly reflects the lengths of all the parallel arrays
 * Postcondition:
 * - sorts the parallel arrays using points as the keys
 */
void bubbleSort(string firsts[], string lasts[], int heights[], int att2s[], int md2s[], int att3s[], int md3s[], int attFTs[], int mdFTs[], int points[], int size)
{
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(points[j] < points[j + 1])
            {
                swap(firsts[j], firsts[j + 1]);
                swap(lasts[j], lasts[j + 1]);
                swap(heights[j], heights[j + 1]);
                swap(att2s[j], att2s[j + 1]);
                swap(md2s[j], md2s[j + 1]);
                swap(att3s[j], att3s[j + 1]);
                swap(md3s[j], md3s[j + 1]);
                swap(attFTs[j], attFTs[j + 1]);
                swap(mdFTs[j], mdFTs[j + 1]);
                swap(points[j], points[j + 1]);
            }
}

/**
 * Precondition:
 * - i is a valid index to the parallel arrays
 * Postcondition:
 * - adjusts the i'th element of the parallel arrays
 */
void recordPlay(int att2s[], int md2s[], int att3s[], int md3s[], int attFTs[], int mdFTs[], int points[], int i, string attempt, string shot)
{
    if(shot == " Dunk." || shot == " Layup." || shot == " Jumper." || shot == " Two Point Tip Shot.")
    {
        att2s[i] += 1;
        if(attempt == "made")
        {
            md2s[i] += 1;
            points[i] += 2;
        }
    } 

    if(shot == " Three Point Jumper.")
    {
        att3s[i] += 1;
        if(attempt == "made")
        {
            md3s[i] += 1;
            points[i] += 3;
        }
    }

    if(shot == " Free Throw.")
    {
        attFTs[i] += 1;
        if(attempt == "made")
        {
            mdFTs[i] += 1;
            points[i] += 1;
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

int getSum(int list[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += list[i];
  
    return sum;
}