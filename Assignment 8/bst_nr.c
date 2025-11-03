#include <stdio.h>
#include <stdlib.h>

struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
};

struct stack {
    struct tree *address;
    struct stack *next;
};

void insert (struct tree **froot, int new);
void delete(struct tree **froot, int fdel);
void search(struct tree **froot, int fns);
void inorder(struct tree **froot);
void preorder(struct tree **froot);
void postorder(struct tree **froot);
int menu (void);

int push(struct stack **ftop, struct tree **fidata)
{
	struct stack *top=NULL;
	struct stack *newnode=NULL;
	int fsuccess=0;
	top=*ftop;
	newnode=(struct stack *)calloc(1,sizeof(struct stack));
	if (newnode==NULL)
	{
		printf("Memory allocation failed. Stack full");
		fsuccess=1;
	}
	else
	{
		newnode->address=*fidata;
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

int pop(struct stack **ftop, struct tree **fodata)
{
	struct stack *top=NULL;
	struct stack *X=NULL;
	int fsuccess=0;
	top=*ftop;
	if (top==NULL)
	{
		printf("Nothing to pop. Stack Empty");
		fsuccess=1;
	}
	else
	{
		*fodata=top->address;
		X=top;
		top=top->next;
		free(X);
	}
	*ftop=top;
	return fsuccess;
}

void insert (struct tree **froot, int new)
{
    struct tree *root=NULL;
    root=*froot;
    if (root==NULL)
    {
        struct tree *newnode=(struct tree *)calloc(1,sizeof(struct tree));
        newnode->data=new;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else if (new<root->data)
    {
        insert(&root->left, new);
    }
    else if(new>root->data)
    {
        insert(&root->right, new);
    }
    else
    {
        printf("\nDuplicate value ignored: %d",new);
    }
    *froot=root;
}

void delete(struct tree **froot, int fdel)
{
    struct tree *root=NULL;
    root=*froot;
    if (root==NULL)
    {
        printf("\nNothing to delete, tree is empty");
        return;
    }
    if (fdel<root->data)
    {
        delete(&root->left, fdel);
    }
    else if (fdel>root->data)
    {
        delete(&root->right, fdel);
    }
    else
    {
        //leaf node (no child)
        if (root->left==NULL &&root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        //one child
        else if (root->left==NULL)
        {
            struct tree *temp=NULL;
            temp=root;
            root=root->right;
            free (temp);
        }
        else if (root->right==NULL)
        {
            struct tree *temp=NULL;
            temp=root;
            root=root->left;
            free (temp);
        }
        //two children
        else
        {
            struct tree *successor=NULL;
            successor=root->right;
            while(successor->left!=NULL)
            {
                successor=successor->left;
            }
            root->data=successor->data;
            delete(&root->right, successor->data);
        }
    }
    *froot=root;
}

void search(struct tree **froot, int fns)
{
    struct tree *root=NULL;
    root=*froot;
    if (root==NULL)
    {
        printf("\nNumber not found!");
    }
    else if(root->data==fns)
    {
        printf("\nNumber found!");        
    }
    else if (fns<root->data)
    {
        search(&root->left,fns);
    }
    else if(fns>root->data)
    {
        search(&root->right,fns);
    }
    *froot=root;
}

void inorder(struct tree **froot)
{
	struct tree *root=NULL;
	root=*froot;
	struct tree *current=root;
	struct tree *temp=NULL;
	struct stack *top=NULL;
	while(current!=NULL || top!=NULL)
	{
	    while(current!=NULL)
	    {
	        push(&top, &current);
	        current=current->left;
	    }
	    pop(&top,&temp);
	    if(temp!=NULL)
	    {
	        printf("%d ",temp->data);
	        current=temp->right;
	    }
	}
	*froot=root;
}
	

void preorder(struct tree **froot)
{
    struct tree *root=NULL;
    root=*froot;
	struct tree *current=root;
	struct tree *temp=NULL;
	struct stack *top=NULL;
	
	if (root==NULL)
	{
	    return;
	}
	current=root;
	push(&top, &current);
	
	while(top!=NULL)
	{
	    pop(&top, &current);
	    if (current==NULL)
	    {
	        continue;
	    }
	    printf("%d ",current->data);
	    
	    if (current->right!=NULL)
	    {
	        temp=current->right;
	        push(&top, &temp);
	    }
	    
	    if (current->left!=NULL)
	    {
	        temp=current->left;
	        push(&top, &temp);
	    }
	    *froot=root;
	}
}    
    
void postorder(struct tree **froot)
{
    struct tree *root=NULL;
    root=*froot;
	struct tree *current=root;
	struct tree *temp=NULL;
	struct stack *top1=NULL;
	struct stack *top2=NULL;
    
    if (root==NULL)
	{
	    return;
	}
	push(&top1, &root);
    
    while(top1!=NULL)
    {
        pop(&top1, &current);
        push(&top2, &current);
        if (current->left!=NULL)
        {
            temp=current->left;
            push(&top1, &temp);
        }
        if (current->right!=NULL)
        {
            temp=current->right;
            push(&top1,&temp);
        }
    }
    while(top2!=NULL)
    {
        pop(&top2, &current);
        printf("%d ", current->data);
    }
    *froot=root;
}    

int menu (void)
{
    int choice=0;
    do
    {
        printf("\nBINARY SEARCH TREE");
        printf("\nWhat would you like to perform?");
        printf("\n1. Insert \n2. Delete \n3. Search \n4. Traversals \n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    }while(choice<0||choice>4);
    return choice;
}

int main()
{
    int n=0;
    int i=0;
    struct tree *root=NULL;
    int result=0;
    printf("\nHow many elements do you want to enter? ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements: ");
    for (i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        insert(&root,a[i]);
    }
    do
    {
        result=menu();
        switch(result)
        {
            case 1:
            int new=0;
            printf("\nEnter the element you want to insert: ");
            scanf("%d",&new);
            insert(&root,new);
            break;
            
            case 2:
            int del=0;
            printf("\nEnter the element you want to delete: ");
            scanf("%d",&del);
            delete(&root, del);
            break;
            
            case 3: 
            int ns=0;
            printf("\nEnter the element you want to search: ");
            scanf("%d", &ns);
            search(&root,ns);
            break;
            
            case 4:
            int ch=0;
            printf("\nWhat traversal do you want? ");
            printf("\n1. Inorder \n2. Preorder \n3. Postorder \n0. Exit");
            printf("\nEnter your choice: ");
            scanf("%d", &ch);
            switch(ch)
            {
                case 1:
                printf("\nThe inorder traversal is: ");
                inorder(&root);
                break;
                
                case 2:
                printf("\nThe preorder traversal is: ");
                preorder(&root);
                break;
                
                case 3:
                printf("\nThe postorder traversal is: ");
                postorder(&root);
                break;
                
                case 0:
                printf("\nExiting...");
                printf("\nThank you! ");
                
            }
            break;
            
            case 0:
            printf("\nExiting...");
            printf("\nThank you! ");
            
        }
    }while(result!=0);

    return 0;
}
