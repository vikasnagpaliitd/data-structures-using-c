/* Binary Tree : Iterative Post order Traversal
 * Note : uses stack functions declared in stack.h
 * Version 1.0
 * Author: Vikas Nagpal : http://anuttaralearning.com/
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h" // For using stack related functions */

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

/* Iterative Post Order */
void iterative_postorder(treenode_t *root)
{
  stack_t stack1;
  stack_t stack2;


  treenode_t *ptr = root;

  if (ptr == NULL)
    return;

  /* Initialize */
  init_stack(&stack1);
  init_stack(&stack2);
 
  Push(&stack1, ptr);

  while (!Is_Empty(&stack1))
  {
      ptr = Pop(&stack1);

      Push(&stack2, ptr);

      if (ptr->left != NULL)
        Push(&stack1, ptr->left);

      if (ptr->right != NULL)
        Push(&stack1, ptr->right);
  }


  //print content of Stack2
  printf("Postorder traversal is : ");
  while (!Is_Empty(&stack2))
  {
      ptr = Pop(&stack2);
      printf("%d ", ptr->data);
  }
  printf("\n");

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


   iterative_postorder(root);
   exit(0);
}
