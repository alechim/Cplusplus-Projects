/** 
 * Alec Him, 2001543593, CS135 1009, Lab 10
 * Description: Create a battle royale simulation
 * Input: Chars - F, B, H & Enter Key
 * Output: Map Area & Border 
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

// Global Constant Variables
const int MAX_MAP_HEIGHT = 50;
const int MAX_MAP_WIDTH = 50;

// Function Prototypes
int getNumPlayers(char[][MAX_MAP_WIDTH], int, int);
void load(char[][MAX_MAP_WIDTH], int&, int&, int&, int&, int&);
void drop(char[][MAX_MAP_WIDTH], int, int, int);
void shrinkStorm(char[][MAX_MAP_WIDTH], int, int, int, int, int&);
void render(char[][MAX_MAP_WIDTH], int, int);

int main()
{
    // Variables
    char map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
    int height = 0, width = 0;
    int playerCount = 0;
    int eyeR = 0, eyeC = 0;
    int radius = 0;
    char temp = ' ';
    srand(time(0));

    // Function Calls
    load(map, height, width, playerCount, eyeR, eyeC);
    render(map, height, width);
    drop(map, height, width, playerCount);
    radius = width;

    while(playerCount > 1)
    {
        cout << "Hit enter to continue";
        cin.get(temp);
        shrinkStorm(map, height, width, eyeR, eyeC, radius);
        playerCount = getNumPlayers(map, height, width);
        render(map, height, width);
    }

    return 0;
}

// Function Definitions
/**
 * render: Creates the outline/screen space for the map
 * @param char screenSpace[][MAX_MAP_WIDTH] - 2D array of the map
 * @param int rows - allowed rows for the map
 * @param int cols - allowed columns for the map
 */
void render(char screenSpace[][MAX_MAP_WIDTH], int rows, int cols)
{
    string border = "";
    border.append(cols + 2, '_');

    cout << border << endl;
    for(int r = 0; r < rows; r++)
    {
        cout << "|";
        for(int c = 0; c < cols; c++)
            cout << screenSpace[r][c];
        cout << "|\n";
    }
    cout << border << endl;
}

/**
 * load: Decides how many players and size of the map are executed based on user input
 * @param char map[][MAX_MAP_WIDTH] - 2D array of the map
 * @param int rows - allowed rows for the map
 * @param int cols - allowed columns for the map
 * @param int playerCount - total amount of players
 * @param int eyeR - The row coordinate of the storm's eye/center
 * @param int eyeC - The column coordinate of the storm's eye/center
 */
void load(char map[][MAX_MAP_WIDTH], int& rows, int& cols, int& playerCount, int& eyeR, int& eyeC)
{
    // Variables - Map
    const int FL_HEIGHT = 20;   // size of Farmland
    const int FL_WIDTH = 40;
    const int BY_HEIGHT = 15;   // size of Boneyard
    const int BY_WIDTH = 30;
    const int HP_HEIGHT = 10;   // size of Hospital
    const int HP_WIDTH = 20;

    // Variables - Players & Marker
    const int FL_PC = 26;   // players in Farmland
    const int BY_PC = 15;   // players in Boneyard
    const int HP_PC = 10;   // players in Hospital
    char marker = ' ';

    // Display Menu
    cout << "Where we droppin bois?\n";
    cout << "[F]armland\n";
    cout << "[B]oneyard\n";
    cout << "[H]ospital\n";
    cout << "Choice: ";
    cin >> marker;
    cin.ignore(256, '\n');

    switch(marker)
    {
        case 'F':
        case 'f':
            rows = FL_HEIGHT;
            cols = FL_WIDTH;
            playerCount = FL_PC;
            break;
        case 'B':
        case 'b':
            rows = BY_HEIGHT;
            cols = BY_WIDTH;
            playerCount = BY_PC;
            break;
        default:
            rows = HP_HEIGHT;
            cols = HP_WIDTH;
            playerCount = HP_PC;
            break;
    }

    eyeR = rand() % rows;
    eyeC = rand() % cols;

    // Clear map
    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            map[r][c] = ' ';
    
}

/**
 * getNumPlayers: Detects how many players are left in the map
 * @param char screenSpace[][MAX_MAP_WIDTH] - 2D array of the map
 * @param int rows - allowed rows for the map
 * @param int cols - allowed columns for the map
 */
int getNumPlayers(char map[][MAX_MAP_WIDTH], int rows, int cols)
{
    int count = 0;
    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            if(map[r][c] != ' ' && map[r][c] != '*')
                count++;
    return count;
}

/**
 * drop: Sets random position of players on the map
 * @param char screenSpace[][MAX_MAP_WIDTH] - 2D array of the map
 * @param int rows - allowed rows for the map
 * @param int cols - allowed columns for the map
 * @param int playerCount - total amount of players
 */
void drop(char map[][MAX_MAP_WIDTH], int rows, int cols, int playerCount)
{
    // Variables
    char player = 'A';
    int drops = 0;

    while(drops < playerCount)
    {
        int r = rand() % rows;
        int c = rand() % cols;

        if(map[r][c] == ' ')
        {
            map[r][c] = player;
            player++;
            drops++;
        }
    }
}

/**
 * shrinkStorm:
 * @param char map[][MAX_MAP_WIDTH] - 2D array of the map
 * @param int rows - allowed rows for the map
 * @param int cols - allowed columns for the map
 * @param int eyeR - The row coordinate of the storm's eye/center
 * @param int eyeC - The column coordinate of the storm's eye/center
 * @param int radius - The current radius of the safe zone
 */
void shrinkStorm(char map[][MAX_MAP_WIDTH], int rows, int cols, int eyeR, int eyeC, int& radius)
{
    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            if(map[r][c] != '*')
            {
                double distance = sqrt(pow(c - eyeC, 2) + pow(r - eyeR, 2));
                if(distance > radius)
                    map[r][c] = '*';
            }
    radius--;
}