// Question 6: Count and Calculate Percentage of Letters
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Structs
struct letterType
{
    char letter;
    int count;
    double percentage;
};

// Function Prototypes
void initialize(letterType[]);
int openFile(ifstream&, ofstream&);
void count(ifstream&, letterType[]);
void printResult(ofstream&, letterType[]);

int main()
{
    // Variables
    letterType letters[52];
    ifstream iFile;
    ofstream oFile;

    if(openFile(iFile, oFile) == 1)
        return 1;
    initialize(letters);
    count(iFile, letters);
    printResult(oFile, letters);

    iFile.close();
    oFile.close();

    return 0;
}

// Function Definitions
/**
 * initialize: 
 * @param letterType letters[] - 
 */
void initialize(letterType letters[])
{
    for(int i = 0; i < 52; i++)
    {
        letters[i].letter = ((i < 26) ? static_cast<char>('a' + i) : static_cast<char>('A' + (i - 26)));
        letters[i].count = 0;
        letters[i].percentage = 0.0;
    }
}

/**
 * openFile: 
 * @param ifstream& iFile - 
 * @param ofstream& oFile - 
 * @return int - 
 */
int openFile(ifstream& iFile, ofstream& oFile)
{
    string inputFile = "", outputFile = "";

    // Prompt and Validate Input - Input File Name
    do
    {
        cout << "Please enter an input file name: ";
        cin >> inputFile;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a valid string value." << endl;
        } else
            break;
    } while(true);

    // Open and Verify input file is opened
    iFile.open(inputFile);
    if(!iFile.is_open())
    {
        cout << "Error - Input file does not open.";
        return 1;
    }

    // Prompt and Validate Input - Output File Name
    do
    {
        cout << "Please enter an output file name: ";
        cin >> outputFile;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a valid string value." << endl;
        } else
            break;
    } while(true);

    // Open and Verify output file is opened
    oFile.open(outputFile);
    if(!oFile.is_open())
    {
        cout << "Error - Output file does not open.";
        return 1;
    }

    return 0;
}

/**
 * count: 
 * @param ifstream& iFile - 
 * @param letterType letters - 
 */
void count(ifstream& iFile, letterType letters[])
{
    string word = "";
    int sum = 0;
    while(iFile >> word)
        for(int i = 0; i < word.length(); i++)
            for(int j = 0; j < 52; j++)
                if(word[i] == letters[j].letter)
                {
                    letters[j].count++;
                    sum++;
                    break;
                }

    for(int i = 0; i < 52; i++)
        letters[i].percentage = static_cast<double>(letters[i].count) / sum;
}

/**
 * printResult: 
 * @param ofstream& oFile - 
 * @param letterType letters[] - 
 */
void printResult(ofstream& oFile, letterType letters[])
{
    for(int i = 0; i < 52; i++)
    {
        if(i != 0 && i != 26 && i % 13 == 0)
            oFile << endl << "| ";
        if(i == 0)
            oFile << "+=== Small Letters ===+" << endl << "| ";
        if(i == 26)
            oFile << endl << "+=== Capital Letters ===+" << endl << "| ";
        oFile << letters[i].letter << ": " << letters[i].count << ", " << round(letters[i].percentage * 100) << "% | ";
    }
}