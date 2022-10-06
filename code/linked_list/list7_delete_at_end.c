// Linked list : delete_at_end() implementation
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

node_t *insert_at_end(node_t *head, int value)
{
  node_t *ptr;
  node_t *p_newnode;

  // Allocate node and initialize it  
  p_newnode = (node_t *) malloc(sizeof(node_t));
  // TBD : Error check
  p_newnode->data = value;
  p_newnode->next = NULL;

 
  // Handle empty list case 
  if (head == NULL)
  {
    head = p_newnode;
    return head;
  }
 
  // Make ptr reach the last node 
  ptr = head;
  while (ptr->next != NULL)
     ptr = ptr->next;
  
  ptr->next = p_newnode;
  return head;
}

node_t *delete_at_end(node_t *head)
{
  node_t *ptr;
  // handle empty list
  if (head == NULL)
     return head;
  
  // handle list with one node
  if (head->next == NULL)
  {
     // handle appropriately
     free(head);
     head = NULL;
     return head;
  }
  
  // We come here if we have atleast two nodes.
  // Make ptr reach the 2nd last node
  ptr = head;
  while (ptr->next->next != NULL)
    ptr = ptr->next;
  
  // ptr is at 2nd last node
  free(ptr->next);
  ptr->next = NULL;
  return head;
}

int main()
{
  node_t *head = NULL;
  int i;

  head = insert_at_end(head, 10);
  head = insert_at_end(head, 20);
  head = insert_at_end(head, 30);
  head = insert_at_end(head, 40);

  display(head);

  for(i=0;i<5;i++)
  {
     printf("Deleting 1 element....\n");
     head = delete_at_end(head);
     display(head);
  }

  
  
  return 0;
}
