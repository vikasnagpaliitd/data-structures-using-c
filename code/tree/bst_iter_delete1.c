
/******************************************************************
 	Program deletes a node from a Binary search tree
******************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
        	int data;
       		struct node *left;
      	        struct node *right;
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

/*********************************************************************
Function to traverse and display a tree using inorder traversal
**********************************************************************/
void inorder(node* tree)
{
            if (NULL == tree)
              	  return;
      	   inorder(tree->left);
       	   printf("\n%d",tree->data);
       	   inorder(tree->right);
}

/**********************************************************************
Function to delete a node with two children
***********************************************************************/
void node_with_two_child(node *current)
{
	node *temp, *parent;
	temp = current;
	
	/** changing the pointer to root of right sub tree to find
       the minimum value node **/
	current = current->right;
	
	/** check if the root of the right sub tree is the lowest, i.e
       it doesnot have a left child **/
	if(NULL == current->left)
	{
		temp->data = current->data;
		if(NULL == current->right)
		temp->right = NULL;
		else
		temp->right = current->right;
		free(current);
	}
	else
	{
		/**********Traversing the right subtree 
		 to find the min value***/
		while(NULL != current->left)
		{
			parent = current;
			current = current->left;
		}
		if(NULL == current->right)
		{
			temp->data = current->data;
			parent->left = NULL;
			free(current);
		}
		else
		{
			temp->data = current->data;
			parent->left = current->right;
			free(current);
		}
	}
}


/**********************************************************************
Function to delete a node from the tree.
***********************************************************************/
node* delete(node *rootptr, int value)
{
	node *current, *temp, *parent;
	/** 
	Variables to check if node to be deleted is the left or 
	right child of parent node.
	If right =1, node to be deleted is right child of parent.
	If left = 1, node to be deleted is left child of parent.
	**/
	int left=0, right=0;
	current = rootptr;
	parent = rootptr;
	/**
	If tree is empty. 
	**/
	if(NULL == rootptr)
	{
		printf("No node to delete.");
		printf("Empty list!");
		exit(1);
	}
	/**
	Traverse the Tree to find the node to be delete 
	**/
	while(NULL != current && value != current->data)
	{
		left = 0;
		right = 0;
		parent = current;
		/**
		Traverse left if value is less than current node.
		**/
		if(value < current->data)
		{ 
			current = current->left;
			left = 1;
		}
		/**
		Traverse right if value is greater than current node.
		**/
		else
		{
			current = current->right;
			right = 1;
		}
	}
	/**
	If node to be deleted is not in the tree.
	**/
	if(NULL==current)
	{
		printf("No such value in the tree. Enter a valid node value!!");
		return rootptr;
	}
	temp = current;
	if(NULL == current->left)
	{
        /**
          Case 1 : If the node to be deleted has no child
        **/
		if(NULL == current->right)
		{
			/**
			If the node to be deleted is the left child of parent.
			**/
			if(left == 1)
			{
				parent->left = NULL;
			}	
			/**
			If the node to be deleted is the right child of parent.
			**/
			if(right == 1)
			{
				parent->right = NULL;
			}
			free(temp);
		
			/** Incase tree has just one node, i.e, root with no childs.
			Since we initialised parent and current to point
			to root , Hence, this check for root. **/
			if(parent == current)
			{
				printf("-------------\n");
				printf("Tree Empty\n");
				printf("-------------\n");
				return NULL;
			}
		}
		else
		{
			/**
			Case 2 : If the node to be deleted has one child
			Right child in this case.
			**/
			/**If root node to be deleted **/
			if(parent == current)
			{
				parent = current->right;
				return parent; //return the new root of the tree;
			}

			if(left == 1)
				parent->left = current->right;
			if(right == 1)
				parent->right = current->right;
			free(temp);
		}
	}
	else
	{
		/**
            Case 2 : If the node to be deleted has one child
            Left child in this case.
		**/
		if(NULL == current->right)
		{
			/** If root node to be deleted **/
			if(parent == current)
			{
				parent = current->left;
				return parent; /**return the new root of the BST.**/
			}

			if(left == 1)
			{
				parent->left = current->left;
			}	
			if(right == 1)
			{
				parent->right = current->left;
			}
			free(temp);
		
		}
		/**
		Case 3: Node to be deleted has 2 children.
		**/
		else
		{
			node_with_two_child(current);
		}	
	}
	return rootptr;
}

/**********************************************************************
Function to insert a node in a tree.
***********************************************************************/

node *insert(node *rootptr,int item)
{
        node * current,*parent;
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
                /**
                  Traverse the tree to find the location
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
		                  /*Inserting element at the left of parent->data */
                        parent->left = newnode(item);
                }
                else
                {
		                  /*Inserting element at the right of parent->data */
                        parent->right = newnode(item);
                }
        }
        return rootptr;
}


/**  Main function **/
int main()
{
        node *root =NULL;
        int val;
        root = insert(root,20);
        root = insert(root,10);
        root = insert(root,25);
        root = insert(root,5);
        root = insert(root,15);
        root = insert(root,30);
        printf("The inorder traversal of the tree is : ");
        inorder(root);
        printf("\nEnter the node to be deleted : ");
        scanf("%d", &val);
        root = delete(root,val);
        printf("\nAfter DELETION, inorder traversal of the tree is : ");
        inorder(root);
        return 0;
}
