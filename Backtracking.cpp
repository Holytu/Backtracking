#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int solution[5];
void PrintSolution()
{
    for (int i = 0 ; i < 5; i++)
    {
        cout<<solution[i]<<" ";
    }
    cout<<"\n";
}
void backtracking(int n)
{
    if( n == 5)
    {
        PrintSolution();
        return;
    }
    else
    {
        for (int i = 0; i <= 1; i++)
        {
            solution[n] = i;
            backtracking(n+1);
        }
    }
}
int main(void)
{
    backtracking(0);

    return 0;
}
