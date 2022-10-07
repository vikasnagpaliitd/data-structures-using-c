// Linked list : dequeue to return the value
// Only problem : inefficient enqueue O(N)// next step: front and rear
#include <stdio.h>
#include <stdlib.h>

#define SUCESS 1
#define FAILURE 0
#define INVALID_VALUE -9999
typedef struct node
{
  int data;
  struct node *next;
} node_t;

typedef struct queue
{
  node_t *front;
  node_t *rear;
} queue_t;

void display(queue_t *p_queue)
{
  node_t *ptr;
  node_t *front = p_queue->front;

  ptr = front;

  printf("Linked list contents : ");
  while (ptr != NULL)
  {
     printf("%d ", ptr->data);
     ptr = ptr->next;
  }
  printf("\n");
}


// need to return the value
int dequeue(queue_t *p_queue)
{
  node_t *p_node;
  node_t *front = p_queue->front;
  // TBD : rear will change if we dequeue the last (and only) element

  // We need to be careful if the list is empty
  if (front == NULL)
  {
     *p_elem = INVALID_VALUE;
     return front;
  }

  // We come here only if list is non empty
  p_node = front; // store pointer to the to-be-deleted node
  front = front->next; // move front
  printf("debug:dequeue: deleting node with value %d\n", p_node->data);
  *p_elem = p_node->data;
  free(p_node);

  return front;
}
// Returns SUCCESS/FAILURE
int enqueue(queue_t *p_queue, int value)
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
  queue_t queue;
  int elem, i;

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  enqueue(&queue, 40);

  display(&queue);

  for(i = 0; i < 5; i++)
  {
     dequeue(&queue, &elem);
     printf("dequeue returned %d\n", elem);

  }

  
  return 0;
}
