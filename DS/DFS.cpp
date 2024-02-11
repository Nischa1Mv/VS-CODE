#include <stdio.h>
#include <conio.h>
void dfs(int);
int n = 4;
int visited[4] = {0};
int vertex[4] = {0, 1, 2, 3};
int g[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0},
};
void dfs(int i)
{
    int j;
    printf("%d", vertex[i]);
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && g[i][j] == 1)
            dfs(j);
}

int main()
{
    dfs(0);
    return 0;
}