// Question 16: Pick 5 Lottery with Sequential Search
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Global Constant Variables
const int MAX_RUNS = 100;                   // Amount of times program can be run until it needs to terminate
const int ATTEMPTS = 10;                    // Number of attempts the user gets per session

// Function Prototypes
void generateNumber(int[]);
void sequentialSearch(int[][5], int[]);

int main()
{
    // Variables
    int prevArray[MAX_RUNS][5] = {0, 0};
    int randomArray[5], guess[5];
    char choice = ' ';
    int attempts = 0, count = 0, correct = 0;

    // Start Session of MAX_RUN Plays
    do
    {
        // Check if there are no attempts, then initialize session
        if(attempts == 0)
        {
            cout << "Remaining Plays: " << MAX_RUNS - count << endl;
            cout << setfill('=') << setw(30) << "" << endl << setfill(' ');
            attempts = ATTEMPTS;
            generateNumber(randomArray);
            sequentialSearch(prevArray, randomArray);
        }

        // Main Game Logic
        do
        {
            // Initialize Correct Counter
            correct = 0;

            // Display attempts remaining & verify that input is correct
            cout << left << setw(attempts < 10 ? 10 : 9) << "Attempts" << "[" << attempts << "/" << ATTEMPTS << "]" << " | Please guess 5 digits between 1 - 9:\nGuess: ";
            for(int i = 0; i < 5;)
            {
                cin >> guess[i];
                if(cin.fail() || (guess[i] < 1 || guess[i] > 9))
                {
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Invalid Input! Please enter 5 integer values between 1 and 9." << endl;
                    i = 0;      // Restart input
                    continue;
                }
                i++;            // Only increment if valid input
            }
            cout << setfill('-') << setw(17) << "" << endl << setfill(' ');

            // Output correct digit in correct index, or display 'X' in incorrect index
            cout << "|>| ";
            for(int i = 0; i < 5; i++)
            {
                if(randomArray[i] == guess[i])
                {
                    cout << randomArray[i] << " ";
                    correct++;
                }
                else
                    cout << "X ";
            }
            cout << "|<|" << endl;
            cout << setfill('-') << setw(17) << "" << endl << setfill(' ') << endl;

            // Exit session loop and display win if user guesses correctly
            if(correct == 5)
            {
                cout << "+=== You Win! ===+=== ";
                break;
            }
            
            attempts--;
        } while(attempts != 0);

        // Check correct counter if user has lost after exiting session loop
        if(correct != 5)
            cout << "+=== You Lose... ===+=== " << endl;
        
        // Display correctly generated 5 digit lotto
        cout << " Correct Answer: ";
        for(int i = 0; i < 5; i++)
            cout << randomArray[i] << " ";
        cout << " ===+" << endl;

        // Increment plays amount and prompt user if they would like to play again
        count++;
        do 
        {
            cout << "Would you like to play again? [y/n]: ";
            cin >> choice;
            if(cin.fail() || (choice != 'y' && choice != 'n'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
            } else
                break;
        } while(true);
        cout << setfill('=') << setw(30) << "" << endl << setfill(' ');
    } while(choice == 'y' || count < MAX_RUNS);
    
    cout << "Exiting Program... Goodbye!" << endl;

    return 0;
}

// Function Definitions
/**
 * generateNumber: Generates 5 random numbers between 1-9
 * @param int array[] - Array to store the 5 generated numbers
 */
void generateNumber(int array[])
{
    // Seed and Generate Random Number
    srand(time(0));
    for(int i = 0; i < 5; i++)
        array[i] = rand() % 9 + 1;      // Generate 1-9
}

/**
 * sequentialSearch: Checks if the generated lottery numbers already exist in previous plays and stores the new numbers in the history array
 * @param int exists[][5] - 2D array storing all previous lottery number combinations
 * @param int array[] - The newly generated lottery numbers to check and store
 */
void sequentialSearch(int exists[][5], int array[])
{
    int check = 0;
    for(int i = 0; i < MAX_RUNS; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(exists[i][j] == 0)
            {
                exists[i][j] = array[i];
                return;
            }
            if(exists[i][j] == array[i])
                check++;
        }
        if(check == 5)
        {
            generateNumber(array);
            sequentialSearch(exists, array);
        }
        check = 0;
    }
}