#include <stdio.h>
#include <stdlib.h>
int *arr;
int c = 0;
void merge(int l, int mid, int u)
{
    int *temp, i = l, j = mid + 1, k = 0, m = u - l + 1;
    temp = (int *)malloc(sizeof(int) * m);
    while (i <= mid && j <= u)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
            c++;
        }
        else
        {
            temp[k++] = arr[j++];
            c++;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
        c++;
    }
    while (j <= u)
    {
        temp[k++] = arr[j++];
        c++;
    }
    for (i = l, j = 0; i <= u; i++, j++)
    {
        arr[i] = temp[j];
    }
}
void merge_sort(int l, int u)
{
    if (l < u)
    {
        int mid = (l + u) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, u);
        merge(l, mid, u);
    }
}
int main()
{
    int i, n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    /*for(i=0;i<n;i++)
    {
        arr[n-1-i]=i;
    }*/
    /*for(i=n-1;i>=0;i--)
    {
        arr[n-1-i]=i;
    }*/
    merge_sort(0, n - 1);
    printf("Sorted list is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Comparisons =%d\n", c);
    return 0;
}
