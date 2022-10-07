/* Queue using Circular Array Code
*  Notes:
*   Q Empty condition : front == rear
*   Q Full condition front == rear + 1 (circularly)
*   Front : Index one less than the front element (circularly)
*   Rear : Index of last filled element
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
#define SUCCESS 1
#define FAILURE 0

/* Data Type for Queue ADT */
typedef struct queue
{
  int arr[MAX_QUEUE_SIZE];
  int front;
  int rear;
}queue_t;

/* Initialize Queue to empty */
void init_queue(queue_t *q)
{
  q->front = 0;
  q->rear = 0;
}

int is_empty(queue_t *q)
{
  return (q->front == q->rear);
}

int is_full(queue_t *q)
{
   return (q->front == ((q->rear +1) % MAX_QUEUE_SIZE));
}

int enqueue(queue_t *q, int elem)
{
  if (is_full(q))
     return FAILURE; /* Failure */

  /* Increment rear. Then store the element */
  q->rear =  (q->rear + 1) % MAX_QUEUE_SIZE;
  q->arr[q->rear] = elem;
 
  return SUCCESS;

}

/* Note: p_elem pointer is used to return the removed element */
int dequeue(queue_t *q, int *p_elem)
{
  if (is_empty(q))
     return FAILURE; /* Failure */

  q->front = (q->front + 1)%MAX_QUEUE_SIZE;

  *p_elem = q->arr[q->front];
  return SUCCESS; /* Success */
}

void debug_print(queue_t *q)
{
  int index;

  printf("q->front = %d\n", q->front);
  printf("q->rear = %d\n", q->rear);

  if (q->front == q->rear)
  {
    printf("Queue is empty\n");
    return;
  } 

  /* If Queue is not empty, we print from index + 1 till rear */
  index = q->front;
  do
  {
     index = (index + 1)%MAX_QUEUE_SIZE;
     printf("q->arr[%d]=%d\n", index, q->arr[index]);
  }
  while (index != q->rear);
  
}

int main()
{
   queue_t q1;
   int option;
   int status; // success/failure return
   int elem; // element value;

   // Initialize the Queue
   init_queue(&q1);

   // Main Input loop (or driver loop)
   while(1)
   {
     printf("What do you want to do?\n");
     printf("1) Enqueue an element\n");
     printf("2) Dequeue an element\n");
     printf("3) Check Empty\n");
     printf("4) Check Full\n");
     printf("5) Debug Print the queue  data\n");
     printf("6) Exit\n");
  
     scanf("%d", &option);

     switch (option)
     {
       case 1: /* Insert an element */
           printf("Enter the element\n");
           scanf("%d", &elem);
           status = enqueue(&q1, elem);
           printf("enqueue returned %d\n", status);
           break;

       case 2: /* Remove the front element */
           status = dequeue(&q1, &elem);
           printf("dequeue returned status %d\n", status);
           if (status == 1)
            printf("dequeue returned element %d\n", elem);
           break;

 
       case 3: /* Check Empty */
           status = is_empty(&q1);
           printf("is_empty returned status %d\n", status);
           break;

       case 4: /* Check Full */
           status = is_full(&q1);
           printf("is_full returned status %d\n", status);
           break;

       case 5: /* Debug Print */ 
           debug_print(&q1);
           break;

       case 6: /* Exit*/ 
           return 0;
           break;

     }
 
   }
   return 0;
}
