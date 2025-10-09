/*
 * assignment1.c
 *
 *  Created on: Jul 28, 2025
 *      Author: administrator
 */


#include <stdio.h>
int accept(int fa[],int fn);
int display(int fa[],int fn);
int linearSearch(int fa[], int fn, int fns);
int bubbleSort(int fa[], int fn);
int binarySearch(int fa[], int fn, int fns);
int menu(void);

int accept(int fa[],int fn)
{
	for (int i=0;i<fn;i++)
	{
		printf("\nEnter element %d: ",i+1);
		scanf("%d",&fa[i]);
	}
	return 0;
}
int display(int fa[],int fn)
{
	printf("The array is: ");
	for (int i=0;i<fn;i++)
		{
			printf("%d ",fa[i]);
		}
	return 0;
}
int linearSearch(int fa[], int fn, int fns)
{
	int i=0;
	int flag=1;
	for (i=0;i<fn;i++)
		{
			if (fa[i]==fns)
			{
				flag=0;
			}
		}
	return flag;
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
	return 0;
}

int binarySearch(int fa[], int fn, int fns)
{
	int low=0;
	int high=(fn-1);
	int mid= (low+high)/2 ;
	int flag=0;
	while (low <=high)
	{
		if (fns==fa[mid])
			flag=1;
		if (fns<fa[mid])
			high=mid-1;
		else
			low=mid+1;

		mid=(low+high)/2;
	}
	return flag;
}

int menu(void)
{
	int choice=0;
	do
	{
		printf("\nMENU OPERATIONS:  \n");
		printf("\n1. Linear Search \n2. Bubble Sort \n3. Binary Search \n0. Exit\n");
		printf("\nWhat operation would you like to perform? ");
		scanf("%d",&choice);
	}while(choice<0 || choice>3);
	return choice;
}


int main()
{
	int n=0;
	int found=0;
	printf("\nEnter how many elements you want in array? ");
	scanf("%d",&n);
	printf("\nEnter the elements: \n");
	int a[n];
	accept(a,n);
	display(a,n);


	int ch=0;
	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:

			int ns=0;
			printf("\nWhich element do you want to search? ");
			scanf("%d",&ns);
			found= linearSearch(a,n,ns);
			if (found==0)
			{
				printf("\nThe number %d is found in the array\n",ns);
			}
			else
			{
				printf("\nThe number %d is not found in the array\n",ns);
			}
			break;

		case 2:

			bubbleSort(a,n);
			printf("\nThe sorted array is:  ");
			for (int i=0;i<n;i++)
			{
				printf("%d ",a[i]);
			}
			break;

		case 3:

			bubbleSort(a,n);
			printf("\nWhich element do you want to search? ");
			scanf("%d",&ns);
			found= binarySearch(a,n,ns);
			if (found==1)
			{
				printf("\nThe number %d is found in the array\n",ns);
			}
			else
			{
				printf("\nThe number %d is not found in the array\n",ns);
			}
			break;

		case 0:

			printf("\nTHank you! ");
			break;
		}


	}while(ch!=0);
	return 0;
}
