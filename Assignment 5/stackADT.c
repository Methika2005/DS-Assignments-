/*
 * stack.c
 *
 *  Created on: 6 Oct 2025
 *      Author: Admin
 */


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int push (struct node **ftop, int *fidata);
int pop (struct node **ftop, int *fodata);
void stackEmpty(struct node **ftop);
void displayTop(struct node **ftop);
int menu(void);

int push (struct node **ftop, int *fidata)
{
	struct node *top=NULL;
	struct node *newnode=NULL;
	int fsuccess=0;
	top=*ftop;
	newnode=(struct node *)calloc(1, sizeof(struct node));
	if (newnode==NULL)
	{
		printf("Memory allocation failed, stack full");
		fsuccess=1;
	}
	else
	{
	    newnode->data=*fidata;
		if (top==NULL)
		{
			top=newnode;
		}
		else
		{
			newnode->next=top;
			top=newnode;
		}
	}
	*ftop=top;
	return fsuccess;
}

int pop (struct node **ftop, int *fodata)
{
	struct node *top=NULL;
	struct node *X=NULL;
	struct node *i=NULL;
	int fsuccess=0;
	top=*ftop;
	if (top==NULL)
	{
		printf("\nNo element to pop. Stack Empty");
		fsuccess=1;
		return fsuccess;
	}
	else
	{
	    *fodata=top->data;
	    printf("\nThe popped element is %d",*fodata);
		X=top;
		top=top->next;
		free(X);
	}
	*ftop=top;
	return 0;
}

void stackEmpty(struct node **ftop)
{
	struct node *top=NULL;
	top=*ftop;
	if (top==NULL)
	{
		printf("\nTrue");
	}
	else
	{
		printf("\nFalse");
	}
	*ftop=top;
}

void displayTop(struct node **ftop)
{
	struct node *top=NULL;
	int topdata=0;
	top=*ftop;
	if (top!=NULL)
	{
		topdata=top->data;
	}
	*ftop=top;
	printf("The top element is %d",topdata);
}

int menu(void)
{
	int ch=0;
	do
	{
		printf("\nSTACK OPERATIONS");
		printf("\n1. push \n2. pop \n3. stackEmpty \n4. displayTop \n0. Exit");
		printf("\nEnter your choice: ");
		fflush(stdout);
		scanf("%d", &ch);
	}while(ch<0 || ch>4);
	return ch;
}

int main(void)
{
	struct node *top=NULL;
	int option=0;
	int odata=0;
	int idata=0;
	do
	{
		option=menu();
		switch(option)
		{
		case 1:
			printf("\nEnter the element to push: ");
			fflush(stdout);
			scanf("%d", &idata);
			push(&top, &idata);
			break;

		case 2:

			printf("\nThe popped element is : ");
			pop(&top,&odata);
			break;

		case 3:
			stackEmpty(&top);
			break;

		case 4:
			printf("\nThe top element is: ");
			displayTop(&top);
			break;

		case 0:
			printf("Exiting...");
			printf("Thank you!");
			break;
		}

	}while(option!=0);
	return 0;
}