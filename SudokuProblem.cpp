#include <iostream>
#define N 9
#define UNASSIGNED 0

using namespace std;

bool FindUnassignedLocation(int grid[N][N], int &row, int &col)//v
{
    /*for (row = 0; row < N; row++)
        for ( col = 0; col < N; col++)
            if(grid[row][col] == UNASSIGNED)
            {
                return true;
            }

    return false;*/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if(grid[i][j] == UNASSIGNED)
            {
                return true;
            }

    return false;
}

bool RowNotSafe(int grid[N][N], int row, int num)//v
{
    for (int j = 0; j < N; j++)
        if(grid[row][j] == num)
            return true;

    return false;
}
bool ColNotSafe(int grid[N][N], int col, int num)//v
{
    for (int i = 0; i < N; i++)
        if(grid[i][col] == num)
            return true;

    return false;
}
bool SmallSquareNotSafe(int grid[N][N], int row, int col, int num)//v
{

    for (int i = 0; i < 3 ; i++)
        for (int j = 0; j < 3 ; j++)
            if(grid[i + row][j + col] == num )
                return true;

    return false;
}
bool isSafe(int grid[N][N], int row, int col, int num)//v
{
    return !RowNotSafe(grid, row, num) &&
           !ColNotSafe(grid, col, num) &&
           !SmallSquareNotSafe(grid, row - row % 3,
                               col - col % 3, num) &&
           (grid[row][col] == UNASSIGNED);
}


void printGrid(int grid[N][N])//v
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;

    if(FindUnassignedLocation(grid, row, col) == false)///What the fuck?!
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if(SolveSudoku(grid))
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    //cout<<"Into here4!\n";

    return false;

}

int main()//v
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};


    if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
