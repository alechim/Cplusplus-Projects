// Question 17: 2-Player Tic-Tac-Toe
#include <iostream>
#include "ticTacToe.h"

using namespace std;

int main()
{
    ticTacToe game;
    game.printBoard();

    // Main loop for Tic-Tac-Toe
    do
    {
        game.getMove();
        game.printBoard();
        game.checkWinner();

        // Exit the loop if the game has determined a winner or tie, otherwise toggle player
        if(game.getGameEnd())
            break;
        else
            game.togglePlayer();
    } while(true);

    // Output Message based on the boolean value
    if(game.getIsTie())
        cout << "+===== Game Over. It's a Tie! =====+" << endl;
    else
        cout << "+===== Player " << ((game.getPlayer()) ? "1" : "2") << " Wins! =====+" << endl;

    return 0;
}