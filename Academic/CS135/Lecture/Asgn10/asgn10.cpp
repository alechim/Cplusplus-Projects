/**
 * Alec Him, 2001543593, CS135 1004, Assignment 10
 * Description: Create a game where there are four main variables that decide the winner
 * Input: 1a-e, 2a-e, 3a-e, 4a-e, 5a-e
 * Output: Sectors of Wilderness, Popularity, Ecology, Commerce, Industry
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Global Enumerators
enum resourceTypes{POPULARITY, ECOLOGY, COMMERCE, INDUSTRY};

// Global Constant Variables
const int RESOURCE_TYPES = 4;
const int UPGRADE_COUNT = 6;
const int COLONY_HEIGHT = 4;        // Colony Array is Height x Width
const int COLONY_WIDTH = 5;

// Structs
struct improvement
{
    string name = "";
    // Hold values for the 4 resource types & descibes how much of a resource this improvement can extract from its sector.
    int collects[RESOURCE_TYPES]; 
    // Holds values for the 4 resource types & describes how much of a bonus or penalty is applied to the sector when constructed.
    int develops[RESOURCE_TYPES];
};

struct sector
{
    // Tracks how much of the four resources are available in the sector.
    int resources[RESOURCE_TYPES];
    improvement zone;
};

// Struct Variables
improvement zone;
sector colony[COLONY_HEIGHT][COLONY_WIDTH];

// Function Prototypes
void printColony(const sector[][COLONY_WIDTH]);
void getResourceTotals(sector[][COLONY_WIDTH], int[], int);
int getScore(int resources[], int resourceCount);
void placeImprovement(sector[][COLONY_WIDTH], improvement, int, int);

int main()
{
    // Variables
    sector colony[COLONY_HEIGHT][COLONY_WIDTH];
	int resourceTotals[RESOURCE_TYPES];
    int zoneType = 0;
    string location = "";
    int x = 0, y = 0;

    // Variables - Sector Improvements
    improvement upgrades[UPGRADE_COUNT];
	upgrades[0] = {"Wilderness", {0,0,0,0}, { 0, 0, 0, 0}};
	upgrades[1] = {"Settlement", {1,1,1,1}, { 0, 0, 0, 0}};
	upgrades[2] = {"Farm", {0,2,0,0}, { 1, 1,-1,-1}};
	upgrades[3] = {"Mine", {0,0,0,2}, {-1,-1, 1, 1}};
	upgrades[4] = {"City", {0,0,2,0}, { 0,-1, 2,-1}};
	upgrades[5] = {"Resort", {2,0,0,0}, { 1, 1, 0,-2}};

    // Seed Random Number Generator
    srand(time(NULL));

    // Initialize sector resource values to random amounts from 0-3
    for(int i = 0; i < COLONY_HEIGHT; i++)
        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            colony[i][j].zone = upgrades[0];
            for(int k = 0; k < RESOURCE_TYPES; k++)
            {
                int randomAmount = rand() % 100;
                if(randomAmount >= 95)
                    colony[i][j].resources[k] = 3;
                else if(randomAmount >= 80)
                    colony[i][j].resources[k] = 2;
                else if(randomAmount >= 50)
                    colony[i][j].resources[k] = 1;
                else
                    colony[i][j].resources[k] = 0;
            }
        }
    
    // Allows user to select 12 improvements to the colony then provides a final score
    for(int i = 12; i > 0; i--)
    {
        // Colony Status
        printColony(colony);
        getResourceTotals(colony, resourceTotals, RESOURCE_TYPES);

        cout << "Colony Status: ";
        cout << "[" << resourceTotals[POPULARITY] << " Popularity] ";
        cout << "[" << resourceTotals[ECOLOGY] << " Ecology] ";
        cout << "[" << resourceTotals[COMMERCE] << " Commerce] ";
        cout << "[" << resourceTotals[INDUSTRY] << " Industry] ";
        cout << "\nCurrent Score: " << getScore(resourceTotals, RESOURCE_TYPES) << endl;
    
        // Improvement Selection Menu
        cout << "Place Improvement (" << i << "/12)\n";
        cout << "[1] Settlement (Px1 Ex1 Cx1 Ix1)(P 0 E 0 C 0 I 0)\n";
        cout << "[2] Farm       (Px0 Ex2 Cx0 Ix0)(P+1 E+1 C-1 I-1)\n";
        cout << "[3] Mine       (Px0 Ex0 Cx0 Ix2)(P-1 E-1 C+1 I+1)\n";
        cout << "[4] City       (Px0 Ex0 Cx2 Ix0)(P 0 E-1 C+2 I-1)\n";
        cout << "[5] Resort     (Px2 Ex0 Cx0 Ix0)(P+1 E+1 C 0 I-2)\n";

        // User Selects Improvement to Build
        do
        {
            cout << "Select improvement to construct(1-"<<UPGRADE_COUNT-1<<"): ";
    	    cin >> zoneType;
            if(cin.fail() || zoneType <= 0 || zoneType > UPGRADE_COUNT)
            {
                cin.clear();
      	        cin.ignore(100000,'\n');
                cout << "Invalid improvement type, please try again.\n";
            } else
                break;
        } while(true);
        
        // User Selects Location to Build Improvement
        do
        {
            cout << "Construct "<< upgrades[zoneType].name <<" location: ";
            cin >> location;

            if(location.length() == 2)
            {
                // Allows location to be selected with either lower or upper case coordinate value
                if(location[1] >= 'a' && location[1] <= 'z')
                    location[1] -= 'a' - 'A';
                
                // Converts user input to coordinates
                x = location[1]-'A';
                y = location[0]-'1';
            
                // Ensures coordinates are within the colony bounds
                if(y >= 0 && y < COLONY_HEIGHT && x >= 0 && x < COLONY_WIDTH)
                    break;
                else
                {
                    cin.clear();
                    cin.ignore(100000,'\n');
                    cout << "Invalid location, please try again.\n";
                }
            } else
            {
                cin.clear();
                cin.ignore(100000,'\n');
                cout << "Invalid location, please try again.\n";
                continue;
            }
            break;
        } while(true);
        
        placeImprovement(colony, upgrades[zoneType], x, y);
    }

    // Final Status of Colony
    printColony(colony);
    getResourceTotals(colony, resourceTotals, RESOURCE_TYPES);

    cout << "\nFinished Colony: ";
	cout << "[" << resourceTotals[POPULARITY] << " Popularity] ";
	cout << "[" << resourceTotals[ECOLOGY] << " Ecology] ";
	cout << "[" << resourceTotals[COMMERCE] << " Commerce] ";
	cout << "[" << resourceTotals[INDUSTRY] << " Industry] ";
	cout << "\nFinal Score: " << getScore(resourceTotals, RESOURCE_TYPES) << endl;

    return 0;
}

// Function Definitions
/**
 * printColony: Displays the current state of the colony grid with all sectors and their resource information.
 * @param sector colony[][COLONY_WIDTH] - The 2D array representing the colony grid
 */
void printColony(const sector colony[][COLONY_WIDTH])
{
    for(int i = 0; i < COLONY_HEIGHT; i++)
    {    
        for(int j = 0; j < COLONY_WIDTH; j++)
            cout << "+----" << i + 1 << static_cast<char>('A' + j) << "----+ ";
        cout << endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            cout << "|";
            size_t spaces = 10 - colony[i][j].zone.name.length();

            for(size_t k = 0; k < spaces / 2; k++)
                cout << " ";
            cout << colony[i][j].zone.name;

            for(size_t k = 0; k < spaces - spaces / 2; k++)
                cout << " ";
            cout << "| ";
        }
        cout << endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            cout << "|POP: " << colony[i][j].zone.collects[POPULARITY];
            cout << " x" << setw(2) << colony[i][j].resources[POPULARITY] << "| ";
        }
        cout << endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            cout << "|ECO: " << colony[i][j].zone.collects[ECOLOGY];
            cout << " x" << setw(2) << colony[i][j].resources[ECOLOGY] << "| ";
        }
        cout << endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            cout << "|COM: " << colony[i][j].zone.collects[COMMERCE];
            cout << " x" << setw(2) << colony[i][j].resources[COMMERCE] << "| ";
        }
        cout << endl;

        for(int j = 0; j < COLONY_WIDTH; j++)
        {
            cout << "|IND: " << colony[i][j].zone.collects[INDUSTRY];
            cout << " x" << setw(2) << colony[i][j].resources[INDUSTRY] << "| ";
        }
        cout << endl;
    }

    for(int j = 0; j < COLONY_WIDTH; j++)
        cout << "+----------+ ";
    cout << endl;
}

/**
 * getResourceTotals: Calculates the total amount of each resource type collected across the entire colony.
 * @param sector colony[][COLONY_WIDTH] - The 2D array representing the colony grid
 * @param int resourceTotals[] - Array to store the calculated resource totals
 * @param int resourceCount - The number of different resource types
 */
void getResourceTotals(sector colony[][COLONY_WIDTH], int resourceTotals[], int resourceCount)
{
    // Initialize resourceTotals to 0
    for(int i = 0; i < resourceCount; i++)
        resourceTotals[i] = 0;

    // Calculate resourceTotals
    for(int r = 0; r < COLONY_HEIGHT; r++)
        for(int c = 0; c < COLONY_WIDTH; c++)
            for(int i = 0; i < resourceCount; i++)
                resourceTotals[i] += colony[r][c].zone.collects[i] * colony[r][c].resources[i];
}

/**
 * getScore: Calculates the colony's score based on resource totals.
 * @param int resources[] - Array containing the total amount of each resource type
 * @param int resourceCount - The number of different resource types
 * @return int - The calculated score based on popularity and the lowest resource value
 */
int getScore(int resources[], int resourceCount)
{
    int lowestResource = 10000;

    if(resources[POPULARITY] < 0)
        resources[POPULARITY] = 0;
    
    for(int i = 0; i < resourceCount; i++)
    {
        if(resources[i] < 0)
        {
            lowestResource = 0;
            break;
        } else if(resources[i] < lowestResource)
            lowestResource = resources[i];
    }

    return resources[POPULARITY] * lowestResource;
}

/**
 * placeImprovement: Places a new improvement in the specified location and applies its development effects to the surrounding sectors.
 * @param sector colony[][COLONY_WIDTH] - The 2D array representing the colony grid
 * @param improvement newZone - The improvement to place
 * @param int x - The x-coordinate (column) of the placement location
 * @param int y - The y-coordinate (row) of the placement location
 */
void placeImprovement(sector colony[][COLONY_WIDTH], improvement newZone, int x, int y)
{
    colony[y][x].zone = newZone;

    for(int k = 0; k < RESOURCE_TYPES; k++)
        for(int i = max(0, y - 1); i <= min(COLONY_HEIGHT - 1, y + 1); i++)
            for(int j = max(0, x - 1); j <= min(COLONY_WIDTH - 1, x + 1); j++)
                colony[i][j].resources[k] += newZone.develops[k];
}