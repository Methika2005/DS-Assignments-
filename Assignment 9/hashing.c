#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int hash (int key);
void create (struct node *ftable[], int fvalue);
void display(struct node *ftable[]);
void search(struct node *ftable[], int fns);
int menu (void);

int hash (int key)
{
    return key%10;
}

void create (struct node *ftable[], int fvalue)
{
    int index=0;
    index=hash(fvalue);
    struct node *newnode=NULL;
    struct node *temp=NULL;
    newnode=(struct node *)calloc(1,sizeof(struct node));
    newnode->data=fvalue;
    newnode->next=NULL;
    
    if (ftable[index]==NULL)
    {
        ftable[index]=newnode;
    }
    else
    {
        temp=ftable[index];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}


void display(struct node *ftable[])
{
    int i=0;
    struct node *j=0;
    printf("\nHash Table\n");
    for (i=0;i<10;i++)
    {
        printf("[%d]: ", i);
        j=ftable[i];
        while(j!=NULL)
        {
            printf("%d -> ", j->data);
            j=j->next;
        }
        printf("NULL\n");
    }
}


void search(struct node *ftable[], int fns)
{
    int index=0;
    int found=0;
    index=hash(fns);
    struct node *i=NULL;
    i=ftable[index];
    while(i!=NULL)
    {
        if (i->data==fns)
        {
            printf("\n%d found at index %d\n", fns, index);
            found=1;
            break;
        }
        i=i->next;
    }
    if (found==0)
    {
        printf("%d not found", fns);
    }
    
}

int menu (void)
{
    int choice=0;
    do
    {
        printf("\nHASHING");
        printf("\nWhat would you like to perform?");
        printf("\n1. Create \n2. Display \n3. Search \n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    }while(choice<0||choice>3);
    return choice;
}

int main(void)
{
    struct node *table[10]={NULL};
    int value=0;
    int ns=0;
    int ch=0;
    do
    {
        ch=menu();
        switch(ch)
        {
            case 1:
            printf("\nEnter value to insert: ");
            scanf("%d",&value);
            create(table,value);
            break;
            
            case 2:
            display(table);
            break;
            
            case 3:
            printf("\nEnter value to search: ");
            scanf("%d", &ns);
            search(table, ns);
            break;
            
            case 0:
            printf("\nExiting...");
            printf("\nThank you!");
        }
    }while(ch!=0);
    
    return 0;
}