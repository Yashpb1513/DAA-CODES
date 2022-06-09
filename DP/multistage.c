#include <stdio.h>
#include <limits.h>
#define n 8

int main()
{
    int stages = 4;
    printf("Number of stages=4 \n");
    // cost adjacency matrix
    int graph[n][n] =
        {{0, 1, 2, 5, 0, 0, 0, 0},
         {0, 0, 0, 0, 4, 11, 0, 0},
         {0, 0, 0, 0, 9, 5, 16, 0},
         {0, 0, 0, 0, 0, 0, 2, 0},
         {0, 0, 0, 0, 0, 0, 0, 18},
         {0, 0, 0, 0, 0, 0, 0, 13},
         {0, 0, 0, 0, 0, 0, 0, 2},
         {0, 0, 0, 0, 0, 0, 0, 0}};
    int distance[n];
    int path[stages];
    int cost[n];
    cost[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int min = INT_MAX;
        for (int k = i + 1; k <= n - 1; k++)
        {
            if (graph[i][k] != 0 && graph[i][k] + cost[k] < min)
            {
                min = graph[i][k] + cost[k];
                distance[i] = k; //saving the vertex which gave minmum value
            }
        }
        cost[i] = min;
    }
    path[0] = 0; //first vertex will always be 1(added +1 in display)
    path[stages - 1] = n;
    for (int i = 1; i < stages - 1; i++)
    {
        path[i] = distance[path[i - 1]];
    }
    printf("Path is: ");
    for (int i = 0; i < stages; i++)
    {
        if (i == stages - 1)
        {
            printf("%d\n", path[i]); // last node
        }
        else
        {
            // adding +1 because we are starting from 0 and vertices starts from 1
            printf("%d -> ", path[i] + 1); 
        }
    }
    printf("Minimum Cost= %d", cost[0]);
    return 0;
}
