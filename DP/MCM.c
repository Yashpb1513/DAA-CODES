#include <stdio.h>
#include <limits.h>

int alpha = 65;
void parenthesis(int i, int j, int n, int para[n][n])
{
    if (i == j)
    {
        printf("%c", (char)alpha);
        alpha++;
        return;
    }
    printf("(");
    parenthesis(i, para[i][j], n, para);
    parenthesis(para[i][j] + 1, j, n, para);
    printf(")");
}
void mcm(int input[], int n)
{
    int matrix[n][n];
    int para[n][n];
    for (int i = 1; i < n; i++)
    {
        matrix[i][i] = 0;
    }
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            matrix[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = matrix[i][k] + matrix[k + 1][j] + input[i - 1] * input[k] * input[j];
                if (cost < matrix[i][j])
                {
                    matrix[i][j] = cost;
                    para[i][j] = k;
                }
            }
        }
    }
    printf("Optimal Solution is : ");
    parenthesis(1, n - 1, n, para);
    printf("\nOptimal Cost is: %d", matrix[1][n - 1]);
}
int main()
{
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int input[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    mcm(input, n);
    return 0;
}