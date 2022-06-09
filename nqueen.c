#include <stdio.h>
#include <stdbool.h>
void printSolution(int n, int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
            {
                printf("Q ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
bool isAttacking(int n, int board[n][n], int row, int col)
{
    for (int i = 0; i < col; i++) // if queens placed in same columns
    {
        if (board[row][i])
        {
            return true;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // if queen placed is conflicting with left upper diagonal
    {
        if (board[i][j])
        {
            return true;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) // if queen placed is conflicting with left lower diagonal
    {
        if (board[i][j])
        {
            return true;
        }
    }
    return false;
}
bool solvenq(int n, int board[n][n], int col)
{
    if (col >= n)
    {
        printSolution(n, board);
    }
    for (int i = 0; i < n; i++)
    {
        if (!isAttacking(n, board, i, col))
        {
            board[i][col] = 1;
            if (solvenq(n, board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
int main()
{
    const int n = 4;
    printf("Size of Queen is 4\n");
    int board[4][4] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};
    solvenq(n, board, 0);
    return 0;
}
