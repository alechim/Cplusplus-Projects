/**
 * Alec Him, 2001543593, CS 202 1004, Assignment 1
 * Description: Parse and Sort Cars CSV file
 * Input: 0-13
 * Output: Make, Model, MPG, Cylinders, Displacement, Horsepower, Weight, Year, Origin
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Car Struct
struct Car 
{
    string make;                // Manufacturer
    string model;               // Model
    double mpg;                 // Fuel Efficiency in MPG
    unsigned int cylinders;     // Number of cylinders
    unsigned int displacement;  // Displacement in cu
    unsigned int horsepower;    // Horsepower in hp
    unsigned int weight;        // Weight in lbs
    unsigned int year;          // Model year in yy format
    string origin;              // Country/Continent of Origin
};

// Function Prototypes
int readFile(string, vector<Car>&);
void printCar(ostream&, const Car);
void sortListByMPG(vector<Car>&);
void sortListByHP(vector<Car>&);
void listByMakeMPG(const vector<Car>);
void listByMakeHP(const vector<Car>);
void saveToFile(const vector<Car>, string);
int selectionMenu();

int main(int argc, char *argv[])
{
    // Check if program is run correctly
    if(argc != 2)
    {
        cout << "ERROR: Invalid Arguments \nUsage: ./asgn1 <filename>" << endl;
        return EXIT_FAILURE;
    }

    // Variables
    vector<Car> cars;
    int n_cars = 0, ch = 0;
    string fileName = "";

    n_cars = readFile(string(argv[1]), cars);
    if(n_cars == -1)
        return -1;

    cout << "Read " << n_cars << " cars from file." << endl;

    do
    {
        ch = selectionMenu();
        switch(ch)
        {
            case 1:
                listByMakeMPG(cars);
                break;
            case 2:
                listByMakeHP(cars);
                break;
            case 3:
                cout << "Enter filename: ";
                cin >> fileName;
                fileName += ".txt";
                saveToFile(cars, fileName);
                cout << "All cars saved to file \"" << fileName << "\"" << endl;
                break;
            default:
                break;
        }
    } while(ch != 0);
    
    return EXIT_SUCCESS;
}

// Function Definitions
/**
 * printCar: outputs data to the file
 * @param ofstream& out - 
 * @param const Car car - 
 */
void printCar(ofstream& out, const Car car)
{
    out << "Make : " << car.make << "\n";
    out << "Model : " << car.model << "\n";
    out << "Fuel Efficiency (MPG) : " << car.mpg << "\n";
    out << "Cylinders : " << car.cylinders << "\n";
    out << "Displacement (cu) : " << car.displacement << "\n";
    out << "Horsepower (hp) : " << car.horsepower << "\n";
    out << "Model : 19" << car.year << "\n";
    out << "Origin: " << car.origin << "\n";
}

/**
 * readFile: reads in the input file 'car.sv' and stores values into the vector
 * @param string file - 
 * @param vector<Car>& carVector - 
 */
int readFile(string file, vector<Car>& carVector)
{
    // Variables
    string str = "";
    ifstream iFile;
    int count = 0;
    Car carType;

    // Open the file
    iFile.open(file);

    // Verify if file is open
    if(!iFile.is_open())
    {
        cout << "Error - File did not open." << endl;
        return -1;
    }

    // Skip the header row
    getline(iFile, str);

    // Read the entire file
    while(getline(iFile, str))
    {
        stringstream sstream(str);
        vector<string> strVector;
        string token = "";

        while(getline(sstream, token, ';'))
            strVector.push_back(token);

        // Store values into car struct
        carType.make = strVector[0].substr(0, strVector[0].find(' '));
        carType.model = strVector[0].substr(strVector[0].find(' ') + 1);
        carType.mpg = stod(strVector[1]);
        carType.cylinders = stoul(strVector[2]);
        carType.displacement = stoul(strVector[3]);
        carType.horsepower = stoul(strVector[4]);
        carType.weight = stoul(strVector[5]);
        carType.year = stoul(strVector[6]);
        carType.origin = strVector[7];

        // Push the struct into the vector
        carVector.push_back(carType);

        count++;
    }

    // Close the file
    iFile.close();

    return count;
}

/**
 * selectionMenu: displays the prompt for user input and chooses function based on input
 * @return int
 */
int selectionMenu()
{
    // Variables
    int choice = 0;

    // Display Menu
    cout << "**** SELECT OPTION ****" << endl;
    cout << "1.  Sort by MPG" << endl;
    cout << "2.  Sort by Horsepower" << endl;
    cout << "3.  Save all cars to file" << endl;
    cout << "0.  Exit" << endl;
    cout << "***********************" << endl;

    // Prompts the user to enter a choice
    do
    {
        cout << "Enter number: ";
        cin >> choice;

        if(cin.fail() || choice < 0 || choice > 3)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Please try again." << endl;
        } else
            break;
    } while(true);
    
    return choice;
}

/**
 * listByMakeMPG: displays the list of available car manufacturers by MPG and prompts user to select one
 * @param const vector<Car> carVector - 
 */
void listByMakeMPG(const vector<Car> carVector)
{
    // Variables
    int select = 0;
    char confirm = ' ';
    string file = "";
    vector<Car> changedVector;

    // Display Menu
    cout << "Select Make:" << endl;
    cout << "1. : All Vehicles" << endl;
    for(int i = 0; i < 18; i++)
        cout << i + 2 << ". : " << carVector[i].make << endl;

    // Prompts the user to enter a number for the Make of the Car
    do
    {
        cout << "\nEnter number: ";
        cin >> select;
        
        // Input Validation
        if(cin.fail() || select < 1 || select > 18)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Please try again." << endl;
        } else
            break;
    } while(true);
    
    string make = "";
    if(select == 1)
        changedVector = carVector;
    else
    {
        make = carVector[select - 2].make;
        for(size_t i = 0; i < carVector.size(); i++)
            if(make == carVector[i].make)
                changedVector.push_back(carVector[i]);
    }
        
    sortListByMPG(changedVector);
    cout << "All cars " << (make != "" ? "made by " + make : "") << " sorted by MPG...\n" << endl;

    // Prompts user whether or not to save the file
    do
    {
        cout << "Save to file? [y/n]: ";
        cin >> confirm;

        switch(confirm)
        {
            case 'y':
                cout << "Enter filename : ";
                cin >> file;
                file += ".txt";
                saveToFile(changedVector, file);
                cout << "All cars saved to file \"" << file << "\"" << endl;
                return;
            case 'n':
                return;
            default:
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Error - Please try again." << endl;
        }
    } while(true);
}

/**
 * sortListByMPG: sorts the listByMakeMPG function by using a bubble sort
 * @param vector<Car>& carVector - 
 */
void sortListByMPG(vector<Car>& carVector)
{
    for(size_t i = 0; i < carVector.size() - 1; i++)
        for(size_t j = 0; j < carVector.size() - i - 1; j++)
            if(carVector[j].mpg > carVector[j + 1].mpg)
                swap(carVector[j].mpg, carVector[j + 1].mpg);
}

/**
 * listByMakeHP: displays the list of available car manufacturers by HP and prompts the user to select one
 * @param const vector<Car> carVector - 
 */
void listByMakeHP(const vector<Car> carVector)
{
    // Variables
    int select = 0;
    char confirm = ' ';
    string file = "";
    vector<Car> changedVector;

    // Display Menu
    cout << "Select Make:" << endl;
    cout << "1. : All Vehicles" << endl;
    for(int i = 0; i < 18; i++)
        cout << i + 2 << ". : " << carVector[i].make << endl;

    // Prompts the user to enter a number for the Make of the Car
    do
    {
        cout << "\nEnter number: ";
        cin >> select;
        
        // Input Validation
        if(cin.fail() || select < 1 || select > 19)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error - Please try again." << endl;
        } else
            break;
    } while(true);
    
    string make = "";
    if(select == 1)
        changedVector = carVector;
    else
    {
        make = carVector[select - 2].make;
        for(size_t i = 0; i < carVector.size(); i++)
            if(make == carVector[i].make)
                changedVector.push_back(carVector[i]);
    }
        
    sortListByHP(changedVector);
    cout << "All cars " << (make != "" ? "made by " + make : "") << " sorted by MPG...\n" << endl;

    // Prompts user whether or not to save the file
    do
    {
        cout << "Save to file? [y/n]: ";
        cin >> confirm;

        switch(confirm)
        {
            case 'y':
                cout << "Enter filename : ";
                cin >> file;
                file += ".txt";
                saveToFile(changedVector, file);
                cout << "All cars saved to file \"" << file << "\"" << endl;
                return;
            case 'n':
                return;
            default:
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Error - Please try again." << endl;
        }
    } while(true);
}

/**
 * sortListByHP: sorts the listBYMakeHP function by using a bubble sort
 * @param vector<Car> carVector
 */
void sortListByHP(vector<Car>& carVector)
{
    for(size_t i = 0; i < carVector.size() - 1; i++)
        for(size_t j = 0; j < carVector.size() - i - 1; j++)
            if(carVector[j].horsepower > carVector[j + 1].horsepower)
                swap(carVector[j].horsepower, carVector[j + 1].horsepower);
}

/**
 * saveToFile: prompts the user to name the file and creates the file 
 * @param const vector<Car> carVector - 
 * @param string saveFile - 
 */
void saveToFile(const vector<Car> carVector, string saveFile)
{
    ofstream oFile;
    oFile.open(saveFile);
    oFile << "+=========+" << endl;
    for(size_t i = 0; i < carVector.size(); i++)
    {
        printCar(oFile, carVector[i]);
        oFile << "+=========+" << endl;
    }
}