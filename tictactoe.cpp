#include <iostream>
#include <windows.h> // For colors (works on Windows)
using namespace std;

// Function to set color
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Display Board
void displayBoard(char board[3][3])
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
                setColor(12); // red
            else if (board[i][j] == 'O')
                setColor(9);  // blue
            else
                setColor(7);  // white

            cout << board[i][j];
            setColor(7);

            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Check Win
bool checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Game Function
void playGame()
{
    char board[3][3];
    int num = 1;

    // Initialize board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++ + '0';

    char player1 = 'X'; // you can say ??
    char player2 = 'O'; // you can say ?

    char current = player1;
    int choice, row, col;
    int moves = 0;
    bool win = false;

    while (!win && moves < 9)
    {
        displayBoard(board);

        cout << "Player ";
        setColor(current == 'X' ? 12 : 9);
        cout << current;
        setColor(7);
        cout << ", enter box (1-9): ";

        cin >> choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        {
            setColor(12);
            cout << "Invalid move! Try again.\n";
            setColor(7);
            continue;
        }

        board[row][col] = current;
        moves++;

        if (checkWin(board, current))
        {
            displayBoard(board);
            setColor(10);
            cout << "?? Player " << current << " wins!\n";
            setColor(7);
            win = true;
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    if (!win)
    {
        displayBoard(board);
        setColor(14);
        cout << "?? Game Draw!\n";
        setColor(7);
    }
}

// Menu
int main()
{
    int choice;

    do
    {
        setColor(11);
        cout << "\n===== ?? TIC TAC TOE =====\n";
        setColor(7);

        cout << "1. Play Game\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playGame();
            break;

        case 2:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 2);

    return 0;
}
