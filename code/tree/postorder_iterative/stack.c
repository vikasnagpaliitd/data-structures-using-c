/* Program (Level 2): Stack using (Statically allocated) Array
 * Follows modular breakup into functions, and encapsulation of data into
 *   a struct
 * Author: Vikas Nagpal : http://anuttaralearning.com/
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/* Max number of elements in Stack */
#define MAX_STACK_SIZE 10


/* Function : to initialize the stack */
void init_stack(stack_t *p_stack)
{
    p_stack->top = -1;
}

/* Function Is_Empty : returns 1 if stack empty. Otherwise, returns 0 */
int Is_Empty(stack_t *p_stack)
{
  if (p_stack->top == -1)
     return 1;
  else
     return 0;
}


/* Function Is_Full : returns 1 if stack full. Otherwise, returns 0 */
int Is_Full(stack_t *p_stack)
{
  if (p_stack->top == MAX_STACK_SIZE - 1)
     return 1;
  else
     return 0;
}

/* Pop : returns the popped element. Exits process with error if stack is empty
 *    Note : Better alternative of printing error would have been returning
 *      error to the caller function (using return value or a pointer argument
 */
treenode_t *Pop(stack_t *p_stack)
{
   treenode_t *elem;

   /* Check for empty */
   if (Is_Empty(p_stack))
   {
      printf("Stack Underflow");
      exit(1);
   }

   elem = p_stack->array[p_stack->top];
   (p_stack->top)--;
   return elem;
}


/* Push: Pushes an element into the stack. Exits process with error
 *     if stack is full
 *    Note : Better alternative of exiting would have been returning
 *      error to the caller function
 */
void Push(stack_t *p_stack, treenode_t *elem)
{
   /* Check for full */
   if (Is_Full(p_stack))
   {
      printf("Stack Overflow");
      exit(1);
   }

   (p_stack->top)++;
   p_stack->array[p_stack->top] = elem;
}

/* For diagnostics and debugging : printing the stack */
void debug_print(stack_t *p_stack)
{
  int top,i ;

  top = p_stack->top;

  printf("Stack : ");
  for(i = 0; i <= top; i++)
     printf("%p ", p_stack->array[i]);
  printf("\n");
}

