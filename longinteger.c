#include <stdio.h>
#include <math.h>
int noOfDigits(int x, int y)
{
    int n = 0;
    if (x < y)
    {
        x = y;
    }
    while (x != 0)
    {
        if (x != 0)
        {
            n++;
        }
        x = x / 10;
    }
    return n;
}
int longinteger(int u, int v, int n)
{
    int x, w, y, z;
    if (n == 1)
    {
        return u * v;
    }
    else
    {
        x = u / pow(10, n / 2);
        y = u % (int)pow(10, n / 2);
        w = v / pow(10, n / 2);
        z = v % (int)pow(10, n / 2);
        // u = pow(10, n / 2) * x + y;
        // v = pow(10, n / 2) * w + z;
        int p1 = longinteger(x, w, n / 2);
        int p2 = longinteger(y, z, n / 2);
        int p3 = longinteger(x + y, z + w, n / 2);
        int t = p1 * pow(10, n) + (p3 - p1 - p2) * pow(10, n / 2) + p2;
        return (t);
    }
}
int main()
{
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    int n = noOfDigits(x, y);
    printf("%d", longinteger(x, y, n));
    return 0;
}