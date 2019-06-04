#include <iostream>
#include <cstdio>

#define N 4

using namespace std;
void PrintSolution(int sol[N][N] )
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool isSafety(int x, int y, int maze[N][N])
{
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 )/// x > 0
    {
        return true;
    }

    return false;
}
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x == N -1 && y == N - 1 )
    {
        sol[x][y] = 1;
        return true;
    }

    if(isSafety(x, y, maze) == true)
    {
        sol[x][y] = 1;

        if(solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;

        if(solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;

        sol[x][y] = 0;

        return false;
    }

    return false;///return true;
}
void solveMaze(int maze[N][N])
{
    int sol[N][N]  = {0};


    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        cout<<"No solutions\n";
    }

    PrintSolution(sol);
}
int main()
{
    int maze[N][N] = {
                       { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 }

                    };

    solveMaze(maze);

    return 0;
}
