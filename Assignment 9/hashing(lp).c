/*
 * hashing.c
 *
 *  Created on: 28-Oct-2025
 *      Author: ADMIN
 */


#include <stdio.h>
#include <stdlib.h>

int hash(int key, int SIZE);
void create(int ftable[][3], int fSIZE, int value);
void display(int ftable[][3], int fSIZE);
void search(int ftable[][3], int fSIZE, int fns);
int menu (void);

int hash(int key, int SIZE)
{
	return key%SIZE;
}

void create(int ftable[][3], int fSIZE, int value)
{
	int home=0;
	int index=0;
	home= hash(value,fSIZE);
	index=home;

	if (ftable[index][1]==-1)
	{
		ftable[index][1]=value;
	}
	else
	{
		while(ftable[index][1]!=-1)
		{
			index=(index+1)%fSIZE;
			if (index==home)
			{
				printf("Hash table full, cannot insert %d\n", value);
				return;
			}
		}
		ftable[index][1]=value;
		int prev=home;
		while (ftable[prev][2]!=-1)
		{
			prev=ftable[prev][2];
		}
		ftable[prev][2]=index;
	}
}

void display(int ftable[][3], int fSIZE)
{
	int i=0;
	int j=0;
	printf("Bucket\tData\tChain\n");
	for (i=0;i<fSIZE;i++)
	{
		printf("\n");
		for (j=0;j<3;j++)
		{
			printf("%d\t", ftable[i][j]);
		}
	}
}

void search(int ftable[][3], int fSIZE, int fns)
{
    int home=0;
    int index=0;
    home=hash(fns,fSIZE);
    index=home;
    
    while(index!=-1)
    {
        if(ftable[index][1]==fns)
        {
            printf("\n%d found at bucket (index)%d.",fns,index);
            return;
        }
        index=ftable[index][2];
    }
    
    printf("\n%d not found in the hash table",fns);
}


int menu (void)
{
    int choice=0;
    do
    {
        printf("\nHASHING");
        printf("\nWhat would you like to perform?");
        printf("\n1. Create \n2. Display \n3. Search \n0. Exit");
        printf("\nEnter your choice: \n");
        scanf("%d",&choice);
    }while(choice<0||choice>3);
    return choice;
}

int main(void)
{
	int SIZE;
	printf("Enter number of buckets: ");
	scanf("%d", &SIZE);

	int table[SIZE][3];
	int i=0;
	for (i=0;i<SIZE;i++)
	{
		table[i][0]=i;
		table [i][1]=-1;
		table[i][2]=-1;
	}
	int n;
	
    printf("\nEnter number of values to insert (max %d): ", SIZE);
    scanf("%d", &n);
    
    int arr[n];
	
    int ns=0;
    int ch=0;
    do
    {
        ch=menu();
        switch(ch)
        {
            case 1:
            for (i=0;i<n;i++)
            {
                printf("Enter %d element: ",i+1);
                scanf("%d", &arr[i]);
            }
			for (i=0;i<n;i++)
			{
				create(table, SIZE, arr[i]);
			}
			break;

            case 2:
            display(table,SIZE);
            break;

            case 3:
            printf("\nEnter value to search: ");
            scanf("%d", &ns);
            search(table, SIZE,ns);
            break;

            case 0:
            printf("\nExiting...");
            printf("\nThank you!");
        }
    }while(ch!=0);

    return 0;
}
