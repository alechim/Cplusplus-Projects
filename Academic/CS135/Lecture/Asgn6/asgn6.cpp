/* Alec Him, 2001543593, CS135 1004, Assignment 6
 * Description: Distribute droids (randomly) to either a User or Admin
 * Input: c.txt and out.txt
 * Output: Droid Number and Droid Type 
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes
void assignModel(string name1, string name2, int value, int count[4], string& type, string& model);
void outCount(ofstream& oFile, string name1, string name2, int droneCount, string type, string model, int count[4]);

int main()
{
    // Variables
    int recordCount = 0;
    int droneCount = 0;
    // 0: admin, 1: main, 2: proto, 3: astro
    int count[4] = {0, 0, 0, 0};
    int value = rand() % 4; // random number limited in range from 0-3
    string inFile = "c.txt";
    string outFile = "out.txt";
    ifstream iFile;
    ofstream oFile;
    char y_n;
    string name1 = "", name2 = "", type = "", model = "";

    // Display Menu / Input Files
    // - Open Input File
    do
    {
        cout << "Enter file name to process: ";
        cin >> inFile;

        if(inFile != "c.txt")
            cout << "File " << inFile << " did not open." << endl;
        else
            iFile.open(inFile);
    } while(!iFile.is_open());

    // - Open Output File
    do
    {
        cout << "Enter output file name: ";
        cin >> outFile;

        if(outFile != "out.txt")
            cout << "File " << outFile << " did not open." << endl;
        else
            oFile.open(outFile);
    } while(!oFile.is_open());

    // Records Processing
    do
    {
        cout << "Would you like to process all the records in the file? (y/n): ";
        cin >> y_n;

        if(y_n != 'y' and y_n != 'n')
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Character - Please Try Again." << endl;
        }
    } while(y_n != 'y' and y_n != 'n');
    
    if(y_n == 'y')
    {
        while(iFile >> name1 >> name2)
        {
            assignModel(name1, name2, value, count, type, model);
            value = rand() % 4;
            droneCount++;
            outCount(oFile, name1, name2, droneCount, type, model, count);
        }
        cout << "End of File detected, " << count << " records read" << endl;
    } else
    {
        // Prompt for No. of Records
        do
        {
            cout << "Enter the number of records to process: ";
            cin >> recordCount;
            if(cin.fail() || recordCount <= 0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "\nXXXXXXXXXX Error-non numeric or negative value, try again\n" << endl;
            } else
                break;
        } while(true);
        
        int temp = recordCount;
        while(temp > 0 && iFile >> name1 >> name2)
        {
            assignModel(name1, name2, value, count, type, model);
            value = rand() % 4;
            droneCount++;
            temp--;
            outCount(oFile, name1, name2, droneCount, type, model, count);
        }
        if(temp != 0 && iFile.eof())
            cout << "End of File detected, " << count << " records read" << endl;
        else
            cout << "Maximum requested record count of " << recordCount << " reached" << endl;
    
    }

    // End Menu
    cout << "\nThank you for using Rebel Alliance Computational Support" << endl;
    cout << "May the Force be with you!" << endl;

    cout << "            x            " << endl;
    cout << "      x    xxx    x      " << endl;
    cout << "     x    x x x    x     " << endl;
    cout << "    x      xxx      x    " << endl;
    cout << "   xx       x       xx   " << endl;
    cout << "  xxx      xxx      xxx  " << endl;
    cout << "  xxxx     xxx     xxxx  " << endl;
    cout << "  xxxxx    xxx    xxxxx  " << endl;
    cout << "   xxxxxxxxxxxxxxxxxxx   " << endl;
    cout << "    xxxxxxxxxxxxxxxxx    " << endl;
    cout << "     xxxxxxxxxxxxxxx     " << endl;
    cout << "      xxxxxxxxxxxxx      " << endl;

    // Close the files
    iFile.close();
    oFile.close();

    return 0;
}

// Function Definitions
void assignModel(string name1, string name2, int value, int count[4], string& type, string& model)
{
    // Enumeration Types
    enum DROID_TYPES { ADMINISTRATIVE, MAINTENANCE, PROTOCOL, ASTROMECH };
    enum ADMINISTRATIVE_TYPES { ET_74, XA_540, a3D_4X };
    enum MAINTENANCE_TYPES { F1_DX, EB_89, CB_2B, SA_45 };
    enum PROTOCOL_TYPES { C3PO, L80, SA_5, RA_7 };
    enum ASTROMECH_TYPES { M4_Y6, BB_8, D3_S5, R2_D2 };

    DROID_TYPES droid = ADMINISTRATIVE;
    droid = static_cast<DROID_TYPES>(value);

    ADMINISTRATIVE_TYPES admin = ET_74;
    admin = static_cast<ADMINISTRATIVE_TYPES>(value);

    MAINTENANCE_TYPES main = F1_DX;
    main = static_cast<MAINTENANCE_TYPES>(value);

    PROTOCOL_TYPES proto = C3PO;
    proto = static_cast<PROTOCOL_TYPES>(value);

    ASTROMECH_TYPES astro = M4_Y6;
    astro = static_cast<ASTROMECH_TYPES>(value);

    if(name1 == "Admiral" || name1 == "Captain" || name1 == "Commander"
    || name1 == "Darth" || name1 == "Emperor" || name1 == "Queen")
        droid = ADMINISTRATIVE;

    switch(droid)
    {
        case ADMINISTRATIVE:
            type = "administrative";
            switch(admin)
            {
                case ET_74:
                    model = "ET-74";
                    break;
                case XA_540:
                    model = "XA-540";
                    break;
                case a3D_4X:
                    model = "a3D-4X";
            }
            count[0]++;
            break;
        case MAINTENANCE:
            type = "maintenance";
            switch(main)
            {
                case F1_DX:
                    model = "F1-DX";
                    break;
                case EB_89:
                    model = "EB-89";
                    break;
                case CB_2B:
                    model = "CB-2B";
                    break;
                case SA_45:
                    model = "SA-45";
            }
            count[1]++;
            break;
        case PROTOCOL:
            type = "protocol";
            switch(proto)
            {
                case C3PO:
                    model = "C3PO";
                    break;
                case L80:
                    model = "L80";
                    break;
                case SA_5:
                    model = "SA-5";
                    break;
                case RA_7:
                    model = "RA-7";
            }
            count[2]++;
            break;
        case ASTROMECH:
            type = "astromech";
            switch(astro)
            {
                case M4_Y6:
                    model = "M4-Y6";
                    break;
                case BB_8:
                    model = "BB-8";
                    break;
                case D3_S5:
                    model = "D3_S5";
                    break;
                case R2_D2:
                    model = "R2-D2";
            }
            count[3]++;
    }
}

void outCount(ofstream& oFile, string name1, string name2, int droneCount, string type, string model, int count[4])
{
    oFile << left << setw(9) << "Number";
    oFile << setw(13) << "First Name";
    oFile << setw(14) << "Last Name";
    oFile << setw(16) << "Droid Type";
    oFile << setw(8) << "Model";
    oFile << "\n------------------------------------------------------------" << endl;

    oFile << setw(4) << setfill('0') << droneCount;  
    oFile << setfill(' ');  
    oFile << setw(5) << ""; 
    oFile << left << setw(13) << name1;  
    oFile << setw(14) << name2; 
    oFile << setw(16) << type;  
    oFile << setw(8) << model; 
    oFile << endl;

    oFile << "*********************" << endl;
    oFile << "Assigned Droid Count " << endl;
    oFile << "*********************" << endl;

    oFile << "Astromech:" << right << setw(10) << count[3] << endl;
    oFile << "Maintenance:" << setw(8) << count[1] << endl;
    oFile << "Protocol:" << setw(11) << count[2] << endl;
    oFile << "Administrative:" << setw(5) << count[0] << endl << endl << endl;

    oFile << "Total Droids Required" << setw(6) << droneCount << endl;
}