// Question 7: Menu Driven Football Player Entries
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Structs
struct footballPlayer
{
    string name;
    string position;
    int touchdowns;
    int catches;
    int passingYards;
    int receivingYards;
    int rushingYards;
};

// Function Prototypes
int readData(ifstream&, footballPlayer[]);
void saveData(ofstream&, footballPlayer[]);
void displayRoster(footballPlayer[]);
void displayPlayer(footballPlayer[]);
void updatePlayer(footballPlayer[]);
void changeStatistic(footballPlayer&, int);
void promptInput(string&, string);
void promptInput(int&, string);
void promptInput(int&, string, int, int);

int main()
{
    // Variables
    ifstream iFile;
    ofstream oFile;
    footballPlayer players[10];
    bool quitMenu = false;
    char select = ' ';

    // Open and Verify Input file
    if(readData(iFile, players) == 1)
    {
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        cout << "| Error - Input File did not open." << endl;
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        return 1;
    }

    // Display Menu
    do
    {
        cout << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ');
        cout << "| [D/d] Display Roster" << endl; 
        cout << "| [P/p] Display Player Statistics" << endl; 
        cout << "| [U/u] Update Player Statistics" << endl; 
        cout << "| [Q/q] Quit Program" << endl;
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        cout << "| Please enter a choice: ";
        cin >> select;
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');

        switch(tolower(select))
        {
            case 'd':
                displayRoster(players);
                break;
            case 'p':
                displayPlayer(players);
                break;
            case 'u':
                updatePlayer(players);
                break;
            case 'q':
                quitMenu = true;
                break;
            default: 
                cin.clear();
                cin.ignore(40, '\n');
                cout << "| Invalid Input! Please enter one of the valid choices." << endl;
                cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        }
    } while(!quitMenu);

    do
    {
        cout << "| Would you like to save the roster to a file? [y/n]: ";
        cin >> select;
        if(cin.fail() || (select != 'y' && select != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
            cout << "| Invalid Input! Please enter either 'y' or 'n'." << endl;
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        } else
            break;
    } while(true);
    if(select == 'y')
        saveData(oFile, players);
        
    cout << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ');

    return 0;
}

// Function Definitions
/**
 * readData: Reads player data from an input file into an array of football players
 * @param ifstream& iFile - Reference to the input file stream
 * @param footballPlayer players[] - Array of football player structures to store data
 * @return int - Returns 0 if successful, 1 if file couldn't be opened
 */
int readData(ifstream& iFile, footballPlayer players[])
{
    string firstName = "", lastName = "";

    // Open and Validate if file is opened
    iFile.open("players.txt");
    if(!iFile.is_open())
        return 1;

    // Loop through all 10 players within the text document
    for(int i = 0; i < 10; i++)
    {
        // Read two string values of first and last name
        iFile >> firstName >> lastName;
        players[i].name = firstName + " " + lastName;       // Concatenate strings
        
        // Reinitialize strings to blank
        firstName = "";
        lastName = "";
        
        // Continue to read player data
        iFile >> players[i].position >> players[i].touchdowns >> players[i].catches >> players[i].passingYards >> players[i].receivingYards >> players[i].rushingYards;
    }

    iFile.close();
    return 0;
}

/**
 * saveData: Saves the football player data to an output file
 * @param ofstream& oFile - Reference to the output file stream
 * @param footballPlayer players[] - Array of football player structures to save
 */
void saveData(ofstream& oFile, footballPlayer players[])
{
    // Variables
    string outputFile = "";

    // Prompt and Validate Input
    cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
    promptInput(outputFile, "Enter the name of the file to output to: ");

    // If the output file is the same as the input file, change to a different file name
    if(outputFile == "players.txt")
        outputFile = "players1.txt";

    // Open the output file
    oFile.open(outputFile);

    // Store data into the output file
    for(int i = 0; i < 10; i++)
    {
        oFile << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ');
        oFile << left << setw(19) << "| Player's Name: " << players[i].name << endl;
        oFile << left << setw(19) << "| Position: " << players[i].position << endl;
        oFile << left << setw(19) << "| Touchdowns: " << players[i].touchdowns << endl;
        oFile << left << setw(19) << "| Catches: " << players[i].catches << endl;
        oFile << left << setw(19) << "| Passing Yards: " << players[i].passingYards << endl;
        oFile << left << setw(19) << "| Receiving Yards: " << players[i].receivingYards << endl;
        oFile << left << setw(19) << "| Rushing Yards: " << players[i].rushingYards << endl;
        oFile << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ') << endl;
    }

    // Close the output file
    oFile.close();
}

/**
 * displayRoster: Displays a formatted list of player names from the roster
 * @param footballPlayer players[] - Array of football player structures
 */
void displayRoster(footballPlayer players[])
{
    cout << endl << "+" << setw(7) << setfill('=') << "" << setfill(' ') << " Current Roster " << setw(7) << setfill('=') << "" << "+" << setfill(' ') << endl;
    for(int i = 0; i < 10; i++)
        cout << "| " << left << setw(4) << to_string(i + 1) + ": " << setw(25) << players[i].name << "|" << endl;
    cout << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ') << endl;
}   

/**
 * displayPlayer: Allows user to view detailed statistics for a selected player
 * @param footballPlayer players[] - Array of football player structures
 */
void displayPlayer(footballPlayer players[])
{
    // Variables
    int choice = 0;
    char select = ' ';

    do
    {
        // Prompt and Validate Input - Player Index
        promptInput(choice, "Enter a player to display: ", 1, 10);
        cout << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ');
        cout << left << setw(19) << "| Player's Name: " << players[choice - 1].name << endl;
        cout << left << setw(19) << "| Position: " << players[choice - 1].position << endl;
        cout << left << setw(19) << "| Touchdowns: " << players[choice - 1].touchdowns << endl;
        cout << left << setw(19) << "| Catches: " << players[choice - 1].catches << endl;
        cout << left << setw(19) << "| Passing Yards: " << players[choice - 1].passingYards << endl;
        cout << left << setw(19) << "| Receiving Yards: " << players[choice - 1].receivingYards << endl;
        cout << left << setw(19) << "| Rushing Yards: " << players[choice - 1].rushingYards << endl;
        cout << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ');

        // Prompt and Validate Input - Repeat Function
        do
        {
            cout << "| Would you like to display another player's information? [y/n]: ";
            cin >> select;
            if(cin.fail() || (select != 'y' && select != 'n'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
                cout << "| Invalid Input! Please enter either 'y' or 'n'." << endl;
                cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
            } else
                break;
        } while(true);
    } while(select != 'n');
}

/**
 * updatePlayer: Allows user to modify statistics for a selected player
 * @param footballPlayer players[] - Array of football player structures
 */
void updatePlayer(footballPlayer players[])
{
    // Variables
    int index = 0, choice = 0;
    char select = ' ';

    do
    {
        // Prompt and Validate Input - Player Index
        promptInput(index, "Enter a player to update: ", 1, 10);

        // Display Secondary Menu
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        cout << "| 1. Name" << endl; 
        cout << "| 2. Position" << endl; 
        cout << "| 3. Touchdowns" << endl; 
        cout << "| 4. Catches" << endl; 
        cout << "| 5. Passing Yards" << endl; 
        cout << "| 6. Receiving Yards" << endl; 
        cout << "| 7. Rushing Yards" << endl; 
        cout << "| 8. All" << endl; 
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');

        // Prompt and Validate Input - Statistic Choice
        promptInput(choice, "Please enter one of the choices above: ", 1, 8);
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        changeStatistic(players[index - 1], choice);
        
        // Prompt and Validate Input - Repeat Function
        do
        {
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
            cout << "| Would you like to update another player's information? [y/n]: ";
            cin >> select;
            if(cin.fail() || (select != 'y' && select != 'n'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
                cout << "Invalid Input! Please enter either 'y' or 'n'." << endl;
                cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
            } else
                break;
        } while(true);
    } while(select != 'n');
}

/**
 * changeStatistic: Updates specific statistics for a player based on user input
 * @param footballPlayer& player - Reference to the football player to be updated
 * @param int choice - Integer representing which statistic to update (1-7) or all (8)
 */
void changeStatistic(footballPlayer& player, int choice)
{
    // Variables
    string firstName = "", lastName = "";

    if(choice == 1 || choice == 8)
    {
        promptInput(firstName, "Enter the player's first name: ");
        promptInput(lastName, "Enter the player's last name: ");
        player.name = firstName + " " + lastName;
    }
    if(choice == 2 || choice == 8)
        promptInput(player.position, "Enter the player's position: ");
    if(choice == 3 || choice == 8)
        promptInput(player.touchdowns, "Enter the player's touchdown count: ");
    if(choice == 4 || choice == 8)
        promptInput(player.catches, "Enter the player's amount of catches: ");
    if(choice == 5 || choice == 8)
        promptInput(player.passingYards, "Enter the player's total passing yards");
    if(choice == 6 || choice == 8)
        promptInput(player.receivingYards, "Enter the player's total receiving yards: ");
    if(choice == 7 || choice == 8)
        promptInput(player.rushingYards, "Enter the player's total rushing yards: ");
}

/**
 * promptInput: Gets and validates a string input from the user
 * @param string& value - Reference to the string variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(string& value, string prompt)
{
    do
    {
        cout << "| " << prompt;
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
            cout << "Invalid Input! Please enter a valid string value." << endl;
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
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
        cout << "| " << prompt;
        cin >> value;
        if(cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        } else
            break;
    } while(true);
}

/**
 * promptInput: Gets and validates an integer input within a specified range
 * @param int& value - Reference to the integer variable to store the input
 * @param string prompt - Message to display to the user
 * @param int min - Minimum acceptable value
 * @param int max - Maximum acceptable value
 */
void promptInput(int& value, string prompt, int min, int max)
{
    do
    {
        cout << "| " << prompt;
        cin >> value;
        if(cin.fail() || value < min || value > max)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
            cout << "Invalid Input! Please enter one of the valid choices." << endl;
            cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        } else
            break;
    } while(true);
}