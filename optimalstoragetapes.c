#include <stdio.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int optimal(int *programs, int n)
{
    int t = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            t = t + programs[j];
        }
    }
    return t;
}
int main()
{
    int n;
    printf("Enter number of programs: ");
    scanf("%d", &n);
    int programs[n];
    printf("Enter retrieval time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &programs[i]);
    }
    qsort(programs, n, sizeof(int), cmpfunc);
    printf("Sorted Programs: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", programs[i]);
    }
    printf("\n");
    float mrt = (float)optimal(programs, n);
    printf("Total retrieval time=%f\n", mrt);
    printf("Mean retrieval time=%f", mrt / n);
}