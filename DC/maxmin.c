#include <stdio.h>
int min, max;
int a[100];
void maxmin(int i, int num)
{
    int max1, min1, mid;
    if (i == num)
    {
        max = min = a[i];
    }
    else
    {
        if (i == num - 1)
        {
            if (a[i] < a[num])
            {
                max = a[num];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[num];
            }
        }
        else
        {
            mid = (i + num) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, num);
            if (max < max1)
            {
                max = max1;
            }
            if (min > min1)
            {
                min = min1;
            }
        }
    }
}
int main()
{
    int i, num;
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &num);
    printf("Enter the numbers : \n");
    for (i = 1; i <= num; i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];
    min = a[0];
    maxmin(1, num);
    printf("Minimum element in an array : %d\n", min);
    printf("Maximum element in an array : %d\n", max);
    return 0;
}
