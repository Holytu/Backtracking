#include <iostream>
#include <cstdio>
#include <stdbool.h>
#include <cstdlib>
#include <time.h>
#define N 4

using namespace std;
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool isSafe(int board[N][N], int row, int col)
{
    int x = 0, y = 0;
    bool return_value = true;

    while(y < col)// same row, and in the left column
    {
        if(board[row][y] == 1)
        {
            return_value = false;
            break;
        }
        y++;
    }

    x = 0; y = 0;
    while(x < row && y < col)//upper diagonal
    {
        if(board[x][y] == 1)
        {
            return_value = false;
            break;
        }
        x++; y++;
    }
    x = N - 1; y = 0;
    while(x > row && y < col)// left diagonal
    {
        if(board[x][y] == 1)
        {
            return_value = false;
            break;
        }
        x--; y++;
    }

    return return_value;
}
bool solveNQUtil(int board[N][N], int col)
{
    if(col >= N)//lose to add this condition
        return true;

    for (int i = 0 ; i < N; i++)
    {
        if( isSafe(board, i, col) == true)
        {
            board[i][col] = 1;

            if(solveNQUtil(board, col + 1))
            {
                return true;
            }

        }
        board[i][col] = 0;
    }
    return false;
}
void solveNQ()
{
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if(solveNQUtil(board, 0) == false)
    {
        cout<<"Wrong NQ answer. Try another one\n";
    }

    printSolution(board);
}
int main()
{
    solveNQ();
    return 0;
}
