/**
 * Alec Him, 2001543593, CS135 1004, Assignment 8
 * Description: Create shapes based on input file
 * Input: AS8Data.txt
 * Output: Text files containing generated shapes
 */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function Prototypes
void openInputFile(ifstream&, string);
bool openOutputFile(ofstream& oFile, string fname);
void outputChar(ofstream&, int count, char l);
void makeEight(ofstream& oFile, int size, char c);
void makeTriangle(ofstream&, int size, char c);
void makeSlash(ofstream& oFile, int size, char c);
string createOutputFilename(string typeString, int labelSize);
bool readRecord(ifstream& iFile, string& typeString, int& lSize, char& c);
string to_string(int);

int main()
{
    // Variables
    ifstream iFile;
    ofstream oFile;
    string ofName;
    string typeString;
    int labelSize = 0;
    char labelChar = 0;
    int recordCount = 0;
    bool done = false;

    cout << "Welcome to Rebel Alliance Computational Support" << endl;
    cout << "\t            x" << endl;
    cout << "\t      x    xxx    x" << endl;
    cout << "\t     x    x x x    x" << endl;
    cout << "\t    x      xxx      x" << endl;
    cout << "\t   xx       x       xx" << endl;
    cout << "\t  xxx      xxx      xxx" << endl;
    cout << "\t  xxxx     xxx     xxxx" << endl;
    cout << "\t  xxxxx    xxx   xxxxx" << endl;
    cout << "\t   xxxxxxxxxxxxxxxxxxx" << endl;
    cout << "\t    xxxxxxxxxxxxxxxxx" << endl;
    cout << "\t     xxxxxxxxxxxxxxx" << endl;
    cout << "\t       xxxxxxxxxxx" << endl;
    cout << endl << endl;

    // Open Input File
    openInputFile(iFile, "Input Specification File: ");

    // Read all records from the specification file.
    while(true)
    {
        // Read all records from the file
        done = readRecord(iFile, typeString, labelSize, labelChar);

        // Verify that it worked, if not exit.
        if(!done)
        {
            cout << "Finished processing input file" << endl;
            cout << recordCount << " Shapes Created " << endl;
            iFile.close();
            oFile.close();
            exit(0);
        }

        recordCount++;

        // Create the output filename
        ofName = createOutputFilename(typeString, labelSize);

        // Open output file
        if(!openOutputFile(oFile, ofName))
        {
            // Output a message that the file successfully opened
            cout << "Output file \"" << ofName << "\" did not open" << endl;
            cout << "File \"" << ofName << "\" not generated" << endl;
        } else
        {
            // Output a message that the file successfully opened
            cout << "File \"" << ofName << "\" successfully opened" << endl;

            // Call appropriate function
            if (typeString == "figureEight")
                makeEight(oFile, labelSize, labelChar);
            else if (typeString == "triangle")
                makeTriangle(oFile, labelSize, labelChar);
            else if (typeString == "slash")
                makeSlash(oFile, labelSize, labelChar);
        }

        // Close the shape file so that we can use re-use oFile variable
        oFile.close();
    }
}

// Function Definitions
/**
 * readRecord: reads iFile inputs and tests whether or not the eof is true
 * @param ifstream iFile - file to be read from
 * @param string typeString - first value from data
 * @param int lSize - second value from data
 * @param char c - final value from data
 * @return bool
 */
bool readRecord(ifstream& iFile, string& typeString, int& lSize, char& c)
{
    iFile >> typeString >> lSize >> c;
    if (iFile.eof())
        return false;
    
    return true;
}

/**
 * createOutputFilename: combines both type and size into string to create oFile name
 * @param string typeString - name of the output file
 * @param int labelSize - assigned numerical value of the output file
 */
string createOutputFilename(string typeString, int labelSize)
{
    string numStr = to_string(static_cast<long long>(labelSize));
    return typeString + "_" + numStr + ".txt";
}

/**
 * openInputFile: prompts user for input file name until correct iFile is opened
 * @param ifstream iFile - 
 * @param string prompt - 
 */
void openInputFile(ifstream& iFile, string prompt)
{
    string fileName = "";

    do
    {
        cout << prompt;
        cin >> fileName;
        iFile.open(fileName);
        if(!iFile.is_open() || cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - File Did Not Open" << endl;
        } else
            break;
    } while(true);
}

/**
 * openOutputFile: verifies whether oFile is opened
 * @param ofstream oFile - file to be created
 * @param string fname - file name to be opened
 */
bool openOutputFile(ofstream& oFile, string fname)
{
    oFile.open(fname);
    if(!oFile.is_open())
        return false;
    
    return true;
}

/**
 * makeEight: creates a figure eight shape based on iFile and displays it in oFile
 * @param ofstream oFile - file to be outputted to
 * @param int size - the size to use for the shape
 * @param char c - the character to be printed
 */
void makeEight(ofstream& oFile, int size, char c)
{
    // Variables
    int width = size, height = size;
    int count = 1;

    oFile << "Symbol: Figure Eight";
    oFile << "  Size: " << size;
    oFile << "  Character: " << "\'" << c << "\'";
    oFile << "\n    ";

    // Output the top scale for width
    for(int w = 0; w < width; w++)
    {
        oFile << count;
        count++;
        if(count > 9)
            count = 0;
    }
    count = 1;
    oFile << endl << endl;

    // Output the scale for height and create shape
    for(int h = 0; h < height; h++)
    {
        oFile << setw(2) << count << "  ";
        if((h + 1) == 1 || (h + 1) == size / 2 || (h + 1) == size)
        {    
            oFile << " ";
            outputChar(oFile, size - 2, c);
        } else
            oFile << c << setw(size - 2) << " " << c;
        oFile << endl;
        count++;
    }

    // Output the bottom scale for width
    count = 1;
    oFile << "\n    ";
    for(int w = 0; w < width; w++)
    {
        oFile << count;
        count++;
        if(count > 9)
            count = 0;
    }
}

/**
 * outputChar: determines which character and the amount is used in each file
 * @param ofstream of - file to be outputted to
 * @param int count - the number of characters to be printed
 * @param char l - the character to be printed
 */
void outputChar(ofstream& of, int count, char l)
{
    for(int i = 0; i < count; i++)
        of << l;
}

/**
 * makeTriangle: creates a triangle shape based on iFile and displays it in oFile
 * @param ofstream oFile - file to be outputted to
 * @param int size - the size to use for the shape
 * @param char c - the character to be printed
 */
void makeTriangle(ofstream& oFile, int size, char c)
{
    // Variables
    int width = size * 2, height = size;
    int count = 1;

    oFile << "Symbol: Triangle";
    oFile << "  Size: " << size;
    oFile << "  Character: " << "\'" << c << "\'";
    oFile << "\n    ";

    // Output the top scale for width
    for(int w = 0; w < width; w++)
    {
        oFile << count;
        count++;
        if(count > 9)
            count = 0;
    }
    count = 1;
    oFile << endl << endl;

    // Output the scale for height and create shape
    for(int h = 0; h < height; h++)
    {
        oFile << setw(2) << count << "  ";
        if((h + 1) == 1)
        {
            if(width % 2 == 0)
                oFile << setw((width / 2) - 1) << " " << c << c;
            else
                oFile << setw(width / 2) << " " << c;
        }    
        else if((h + 1) == size)
            outputChar(oFile, width, c);
        else
        {
            if(width % 2 == 0)
                oFile << setw((width / 2) - 1 - h) << "" << c << setw(2 * h) << " " << c;
            else
                oFile << setw((width / 2) - h) << "" << c << setw(2 * h - 1) << " " << c;  
        }    
        oFile << endl;
        count++;
    }

    // Output the bottom scale for width
    count = 1;
    oFile << "\n    ";
    for(int w = 0; w < width; w++)
    {
        oFile << count;
        count++;
        if(count > 9)
            count = 0;
    }
}

/**
 * makeSlash: creates a slash shape based on iFile and displays it in oFile
 * @param ofstream oFile - file to be outputted to
 * @param int size - the size to use for the shape
 * @param char c - the character to be printed
 */
void makeSlash(ofstream& oFile, int size, char c)
{
    // Variables
    int width = size, height = size;
    int count = 1;

    oFile << "Symbol: Slash";
    oFile << "  Size: " << size;
    oFile << "  Character: " << "\'" << c << "\'";
    oFile << "\n    ";

    // Output the top scale for width
    for(int w = 0; w < width; w++)
    {
        oFile << count;
        count++;
        if(count > 9)
            count = 0;
    }
    count = 1;
    oFile << endl << endl;

    // Output the scale for height and create shape
    for(int h = 0; h < height; h++)
    {
        oFile << setw(2) << count << "  ";
        for(int w = 0; w < width; w++)
            if(h == w)
            {
                oFile << c;
                break;
            }
            else
                oFile << " ";
        oFile << endl;
        count++;
    }

    // Output the bottom scale for width
    count = 1;
    oFile << "\n    ";
    for(int w = 0; w < width; w++)
    {
        oFile << count;
        count++;
        if(count > 9)
            count = 0;
    }
}