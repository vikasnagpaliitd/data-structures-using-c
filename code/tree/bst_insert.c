//Binary Search Tree : Recursive and iterative insert logic 
// Author: Vikas Nagpal : http://anuttaralearning.com/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

/* Recursive variant of insert function */
treenode_t *recur_insert_node(treenode_t *root, int val)
{
  /* Handle  empty tree as a special case */
  if (root == NULL)
  {
     root = create_node(val);
     return root;
  }

  /* We come here, if non-empty tree */ 
  if (root->data == val)
    printf("The value is already existing. Not adding\n");
  else if (val < root->data)
     root->left = recur_insert_node(root->left, val);
  else
     root->right = recur_insert_node(root->right, val);
  return root;
}

/* Iterative variant of insert function */
treenode_t *insert_node(treenode_t *root, int val)
{
  treenode_t *ptr;

  /* Handle  empty tree as a special case */
  if (root == NULL)
  {
     root = create_node(val);
     return root;
  }

  /* We come here, if non-empty tree */ 
  ptr = root;

  while(ptr != NULL)
  {
     if (val < ptr->data)
     {
        if (ptr->left == NULL)
        {
          ptr->left = create_node(val);
          return root;
        }
        ptr = ptr->left;
     }
     else if (val > ptr->data)
     {
        if (ptr->right == NULL)
        {
          ptr->right = create_node(val);
          return root;
        }
        ptr = ptr->right;
     }
     else
     {
         printf("The value is already existing. Not adding\n");
         return root;
     }
  }
 
  /* We should not come here */ 
  assert(0);
  return root;
}

int main()
{
   treenode_t *root = NULL;

   root = recur_insert_node(root,10);
   root = recur_insert_node(root,5);
   root = recur_insert_node(root,20);
   root = insert_node(root,6);
   root = insert_node(root,4);

   root = insert_node(root,22);
   root = recur_insert_node(root,18);
   print_tree(root);
   printf("\n");
   exit(0);
}
