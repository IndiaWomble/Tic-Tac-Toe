//Tic Tac Toe

#include <iostream>

using namespace std;

char board [3][3];

void init_board ()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board [i][j] = ' ';
        }
    }
}

void display ()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board [i][j];
            if (j != 2)
            {
                cout << "   |";
            }
        }
        if (i != 2)
        {
            cout << endl;
            cout << "____|____|____";
        }
        cout << endl;
    }
}

bool user_input (int r, int c)
{
    if (board [r][c] != ' ')
    {
        return false;
    }
    else
    {
        board [r][c] = 'O';
        return true;
    }
}

bool availability ()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board [i][j] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

void computer_move ()
{
    if ((board [0][0] == board [0][1] || board [0][1] == board [0][0]) && board [0][2] == ' ')
    {
        board [0][2] = 'X';
    }
    else if ((board [0][0] == board [0][2] || board [0][2] == board [0][0]) && board [0][1] == ' ')
    {
        board [0][1] == 'X';
    }
    else if ((board [0][0] == board [2][2] || board [2][2] == board [0][0]) && board [1][1] == ' ')
    {
        board [1][1] = 'X';
    }
    else if ((board [0][0] == board [1][0] || board [1][0] == board [0][0]) && board [2][0] == ' ')
    {
        board [2][0] == 'X';
    }
    else if ((board [0][0] == board [1][1] || board [1][1] == board [0][0]) && board [2][2] == ' ')
    {
        board [2][2] == 'X';
    }
    else if ((board [0][0] == board [2][0] || board [2][0] == board [0][0]) && board [1][0] == ' ')
    {
        board [1][0] == 'X';
    }
    else if ((board [0][1] == board [0][2] || board [0][2] == board [0][1]) && board [0][0] == ' ')
    {
        board [0][0] == 'X';
    }


    else if ((board [0][2] == board [1][2] || board [1][2] == board [0][2]) && board [2][2] == ' ')
    {
        board [2][2] == 'X';
    }
    else if ((board [0][2] == board [2][2] || board [2][2] == board [0][2]) && board [1][2] == ' ')
    {
        board [1][2] == 'X';
    }
    else if ((board [0][2] == board [1][1] || board [1][1] == board [0][2]) && board [2][0] == ' ')
    {
        board [2][0] == 'X';
    }
    else if ((board [0][2] == board [2][0] || board [2][0] == board [0][2]) && board [1][1] == ' ')
    {
        board [1][1] == 'X';
    }
    else if ((board [1][0] == board [1][1] || board [1][1] == board [1][0]) && board [1][2] == ' ')
    {
        board [1][2] == 'X';
    }
    else if ((board [1][0] == board [1][2] || board [1][2] == board [1][0]) && board [1][1] == ' ')
    {
        board [1][1] == 'X';
    }
    else if ((board [1][0] == board [2][0] || board [2][0] == board [1][0]) && board [0][0] == ' ')
    {
        board [0][0] == 'X';
    }
    else if ((board [1][1] == board [2][2] || board [2][2] == board [1][1]) && board [0][0] == ' ')
    {
        board [0][0] == 'X';
    }
    else if ((board [1][1] == board [2][0] || board [2][0] == board [1][1]) && board [0][2] == ' ')
    {
        board [0][2] == 'X';
    }
    else if ((board [1][1] == board [2][1] || board [2][1] == board [1][1]) && board [0][1] == ' ')
    {
        board [0][1] == 'X';
    }
    else if ((board [1][1] == board [1][2] || board [1][2] == board [1][1]) && board [1][0] == ' ')
    {
        board [1][0] == 'X';
    }
    else if ((board [1][2] == board [2][2] || board [2][2] == board [1][2]) && board [0][2] == ' ')
    {
        board [0][2] == 'X';
    }
    else if ((board [2][0] == board [2][2] || board [2][2] == board [2][0]) && board [2][1] == ' ')
    {
        board [2][1] == 'X';
    }
    else if ((board [2][0] == board [2][1] || board [2][1] == board [2][0]) && board [2][2] == ' ')
    {
        board [2][2] == 'X';
    }
    else if ((board [2][1] == board [2][2] || board [2][2] == board [2][1]) && board [2][0] == ' ')
    {
        board [2][0] == 'X';
    }
    else if (availability ())
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board [i][j] == ' ')
                {
                    board [i][j] = 'X';
                    break;
                }
            }
        }
    }
}

void welcome ()
{
    cout << "\t\tWelcome to TicTacToe!\n";
    cout << "You will be playing against computer.\n";
    cout << "Enter the row and column in which you want to place your mark.\n";
    cout << "Your mark is 'O' \n";
}

int main ()
{
    welcome ();
    init_board ();
    display ();
    int row, column;
    while (availability ())
    {
        cin >> row >> column;
        if (row > 2 || column > 2)
        {
            return -1;
        }
        else
        {
            if (!user_input (row, column))
            {
                return -1;
            }
            else
            {
                 display ();
                cout << endl;
                computer_move ();
                display ();
            }
        }
    }
    return 0;
}
