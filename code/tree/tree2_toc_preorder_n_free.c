/* Binary Tree : tree of topics (strings) : Pre-order traversal
 * Example : Table of content as a hierarchical tree
 * NOTES :
 *   1) An N-ry tree would have been better to store TOC.
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
   char *section_name;
   struct treenode *left;
   struct treenode *right;
} treenode_t;

/* create_node : To create a new node taking care of memory allocation,
 * filling value, and setting left and right pointers to NULL.
 */
treenode_t *create_node(char *section_name)
{
   treenode_t *node;

   /* Self Testing. If caller function is correct, it will never pass 
    * section_name as NULL.
    */
   assert(section_name != NULL);

   node = (treenode_t *) malloc(sizeof(treenode_t));
   if (node == NULL)
   {
       fprintf(stderr, "malloc failed\n");
       exit(1);
   }

   node->section_name = malloc(sizeof(char) * (strlen(section_name)+1));
   if (node->section_name == NULL)
   {
       fprintf(stderr, "malloc failed\n");
       exit(1);
   }

   /* Copy Data */
   strcpy(node->section_name, section_name);
  
   /* Set pointers NULL */
   node->left = NULL;
   node->right = NULL;

   return node;
}

/* Notice : this is PRE-ORDER TRAVERSAL because
 * the 'root' node comes before (PREVIOUS) than the LEFT and RIGHT
 * Subtrees.
 * indent_level denotes the desired level of indentation
 */
void print_tree(treenode_t *root, int indent_level)
{
   int i;

   /* Base case of recursion : If root is NULL, do nothing */
   if (root == NULL)
      return;

   /* Recursive definition: print_tree calls itself (twice).
    * PRE-ORDER because ROOT is printed between LEFT and RIGHT
    */
   for(i = 0;i < indent_level; i++)
     printf("  ");
   printf("%s\n", root->section_name);
   print_tree(root->left, indent_level + 1);
   print_tree(root->right, indent_level + 1);
}
//TBD : value of root seems to go wrong as soon as this function is called
//void free_tree(treenode_t *root)
void free_tree(treenode_t **p_root)
{
   if (*p_root == NULL)
      return;

   free_tree(&((*p_root)->left));
   free_tree(&((*p_root)->right));
   free(*p_root);
   *p_root = NULL;
}

int main()
{
   treenode_t *root = NULL;

   root = create_node("Book-Of-Life");

   root->left = create_node("1 Chapter-on-Suffering");
   root->right = create_node("2 Chapter-on-Happiness");
   root->left->left = create_node("1.1 Truth of Suffering");
   root->left->right = create_node("1.2 Reason of Suffering");
   root->right->left = create_node("2.1 Path to Happiness");
   root->right->right = create_node("2.2 Reason of Happiness");

   print_tree(root, 0);

   free_tree(&root);
   exit(0);
}
