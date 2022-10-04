// It is easier to typedef struct node to node_t
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node_t;


int main()
{
  node_t node1;
  node_t *p_node;

  node1.data = 10;
  node1.next = NULL;

  printf("node1.data=%d\n", node1.data);

  p_node = (node_t *)malloc(sizeof(node_t));
  p_node->data = 20;
  p_node->next = &node1;
  printf("p_node->data=%d\n", (*p_node).data);
  printf("p_node->next->data=%d\n", p_node->next->data);

  free(p_node);
}
