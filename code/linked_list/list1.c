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
  // declare head pointer
  struct node *head = NULL;
  struct node *ptr = NULL;


   // create node1 
   struct node node1;
   node1.data = 10;
   node1.next = NULL;

   // point head to node1
   head = &node1;
 

  // create node2, 
   struct node node2;
   node2.data = 20;
   node2.next = NULL;

  // connect node2 after node1
  node1.next = &node2;


  // print the linked list
  printf("Contents of Linked Lists : ");
  ptr = head;
  while (ptr != NULL)
  {
       printf("%d ", ptr->data);//data in struct pointed at by ptr
       ptr = ptr->next; //next in struct pointed at by ptr
  }
  printf("\n");

}
