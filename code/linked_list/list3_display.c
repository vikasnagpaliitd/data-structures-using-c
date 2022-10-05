// Linked list : display() implementation
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


int main()
{
  // declare head pointer
  node_t *head = NULL;

  // create node1 
  node_t *p_node1;
  p_node1 = (node_t*) malloc(sizeof(node_t));
  p_node1->data = 10;
  p_node1->next = NULL;

  // point head to node1
  head = p_node1;
 

  // create node2, 
  node_t *p_node2;
  p_node2 = (node_t*) malloc(sizeof(node_t));
  p_node2->data = 20;
  p_node2->next = NULL;

  // connect node2 after node1
  p_node1->next = p_node2;

  display(head);
  //display(NULL); // to test for empty linked list

  //TBD : add loop to free the memory
  return 0;
}
