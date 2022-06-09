#include<stdio.h>
#include<stdlib.h>
int c=0;
int partition(int *a,int l,int u)
{
	int temp,start,end,pivot;
	pivot=a[l];
	start=l;
	end=u+1;
	do
	{
		do
		{
			start++; 
			c++;
		}while(a[start]<pivot && start<=u);
		do
		{
			end--;
		}while(pivot<a[end]);
		if(start<end)
		{
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}while(start<end);
	a[l]=a[end];
	a[end]=pivot;
	return (end);
}
void quicksort(int *a,int l,int u)
{
	int pivot;
	if(l<u)
	{
		pivot=partition(a,l,u);
		quicksort(a,l,pivot-1);
		quicksort(a,pivot+1,u);
		c++;
	}
}
int main()
{
	int *a,i,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    /*for(i=0;i<n;i++)
    {
        a[n-1-i]=i;
    }*/
    /*for(i=n-1;i>=0;i--)
    {
        a[n-1-i]=i;
    }*/
	quicksort(a,0,n-1);
	// printf("Sorted List:\n");
	// for(i=0;i<=n-1;i++)
	// {
	// 	printf("%d\n",a[i]);
	// }
	printf("Comparisons= %d",c);
}