// Example B: Text Processing
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

// Function Prototypes
void initialize(int&, int[]);
void copyText(ifstream&, ofstream&, char&, int[]);
void characterCount(char, int[]);
void writeTotal(ofstream&, int, int[]);

int main()
{
    // Variables
    int lineCount;
    int letterCount[26];
    char ch;
    ifstream iFile;
    ofstream oFile;

    iFile.open("textIn.txt");

    if(!iFile)
    {
        cout << "Cannot open the input file." << endl;
        return 1;
    }

    oFile.open("textOut.out");

    initialize(lineCount, letterCount);

    iFile.get(ch);

    while(iFile)
    {
        copyText(iFile, oFile, ch, letterCount);
        lineCount++;
        iFile.get(ch);
    }

    writeTotal(oFile, lineCount, letterCount);

    iFile.close();
    oFile.close();

    return 0;
}

// Function Definitions
/**
 * initialize: Initializes lineCount and letterCount to 0
 * @param int& lc - The variable that represents line count
 * @param int[] list - The array that represents the letter count
 */
void initialize(int& lc, int list[])
{
    lc = 0;
    for(int j = 0; j < 26; j++)
        list[j] = 0;
}

/**
 * copyText: Reads and outputs the line
 * @param ifstream& iFile - The file to be read from
 * @param ofstream& oFile - The file to output to
 * @param char& ch - The character to be processed
 * @param int[] list - The array that represents the letter count
 */
void copyText(ifstream& iFile, ofstream& oFile, char& ch, int list[])
{
    while(ch != '\n')               // Process the entire line
    {
        oFile << ch;                // Output the character
        characterCount(ch, list);   // Call the function characterCount
        iFile.get(ch);              // Read the next character
    }
    oFile << ch;                    // Output the newline character
}

/**
 * characterCount: Increments the letterCount array with the appropriately passed character
 * @param char ch - The character to be incremented in the letterCount
 * @param int[] list - The letterCount array
 */
void characterCount(char ch, int list[])
{
    int index = static_cast<int>(toupper(ch)) - static_cast<int>('A');

    if(0 <= index && index < 26)
        list[index]++;
}

/**
 * writeTotal: Outputs the line count and letter count
 * @param ofstream& oFile - The file to be outputted to
 * @param int lc - The lineCount variable
 * @param int[] list - The letterCount array
 */
void writeTotal(ofstream& oFile, int lc, int list[])
{
    oFile << endl << "The number of lines = " << lc << endl;

    for(int index = 0; index < 26; index++)
        oFile << static_cast<char>(index + static_cast<int>('A')) << " count = " << list[index] << endl;
}