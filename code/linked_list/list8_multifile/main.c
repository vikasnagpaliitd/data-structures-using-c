// Linked list : delete_at_end() implementation
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
  node_t *head = NULL;
  int i;

  head = insert_at_end(head, 10);
  head = insert_at_end(head, 20);
  head = insert_at_end(head, 30);
  head = insert_at_end(head, 40);

  display(head);

  for(i=0;i<5;i++)
  {
     printf("Deleting 1 element....\n");
     head = delete_at_end(head);
     display(head);
  }

  
  
  return 0;
}
