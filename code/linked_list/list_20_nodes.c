// Adding 20 nodes in linked list
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
  int i;


   // create node1 
   struct node *p_node1, *p_node;
   struct node *last;

   p_node1 = (struct node*) malloc(sizeof(struct node));
   p_node1->data = 10;
   p_node1->next = NULL;

   // point head to node1
   head = last = p_node1;


   for(i = 0; i < 19; i++)
   {
     //create node
     p_node = (struct node*) malloc(sizeof(struct node));
     p_node->data = (i+2)*10;
     p_node->next = NULL;

     //connect at end
     last->next = p_node;
     last = p_node;
   }
  


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
