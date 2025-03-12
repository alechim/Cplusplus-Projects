/* Alec Him, 2001543593, CS135 1009, Lab 5
 * Description: Creating a Rock, Paper, Scissors Game with a Computer Opponent
 * Input: Rock, Paper, Scissors
 * Output: Rock, Paper, Scissors and Winner 
 * Algorithm:
 * - 1. Generate CPU Move
 * - 2. Convert char input to integer
 * - 3. Compare CPU and playerMoves 
 */

#include <iostream>    // Cout and Cin
#include <cstdlib>     // Random Number Generator (Among other Things)
#include <ctime>       // We will use the current time as a seed

using namespace std;

int main()
{
    // Variables
    int playerMove = 0;
    char playerInput = ' ';
    string moveDisplay = "";
    string result = "";

    while(true)
    {
        srand(time(0));
        // 0: Rock, 1: Paper, 2: Scissors
		int computerMove = rand() % 3; // 0, 1, 2

        // Display Menu
        cout << "[R]ock" << endl;
		cout << "[P]aper" << endl;
		cout << "[S]cissors" << endl;
		cout << "[E]xit" << endl;

        // Prompt for Input
        cout << "Your Move: ";
		cin >> playerInput;

        switch(playerInput)
        {
            case 'R':
			case 'r':
                playerMove = 0;
                break;
            case 'P':
			case 'p':
                playerMove = 1;
                break;
            case 'S': 
			case 's':
                playerMove = 2;
                break;
            case 'E':
			case 'e':
                cout << "Exiting Program" << endl;
                return 0;
            default:
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input!" << endl;
                continue;
        }
    
        cout << "Computer Move: ";
        if(computerMove == 0)
            cout << "Rock" << endl;
        else if(computerMove == 1)
            cout << "Paper" << endl;
        else
            cout << "Scissors" << endl;

        // Display Final Results
        if(playerMove == computerMove)
            result = "Tie";
        else if((playerMove == 0 && computerMove == 2) || (playerMove == 1 && computerMove == 0) || (playerMove == 2 && computerMove == 1))
            result = "You Win!";
        else
            result = "You Lose.";

        cout << "Result: " << result << endl << endl;
    }

    return 0;
}