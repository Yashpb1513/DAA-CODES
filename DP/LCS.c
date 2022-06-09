#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
void lcs(int len1, int len2, char *str1, char *str2)
{
    int LCS[len1 + 1][len2 + 1];
    int k = 0;
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
            {
                LCS[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    int ind = LCS[len1][len2];
    char sequence[ind + 1];
    sequence[ind] = '\0';
    printf("The length of longest commen subsequnece: %d", ind);
    while (len1 > 0 && len2 > 0)
    {
        if (str1[len1-1] == str2[len2 - 1])
        {
            sequence[ind - 1] = str1[len1 - 1];
            len1--;
            len2--;
            ind--;
        }
        else if (LCS[len1 - 1][len2] > LCS[len1][len2 - 1])
        {
            len1--;
        }
        else
        {
            len2--;
        }
    }
    printf("\nLongest Common Subsequnce is: ");
    puts(sequence);
}
int main()
{
    int len1 = 0, len2 = 0;
    char dummy[100], _tempnam;
    printf("Enter string 1: ");
    gets(dummy);
    len1 = strlen(dummy);
    char str1[len1];
    strcpy(str1, dummy);
    printf("Enter string 2: ");
    gets(dummy);
    len2 = strlen(dummy);
    char str2[len2];
    strcpy(str2, dummy);
    lcs(len1, len2, str1, str2);
    return 0;
}