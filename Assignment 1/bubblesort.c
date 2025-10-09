/*
 * bubblesort.c
 *
 *  Created on: Jul 28, 2025
 *      Author: administrator
 */


#include <stdio.h>
int bubbleSort(int fa[], int fn);
int main(void)
{
	int i=0;
	int j=0;
	int n=0;
	printf("Number of elements? ");
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	bubbleSort(a,n);

	return 0;
}
int bubbleSort(int fa[], int fn)
{
	for (int i=0;i<(fn-1);i++)
		{
			for (int j=0;j<(fn-1-i);j++)
			{
				if (fa[j]>fa[j+1])
				{
					int temp=fa[j];
					fa[j]=fa[j+1];
					fa[j+1]=temp;
				}
			}
		}
		for (int i=0;i<fn;i++)
		{
			printf("%d ",fa[i]);
		}

	return 0;
}
