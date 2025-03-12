/* Alec Him, 2001543593, CS135 1004, Assignment 5
 * Description: Create a game against a computer with simple input
 * Input: Enter Key
 * Output: Body, Head, Eye, Wing, Leg, Tail 
 */
#include <iostream>     // Contains cout and cin
#include <iomanip>      // Contains setw() for formatting
#include <cstdlib>      // Contains rand() and srand()
#include <ctime>        // Used and Initialize srand()

using namespace std;

// Function Prototypes
void playGame(int items[6], int move, string player);
void displayInventory(int items[6], string player);
void displayWinner(int player[6], int computer[6], string victor);

int main(int argc, char* argv[])
{
    // Variables
    string answer = "";
    string option = "";
	int counter = 1;
	bool debugMode = false;
    // 0: body, 1: head, 2: wing, 3: leg, 4: eye, 5: tail
    int player[6] = {0, 0, 0, 0, 0, 0};
    int computer[6] = {0, 0, 0, 0, 0, 0};

    cout << "***************************" << endl;
	cout << "    Welcome to Can-cell    " << endl;
	cout << "***************************" << endl;
    
    if(argc > 1)
    {
        option = argv[1];
        debugMode = (option == "debug") ? true : false;
    }

    if(debugMode)
    {
		cout << "\n<<<<<<<<<<< Debug Mode Active >>>>>>>>>>>>>\n";

		while(true){
            cout << "################" << endl;
            cout << "Round #" << counter << endl << endl;
            counter++;

            // Number Generator
            srand(time(0));
            int rand(void);
            int playerMove = rand() % 6+1;
            int computerMove = rand() % 6+1;

            // Prompt Input
            cout << "Hit enter to roll die: ";
            getline (cin, answer);

            // Player Game
            playGame(player, playerMove, "one");
            displayInventory(player, "one");
            
            // Computer Game
            playGame(computer, computerMove, "two");
            displayInventory(computer, "two");

            if(player[0] == 1 && player[1] == 1 && player[2] == 4 &&
               player[3] == 6 && player[4] == 2 && player[5] == 1)
            {   
                displayWinner(player, computer, "one");
                return 0;
            }
            else if(computer[0] == 1 && computer[1] == 1 && computer[2] == 4 &&
                    computer[3] == 6 && computer[4] == 2 && computer[5] == 1)
            {   
                displayWinner(player, computer, "two");
                return 0;
            }
        } 
    } 
    
    if(argc > 1 && option != "debug")
        cout << "\n<<<<<<<<<<< Silent Mode Active >>>>>>>>>>>>>\n";

    while(true){
        cout << "################" << endl;
        cout << "Round #" << counter << endl << endl;
        counter++;

        // Number Generator
        srand(time(0));
        int rand(void);
        int playerMove = rand() % 6+1;
        int computerMove = rand() % 6+1;

        // Prompt Input
        cout << "Hit enter to roll die: ";
        getline (cin, answer);

        // Player & Computer Game
        playGame(player, playerMove, "one");
        playGame(computer, computerMove, "two");

        if(player[0] == 1 && player[1] == 1 && player[2] == 4 &&
            player[3] == 6 && player[4] == 2 && player[5] == 1)
        {   
            displayWinner(player, computer, "one");
            return 0;
        }
        else if(computer[0] == 1 && computer[1] == 1 && computer[2] == 4 &&
                computer[3] == 6 && computer[4] == 2 && computer[5] == 1)
        {   
            displayWinner(player, computer, "two");
            return 0;
        }
    } 

    return 0;
}

// Function Definitions
/**
 * playGame: Logic for Can-cell Game
 * @param int items[6] - Inventory of parts from respective player
 * @param int move - Random number generated from main
 * @param string player - Used to output correct player for message
 */
void playGame(int items[6], int move, string player)
{
    // Variables
    string part = "";
	string missing = "";

    // Determine move
    switch(move)
    {
        case 1:
            part = "1 BODY";
            if(items[0] == 1)
                part = "1 duplicate BODY";
            else
                items[0]++;
            break;
        case 2:
            part = "2 HEAD";
            if(items[1] == 1)
                part = "2 duplicate HEAD";
            else if(items[0] == 1)
                items[1]++;
            break;
        case 3:
            part = "3 WING";
            if(items[2] == 4)
                part = "3 duplicate WING";
            else if(items[0] == 1)
                items[2]++;
            break;
        case 4:
            part = "4 LEG";
            if(items[3] == 6)
                part = "4 duplicate LEG";
            else if(items[0] == 1)
                items[3]++;
            break;
        case 5:
            part = "5 EYE";
            if(items[0] == 1 && items[1] == 0)
                missing = "HEAD";
            else if(items[4] == 2)
                part = "5 duplicate EYE";
            else if(items[0] == 1)
                items[4]++;
            break;
        case 6:
            part = "6 TAIL";
            if(items[5] == 1)
                part = "6 duplicate TAIL";
            else if(items[0] == 1)
                items[5]++;
            break;
    }

    // Output Message
    if(items[0] == 0)
        missing = "BODY";
    if(items[0] == 0 || (move == 5 && items[1] == 0))
        cout << "Player " << player << "'s roll is " << part << ", must have " << missing << " first." << endl;
    else    
        cout << "Player " << player << "'s roll is " << part << endl;
}

/**
 * displayInventory: Display current inventory of respective player
 * @param int items[6] - Inventory of parts from respective player
 * @param string player - Used to output correct player for message
 */
void displayInventory(int items[6], string player)
{
    cout << "---------------------" << endl;
	cout << "Player " << player << "'s Inventory" << endl;
    cout << left << setw(12) << "Body:" << items[0] << endl;
    cout << left << setw(12) << "Head:" << items[1] << endl;
    cout << left << setw(12) << "Eye:" << items[2] << endl;
    cout << left << setw(12) << "Wing:" << items[3] << endl;
    cout << left << setw(12) << "Leg:" << items[4] << endl;
    cout << left << setw(12) << "Tail:" << items[5] << endl << endl;
}

/**
 * displayWinner: Display final results of game after victor is decided
 * @param int player[6] - Inventory of parts from player
 * @param int computer[6] - Inventory of parts from computer
 * @param string victor - Used to output correct victor for message
 */
void displayWinner(int player[6], int computer[6], string victor)
{
    cout << "*******************" << endl;
	cout << "Player " << victor << " has won" << endl;
    cout << "*******************" << endl;
    cout << setw(42) << right << "Game Results" << endl;
    cout << "------------------------------------------" << endl;
    cout << left << setw(22) << "Player 1 Inventory" << "Player 2 Inventory" << endl;
    cout << left << setw(12) << "Body:" << left << setw(10) << player[0] 
         << left << setw(12) << "Body:" << computer[0] << endl;
    cout << left << setw(12) << "Head:" << left << setw(10) << player[1] 
         << left << setw(12) << "Head:" << computer[1] << endl;
    cout << left << setw(12) << "Eye:" << left << setw(10) << player[2] 
         << left << setw(12) << "Eye:" << computer[2] << endl;
    cout << left << setw(12) << "Wing:" << left << setw(10) << player[3] 
         << left << setw(12) << "Wing:" << computer[3] << endl;
    cout << left << setw(12) << "Leg:" << left << setw(10) << player[4] 
         << left << setw(12) << "Leg:" << computer[4] << endl;
    cout << left << setw(12) << "Tail:" << left << setw(10) << player[5] 
         << left << setw(12) << "Tail:" << computer[5] << endl;
}