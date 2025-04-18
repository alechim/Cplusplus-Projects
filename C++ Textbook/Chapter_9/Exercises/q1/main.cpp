// Question 1: 
#include <iostream>

using namespace std;

// Structs
struct computerType
{
    string motherboard;
    string cpu;
    string gpu;
    int ram;
    int wattage;
};

// Function Prototypes
void promptInput(string&, string);
void promptInput(int&, string);

int main()
{
    computerType computer;

    // Prompt Inputs
    cout << "+======================================" << endl;
    promptInput(computer.motherboard, "| Please enter the motherboard of the computer: ");
    promptInput(computer.cpu, "| Please enter the CPU of the computer: ");
    promptInput(computer.gpu, "| Please enter the GPU of the computer: ");
    promptInput(computer.ram, "| Please enter the total GB of RAM in the computer: ");
    promptInput(computer.wattage, "| Please enter the total wattage of the computer: ");

    // Display Results
    cout << "+======================================" << endl;
    cout << "| Computer Specs - " << endl;
    cout << "+--------------------------------------" << endl;
    cout << "| Motherboard: " << computer.motherboard << endl;
    cout << "| CPU: " << computer.cpu << endl;
    cout << "| GPU: " << computer.gpu << endl;
    cout << "| RAM: " << computer.ram << " GB" << endl;
    cout << "| Wattage: " << computer.wattage << " W" << endl;
    cout << "+======================================" << endl;

    return 0;
}

// Function Definitions
/**
 * promptInput: Gets and validates a string input from the user
 * @param string& value - Reference to the string variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(string& value, string prompt)
{
    do
    {   
        cout << prompt;
        getline(cin, value);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a string value." << endl;
        } else
            break;
    } while(true);
}

/**
 * promptInput: Gets and validates a positive integer input from the user
 * @param int& value - Reference to the integer variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(int& value, string prompt)
{
    do
    {   
        cout << prompt;
        cin >> value;

        if(cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a string value." << endl;
        } else
            break;
    } while(true);
}