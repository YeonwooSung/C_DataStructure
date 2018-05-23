#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef char * stackElement;

typedef struct node {
    stackElement element;
    struct stackNode *next;
} stackNode;

typedef struct {
    stackNode *top;
} Stack;

/* function to initialize a new stack variable */
void initStack(Stack *);

/* function to free the memory associated with the stack */
void freeStack(Stack *);

/* function to add an element to the top of the stack */
void push(Stack *, stackElement);

/* function that removes the element from the top of the stack */
stackElement pop(Stack *);

/* function that returns a true value if the stack is empty */
bool isEmpty(Stack *);

/* function that returns the number of elements in the stack */
int length(Stack *);

/* function that returns the top element in the stack without removing it */
stackElement top(Stack *);

#endif //_STACK_H
