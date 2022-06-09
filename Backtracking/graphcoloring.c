#include <stdio.h>
int G[50][50], x[50];

void GraphColor(int k)
{
    int i, j;
    x[k] = 1;
    for (i = 0; i < k; i++)
    {
        if (G[i][k] != 0 && x[k] == x[i])
        {
            x[k] = x[i] + 1;
        }
    }
}
int main()
{
    int n, e, i, j, k, l;
    printf("Enter the number of vertices:-->");
    scanf("%d", &n);
    printf("Enter the number of edges:-->");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }
    printf("Enter indexes where value is 1:-->\n");
    for (i = 0; i < e; i++)
    {
        printf("Enter the edges:-->");
        scanf("%d %d", &k, &l);
        G[k][l] = 1;
        G[l][k] = 1;
    }
    for (i = 0; i < n; i++)
    {
        GraphColor(i);
    }
    printf("\nThe graph is colored as follows:\n");
    for (i = 0; i < n; i++)
    {
        printf("vertex[%d]: %d\n", i + 1, x[i]);
    }
    return 0;
}