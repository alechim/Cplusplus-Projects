// Question 8: String Functions Censorship
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string firstName = "", lastName = "";
    string socialSecurity = "";
    string userID = "", password = "";
    ifstream iFile;
    ofstream oFile;

    // Open the files
    cout << endl << "Opening the Files..." << endl;
    iFile.open("rawInput.txt");
    oFile.open("censoredData.txt");

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
    while(iFile >> firstName >> lastName >> socialSecurity >> userID >> password)
    {
        // Censor the Social Security Number
        socialSecurity.replace(0, socialSecurity.length(), "xxx-xx-xxx");

        // Censor the password - create a string of 'x' characters of the same length
        string passwordMask = "";
        passwordMask.append(password.length(), 'x');
        password.replace(0, password.length(), passwordMask);

        oFile << firstName << " " << lastName << " " << socialSecurity << " " << userID << " " << password << endl;
    }
    cout << endl << "Done!" << endl;

    // Close the files
    cout << endl << "Closing the Files..." << endl;
    iFile.close();
    oFile.close();

    cout << endl << "Data has been censored and written to censoredData.txt" << endl;

    return 0;
}