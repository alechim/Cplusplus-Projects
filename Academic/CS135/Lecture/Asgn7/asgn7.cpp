/**
 * Alec Him, 2001543593, CS135 1004, Assignment 7
 * Description: Create a game where user attempts to guess the correct password.
 * Input: Start, Help, Exit, Difficulty, Numerical Passcode
 * Output: Display Menu, Difficulty Menu, Attempt Menu, Correct, Too High, Too Low
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes
void setupGame();
void foldCase(string&);
void startGame(string);
void displayHelp();

int main(int argc, char* argv[])
{
    // Normal Mode
    if(argc == 1)
        srand(time(NULL));
    else
    {
        // Debug Mode
        string arg = argv[1];
        if(argc == 2 && arg == "debug")
            srand(0);
        else
        {
            cout << "To start the program in debug mode: \n" << argv[0] << " debug\n";
            return -1;
        }
    }

    // Variables
    string choice = "";

    // Display Main Menu
    do
    {
        cout << "+--------------------+\n";
        cout << "| Main Menu          |\n";
        cout << "+--------------------+\n";
        cout << "| [Start] Simulation |\n";
        cout << "| [Help] Guide       |\n";
        cout << "| [Quit]             |\n";
        cout << "+--------------------+\n";
        cout << endl;

        // Prompt for Input and Validate Input
        cout << "Select a menu option: ";
        cin >> choice;

        foldCase(choice);

        if(choice == "start")
            setupGame();
        else if (choice == "help")
            displayHelp();
        else if (choice == "quit")
            break;
        else 
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Menu Selection.\n";
        }
    } while(choice != "quit");
    
    return 0;
}

// Function Definitions
/**
 * setupGame: Provides and prompts user for input for expected actions
 */
void setupGame()
{
    string difficulty = "";

    // Prompt User and Validate Input
    do
    {
        // Display Menu
        cout << "+--------------------+\n";
        cout << "| Select Difficulty  |\n";
        cout << "+--------------------+\n";
        cout << "| [Easy]             |\n";
        cout << "| [Medium]           |\n";
        cout << "| [Hard]             |\n";
        cout << "+--------------------+\n";
        cout << "| [Help]             |\n";
        cout << "| [Main] Menu        |\n";
        cout << "+--------------------+\n";
        cout << endl;

        cout << "Select a menu option: ";
        cin >> difficulty;

        foldCase(difficulty);

        if(difficulty == "easy" || difficulty == "medium" || difficulty == "hard")
            startGame(difficulty);
        else if(difficulty == "help")
            displayHelp();
        else if(difficulty == "main")
            break;
        else
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Difficulty Selection.\n";
        }
    } while(difficulty != "main");
}

/**
 * foldCase: converts passed string to all lowercase characters
 * @param string lower - string to be converted to lowercase
 */
void foldCase(string& lower)
{
    for(size_t i = 0; i < lower.length(); i++)
        lower[i] = tolower(lower[i]);
}

/**
 * startGame: contains all the logic meant to play the game
 * @param string level - passed string to determine difficulty (easy, medium, hard)
 */
void startGame(string level)
{
    // Variables
    int maxAttempt = 0, correct = 0;
    int totalDig[5], passcode[5];
    int high = 0, low = 0;
    int count = 0, range = 0;

    // Display Menu
    cout << "+--------------------+\n";
    cout << "| Additional Options |\n";
    cout << "+--------------------+\n";
    cout << "| [Help]             |\n";
    cout << "| [Main] Menu        |\n";
    cout << "+--------------------+\n";
    cout << endl;

    // Determine variables based on selected level
    if(level == "easy")
    {
        for(int i = 0; i < 3; i++)
            totalDig[i] = rand() % 3 + 1;
        maxAttempt = 10;
        count = 3;
        range = 3;
    } else if(level == "medium")
    {
        for(int i = 0; i < 5; i++)
            totalDig[i] = rand() % 5 + 1;
        maxAttempt = 15;
        count = 5;
        range = 5;
    } else if(level == "hard")
    {
        for(int i = 0; i < 5; i++)
            totalDig[i] = rand() % 9 + 1;
        maxAttempt = 20;
        count = 5;
        range = 9;
    }

    // Game
    for(int i = 0; i < maxAttempt; i++)
    {
        // Prompt for Input
        cout << "Guess Code (" << count << " Digits, 1-" << range << ") ";
        cout << "[Attempts: " << i + 1 << "/" << maxAttempt << "]: ";
        
        // Input Validation
        int j = 0;
        do
        {
            cin >> passcode[j];
            if(cin.fail() || passcode[j] < 1 || passcode[j] > range)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Error: Invalid Code Format." << endl;
            } else
                j++;
        } while(j < count);
        
        // Value Check
        for(int k = 0; k < count; k++)
        {
            if(totalDig[k] == passcode[k])
                correct++;
            else if(totalDig[k] < passcode[k])
                high++;
            else
                low++;
        }

        // Display Results of Current Iteration
        if(correct == count)
        {
            cout << endl << "Code Found Successfully: ";
            for(int i = 0; i < count; i++)
                cout << totalDig[i];
            cout << endl;

            return;
        } else
        {
            cout << "+--------------------+\n";
            cout << "|      Correct |    " << correct << " |\n";
            cout << "|     Too High |    " << high << " |\n";
            cout << "|      Too Low |    " << low << " |\n";
            cout << "+--------------------+\n";
            
            correct = 0;
            high = 0;
            low = 0;
        }
    }
    cout << "Abort Mission: Imperial security alerted to intrustion." << endl;
    cout << "Code was ";
    for(int i = 0; i < count; i++)
        cout << totalDig[i];
    cout << endl;

    return;
}

/**
 * displayHelp: provides an output on how to interact with the program
 */
void displayHelp()
{
    cout << endl << "Type in Easy, Medium, or Hard after selecting Start in the Main Menu.\nEach Number entered will require a space between each other in order to work.\nThe End of each coding will require Main to be entered to return to Menu.\n" << endl;
}