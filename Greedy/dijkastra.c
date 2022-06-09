#include <stdio.h>
#include <stdbool.h>
#define MAX 999
#define v 9
int mindistance(int distance[], bool vertset[])
{
    int minimum = MAX;
    int index;
    for (int i = 0; i < v; i++)
    {
        if (vertset[i] == false && distance[i] <= minimum)
        {
            minimum = distance[i];
            index = i;
        }
    }
    return index;
}
void djkastra(int graph[v][v], int source)
{
    int distance[v];
    bool vertset[v];
    for (int i = 0; i < v; i++)
    {
        distance[i] = MAX;
        vertset[i] = false;
    }
    distance[source] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int u = mindistance(distance, vertset);
        vertset[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (!vertset[v] && graph[u][j] != 0 && distance[u] != MAX && distance[u] + graph[u][j] < distance[j])
            {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }
    printf("Vertex list \t Distance");
    for (int i = 0; i < v; i++)
    {
        printf("\n%d \t\t %d", i, distance[i]);
    }
}
int main()
{
    // printf("Enter number of vertices:");
    // scanf("%d",&v);
    // int graph[v][v];
    // for(int i=0; i<v;i++)
    // {
    //     printf("Enter edges for vertex %d: ",i);
    //     for(int j=0;j<v;j++)
    //     {
    //         scanf("%d",&graph[i][j]);
    //     }
    // }
    int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    djkastra(graph, 0);
    return 0;
}
