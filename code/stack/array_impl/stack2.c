// Array based implementation of stack
#include <stdio.h>

#define MAX_ELEMENTS 50
#define INVALID_VALUE -9999
typedef struct stack
{
   int arr[MAX_ELEMENTS];
   int top;
} stack_t;

void init(stack_t *p_stack)
{
  p_stack->top = -1; // empty stack
}

int is_empty(const stack_t *p_stack)
{
  return (p_stack->top == -1);
}

int is_full(const stack_t *p_stack)
{
  return (p_stack->top == MAX_ELEMENTS - 1);
}

void push(stack_t *p_stack, int elem)
{
  // error check. validate stack is not full
  if (is_full(p_stack))
  {
     printf("Stack full. not pushing...");
     return;
  }

  p_stack->top ++;
  p_stack->arr[ p_stack->top ] = elem;
}

int pop(stack_t *p_stack)
{
  // error check. validate stack is not empty 
  if (is_empty(p_stack))
  {
     printf("Stack empty. not popping...");
     return INVALID_VALUE; 
  }
  int ret = p_stack->arr[ p_stack->top ];
  p_stack->top--;
  return ret;
}



int main()
{

  stack_t stack;

  init(&stack); // sets top to -1 
 
  int choice, elem, i;
 
  while(1)
  {
 
     printf(" 1)Check Empty \n");
     printf(" 2)Check Full\n");
     printf(" 3)Push\n");
     printf(" 4)Pop\n");
     printf(" 5)Print\n");
     printf(" 0)Exit\n");
     printf(" Enter option : ");
 
     scanf("%d", &choice);
 
     switch(choice)
     {
         case 1: // Check Empty
            if (is_empty(&stack))
               printf("Stack is empty\n");
            else
               printf("Stack is not empty\n");
            break;
 
         case 2: // Check Full
            if (is_full(&stack))
               printf("Stack is full\n");
            else
               printf("Stack is not full\n");
            break;
 
         case 3: // Push
            printf("Enter the element to be inserted:");
            scanf("%d", &elem);

            // If not full, insert element 
            if (is_full(&stack))
                printf("stack is full... can not push\n");
            else
		push(&stack, elem);
            break;
 
         case 4: // Pop

            // If not empty, pop element 
            if (is_empty(&stack))
                printf("stack is empty... can not pop\n");
            else
            {
		elem = pop(&stack);
                printf("Popped value = %d\n", elem);
            }
            break;

         case 5: // Print  (for debugging)
            printf("top = %d\n", stack.top);
            for(i = 0; i <= stack.top;i++)
                printf("stack.arr[%d]=%d\n", i, stack.arr[i]);
            break;

         case 0: // Exit
            return 0;
     }
  }
  return 0;
}
