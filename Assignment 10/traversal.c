/*
 * traversal.c
 *
 *  Created on: Oct 30, 2025
 *      Author: administrator
 */


#include<stdio.h>
#include<stdlib.h>

struct node         // for adjacency list
{          
    int vnum;
    struct node *next;
};

struct stacknode        // for stack
{     
    int data;
    struct stacknode *next;
};

struct queuenode        // for queue
{
    int data;
    struct queuenode *next;
};



int push (struct stacknode **ftop, int fidata)
{
	struct stacknode *top=NULL;
	struct stacknode *newnode=NULL;
	int fsuccess=0;
	top=*ftop;
	newnode=(struct stacknode *)calloc(1, sizeof(struct stacknode));
	if (newnode==NULL)
	{
		printf("Memory allocation failed, stack full");
		fsuccess=1;
	}
	else
	{
	    newnode->data=fidata;
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

int pop (struct stacknode **ftop, int *fodata)
{
	struct stacknode *top=NULL;
	struct stacknode *X=NULL;
	struct stacknode *i=NULL;
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
		X=top;
		top=top->next;
		free(X);
	}
	*ftop=top;
	return 0;
}

int enqueue(struct queuenode **ffront, struct queuenode **frear, int *fidata)
{
    struct queuenode *front=NULL;
    struct queuenode *newnode=NULL;
    struct queuenode *rear=NULL;
    front=*ffront;
    rear=*frear;
    int fsuccess=0;
    newnode=(struct queuenode *)calloc(1,sizeof(struct queuenode));
    if (newnode==NULL)
    {
        printf("\nMemory Allocation failed\n");
        fsuccess=1;
    }
    newnode->data=*fidata;
    newnode->next=NULL;
    if (rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    *ffront=front;
    *frear=rear;
    return fsuccess;
}

int dequeue(struct queuenode **ffront, struct queuenode **frear, int *fodata)
{
    struct queuenode *front=NULL;
    struct queuenode *temp=NULL;
    struct queuenode *rear=NULL;
    front=*ffront;
    rear=*frear;
    int fsuccess=0;
    if (front==NULL)
    {
        printf("Queue empty");
        fsuccess=1;
    }
    else
    {
        *fodata=front->data;
        temp=front;
        front=front->next;
        if (front==NULL)
        {
            rear=NULL;
        }
        free(temp);
    }
    *ffront=front;
    *frear=rear;
    return fsuccess;
}   


void create(struct node ***fvertex, int fv)
{
	struct node *newnode=NULL;
	*fvertex=(struct node **)calloc(fv,sizeof(struct node *));
	int i=0;
	int j=0;
	for (i=0;i<fv;i++)
	{
	    (*fvertex)[i]=NULL;
	}
	for (i=0;i<fv;i++)
	{
        char link;
        for(j=0;j<fv;j++)
        {
            printf("\nIs there any link from %d to %d? (y/n)", i, j);
		    scanf(" %c", &link);
		    if (link=='Y' || link=='y')
		    {
		        newnode=(struct node *)calloc(1,sizeof(struct node));
		        if (newnode==NULL)
		        {
		            printf("\nMemory allocation failed\n");
		        }
		        newnode->vnum=j;
		        newnode->next=(*fvertex)[i];
		        (*fvertex)[i]=newnode;
		    }
        }
	}

}

void display(struct node **fvertex, int fv)
{
    printf("\nAdjacency List Representation\n");
    struct node *temp=NULL;
    int i=0;
    for (i=0;i<fv;i++)
    {
        printf("Vertex %d->",i);
        temp=fvertex[i];
        while(temp!=NULL)
        {
            printf("%d->", temp->vnum);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void dfs(struct node **fvertex, int start, int fv)
{
    if (start<0||start>=fv)
    {
        printf("\nInvalid starting vertex \n");
        return;
    }
    int *visited=(int *)calloc(fv,sizeof(int));
    struct stacknode *top=NULL;
    push(&top,start);
    printf("\nDFS Traversal starting from vertex %d: ", start);
    
    int curr=0;
    while(top!=NULL)
    {
        pop(&top, &curr);
        if (visited[curr])
        {
            continue;
        }
        visited[curr]=1;
        printf("%d ", curr);
    
        struct node *temp=fvertex[curr];
        while(temp!=NULL)
        {
            int neighbour=0;
            neighbour=temp->vnum;
            if (visited[neighbour]==0)
            {
                push(&top,neighbour);
            }
            temp=temp->next;
        }
    }
    printf("\n");
    free(visited);
}

void bfs(struct node **fvertex, int start, int fv)
{
    struct queuenode *front=NULL;
    struct queuenode *rear=NULL;
    struct node *temp=NULL;
    
    if (start<0||start>=fv)
    {
        printf("\nInvalid starting vertex \n");
        return;
    }
    int *visited=(int *)calloc(fv,sizeof(int));
    if (visited==NULL)
    {
        printf("\nMemory allocation failed.");
        return;
    }
    
    enqueue(&front, &rear,&start);
    visited[start]=1;
    
    printf("\nBFS traversal starting from vertex %d : ", start);
    
    while(front!=NULL)
    {
        int curr=0;
        dequeue(&front, &rear,&curr);
        printf("%d ",curr);
        temp=fvertex[curr];
        while(temp!=NULL)
        {
            int neighbour=0;
            neighbour=temp->vnum;
            if (visited[neighbour]==0)
            {
                visited[neighbour]=1;
                enqueue(&front, &rear, &neighbour);
            }
            temp=temp->next;
        }
        
    }
    printf("\n");
    free(visited);
}


int menu (void)
{
    int choice=0;
    do
    {
        printf("\nGRAPH TRAVERSALS");
        printf("\nWhat would you like to perform?");
        printf("\n1. DFS Traversal \n2. BFS Traversal \n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    }while(choice<0||choice>2);
    return choice;
}

int main(void)
{
	int ch=0;
	int v=0;
	printf("\nHow many vertices do you want in your graph? ");
	scanf("%d", &v);
	struct node **vertex=NULL;
	create (&vertex, v);
	display(vertex, v);
    int start=0;
	do
	{
		ch=menu();
		switch(ch)
		{
		case 1:

			printf("\nDFS Traversal");
			printf("\nEnter starting vertex for DFS: ");
			scanf("%d", &start);
			dfs(vertex, start,v);
			break;

		case 2:
			printf("\nBFS Traversal");
			printf("\nEnter starting vertex for BFS: ");
			scanf("%d", &start);
			bfs(vertex, start,v);
			break;

		case 0:
			printf("\nExiting...");
			printf("\nThank you!");
		}
	}while(ch!=0);

	return 0;
}