// Linked list : delete_at_end() implementation
#ifndef __LIST_H__
#define __LIST_H__

typedef struct node
{
  int data;
  struct node *next;
} node_t;

void display(node_t *head);

node_t *insert_at_begin(node_t *head, int value);


node_t *delete_at_begin(node_t *head);

node_t *insert_at_end(node_t *head, int value);

node_t *delete_at_end(node_t *head);
#endif
