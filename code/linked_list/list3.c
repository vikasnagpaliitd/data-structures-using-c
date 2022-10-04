// Linked List : insert_at_begin: returning single pointer
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node_t;

void display(node_t *head)
{

}

//void insert_at_begin(node_t **p_head, int value)
node_t *insert_at_begin(node_t *head, int value)
{
   node_t *p_newnode;

   p_newnode = (node_t *) malloc(sizeof(node_t));
   p_newnode->data = value;

   // setting next of newnode to current linked list
   p_newnode->next = head;

   // head points to new node
   head = p_newnode;

   return head;
}


int main()
{
  // declare head pointer
  node_t *head = NULL;
  node_t *ptr;


  head = insert_at_begin(head, 10);
  head = insert_at_begin(head, 20);
  head = insert_at_begin(head, 30);
  head = insert_at_begin(head, 40);



  // Call display() : // expect 40 30 20 10
  
#if 0
  node_t *ptr = NULL;


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

#endif
  // print the linked list
  printf("Contents of Linked Lists : ");
  ptr = head;
  while (ptr != NULL)
  {
       printf("%d ", ptr->data);//data in struct pointed at by ptr
       ptr = ptr->next; //next in struct pointed at by ptr
  }
  printf("\n");

  //TBD : add loop to free the memory

}
