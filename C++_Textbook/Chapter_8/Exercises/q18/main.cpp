// Question 18: Randomly Generated Memory Game
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Global Variables
const int EASY = 4;
const int MEDIUM = 6;
const int HARD = 8;

// Function Prototypes
void displayMenu(int&);
void generateGrid(int[], int);
void displayGrid(bool[], int[], int[], int);
void makeGuess(bool[], int[], int[], int[][2], int, int);
void promptGuess(bool[], int[][2], int, int);

int main()
{
    // Variables
    int arraySize = 0, select = 0;
    // Row - 0: Player 1, 1: Player 2
    int score[2] = {0, 0};
    // 0: Row, 1: Column
    int guess[2][2] = {{0, 0}, {0, 0}};
    
    // Prompt Input for Difficulty / Grid Size
    displayMenu(arraySize);

    // Declare Variables based on arraySize
    int gridSize = arraySize * arraySize;
    int grid[gridSize];
    bool revealed[gridSize];

    // Initialize Revealed Boolean to false & generate grid
    for(int i = 0; i < gridSize; i++)
        revealed[i] = false;
    generateGrid(grid, gridSize);

    int count = 1, player = 1, round = 1;
    do
    {
        // Check for two card guesses and whether to swap to either player
        if(count > 2)
        {
            count = 1;
            player++;
            if(player > 2)
            {
                player = 1;
                round++;
            }
        }

        displayGrid(revealed, grid, score, arraySize);
        cout << "| Player " << player << "'s Turn! Round " << round << endl;
        promptGuess(revealed, guess, arraySize, count);
        count++;
        makeGuess(revealed, grid, score, guess, player, arraySize);
    } while((score[0] + score[1]) != gridSize / 2);

    // Display Results of Game
    if(score[0] > score[1])
        cout << "+=== Player 1 Wins! ===+" << endl;
    else if(score[0] < score[1])
        cout << "+=== Player 2 Wins! ===+" << endl;
    else
        cout << "+=== Its a Tie! ===+" << endl;

    return 0;
}

// Function Defintions
/**
 * displayMenu: Presents a menu to the user to select the difficulty level
 * @param int& size - Reference to store the selected grid size based on difficulty
 */
void displayMenu(int& size)
{
    // Variables
    char choice = ' ';
    bool isValid = false;

    // Display Menu and Prompt for Input
    do
    {
        cout << "+" << setw(30) << setfill('=') << "" << "+" << endl << setfill(' ');
        cout << "| [E/e] Easy Mode" << setw(15) << "|" << endl;
        cout << "| [M/m] Medium Mode" << setw(13) << "|" << endl;
        cout << "| [H/h] Hard Mode" << setw(15) << "|" << endl;
        cout << "+" << setw(30) << setfill('-') << "" << "+" << endl << setfill(' ');
        cout << "| Enter a difficulty choice: ";
        cin >> choice;
        
        switch(tolower(choice))
        {
            case 'e':
                size = EASY;
                isValid = true;
                break;
            case 'm':
                size = MEDIUM;
                isValid = true;
                break;
            case 'h':
                size = HARD;
                isValid = true;
                break;
            default:
                cin.clear();
                cin.ignore(40, '\n');
                cout << "| Invalid Input! Please enter a valid of choice." << endl;
        }
    } while(!isValid);
    cout << "+" << setw(30) << setfill('-') << "" << endl << setfill(' ');
}

/**
 * generateGrid: Creates a randomly generated grid with matching pairs
 * @param int grid[] - Array to store the generated values
 * @param int size - Total size of the grid (rows * columns)
 */
void generateGrid(int grid[], int size)
{
    // Seed random number generator
    srand(time(0));
    
    // Initialize array with zeros
    for(int i = 0; i < size; i++)
        grid[i] = 0;
        
    // Generate pairs
    for(int num = 1; num <= size / 2; num++)
    {
        int pair = 0;
        while(pair < 2)
        {
            // Randomizes index and checks if index if empty to fill in the pairs
            int index = rand() % size;
            if(grid[index] == 0)
            {
                grid[index] = num;
                pair++;
            }
        }
    }
}

/**
 * displayGrid: Shows the current state of the game grid and scores
 * @param bool revealed[] - Array indicating which cards are revealed
 * @param int grid[] - Array containing the card values
 * @param int score[] - Array with player scores
 * @param int size - Size of one side of the grid (rows/columns)
 */
void displayGrid(bool revealed[], int grid[], int score[], int size)
{
    cout << endl << "+" <<  setw(size * 5 - 1) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Player 1 Pairs: " << score[0] << endl;
    cout << "| Player 2 Pairs: " << score[1] << endl;
    cout << "+" << setw(size * 5 - 1) << setfill('=') << "" << "+" << endl << setfill(' ');
    for(int i = 0; i < size * size; i++)
    {
        if(i != 0 && i % size == 0)
            cout << "|" << endl;
        cout << "| " << setw(3) << (revealed[i] ? to_string(grid[i]) + " " : "X ");
    }
    cout << "|" << endl << "+" <<  setw(size * 5 - 1) << setfill('=') << "" << "+" << endl << setfill(' ');
}

/**
 * makeGuess: Processes a player's guess and updates the game state
 * @param bool revealed[] - Array indicating which cards are revealed
 * @param int grid[] - Array containing the card values
 * @param int score[] - Array with player scores
 * @param int guess[][2] - 2D array storing the row and column of each guess
 * @param int player - Current player (1 or 2)
 * @param int size - Size of one side of the grid (rows/columns)
 */
void makeGuess(bool revealed[], int grid[], int score[], int guess[][2], int player, int size)
{
    // Reveals passed index if the player has not guessed the second card yet
    if(guess[1][0] == 0 && guess[1][1] == 0)
    {
        revealed[(guess[0][0] - 1) * size + (guess[0][1] - 1)] = true;
        return;
    }

    // Reveals second card on grid
    revealed[(guess[1][0] - 1) * size + (guess[1][1] - 1)] = true;

    int value1 = grid[(guess[0][0] - 1) * size + (guess[0][1] - 1)];
    int value2 = grid[(guess[1][0] - 1) * size + (guess[1][1] - 1)];
    
    // If both cards are pairs, keep revealed, increment correct score and reset guesses 2D array
    if(value1 == value2)
    {
        cout << "| Player " << player << " has found a pair: (" << value1 << ", " << value2 << ")" << endl;
        cout << "+" << setw(size * 5 - 1) << setfill('-') << "" << "+" << endl << setfill(' ');
        score[player - 1]++;
        // Reset guess to 0
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                guess[i][j] = 0;
        return;
    }

    cout << "| Player " << player << " has not found a pair: " << value1 << " & " << value2 << endl;
    cout << "+" << setw(size * 5 - 1) << setfill('-') << "" << "+" << endl << setfill(' ');
    displayGrid(revealed, grid, score, size);
    // Reveal cards after showing board
    revealed[(guess[0][0] - 1) * size + (guess[0][1] - 1)] = false;
    revealed[(guess[1][0] - 1) * size + (guess[1][1] - 1)] = false;

    // Reset guess to 0
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            guess[i][j] = 0;
    return;
}

/**
 * promptGuess: Prompts the player for a card selection and validates the input
 * @param bool revealed[] - Array indicating which cards are revealed
 * @param int guess[][2] - 2D array to store the player's guesses
 * @param int size - Size of one side of the grid (rows/columns)
 * @param int card - Which card is being guessed (1 or 2)
 */
void promptGuess(bool revealed[], int guess[][2], int size, int card)
{
    do
    {
        cout << "+" << setw(30) << setfill('-') << "" << endl << setfill(' ');
        cout << "| Guess the " << ((card == 1) ? "first" : "second") << " card (row & column): ";
        cin >> guess[card - 1][0] >> guess[card - 1][1];
        if(cin.fail() || guess[card - 1][0] < 1 || guess[card - 1][0] > size || guess[card - 1][1] < 1 || guess[card - 1][1] > size)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| Invalid Input! Please enter two integer values between 1 and " << size << "." << endl;
        } 
        if(revealed[(guess[card - 1][0] - 1) * size + (guess[card - 1][1] - 1)])
            cout << "| Invalid Input! That card has already been revealed. Please enter another row and column." << endl;
        else
            break;
    } while(true);
}