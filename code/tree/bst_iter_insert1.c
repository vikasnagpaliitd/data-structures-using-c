	
/******************************************************************
This program inserts a node operations on Binary search tree
******************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
        int data;
        struct node *left;
        struct node *right;
}node;

/******************FUNCTION DEFINITIONS ************************/

/***************************************************************
Function to create a new node.
****************************************************************/
node* newnode(int value)
{
        node* new_node;
        new_node = (node *)malloc(sizeof(node));
        if(NULL == new_node)
        {
                printf("\n Memory not available");
                exit(1);
        }
        /***Populate the node *******/
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
}

/***************************************************************
Function to insert a new node
*****************************************************************/
node *insert(node *rootptr,int item)
{
        node * current,*parent;
        if (item < 0)
        {
                printf("Enter a valid value to be inserted!!\n");
                return NULL;
        }
        /**
          If tree is empty, new node has to be inserted at root.
         **/
        if(NULL == rootptr)
        {
                /* Inserting element at the root */
                rootptr=newnode(item);
                return rootptr;
        }
        else
        {
                parent = rootptr;
                current = rootptr;
                /** Traverse the tree to find the location
                  where the node has to be inserted.
                 **/
                while(current!=NULL)
                {
                        parent = current;
                        if(item < current->data)
                                current = current->left;
                        else if(item > current->data)
                                current = current->right;
                        /**
                          If node with same value found.
                         **/
                        else
                        {
                                printf("\nCannot insert duplicate element ");
                                return rootptr;
                        }
                }
                if(item < parent->data)
                {
                        /* Inserting element at the left of parent->data */
                        parent->left = newnode(item);
                }
                else
                {
                        /* Inserting element at the right of parent->data */
                        parent->right = newnode(item);
                }
        }
        return rootptr;
}


/*********************************************************************
Function to traverse a tree and display using preorder traversal.
**********************************************************************/
void preorder(node * tree)
{
        if(NULL == tree)
                return;
        printf("\n%d",tree->data);
        preorder(tree->left);
        preorder(tree->right);
}

/** Main function **/
int main()
{
        node *root =NULL;
        int item;
        root = insert(root,20);
        root = insert(root,10);
        root = insert(root,25);
        root = insert(root,5);
        root = insert(root,15);
        root = insert(root,30);
        printf("The preorder traversal of the tree is : ");
        preorder(root);
        printf("\nEnter the node to be inserted : ");
        scanf("%d", &item);
     	  root = insert(root,item);
        if (NULL == root) 
        {
                return 0;
        }
        printf("\nAfter INSERTION, preorder traversal of the tree is : ");
        preorder(root);
        return 0;
}
