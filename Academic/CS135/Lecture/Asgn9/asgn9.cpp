/**
 * Alec Him, 2001543593, CS135 1004, Assignment 9
 * Description: Read in Files and Display Targets Hit and Missed
 * Input: StormTrooperData.txt & TargetWeights.txt
 * Output: Graph of Targets, Names, Targets Hit, Score, Top 3 Names
 */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Global Constant Variables
const int SIZE = 20;
const int TRGTS = 10;

// Function Prototypes
int readData(string[], bool[][TRGTS], double[]);
double computeScore(bool[][TRGTS], double[], int);
void outputStormTroopers(string[], bool[][TRGTS], double[], int);
void outputOneStormTrooper(string, bool[], double);
void lowerCase(string&);

int main()
{
    // Variables
    string names[SIZE];
    bool targets[SIZE][TRGTS];
    double targetWeights[TRGTS];
    double scores[SIZE];
    int amtStormTroopers = readData(names, targets, targetWeights);

    for(int i = 0; i < amtStormTroopers; i++)
        scores[i] = computeScore(targets, targetWeights, i);
    
    outputStormTroopers(names, targets, scores, amtStormTroopers);

    return 0;
}

// Function Definitions
/**
 * readData: Reads and processes two data files for calculations
 * @param string name[] - contains the names of all storm troopers
 * @param bool hit[][TRGTS] - contains the array of whether a target was hit or not
 * @param double weights[] - contains the values of each target
 * @return int numTroop - the total number of storm troopers found
 */
int readData(string name[], bool hit[][TRGTS], double weights[])
{
    // Variables
    ifstream iFile1;
    ifstream iFile2;
    string file1 = "StormTrooperData.txt";
    string file2 = "TargetWeights.txt";
    string hit_miss = "";
    int numTroop = 0;

    // Prompt for Input and Validate File is Opened - 1
    do
    {
        cout << "\nPlease enter storm trooper results file: ";
        cin >> file1;

        iFile1.open(file1);
        if(!iFile1.is_open() || cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid file!" << endl;
        } else
        {
            cout << "Stormtrooper data read successfully" << endl;
            break;
        }
    } while(true);

    // Prompt for Input and Validate File is Opened - 2
    do
    {
        cout << "\nEnter target weights: ";
        cin >> file2;

        iFile2.open(file2);
        if(!iFile2.is_open() || cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid file!" << endl;
        } else
        {
            cout << "\nTarget weights updated!\n" << endl;
            break;
        }
    } while(true);
    
    // Read and store the weights into an array
    for(int i = 0; iFile2 >> weights[i]; i++);
    
    // Read the storm trooper data
    for(int i = 0; iFile1 >> name[i]; i++)
    {
        for(int j = 0; j < TRGTS; j++)
        {
            iFile1 >> hit_miss;
            lowerCase(hit_miss);
            if(hit_miss == "hit")
                hit[i][j] = true;
            else
                hit[i][j] = false;
        }
        numTroop++;
    }

    // Close the files
    iFile1.close();
    iFile2.close();

    return numTroop;
}

/**
 * lowerCase: Converts the string to lowercase
 * @param string lower
 */
void lowerCase(string& lower)
{
    for(size_t i = 0; i < lower.length(); i++)
        lower[i] = tolower(lower[i]);
}

/**
 * computeScore: Calculates the score of the storm trooper based on whether the target was hit and the associated weight
 * @param bool hits[][TRGTS] - contains the array of whether a target was hit or not
 * @param double weights[] - contains the different weights of the targets to determine the score
 * @param int numTroop - contains the number of storm troopers
 * @return double
 */
double computeScore(bool hit[][TRGTS], double weights[], int numTroop)
{
    double score = 0.0;
    for(int c = 0; c < TRGTS; c++)
        score += weights[c] * hit[numTroop][c];
    return score;
}

/**
 * outputStormTroopers:
 * @param string name[] - contains the names of all storm troopers
 * @param bool hit[][TRGTS] - contains the array of whether a target was hit or not
 * @param double scores[] - contains the total score for all storm troopers
 * @param int numTroop - contains the number of storm troopers
 */
void outputStormTroopers(string name[], bool hit[][TRGTS], double scores[], int numTroop)
{
    // Variables
    bool confirm[TRGTS];

    // Header Display
    cout << "NAME";
    cout << setw(8) << "T1";
    cout << setw(4) << "T2";
    cout << setw(4) << "T3";
    cout << setw(4) << "T4";
    cout << setw(4) << "T5";
    cout << setw(4) << "T6";
    cout << setw(4) << "T7";
    cout << setw(4) << "T8";
    cout << setw(4) << "T9";
    cout << setw(5) << "T10";
    cout << setw(6) << "TOTAL";
    cout << setw(10) << "SCORE" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    // Output the entire array of troops information
    for(int r = 0; r < numTroop; r++)
    {
        for(int c = 0; c < TRGTS; c++)
            confirm[c] = hit[r][c];

        outputOneStormTrooper(name[r], confirm, scores[r]);
    }
}

/**
 * outputOneStormTrooper: Outputs the display and score of a single storm trooper
 * @param string name - the name of the storm trooper
 * @param bool confirm[] - contains whether a target was hit or not
 * @param double score - contains the value of the total score for the storm trooper
 */
void outputOneStormTrooper(string name, bool confirm[], double score)
{
    int count = 0;

    cout << name;
    for(int i = 0; i < TRGTS; i++)
    {
        if(confirm[i])
        {
            cout << setw(4) << "X";
            count++;
        } else
            cout << setw(4) << " ";
    }
    cout << setw(8) << count;
    cout << setw(10) << setprecision(4) << score << endl;
}