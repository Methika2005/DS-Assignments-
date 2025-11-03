#include <stdio.h>
#include <stdlib.h>

struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
};
void insert (struct tree **froot, int new);
void delete(struct tree **froot, int fdel);
void search(struct tree **froot, int fns);
void inorder(struct tree **froot);
void preorder(struct tree **froot);
void postorder(struct tree **froot);
int menu (void);


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
    if (new<root->data)
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
        printf("\nNothing to Delete");
    }
    
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
	if (root==NULL)
	{
		return;
	}
	inorder(&root->left);
	printf("%d ",root->data);
	inorder(&root->right);
    *froot=root;
}

void preorder(struct tree **froot)
{
	struct tree *root=NULL;
	root=*froot;
	if (root==NULL)
	{
		return;
	}
	
	printf("%d ",root->data);
	preorder(&root->left);
	preorder(&root->right);
    *froot=root;
}

void postorder(struct tree **froot)
{
	struct tree *root=NULL;
	root=*froot;
	if (root==NULL)
	{
		return;
	}
	postorder(&root->left);
	postorder(&root->right);
	printf("%d ",root->data);
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
