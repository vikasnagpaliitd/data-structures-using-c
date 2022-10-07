// Linked list : pop enhanced to return the popped value
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node_t;

void display(node_t *top)
{
  node_t *ptr;

  ptr = top;

  printf("Linked list contents : ");
  while (ptr != NULL)
  {
     printf("%d ", ptr->data);
     ptr = ptr->next;
  }
  printf("\n");
}

node_t *push(node_t *top, int value)
{
  node_t *p_newnode;

  p_newnode = (node_t *) malloc(sizeof(node_t));
  // TBD : check for malloc failure
  p_newnode->data = value;

  // setting next of newnode to current linked list
  p_newnode->next = top;

  // top points to new node
  top = p_newnode;

  return top;
}


node_t *pop(node_t *top, int *p_elem) // p_elem is used to return the popped value
{
  node_t *p_node;

  // We need to be careful if the list is empty
  if (top == NULL)
     return top;

  // We come here only if list is non empty
  p_node = top; // store pointer to the to-be-deleted node
  top = top->next; // move top
  *p_elem = p_node->data;
  printf("debug:pop: deleting node with value %d\n", p_node->data);
  free(p_node);

  
  return top;
}

int main()
{
  node_t *top = NULL;
  int i, elem;

  top = push(top, 10);
  top = push(top, 20);
  top = push(top, 30);
  top = push(top, 40);

  display(top);
  
  // deleting 5 times while there are only 4 nodes at beginning
  for(i = 0; i < 5; i++)
  {
     top = pop(top, &elem);
     printf("pop returned %d\n", elem);
     display(top);
  }
  
  return 0;
}
