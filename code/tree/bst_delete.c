/* Binary Search Tree : Code for deleting node (Also has insert node code)
 * Author: Vikas Nagpal : http://anuttaralearning.com/
 */

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

/* Recursive function to delete a node */
treenode_t *recursive_delete_node(treenode_t *root, int val)
{
   treenode_t *temp, *replacement;
   int   replacement_value;
   if (root == NULL)
      return NULL;

   
   if (val < root->data)
     root->left = recursive_delete_node(root->left, val);
   else if (val > root->data)
     root->right = recursive_delete_node(root->right, val);
   else
   {
     // root is to be deleted.
     /* Three cases : 1) 0 children 2) 1 child 3) 2 children */
     if ((root->left == NULL) && (root->right == NULL))
     {
         // 0 children
         free(root);
         root = NULL;
     }
     else
     if (root->left == NULL)
     {
        // 1 right child
        assert(root->right != NULL);
        temp = root->right;
        free(root);
        root =  temp;
     }
     else
     if (root->right == NULL)
     {
        // 1 left child
        assert(root->left != NULL);
        temp = root->left;
        free(root);
        root =  temp;
     }
     else
     {
        // two children

        /* Find the maxmimum node in the left subtree */
        replacement = root->left;
        while (replacement->right != NULL)
           replacement = replacement->right;
        replacement_value = replacement->data;
        root = recursive_delete_node(root, replacement_value);
        root->data = replacement_value;
     }

   }

   return root;
}

/* Iterative variant delete_node. */
treenode_t *delete_node(treenode_t *root, int val)
{
  treenode_t *ptr, *parent;
  treenode_t *parent_replacement, *replacement;
  treenode_t *child_ptr;

  int is_left = 0; // 1 for left. 0 for right.

  /* Find the node to be deleted */
  parent = NULL;
  ptr=root;
  while(ptr != NULL)
  {
     if (val == ptr->data)
         break; // Found it
     else if (val < ptr->data)
     {
         parent = ptr;
         is_left = 1; /* Left */
         ptr = ptr->left;
     }
     else
     {
         parent = ptr;
         is_left = 0; /* Right */
         ptr = ptr->right;
     }
  }

  /* ptr is either NULL or the node to be deleted */
  if (ptr == NULL)
  {
      printf("Node with value %d not found...\n", val);
      return root;
  }

  /* ptr is pointing to the node to be deleted */ 
  /* Three Cases
   * 1) It is leaf node
   * 2) It has one child
   * 3) It has two children
   */

   if ((ptr->left == NULL) && (ptr->right == NULL))
   {
       /* Case 1 : Leaf Node*/
       if (parent == NULL)
       {
            // The node being deleted is root itself!
            assert(ptr == root);
            free(ptr);
            root = NULL;
       }
       else
       {
             free(ptr);
             if (is_left)
                parent->left = NULL;
             else
                parent->right = NULL;
       }
   }
   else
   if ((ptr->left == NULL) || (ptr->right == NULL))
   {
      /* Case 2: The node has exactly one child */
      if (ptr->left != NULL)
          child_ptr = ptr->left;
      else
          child_ptr = ptr->right;

      if (parent == NULL) // root is being deleted 
      {
         assert(ptr == root);
         root = child_ptr;
         free(ptr);
      }
      else
      {
         // non-root node is being deleted. So, the parent of "to be deleted"
         // node will adopt the "to be deleted" node's child
         if (is_left)
             parent->left = child_ptr;
         else
             parent->right =  child_ptr;
         free(ptr);
      }
   }
   else
   {
       /* Case 3: Node to be deleted has both left and right children */
       
      /* Find replacement. i.e. the highest node less than the to-be-deleted
       *   It can be found as the largest member in the left subtree.
       *   So, we can take one left, and then keep moving right as far as
       *   possible (Note : Alternate approach was to take the minimum in
       *   the right subtree)
       */
      parent_replacement = ptr;
      replacement =  ptr->left;
      is_left = 1; /* Replacement is left child of parent */
      while(replacement->right != NULL)
      {
        parent_replacement = replacement;
        replacement = replacement->right;
        is_left = 0; // Replacement is right child of parent
      }


      /* Copy data */
      ptr->data = replacement->data;
      /* Two broad cases
       * i) Replacement is left child of ptr 
       *   (and could be having 0 or 1 children)
       * ii) Replacement is right (grand)child of ptr->left
       */

      if (is_left)
      {
            // case i : replacement is left child of ptr.
            assert(replacement->right == NULL);
            ptr->left = replacement->left;
            free(replacement);
      }
      else
      {
          // case ii : replacement is right grand(child of ptr->left
          parent_replacement->right = replacement->left;
          free(replacement);
      }
    }
    return root;    
}

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

/* Notice : this is PRE-ORDER TRAVERSAL because
 * the 'root' node comes PREVIOUS than the LEFT and RIGHT
 * Subtrees.
 */
void print_tree(treenode_t *root, int indent_level)
{
   int i;
   /* Base case of recursion : If root is NULL, do nothing */
   if (root == NULL)
      return;

   /* Recursive definition: print_tree calls itself (twice).
    * PRE-ORDER because ROOT is printed before LEFT and RIGHT
    */

   for(i=0;i<indent_level;i++)
      printf("  ");
   printf("%d\n", root->data);
   print_tree(root->left, indent_level + 1);
   print_tree(root->right, indent_level + 1);
}

/* Recursive version : recur_insert_node() */
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

/* Iterative version : insert_node() */
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
   int choice, value;

   while (1)
   {
        printf("BST. What do you want to do?\n");
        printf("1) Insert\n");
        printf("2) Delete\n");
        printf("3) Print\n");
        printf("4) Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
           case 1:
                printf("Enter the value\n");
                scanf("%d", &value);
                root = insert_node(root, value);
                printf("The resultant tree is \n");
                print_tree(root, 0);
                break;
           case 2:
                printf("Enter the value\n");
                scanf("%d", &value);
                root = recursive_delete_node(root, value);
                printf("The resultant tree is \n");
                print_tree(root, 0);
                break;
           case 3:
                print_tree(root, 0);
                break;
           case 4:
                exit(0);
                break;
           default:
               printf("Invalid input. Try again...\n");

        }
   }

   exit(0);
}
