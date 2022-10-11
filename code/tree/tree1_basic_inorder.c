// Binary Tree : Tree Node Structure  + InOrder Print
// Author: Vikas Nagpal : http://anuttaralearning.com/

#include <stdio.h>
#include <stdlib.h>

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

/* Notice : this is IN-ORDER TRAVERSAL because
 * the 'root' node comes IN-BETWEEN the LEFT and RIGHT
 * Subtrees.
 */
void print_tree(treenode_t *root)
{
   /* Base case of recursion : If root is NULL, do nothing */
   if (root == NULL)
      return;

   /* Recursive definition: print_tree calls itself (twice).
    * IN-ORDER because ROOT is printed between LEFT and RIGHT
    */

   print_tree(root->left);
   printf("%d ", root->data);
   print_tree(root->right);
}

int main()
{
   treenode_t *root = NULL;

   root = create_node(10);

   root->left = create_node(5);
   root->left->left = create_node(3);
   root->left->right = create_node(7);
   root->right = create_node(20);

   print_tree(root); 
   printf("\n");
   exit(0);
}
