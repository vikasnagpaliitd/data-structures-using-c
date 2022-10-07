// Linked list : dequeue to return the value
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

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

void init(queue_t *p_queue)
{
  p_queue->front = p_queue->rear = NULL;
}

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


// Returns SUCCESS/FAILURE 
int dequeue(queue_t *p_queue, int *p_elem)
{
  node_t *ptr;

  // handle empty Q
  if (p_queue->front == NULL)
  {
    printf("debug: dequeue : front is NULL... returning FAILURE\n");
    return FAILURE;
  }
    
  // handle single element Q
  if (p_queue->front == p_queue->rear)
  {
    printf("debug: dequeue : single element queue. now becoming empty...\n");
    *p_elem = p_queue->front->data;
    free(p_queue->front);
    p_queue->front = p_queue->rear = NULL;
    return SUCCESS;
  }
  
  // Queue having atleast 2 elements
  *p_elem = p_queue->front->data;
  ptr = p_queue->front;
  p_queue->front = p_queue->front->next;
  free(ptr);
  return SUCCESS;
}
// Returns SUCCESS/FAILURE
int enqueue(queue_t *p_queue, int value)
{
  node_t *p_newnode;

  // Allocate node and initialize it  
  p_newnode = (node_t *) malloc(sizeof(node_t));
  // TBD : Error check
  p_newnode->data = value;
  p_newnode->next = NULL;

 
  // Handle empty list case 
  if (p_queue->rear == NULL)
  {
    p_queue->front = p_queue->rear = p_newnode;
    return SUCCESS; 
  }
 
  // We come here if non-empty Q 
  p_queue->rear->next = p_newnode;
  p_queue->rear = p_newnode;
  return SUCCESS;
}

int main()
{
  queue_t queue;
  int elem, i;

  init(&queue);

  enqueue(&queue, 10);
  display(&queue);
  enqueue(&queue, 20);
  display(&queue);
  enqueue(&queue, 30);
  display(&queue);
  enqueue(&queue, 40);

  display(&queue);

  for(i = 0; i < 5; i++)
  {
     dequeue(&queue, &elem);
     printf("dequeue returned %d\n", elem);

  }

  
  return 0;
}
