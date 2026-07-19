#include <iostream>
#include <windows.h>
using namespace std;

char matrix[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char player = 'X';

void draw()
{
    system("cls");
    
    cout << "-------------\n";

    for (int r = 0; r < 3; r++)
    {
        cout << "| ";

        for (int c = 0; c < 3; c++)
        {
            cout << matrix[r][c] << " | ";
        }

        cout << endl;
        cout << "-------------\n";
    }
}

void read()
{
    char pos;

    cout << "Enter position (" << player << "): ";
    cin >> pos;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (matrix[r][c] == pos)
            {
                matrix[r][c] = player;
            }
        }
    }

    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char checkwinner()
{
 
    for (int r = 0; r < 3; r++)
    {
        if (matrix[r][0] == matrix[r][1] &&
            matrix[r][1] == matrix[r][2])
        {
            return matrix[r][0];
        }
    }

    for (int c = 0; c < 3; c++)
    {
        if (matrix[0][c] == matrix[1][c] &&
            matrix[1][c] == matrix[2][c])
        {
            return matrix[0][c];
        }
    }


    if (matrix[0][0] == matrix[1][1] &&
        matrix[1][1] == matrix[2][2])
    {
        return matrix[0][0];
    }

    if (matrix[0][2] == matrix[1][1] &&
        matrix[1][1] == matrix[2][0])
    {
        return matrix[0][2];
    }


    int counter = 0;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (matrix[r][c] != 'X' &&
                matrix[r][c] != 'O')
            {
                counter++;


                
            }
        }
    }

    if (counter == 0)
        return '=';

    return '*';
}

int main()
{
    while (checkwinner() == '*')
    {
        draw();
        read();
    }

    draw();

    if (checkwinner() == 'X')
        cout << "\nWinner is player X\n";

    else if (checkwinner() == 'O')
        cout << "\nWinner is player O\n";

    else
        cout << "\nNo winner\n";

        return 0;

}