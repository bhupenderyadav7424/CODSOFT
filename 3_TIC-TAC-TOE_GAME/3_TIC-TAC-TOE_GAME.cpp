#include <iostream>
#include <vector>
using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard()
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            board[row][col] = ' ';
        }
    }
}

void displayBoard()
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            cout << board[row][col];
            if (col < BOARD_SIZE - 1)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (row < BOARD_SIZE - 1)
        {
            cout << "---------" << endl;
        }
    }
}

bool isMoveValid(int row, int col)
{
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

bool checkWin(char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; // Check diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true; // Check anti-diagonal
    }
    return false;
}

bool checkDraw()
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == ' ')
            {
                return false; // If any cell is empty, the game is not a draw
            }
        }
    }
    return true;
}

int main()
{
    char currentPlayer = 'X';
    bool gameActive = true;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    initializeBoard();

    while (gameActive)
    {
        displayBoard();
        int row, col;

        do
        {
            cout << "Player " << currentPlayer << ", enter your move (row and column) : ";
            cin >> row >> col;
        }
        while (!isMoveValid(row, col));

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameActive = false;
        }
        else if (checkDraw())
        {
            displayBoard();
            cout << "It's a draw!" << endl;
            gameActive = false;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
