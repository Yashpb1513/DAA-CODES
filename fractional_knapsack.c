#include <stdio.h>
#include <stdlib.h>
struct Sack
{
     float value, weight;
     int id;
};
int comparator(const void *a, const void *b)
{
     struct Sack *p = (struct Sack *)a;
     struct Sack *p1 = (struct Sack *)b;
     return (p1->value / p1->weight - p->value / p->weight);
}
int main()
{
     int items, i;
     float total_profit = 0, fract, capacity, wht = 0;
     printf("Enter number of items:");
     scanf("%d", &items);
     struct Sack *s = (struct Sack *)malloc(items * sizeof(struct Sack));
     printf("Enter capacity of Sack:");
     scanf("%f", &capacity);
     float flag[items];
     for (i = 0; i < items; i++)
     {
          printf("Enter profit and weight of item %d:", i + 1);
          scanf("%f %f", &s[i].value, &s[i].weight);
          s[i].id = i;
          flag[i] = 0;
     }
     qsort(s, items, sizeof(struct Sack), comparator);
     for (i = 0; i < items; ++i)
     {
          if (wht + s[i].weight <= capacity)
          {
               wht += s[i].weight;
               total_profit += s[i].value;
               flag[s[i].id] = 1;
               printf("Item %d added in the Sack and capacity= %f\n", s[i].id + 1, capacity - wht);
          }
          else
          {
               fract = ((capacity - wht) / s[i].weight);
               flag[s[i].id] = fract;
               total_profit += fract * s[i].value;
               wht += s[i].weight * fract;
               printf("%f %% of Item %d  is added in the Sack and capacity= %f\n", fract * 100, s[i].id + 1, capacity - wht);
               break;
          }
     }
     printf("Total profit=%f\n", total_profit);
     printf("Flag array:");
     for (i = 0; i < items; i++)
     {
          printf("%f ", flag[i]);
     }
     return 0;
}