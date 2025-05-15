class ticTacToe
{
    public:
        void printBoard();
        void getMove();
        bool validMove(int, int);
        void checkWinner();

        // Inline Functions
        void togglePlayer() { isPlayerOne = !isPlayerOne; }
        bool getPlayer() const { return isPlayerOne; }
        bool getGameEnd() const { return (isWinner || isTie); }
        bool getIsTie() const { return isTie; }

        ticTacToe();
    private:
        char board[3][3];
        bool isPlayerOne;
        bool isWinner;
        bool isTie;
};