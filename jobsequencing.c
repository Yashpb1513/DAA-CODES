#include <stdio.h>
#include <stdlib.h>
struct Job
{
    int jobid;
    float profit;
    int deadline;
};
int comparator(const void *a, const void *b)
{
    struct Job *j = (struct Job *)a;
    struct Job *j1 = (struct Job *)b;
    return (j1->profit - j->profit);
}
int minValue(int x, int y)
{
    if (x < y)
        return x;
    return y;
}
int main()
{
    int i, j, n, dmax = 0, counter = 0;
    float total_profit = 0;
    printf("Enter number of processes:");
    scanf("%d", &n);
    struct Job *arr = (struct Job *)malloc(n * sizeof(struct Job));
    int alloc[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter profit and deadine for job %d :", i + 1);
        scanf("%f %d", &arr[i].profit, &arr[i].deadline);
        arr[i].jobid = i + 1;
        alloc[i] = -1;
        if (arr[i].deadline > dmax)
        {
            dmax = arr[i].deadline;
        }
    }
    qsort(arr, n, sizeof(struct Job), comparator);
    for (i = 1; i <= n; i++)
    {
        for (j = minValue(dmax, arr[i - 1].deadline); j >= 1; j--)
        {
            if (alloc[j] == -1)
            {
                alloc[j] = i - 1;
                counter++;
                total_profit += arr[i - 1].profit;
                break;
            }
        }
        if (counter == dmax)
        {
            break;
        }
    }
    printf("Sequence:");
    for (i = 1; i <= dmax; i++)
    {
        printf("Job %d ", arr[alloc[i]].jobid);
    }
    printf("\nTotal profit= %f", total_profit);
}
