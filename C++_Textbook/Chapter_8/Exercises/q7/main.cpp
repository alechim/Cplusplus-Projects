// Question 7: Determine Local Election Candidate Winner
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void promptInput(int&, string);
void promptInput(string&, string);
void displayResults(string[], int[], int);

int main()
{
    // Variables
    int totalVotes = 0;
    string candidates[5];
    int votes[5];

    // Prompt for Input
    for(int i = 0; i < 5; i++)
    {
        promptInput(candidates[i], "Please enter the last name for candidate " + to_string(i + 1) + ": ");
        promptInput(votes[i], "Please enter the votes received for candidate " + to_string(i + 1) + ": ");
        totalVotes += votes[i];
    }

    // Output Results
    displayResults(candidates, votes, totalVotes);

    return 0;
}

// Function Definitions
/**
 * promptInput: Prompts the user for an integer input and validates it
 * @param int& value - Reference to the integer variable to store the input
 * @param string prompt - The message to display when prompting the user
 */
void promptInput(int& value, string prompt)
{   
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
            break;
    } while(true);
}

/**
 * promptInput: Prompts the user for a string input and validates it
 * @param string& value - Reference to the string variable to store the input
 * @param string prompt - The message to display when prompting the user
 */
void promptInput(string& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter string value." << endl;
        } else
            break;
    } while(true);
}

/**
 * displayResults: Calculates percentages, determines the winner, and displays election results
 * @param string candidates[5] - Array of candidate names
 * @param int votes[5] - Array of votes received by each candidate
 * @param int totalVotes - The total number of votes cast in the election
 */
void displayResults(string candidates[5], int votes[5], int totalVotes)
{
    double percentOfVotes[5];
    int maxIndex = 0;

    // Calculate the percent of votes for each candidate
    for(int i = 0; i < 5; i++)
        percentOfVotes[i] = static_cast<double>(votes[i]) / totalVotes * 100;

    // Determine maxIndex
    for(int i = 1; i < 5; i++)
        if(percentOfVotes[maxIndex] < percentOfVotes[i])
            maxIndex = i;
    
    // Output Header
    cout << setw(54) << setfill('=') << "" << endl << setfill(' ');
    cout << left << setw(16) << "Candidate" << setw(20) << "Votes Received" << setw(24) << "% of Total Votes" << endl;
    cout << setw(54) << setfill('=') << "" << endl << setfill(' ');
    for(int i = 0; i < 5; i++)
        cout << left << setw(22) << candidates[i] << setw(18) << votes[i] << fixed << setprecision(2) << percentOfVotes[i] << endl;
    cout << left << setw(22) << "Total" << setw(18) << totalVotes << endl;
    cout << setw(54) << setfill('=') << "" << endl << setfill(' ');
    cout << "The Winner of the Election is " << candidates[maxIndex] << "." << endl;
}