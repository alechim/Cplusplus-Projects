// Example 9-A: Sales Data Analysis
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Global Constants
const int NO_OF_SALES_PERSON = 6;

// Structs
struct salesPersonRec
{
    string ID;                  // Salesperson's ID
    double saleByQuarter[4];    // Array to store the total sales for each quarter
    double totalSale;           // Salesperson's yearly sales amount
};

// Function Prototypes
void initialize(ifstream&, salesPersonRec[], int);
void getData(ifstream&, salesPersonRec[], int);
void saleByQuarter(salesPersonRec[], int, double[]);
void totalSaleByPerson(salesPersonRec[], int);
void printReport(ofstream&, salesPersonRec[], int, double[]);
void maxSaleByPerson(ofstream&, salesPersonRec[], int);
void maxSaleByQuarter(ofstream&, double[]);

int main()
{
    // Variables
    ifstream inFile;
    ofstream outFile;
    string inputFile = "";
    string outputFile = "";
    double totalSaleByQuarter[4];
    salesPersonRec salesPersonList[NO_OF_SALES_PERSON];

    cout << "Enter the salesPerson ID file name: ";
    cin >> inputFile;
    cout << endl;

    inFile.open(inputFile.c_str());

    if(!inFile)
    {
        cout << "Cannot open the input file." << endl;
        return 1;
    }

    initialize(inFile, salesPersonList, NO_OF_SALES_PERSON);

    inFile.close();
    inFile.clear();

    cout << "Enter the sales data file name: ";
    cin >> inputFile;
    cout << endl;

    inFile.open(inputFile.c_str());

    if(!inFile)
    {
        cout << "Cannot open the input file." << endl;
        return 1;
    }

    cout << "Enter the output file name: ";
    cin >> outputFile;
    cout << endl;

    outFile.open(outputFile.c_str());
    outFile << fixed << showpoint << setprecision(2);

    getData(inFile, salesPersonList, NO_OF_SALES_PERSON);
    saleByQuarter(salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);
    totalSaleByPerson(salesPersonList, NO_OF_SALES_PERSON);

    printReport(outFile, salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);
    maxSaleByPerson(outFile, salesPersonList, NO_OF_SALES_PERSON);
    maxSaleByQuarter(outFile, totalSaleByQuarter);

    inFile.close();
    outFile.close();

    return 0;
}

// Function Definitions
/**
 * initialize: Reads the salesperson's ID from the file, stores the ID into the array and initializes the quarterly sales and total sales
 * amount for each salesperson to 0 
 */
void initialize(ifstream& inData, salesPersonRec list[], int listSize)
{
    for(int index = 0; index < listSize; index++)
    {
        inData >> list[index].ID;       // Get salesperson's ID

        for(int quarter = 0; quarter < 4; quarter++)
            list[index].saleByQuarter[quarter] = 0.0;
        
        list[index].totalSale = 0.0;
    }
}   // End intialize

/**
 * getData: reads sales data from input file and stores the appropriate information in the array
 */
void getData(ifstream& inFile, salesPersonRec list[], int listSize)
{
    // Variables
    int index = 0;
    int quarter = 0;
    string sID = "";
    int month = 0;
    double amount = 0.0;

    inFile >> sID;          // Get salesperson's ID

    while(inFile)
    {
        inFile >> month >> amount;      // Get the sale month and the sales amount
        
        for(index = 0; index < listSize; index++)
            if(sID == list[index].ID)
                break;
            
        if(1 <= month && month <= 3)
            quarter = 0;
        else if(4 <= month && month <= 6)
            quarter = 1;
        else if(7 <= month && month <= 9)
            quarter = 2;
        else
            quarter = 3;
        
        if(index < listSize)
            list[index].saleByQuarter[quarter] += amount;
        else
            cout << "Invalid salesperson's ID." << endl;
        
        inFile >> sID;
           
    }   // End while
}   // End getData

/**
 * saleByQuarter: Finds the company's total sales for each quarter
 */
void saleByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[])
{
    for(int quarter = 0; quarter < 4; quarter++)
        totalByQuarter[quarter] = 0.0;
    
    for(int quarter = 0; quarter < 4; quarter++)
        for(int index = 0; index < listSize; index++)
            totalByQuarter[quarter] += list[index].saleByQuarter[quarter];
}   // End saleByQuarter

/**
 * totalSaleByPerson: Find each salesperson's yearly sales amount
 */
void totalSaleByPerson(salesPersonRec list[], int listSize)
{
    for(int index = 0; index < listSize; index++)
        for(int quarter = 0; quarter < 4; quarter++)
            list[index].totalSale += list[index].saleByQuarter[quarter];
}   // End totalSaleByPerson

/**
 * printReport: Prints the annual report in a specified format
 */
void printReport(ofstream& outFile, salesPersonRec list[], int listSize, double saleByQuarter[])
{
    outFile << "----------- Annual Sales Report -------------" << endl << endl;
    outFile << " ID         QT1       QT2       QT3       QT4       Total" << endl;
    outFile << "_____________________________________________________________" << endl;

    for(int index = 0; index < listSize; index++)
    {
        outFile << list[index].ID << " ";

        for(int quarter = 0; quarter < 4; quarter++)
            outFile << setw(10) << list[index].saleByQuarter[quarter];
        
        outFile << setw(12) << list[index].totalSale << endl;
    }

    outFile << "Total ";
    for(int quarter = 0; quarter < 4; quarter++)
        outFile << setw(10) << saleByQuarter[quarter];
    
    outFile << endl << endl;
}   // End printReport

/**
 * maxSaleByPerson: Prints the name of the salesperson who produces the maximum sales amount
 */
void maxSaleByPerson(ofstream& outData, salesPersonRec list[], int listSize)
{
    int maxIndex = 0;

    for(int index = 1; index < listSize; index++)
        if(list[maxIndex].totalSale < list[index].totalSale)
            maxIndex = index;

    outData << "Max Sale by SalesPerson: ID = " << list[maxIndex].ID << ", Amount = $" << list[maxIndex].totalSale << endl;
}   // end maxSaleByPerson

/**
 * maxSaleByQuarter: Prints the quarter in which the maximum sales were made
 */
void maxSaleByQuarter(ofstream& outData, double saleByQuarter[])
{
    int maxIndex = 0;

    for(int quarter = 0; quarter < 4; quarter++)
        if(saleByQuarter[maxIndex] < saleByQuarter[quarter])
            maxIndex = quarter;
    
    outData << "Max Sale By Quarter: Quarter = " << maxIndex + 1 << ", Amount = $" << saleByQuarter[maxIndex] << endl;
}   // End maxSaleByQuarter