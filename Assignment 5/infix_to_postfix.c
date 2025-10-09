#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
};

int push(struct node **ftop, char *fidata);
int pop (struct node **ftop, char *fodata);

int push(struct node **ftop, char *fidata)
{
    struct node *top=NULL;
    struct node *newnode=NULL;
    top=*ftop;
    int fsuccess=0;
    newnode=(struct node *)calloc(1,sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed. Stack full!");
        fsuccess=1;
    }
    else
    {
        newnode->data=*fidata;
        if(top==NULL)
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

int pop (struct node **ftop, char *fodata)
{
    struct node *top=NULL;
    struct node *X=NULL;
    top=*ftop;
    int fsuccess=0;   
    if (top==NULL)
    {
        printf("Nothing to pop. Stack empty!");
        fsuccess=1;
    }
    else
    {
        *fodata=top->data;
        X=top;
        top=top->next;
        free (X);
    }
    *ftop=top;
    return fsuccess;
}

int operations(char op)
{
    if (op=='+' || op =='-')
    {
        return 1;
    }
    if (op=='*'|| op =='/')
    {
        return 2;
    }
    return 0;
}

void infix_postfix(char finfix[100], char fpostfix[100])
{
    struct node *top=NULL;
    char idata;
    char odata;
    int i=0;
    int j=0;
    printf("\nEnter the infix expression: ");
    scanf("%[^\n]%*c",finfix);
    
    for (i=0;finfix[i]!='\0';i++)
    {
        if((finfix[i]>='a'&& finfix[i]<='z') || (finfix[i]>='A' && finfix[i]<='Z'))
        {
            fpostfix[j]=finfix[i];
            j++;
        }
        else if (finfix[i]=='(')
        {
            idata=finfix[i];
            push(&top,&idata);
        }
        else if (finfix[i]==')')
        {
            while(top->data!='(')
            {
                pop(&top,&odata);
                fpostfix[j]=odata;
                j++;
            }
            if (top->data=='(')
            {
                pop(&top,&odata);
            }
        }
        else
        {
            idata=finfix[i];
            while (top!=NULL && operations(top->data)>=operations(idata))
            {
                pop(&top, &odata);
                fpostfix[j]=odata;
                j++;
            }
            push(&top,&idata);
        }
    }
    while(top!=NULL)
    {
        pop(&top, &odata);
        fpostfix[j]=odata;
        j++;
    }
    
    fpostfix[j] = '\0';
    printf("\nThe postfix expression is: ");
    for(i=0;fpostfix[i]!='\0';i++)
    {
        printf("%c", fpostfix[i]);
    }
}

int main(void)
{
    char idata;
    char odata;
    char infix[100]; 
    char postfix[100];
    infix_postfix(infix,postfix);
    return 0;
}