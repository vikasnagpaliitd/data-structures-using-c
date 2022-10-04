// Linked List : insert_at_begin: free_list: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node_t;

void display(node_t *head)
{
  node_t *ptr = head;
 
  printf("Linked list contents : ");
  while (ptr != NULL)
  {
     printf("%d ", ptr->data);
     ptr = ptr->next;
  } 
  printf("\n");
}

//void insert_at_begin(node_t **p_head, int value)
node_t *insert_at_begin(node_t *head, int value)
{
   node_t *p_newnode;

   p_newnode = (node_t *) malloc(sizeof(node_t));
   p_newnode->data = value;

   // setting next of newnode to current linked list
   p_newnode->next = head;

   // head points to new node
   head = p_newnode;

   return head;
}

node_t* free_list(node_t *head)
{
 /* Cases
   a) empty list
   b) non-empty list
  */

  if (head != NULL)
  {
    free_list(head->next);
    printf("Freeing node %p\n", head); // for debugging
    free(head);
  }
  // else. nothing to do

  return NULL;
}


int main()
{
  // declare head pointer
  node_t *head = NULL;


  head = insert_at_begin(head, 10);
  head = insert_at_begin(head, 20);
  head = insert_at_begin(head, 30);
  head = insert_at_begin(head, 40);


  display(head);


  head = free_list(head);


  return 0;
}
