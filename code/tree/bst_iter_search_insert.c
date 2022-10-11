/******************************************************************
Program to search a node in a Binary search tree
******************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *left;
	struct node *right;
	int data;
}node;

/*******************************************************************
Function to create a new node.
********************************************************************/
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

/*****************************************************************
Function to search a node in a BST
*****************************************************************/
node *search_node(node* root, int value)
{

	node *curr = root;

	// Situate curr at root, and keep moving left or right as needed
        while (curr != NULL)
        {
             printf("debug:data at curr = %d\n", curr->data);

             if (value == curr->data)
                return curr;

             if (value < curr->data)
                curr = curr -> left;
             else 
                curr = curr -> right;
        }
        
        return NULL; 
}
/**********************************************************************
Function to insert a node.
***********************************************************************/
node *insert(node *root,int value)
{
        node * current,*parent;
        /**
          If tree is empty, new node has to be inserted at root.
        **/
        if(NULL == root)
        {
                root=newnode(value);
                return root;
        }
        
        if(value > root->data)
        {
            /** Insert in the right subtree **/
            root->right = insert(root->right, value);
        }
        else if( value < root->data)
        {
            /** Insert in the left subtree **/
            root->left = insert(root->left, value);
        }
        /** else node with value is already present in tree **/
        return root;
}


/*******************************************************************************
Function to traversea a tree and display its contents using postorder traversal.
********************************************************************************/
void postorder(node * tree)
{
	if(NULL == tree)
		return;
	postorder(tree->left);
	postorder(tree->right);
	printf("\n%d",tree->data);
}

/**  Main function **/
int main()
{
        node *root =NULL;
	    node *node =NULL;
        int val;
        root = insert(root,20);
        root = insert(root,10);
        root = insert(root,25);
        root = insert(root,5);
        root = insert(root,15);
        root = insert(root,30);

        printf("The postorder traversal of the tree is : ");
        postorder(root);

        printf("\nEnter the node to be searched: ");
        scanf("%d",&val);

        node = search_node(root,val);
        if( NULL == node )
        {
        		printf("Data not found.\n");
        		return 1;
        }            	           
    	printf("Data found.\n");
        return 0;
}
