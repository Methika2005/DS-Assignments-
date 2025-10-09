#include <stdio.h>
#include <stdlib.h>

struct node 
{
    float data;
    struct node *next;
};

int push (struct node **ftop, float *fidata);
int pop (struct node **ftop, float *fodata);

int push (struct node **ftop, float *fidata)
{
    struct node *top=NULL; 
    struct node *newnode=NULL;
    int fsuccess=1;
    top=*ftop;
    newnode=(struct node *)calloc(1,sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allcation failed. Stack full");
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


int pop (struct node **ftop, float *fodata)
{
    struct node *top=NULL; 
    struct node *X=NULL;
    int fsuccess=1;
    top=*ftop;
    if (top==NULL)
    {
        printf("Nothing to pop. Stack Empty");
        fsuccess=1;
    }
    else
    {
        *fodata=top->data;
        X=top;
        top=top->next;
        free(X);
    }
    *ftop=top;
    return fsuccess;
}

void postfix_eval(char fpostfix[100])
{
    float idata;
    float odata;
    struct node *top=NULL;
    int i=0;
    float result=0;
    float oprnd1=0;
    float oprnd2=0;
    printf("\nEnter a postfix expression: ");
    scanf("%[^\n]%*c",fpostfix);
    for (i=0;fpostfix[i]!='\0';i++)
    {
        if (fpostfix[i]>='0'&& fpostfix[i]<='9')
        {
            idata=fpostfix[i]-'0';
            push(&top,&idata);
        }
        else
        {
            pop(&top,&oprnd2);
            pop(&top,&oprnd1);
            switch(fpostfix[i])
            {
                case '+':
                result=oprnd1+oprnd2;
                break;
                
                case '-':
                result=oprnd1-oprnd2;
                break;
                               
                case '*':
                result=oprnd1*oprnd2;
                break;
                
                case '/':
                result=oprnd1/oprnd2;
                break;
            }
            push(&top,&result);
        }
    }
    pop(&top,&result);
    printf("\n%.2f",result);
}

int main(void)
{
    char postfix[100];
    postfix_eval(postfix);
    return 0;
}
