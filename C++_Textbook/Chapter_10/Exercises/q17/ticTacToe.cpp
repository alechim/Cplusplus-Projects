#include <iostream>
#include "ticTacToe.h"

using namespace std;

/**
 * ticTacToe::printBoard: 
 */
void ticTacToe::printBoard()
{
    for(int r = 0; r < 3; r++)
    {
        if(r == 0)
        {
            cout << "     1   2   3  " << endl;
            cout << "   +---+---+---+" << endl;
        }
        for(int c = 0; c < 3; c++)
        {
            if(c == 0)
            {
                cout << " " << r + 1 << " |";
            }
            cout << " " << board[r][c] << " |";
        }
        cout << endl << "   +---+---+---+" << endl;
    }
}

/**
 * ticTacToe::getMove: 
 */
void ticTacToe::getMove()
{
    char value = ((isPlayerOne) ? 'X' : 'O');
    int row = 0, col = 0;
    bool validInput = false;
    
    cout << "+===== Player " << ((isPlayerOne) ? "1" : "2") << "'s Turn =====+" << endl;
    do
    {
        cout << "| Enter the row and column: ";
        cin >> row >> col;
        if(cin.fail() || (row < 1 || row > 3 || col < 1 || col > 3))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| Invalid Input! Please enter a valid row and column to make your move." << endl;
            cout << "+---------------------------+" << endl;
            validInput = false;
        } else if(!validMove(row, col))
        {
            cout << "| That position is already taken! Choose another position." << endl;
            cout << "+---------------------------+" << endl;
            validInput = false;
        } else
            validInput = true;
    } while(!validInput);
    cout << "+===========================+" << endl;

    // Set the board to the value
    board[row - 1][col - 1] = value;
}

/**
 * ticTacToe::validMove: 
 * @return bool - 
 */
bool ticTacToe::validMove(int row, int col)
{
    return (board[row - 1][col - 1] == ' ');
}

/**
 * ticTacToe::checkWinner: 
 */
void ticTacToe::checkWinner()
{
    // Check for win conditions
    char value = ((isPlayerOne) ? 'X' : 'O');
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == value && board[i][1] == value && board[i][2] == value)
        {
            isWinner = true;
            return;
        }
        if(board[0][i] == value && board[1][i] == value && board[2][i] == value)
        {
            isWinner = true;
            return;
        }
    }
    if(board[0][0] == value && board[1][1] == value && board[2][2] == value)
    {
        isWinner = true;
        return;
    }
    if(board[2][0] == value && board[1][1] == value && board[0][2] == value)
    {
        isWinner = true;
        return;
    }

    // Check for tie
    // - If there are no blanks left on the board, the game is a tie
    for(int r = 0; r < 3; r++)
        for(int c = 0; c < 3; c++)
            if(board[r][c] == ' ')
                return;
    
    isTie = true;
}

/**
 * ticTacToe::ticTacToe: Default Constructor
 */
ticTacToe::ticTacToe()
{
    // Initialize board to ' '
    for(int r = 0; r < 3; r++)
        for(int c = 0; c < 3; c++)
            board[r][c] = ' ';

    // Set player one to move first
    isPlayerOne = true;
    isWinner = false;
    isTie = false;
}