// Declaring the struct, and simple usage
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};


int main()
{
  struct node node1;
  struct node *p_node;

  node1.data = 10;
  node1.next = NULL;

  printf("node1.data=%d\n", node1.data);

  p_node = (struct node *)malloc(sizeof(struct node));
  p_node->data = 20;
  p_node->next = &node1;
  printf("p_node->data=%d\n", (*p_node).data);
  printf("p_node->next->data=%d\n", p_node->next->data);

  free(p_node);
}
