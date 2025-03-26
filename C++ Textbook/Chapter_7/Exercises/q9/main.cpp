// Question 9: Format Names
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string firstName = "", middleName = "", lastName = "";
    string dataString = "";
    ifstream iFile;
    ofstream oFile;

    // Open the files
    cout << endl << "Opening the Files..." << endl;
    iFile.open("names.txt");
    oFile.open("formattedNames.txt");

    // Validate Files are Opened
    if(!iFile) 
    {
        cout << "Error opening input file." << endl;
        return 1;
    }
    
    if(!oFile) 
    {
        cout << "Error opening output file." << endl;
        return 1;
    }

    cout << endl << "Processing the Data..." << endl;
    while(getline(iFile, dataString))
    {
        // Process Last Name
        lastName = dataString.substr(0, dataString.find(','));
        dataString.erase(0, dataString.find(',') + 2);

        // Process First Name
        firstName = dataString.substr(0, dataString.find(' '));
        dataString.erase(0, dataString.find(' '));

        // Process Middle Name
        if(!dataString.empty())
            middleName = dataString.substr(1, dataString.length() - 1);

        oFile << firstName << " " << (middleName != "" ? middleName + " " : "") << lastName << endl;

        // Re-initialize the variables
        firstName = "";
        middleName = "";
        lastName = "";
    }
    cout << endl << "Done! Names have been formatted and written to 'formattedNames.txt'" << endl;

    // Close the files
    cout << endl << "Closing the Files..." << endl << endl;
    iFile.close();
    oFile.close();

    return 0;
}