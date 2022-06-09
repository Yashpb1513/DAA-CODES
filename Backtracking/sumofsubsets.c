#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int inc[50], w[50], sum, n;
int promising(int i, int wt, int total)
{
    return (((wt + total) >= sum) && ((wt == sum) || (wt + w[i + 1] <= sum)));
}
void SumofSubSet(int i, int wt, int total)
{
    int j;
    if (promising(i, wt, total))
    {
        if (wt == sum)
        {
            printf("\n{\t");
            for (j = 0; j <= i; j++)
            {
                if (inc[j] == TRUE)
                    printf("%d\t", w[j]);
            }
            printf("}\n");
        }
        else
        {
            inc[i + 1] = TRUE;
            SumofSubSet(i + 1, wt + w[i + 1], total - w[i + 1]);
            inc[i + 1] = FALSE;
            SumofSubSet(i + 1, wt, total - w[i + 1]);
        }
    }
}
int main()
{
    int i, j, n, temp, total = 0;
    printf("\nEnter the number of elements in Set:-->");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the Number %d:-->", i + 1);
        scanf("%d", &w[i]);
        total += w[i];
    }
    printf("\nInput the SUM value to create subset:-->");
    scanf("%d", &sum);
    // sort in asc order
    qsort(w, n, sizeof(int), compare);
    printf("\nElements in sorted order:-->", n);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", w[i]);
    }
    if (total < sum)
    {
        printf("\nSubset construction is not possible");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            inc[i] = 0;
        }
        printf("\nPossible solutions using backtracking:\n");
        SumofSubSet(-1, 0, total);
    }
    return 0;
}
