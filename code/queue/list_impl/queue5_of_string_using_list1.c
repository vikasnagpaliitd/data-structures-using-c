#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define MAX_STRING_LEN 256

typedef struct node
{
        char *str;
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

                ptr = p_queue->front;

                printf("Linked list contents : ");
                while (ptr != NULL)
                {
                        printf("%s ", ptr->str);
                        ptr = ptr->next;
                }
                printf("\n");
}


// We need to return char*. So, we take pointer to char*
int dequeue(queue_t *p_queue, char **p_elem)
//int dequeue(queue_t *p_queue, int *p_elem)
{
          node_t *ptr;


          if (p_queue->front == NULL)
          {
                        printf("debug: dequeue : front is NULL... returning FAILURE\n");
                        return FAILURE;
          }
          if (p_queue->front == p_queue->rear)
          {
                        printf("debug: dequeue : single element queue. now becoming empty...\n");
                        // Caller has responsibility to free it
                        *p_elem = p_queue->front->str;
                        free(p_queue->front);
                        p_queue->front = p_queue->rear = NULL;
                        return SUCCESS;
          }


          *p_elem = p_queue->front->str;
          ptr = p_queue->front;
          p_queue->front = p_queue->front->next;
          free(ptr);
          return SUCCESS;
}

int enqueue(queue_t *p_queue, char *str)
{
          node_t *p_newnode;


          p_newnode = (node_t *) malloc(sizeof(node_t));

          p_newnode->str = (char *)malloc(sizeof(char) * (strlen(str) + 1));
          strcpy(p_newnode->str, str);

          p_newnode->next = NULL;


          if (p_queue->rear == NULL)
          {
                        p_queue->front = p_queue->rear = p_newnode;
                        return SUCCESS;
          }
          p_queue->rear->next = p_newnode;
          p_queue->rear = p_newnode;
          return SUCCESS;
}

int main()
{
          queue_t queue;
          int i, ret;
          char str1[MAX_STRING_LEN];
          strcpy(str1, "world");

          char *str2 = malloc(sizeof(char) * MAX_STRING_LEN);
          strcpy(str2, "how");
  
          char *out_str;
 

          init(&queue);

          enqueue(&queue, "hello");
          display(&queue);

          enqueue(&queue, str1);
          display(&queue);

          enqueue(&queue, str2);
          display(&queue);

          for(i = 0; i < 4; i++)
          {
                        ret = dequeue(&queue, &out_str);
                        if (ret == SUCCESS)
                        {
                           printf("dequeue returned %s\n", out_str);
                           free(out_str);
                        }
          }
          free(str2);
          return 0;
}
