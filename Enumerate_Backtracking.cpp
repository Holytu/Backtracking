#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int solution[5];
bool used[5];
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

    for (int i = 0; i < 5; i++)
    {
        if(used[i] == false)
        {
            used[i] = true;
            solution[i] = n;
            backtracking(n+1);

            used[i] = false;
        }
    }
}
int main(void)
{
    for (int i = 0 ; i < 5; i++)
        used[i] = false;

    backtracking(0);

    return 0;
}
