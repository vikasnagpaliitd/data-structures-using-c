// Linked list : enqueue() implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node_t;

void display(node_t *front)
{
  node_t *ptr;

  ptr = front;

  printf("Linked list contents : ");
  while (ptr != NULL)
  {
     printf("%d ", ptr->data);
     ptr = ptr->next;
  }
  printf("\n");
}


// TBD : need to return the value
node_t *dequeue(node_t *front)
{
  node_t *p_node;

  // We need to be careful if the list is empty
  if (front == NULL)
     return front;

  // We come here only if list is non empty
  p_node = front; // store pointer to the to-be-deleted node
  front = front->next; // move front
  printf("debug:dequeue: deleting node with value %d\n", p_node->data);
  free(p_node);

  return front;
}

node_t *enqueue(node_t *front, int value)
{
  node_t *ptr;
  node_t *p_newnode;

  // Allocate node and initialize it  
  p_newnode = (node_t *) malloc(sizeof(node_t));
  // TBD : Error check
  p_newnode->data = value;
  p_newnode->next = NULL;

 
  // Handle empty list case 
  if (front == NULL)
  {
    front = p_newnode;
    return front;
  }
 
  // Make ptr reach the last node 
  ptr = front;
  while (ptr->next != NULL)
     ptr = ptr->next;
  
  ptr->next = p_newnode;
  return front;
}

int main()
{
  node_t *front = NULL;

  front = enqueue(front, 10);
  front = enqueue(front, 20);
  front = enqueue(front, 30);
  front = enqueue(front, 40);

  display(front);

  
  return 0;
}
