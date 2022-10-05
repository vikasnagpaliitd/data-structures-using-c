// Linked list : insert_at_begin() implementation : Taking double pointer (p_head)
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

// For now, we are using approach of returning new 'head'
void insert_at_begin(node_t **p_head, int value)
//node_t *insert_at_begin(node_t *head, int value)
{
  node_t *p_newnode;
  node_t *head =  *p_head; // compute head from p_head

  p_newnode = (node_t *) malloc(sizeof(node_t));
  // TBD : check for malloc failure
  p_newnode->data = value;

  // setting next of newnode to current linked list
  p_newnode->next = head;

  // head points to new node
  head = p_newnode;

  // Modify contents pointed at by p_head
  *p_head = head;

  //return head;
}



int main()
{
  node_t *head = NULL;

  insert_at_begin(&head, 10); // insertion into empty list
  insert_at_begin(&head, 20); // insertion into non-empty list
  insert_at_begin(&head, 30);
  insert_at_begin(&head, 40);

  display(head);

  //TBD : add loop to free the memory
  return 0;
}
