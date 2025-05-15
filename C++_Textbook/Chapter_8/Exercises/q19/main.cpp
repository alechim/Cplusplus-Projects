// Question 19: Airplane Seating Assignment
#include <iostream>
#include <iomanip>

using namespace std;

// Global Constants
const int ROWS = 13;
const int COLS = 6;
const int MAX_DIGIT = 2;        // Only accepts two-digit values

// Function Definitions
void initializeSeats(char[ROWS][COLS], char[ROWS * COLS][2 + MAX_DIGIT]);
void displaySeating(char[ROWS][COLS]);
void bookSeats(char[ROWS][COLS], int[][2]);

int main()
{
    // Variables
    char choice = ' ';
    char seats[ROWS][COLS];

    // This variable is used to intialize seating with already booked seats
    char bookedSeats[ROWS * COLS][2 + MAX_DIGIT] = 
    {
        "C1", "E1", "F1", 
        "B2", "D2", "F2", 
        "C3", "D3", "F3", 
        "A4", "C4", "E4", "F4", 
        "B5", "D5", 
        "B6", "F6", 
        "A7", "E7", "F7",
        "B8", "D8", "E8",
        "A9", "C9", "D9", "F9",
        "B10", "D10", "E10", "F10",
        "C11", "E11",
        "C12", "D12", "F12",
        "E13"
    };
    
    // 0: First Class, 1: Business Class, 2: Economy
    int range[3][2] = {{1, 2}, {3, 7}, {8, 13}};

    // Initialize the 2D Array
    initializeSeats(seats, bookedSeats);

    do
    {
        cout << "+" << setw(36) << setfill('=') << "" << "+" << endl << setfill(' ');
        cout << "| [D/d] Display Current Seating Plan |" << endl; 
        cout << "| [B/b] Book Seats" << setw(19) << "" << "|" << endl; 
        cout << "| [E/e] Exit Program" << setw(17) << "" << "|" << endl;
        cout << "+" << setw(36) << setfill('=') << "" << "+" << endl << setfill(' ');

        cout << "| Please enter a choice: ";
        cin >> choice;
        switch(toupper(choice))
        {
            case 'D':
                displaySeating(seats);
                break;
            case 'B':
                bookSeats(seats, range);
                break;
            case 'E':
                break;
            default:
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a valid choice." << endl;
        }
    } while(toupper(choice) != 'E');

    return 0;
}

// Function Prototypes
/**
 * initializeSeats: Initializes the seating chart array and marks pre-booked seats
 * @param char seating[ROWS][COLS] - 2D array representing the airplane seating chart
 * @param char bookedSeats[ROWS * COLS][4] - Array containing pre-booked seat information in format "A1", "B2", etc.
 */
void initializeSeats(char seating[ROWS][COLS], char bookedSeats[ROWS * COLS][2 + MAX_DIGIT])
{
    // '*' - represents an empty seat
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            seating[i][j] = '*';

    for(int i = 0; i < ROWS * COLS; i++)
    {
        // Break out of loop if there are no more bookedSeats detected
        if(bookedSeats[i][0] == '\0')
            break;

        // Store and convert the column letter from bookedSeats
        int col = static_cast<int>(bookedSeats[i][0] - 'A');
        int seatNumber = 0;
        for(int j = 1; j < 2 + MAX_DIGIT; j++)
        {
            if(bookedSeats[i][j] != '\0')
                if(isdigit(bookedSeats[i][j]))
                    seatNumber = seatNumber * 10 + (bookedSeats[i][j] - '0');
        }
        seating[seatNumber - 1][col] = 'X';
    }
}

/**
 * displaySeating: Displays the current seating chart in a formatted table
 * @param char seating[ROWS][COLS] - 2D array representing the airplane seating chart
 */
void displaySeating(char seating[ROWS][COLS])
{
    // Header 
    cout << "+" << setw(42) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "|" << left << setw(11) << "";
    for(int i = 0; i < COLS; i++)
        cout << setw(5) << static_cast<char>('A' + i);
    cout << " |" << endl;
    for(int i = 0; i < ROWS; i++)
    {
        cout << left << setw(12) << "| Row " + to_string(i + 1);
        for(int j = 0; j < COLS; j++)
        {
            cout << setw(5) << seating[i][j];
        }
        cout << " |" << endl;
    }
    cout << "+" << setw(42) << setfill('=') << "" << "+\n\n" << setfill(' ');
}

/**
 * findAvailableSeating: Handles the seat booking process for different class sections
 * @param char seating[ROWS][COLS] - 2D array representing the airplane seating chart
 * @param int range[][2] - Array containing row ranges for different classes [[1,2], [3,7], [8,13]]
 */
void bookSeats(char seating[ROWS][COLS], int range[][2])
{
    char choice = ' ';
    do
    {
        // Display Header Menu
        cout << "\n+" << setw(35) << setfill('=') << "" << "+" << endl << setfill(' ');
        cout << "| Available Seats" << right << setw(20) << "|" << endl;
        cout << "+" << setw(35) << setfill('-') << "" << "+" << endl << setfill(' ');
        cout << "| [F/f] First Class Rows:    1 - 2  |" << endl;
        cout << "| [B/b] Business Class Rows: 3 - 7  |" << endl;
        cout << "| [E/e] Economy Class Rows:  8 - 13 |" << endl;
        cout << "| [Q/q] Exit" << right << setw(25) << "|" << endl;
        cout << "+" << setw(35) << setfill('-') << "" << "+" << endl << setfill(' ');

        // Variables
        bool valid = false;
        int index = 0;

        // Prompt and Validate Input - Rows
        do
        {
            cout << "| Please enter your desired ticket type: ";
            cin >> choice;
            switch(toupper(choice))
            {
                case 'F':
                    index = 0;
                    valid = true;
                    break;
                case 'B':
                    index = 1;
                    valid = true;
                    break;
                case 'E':
                    index = 2;
                    valid = true;
                    break;
                case 'Q':
                    return;
                default:
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Invalid Input! Please enter a valid choice [F/f], [B/b], or [E/e]." << endl;
            }
        } while(!valid);
        cout << "+" << setw(35) << setfill('-') << "" << "+" << endl << setfill(' ');

        // Display rows based on prior input
        for(int i = range[index][0] - 1; i < range[index][1]; i++)
        {
            cout << left << setw(11) << "| Row " + to_string(i + 1) + ":";
            for(int j = 0; j < COLS; j++)
            {
                if(seating[i][j] == '*')
                    cout << setw(2) << static_cast<char>(j + 'A') << " ";
            }
            cout << endl;
        }
        cout << "+" << setw(35) << setfill('-') << "" << "+" << endl << setfill(' ');

        int rowSeat = 0;
        char colSeat = ' ';
        // Prompt and Validate Input - Seat
        do
        {
            cout << "| Please enter the seat you want to book: ";
            cin >> rowSeat >> colSeat;
            
            if(cin.fail() || (rowSeat < range[index][0] && rowSeat > range[index][1]) || (toupper(colSeat) < 'A' && toupper(colSeat) > 'Z') || seating[rowSeat][toupper(colSeat) - 'A'] != '*')
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please one of the available seats. 'row' 'seat'" << endl;
            } else
            {
                seating[rowSeat - 1][toupper(colSeat) - 'A'] = 'X';
                break;
            }
        } while(!valid);

        cout << "+" << setw(35) << setfill('-') << "" << "+" << endl << setfill(' ');
        // Prompt and Validate Input - Loop
        do
        {
            cout << "| Would you like to book another ticket? [y/n]: ";
            cin >> choice;
            if(cin.fail() || (choice != 'y' && choice != 'n'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
            }
        } while(choice != 'y' && choice != 'n');
        cout << "+" << setw(35) << setfill('=') << "" << "+" << endl << setfill(' ');
    } while(choice == 'y');
}