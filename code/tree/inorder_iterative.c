/* Binary Tree : Iterative : In order traversal
 * Author: Vikas Nagpal : http://anuttaralearning.com/
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_DEPTH 40

/* treenode_t represents data type of a tree node */
typedef struct treenode
{
   int data;
   struct treenode *left;
   struct treenode *right;
} treenode_t;

/* create_node : To create a new node taking care of memory allocation,
 * filling value, and setting left and right pointers to NULL.
 */
treenode_t *create_node(int elem)
{
   treenode_t *node;

   node = (treenode_t *) malloc(sizeof(treenode_t));

   if (node == NULL)
   {
       fprintf(stderr, "malloc failed\n");
       exit(1);
   }
   node->data = elem;
   node->left = NULL;
   node->right = NULL;

   return node;
}

/* Iterative In Order : by maintaining stack on our own */
void iterative_inorder(treenode_t *root)
{
   treenode_t *stack[MAX_TREE_DEPTH];
   int top=-1;

   treenode_t *ptr = root;


 if (ptr == NULL)
    return;

 /* Do while loop */
 do
 {
   while (ptr != NULL)
   {
      stack[++top] = ptr; 
      ptr = ptr->left;
   }

   /* Pop a pointer */
   if (top == -1)
     break; // we are done
 
   ptr = stack[top--];
   printf("%d ", ptr->data); // print the node

   ptr = ptr->right;
 } while((ptr != NULL) || (top > -1));

}

int main()
{
   treenode_t *root = NULL;

   root = create_node(10);

   root->left = create_node(5);
   root->left->left = create_node(3);
   root->left->right = create_node(7);
   root->right = create_node(20);
   root->right->left = create_node(15);
   root->right->right = create_node(25);


   iterative_inorder(root);
   printf("\n");
   exit(0);
}
