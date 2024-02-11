#include <stdio.h>

int queue[100];
int front = 0;
int back = 0;
int vertex[4] = {5, 1, 2, 3};

int visited[4] = {0};
int n = 4;
int g[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0},
};
void enqueue(int n)
{
    queue[back] = n;
    back++;
}

void dequeue()
{
    front++;
}

int bfs(int i)
{
    printf("%d ", vertex[i]);
    visited[i] = 1;
    enqueue(i);
    while (front != back)
    {
        int current = queue[front];
        for (int j = 0; j < 4; j++)
        {
            if (g[current][j] == 1 && visited[j] == 0)
            {
                printf("%d ", vertex[j]);
                visited[j] = 1;
                enqueue(j);
            }
        }
        dequeue();
    }
}

int main()
{
    bfs(0);
    return 0;
}
