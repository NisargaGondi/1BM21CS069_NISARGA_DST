#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *getNode()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    if(temp==NULL)
    {
        printf("Memory full!\n");
        return NULL;
    }
    else
    {
        return temp;
    }
    
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct Node *createBST(struct Node *root, int data)
{
    struct Node *new=getNode();
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    if(root==NULL)
    {
        root=new;
        return root;
    }
    else
    {
        if(data<root->data)
        {
            if(root->left==NULL)
            {
               root->left=new; 
            }
            else
            {
                root->left=createBST(root->left,data);
            }
        }
        else if(data>root->data)
        {
            if(root->right==NULL)
            {
                root->right=new;
            }
            else
            {
                root->right=createBST(root->right,data);
            }
        }
        return root;
    }
}
void main()
{
    struct Node *root=NULL;
    int n,data;
    while(1){
    printf("Enter 1 to create a binary search tree.\nEnter 2 to get preorder traversal.\nEnter 3 to get inorder traversal.\n");
    printf("Enter 4 to get postorder traversal.\nEnter 5 to exit!\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        printf("Enter the value to be inserted:\n");
        scanf("%d",&data);
        root=createBST(root,data);
        break;
        
        case 2:
        preorder(root);
        printf("\n");
        break;
        
        case 3:
        inorder(root);
        printf("\n");
        break;
        
        case 4:
        postorder(root);
        printf("\n");
        break;
        
        case 5:
        exit(0);
        
        default:
        printf("Invalid choice!\n");
    }
    }
}
