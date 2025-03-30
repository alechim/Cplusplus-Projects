// Example 8-A: Code Detection
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Global Variables
const int MAX_CODE_SIZE = 250;

// Function Prototypes
void readCode(ifstream&, int[], int&, bool&);
void compareCode(ifstream&, ofstream&, const int[], int);

int main()
{
    // Variables
    int codeArray[MAX_CODE_SIZE];
    int codeLength = 0;
    bool lengthCodeOk = false;
    ifstream iCode;
    ofstream oCode;
    char inputFile[51];
    char outputFile[51];

    // Prompt for input
    cout << "Enter the input file name: ";
    cin >> inputFile;
    cout << endl;

    iCode.open(inputFile);
    if(!iCode)
    {
        cout << "Cannot open the input file." << endl;
        return 1;
    }

    cout << "Enter the output file name: ";
    cin >> outputFile;
    cout << endl;

    oCode.open(outputFile);
    
    readCode(iCode, codeArray, codeLength, lengthCodeOk);

    if(lengthCodeOk)
        compareCode(iCode, oCode, codeArray, codeLength);
    else
        cout << "Length of the secret code must be <= " << MAX_CODE_SIZE << endl;

    iCode.close();
    oCode.close();

    return 0;
}

// Function Definitions
/**
 * readCode: Read the secret code
 * @param ifstream& iFile - The file to be read from
 * @param int[] list - The array the code is to be stored in
 * @param int& length - The length of the code
 * @param bool& lenCodeOk - Indicates if code is read successfully and length < 250
 */
void readCode(ifstream& iFile, int list[], int& length, bool& lenCodeOk)
{
    lenCodeOk = true;

    iFile >> length;        // Get the length of the secret code

    if(length > MAX_CODE_SIZE)
    {
        lenCodeOk = false;
        return;
    }

    // Get the secret code
    for(int count = 0; count < length; count++)
        iFile >> list[count];
}

/**
 * compareCode: Compare the codes
 * @param ifstream& iFile - The file to be read from
 * @param ofstream& oFile - The file to be outputted to
 * @param const int[] list - The array the code is to be stored in
 * @param int length - The length of the code
 */
void compareCode(ifstream& iFile, ofstream& oFile, const int list[], int length)
{
    // Variables
    int length2 = 0;
    int digit = 0;
    bool codeOk = true;

    iFile >> length2;

    if(length != length2)
    {
        cout << "The original code and its copy are not of the same length." << endl;
        return;
    }

    oFile << "Code Digit    Code Digit Copy" << endl;

    for(int count = 0; count < length; count++)
    {
        iFile >> digit;
        oFile << setw(5) << list[count] << setw(17) << digit;

        if(digit != list[count])
        {
            oFile << "   code digits are not the same" << endl;
            codeOk = false;
        } else
            oFile << endl;
    }

    if(codeOk)
        oFile << "Message transmitted OK." << endl;
    else
        oFile << "Error in transmission. Retransmit!!" << endl;
}