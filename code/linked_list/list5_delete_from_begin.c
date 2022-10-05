// Linked list : delete_at_begin() implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node_t;

void display(node_t *head)
{
  node_t *ptr;

  ptr = head;

  printf("Linked list contents : ");
  while (ptr != NULL)
  {
     printf("%d ", ptr->data);
     ptr = ptr->next;
  }
  printf("\n");
}

node_t *insert_at_begin(node_t *head, int value)
{
  node_t *p_newnode;

  p_newnode = (node_t *) malloc(sizeof(node_t));
  // TBD : check for malloc failure
  p_newnode->data = value;

  // setting next of newnode to current linked list
  p_newnode->next = head;

  // head points to new node
  head = p_newnode;

  return head;
}


node_t *delete_at_begin(node_t *head)
{
  node_t *p_node;

  // We need to be careful if the list is empty
  if (head == NULL)
     return head;

  // We come here only if list is non empty
  p_node = head; // store pointer to the to-be-deleted node
  head = head->next; // move head
  printf("debug:delete_at_begin: deleting node with value %d\n", p_node->data);
  free(p_node);

  return head;
}

int main()
{
  node_t *head = NULL;
  int i;

  head = insert_at_begin(head, 10);
  head = insert_at_begin(head, 20);
  head = insert_at_begin(head, 30);
  head = insert_at_begin(head, 40);

  display(head);
  
  // deleting 5 times while there are only 4 nodes at beginning
  for(i = 0; i < 5; i++)
  {
     head = delete_at_begin(head);
     display(head);
  }
  
  return 0;
}
