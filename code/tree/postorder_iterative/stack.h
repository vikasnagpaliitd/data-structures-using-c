// Author: Vikas Nagpal : http://anuttaralearning.com/
#ifndef __STACK_H__
#define __STACK_H__


/* treenode_t represents data type of a tree node */
typedef struct treenode
{
   int data;
   struct treenode *left;
   struct treenode *right;
} treenode_t;

/* Max number of elements in Stack */
#define MAX_STACK_SIZE 10

typedef struct stack
{
  int top;
  treenode_t* array[MAX_STACK_SIZE]; // Stack of pointer to treenode
} stack_t;

void init_stack(stack_t *p_stack);
int Is_Empty(stack_t *p_stack);
int Is_Full(stack_t *p_stack);
treenode_t *Pop(stack_t *p_stack);
void Push(stack_t *p_stack, treenode_t *elem);
#endif
