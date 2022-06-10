#include <bits/stdc++.h>
using namespace std;
void
paran (int i, int j, int n, vector < vector < int >>bracket, char &name)
{
  if (i == j)
    {
      cout << name++;
      return;

    }
  cout << "(";
  paran (i, bracket[i][j], n, bracket, name);
  paran (bracket[i][j] + 1, j, n, bracket, name);
  cout << ")";
}

void
mcm (int p[], int n)
{
  int m[n][n];
  vector < vector < int >>bracket (n, vector < int >(n));
  for (int i = 1; i < n; i++)
    {
      m[i][i] = 0;
  } for (int t = 2; t < n; t++)
    {
      for (int i = 1; i < n - t + 1; i++)
	{
	  int j = i + t - 1;
	  m[i][j] = INT_MAX;
	  for (int k = i; k <= j - 1; k++)
	    {
	      int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
	      if (temp < m[i][j])
		{
		  m[i][j] = temp;
		  bracket[i][j] = k;
		}
	    }
	}
    }

  char name = 'A';
  cout << "Parenthesization: ";
  paran (1, n - 1, n, bracket, name);
  cout << "\nOptimalCost: " << m[1][n - 1];
} int

main ()
{
  cout << "Enter the number of matrices: ";
  int n;
  cin >> n;
  int a[n + 1];
  cout <<
    "Enter the order consequently without repeating the adjacent ones: ";
  for (int i = 0; i <= n; i++)
    {
      int temp;
      cin >> temp;
      a[i] = temp;
    } mcm (a, sizeof (a) / sizeof (a[0]));
  return 0;
}
