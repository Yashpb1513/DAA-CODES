#include <stdio.h>

#include <conio.h>

#define max 10


int w[max], i, j, p[max];

int n, m;

int y[max], x[max], fp = -1, fw;


void
get ()
{

  printf ("\n Enter total number of items: ");

  scanf ("%d", &n);

  printf ("\n Enter the Maximum capacity of the Sack: ");

  scanf ("%d", &m);

  for (i = 0; i < n; i++)

    {

      printf ("\n Enter the weight of the item # %d : ", i + 1);

      scanf ("%d", &w[i]);

      printf ("\n Enter the profit of the item # %d : ", i + 1);

      scanf ("%d", &p[i]);

    }

}


void
show ()
{

  float s = 0.0;

  printf ("\n\tItem\tWeight\tCost\tSelected ");

  for (i = 0; i < n; i++)

    printf ("\n\t%d\t%d\t%d\t%d", i + 1, w[i], p[i], x[i]);

  printf ("\n\n The Sack now holds following items : ");

  for (i = 0; i < n; i++)

    if (x[i] == 1)

      {

	printf ("%d\t", i + 1);

	s += (float) p[i] * (float) x[i];

      }

  printf ("\n Maximum Profit: %f ", s);

}


float
limit (float cp, float cw, int k)
{

  float b = cp;

  float c = cw;

  for (i = k; i <= n; i++)

    {

      c = c + w[i];

      if (c < m)

	b = b + p[i];

      else

	return (b + (1 - (c - m) / (float) w[i]) * p[i]);

    }

  return b;

}


void
knapsack (int k, float cp, float cw)
{

  if (cw + w[k] <= m)

    {

      y[k] = 1;

      if (k <= n)

	knapsack (k + 1, cp + p[k], cw + w[k]);

      if (((cp + p[k]) > fp) && (k == n))

	{

	  fp = cp + p[k];

	  fw = cw + w[k];

	  for (j = 0; j <= k; j++)

	    x[j] = y[j];

	}

    }

  if (limit (cp, cw, k) >= fp)

    {

      y[k] = 0;

      if (k <= n)

	knapsack (k + 1, cp, cw);

      if ((cp > fp) && (k == n))

	{

	  fp = cp;

	  fw = cw;

	  for (j = 0; j <= k; j++)

	    x[j] = y[j];

	}

    }

}


int
main ()
{


  get ();
  knapsack (0, 0.0, 0.0);

  show ();
  return 0;

}
