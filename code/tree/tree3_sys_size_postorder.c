/* Binary Tree
 * Example : Size taken by directory structure : Post Order Traversal
 *
 * Author: Vikas Nagpal : http://anuttaralearning.com/
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* treenode_t represents data type of a tree node */
typedef struct treenode
{
   char *filename; /* Could be file or directory name */
   int indiv_size; /* Individual size taken by this file/dir  */
   struct treenode *left;
   struct treenode *right;
} treenode_t;

/* create_node : To create a new node taking care of memory allocation,
 * filling value, and setting left and right pointers to NULL.
 */
treenode_t *create_node(char *filename, int indiv_size)
{
   treenode_t *node;

   /* Self Testing. If caller function is correct, it will never pass 
    * filename as NULL.
    */
   assert(filename != NULL);

   node = (treenode_t *) malloc(sizeof(treenode_t));
   if (node == NULL)
   {
       fprintf(stderr, "malloc failed\n");
       exit(1);
   }

   node->filename = malloc((strlen(filename)+1) * sizeof(char));
   if (node->filename == NULL)
   {
       fprintf(stderr, "malloc failed\n");
       exit(1);
   }
   

   /* Copy Data */
   strcpy(node->filename, filename);
   node->indiv_size = indiv_size;
  
   /* Set pointers NULL */
   node->left = NULL;
   node->right = NULL;

   return node;
}

/* Notice : this is POST-ORDER TRAVERSAL because
 * the 'root' node comes after(POST) than the LEFT and RIGHT
 * Subtrees.
 */
int print_sum_tree(treenode_t *root)
{
   int sum = 0;

   /* Base case of recursion : If root is NULL, do nothing */
   if (root == NULL)
      return 0;

   /* Recursive definition: print_sum_tree calls itself (twice).
    * POST-ORDER because ROOT is printed between LEFT and RIGHT
    */
   sum += print_sum_tree(root->left);
   sum += print_sum_tree(root->right);
   sum += root->indiv_size;
   printf("%s has total size=%d, individual size=%d\n", root->filename, sum, root->indiv_size);
   return sum;
}

int main()
{
   treenode_t *root = NULL;

   root = create_node("/", 1);

   root->left = create_node("/dir1", 2);
   root->right = create_node("/dir2", 3); 
   root->left->left = create_node("/dir1/file1", 10);
   root->left->right = create_node("/dir1/file2", 20);
   root->right->left = create_node("/dir2/file3", 30);
   root->right->right = create_node("/dir2/file4", 40);

   print_sum_tree(root);
   exit(0);
}
