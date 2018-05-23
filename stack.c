/*
 * This is a linked list implementation of stack interface.
 *
 * @author Yeonwoo Sung
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

/* The aim of this function is to initialize a new stack variable */
void initStack(Stack *stackP) {
    stackP->top = NULL;
}

/* function to free the memory associated with the stack */
void freeStack(Stack *stkPtr) {
    stackNode *temp, *temp2;

    temp = stkPtr->top;
    while (temp != NULL) {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }

    stkPtr->top = NULL;
}

/* The aim of this function is to add an element to the top of the stack */
void push(Stack *stkPtr, stackElement element) {
    stackNode *newNode;

    /* allocate a new node to hold element pushed */
    newNode = malloc(sizeof(stackNode));

    if (newNode == NULL) {
        perror("Insufficient memory to push element on stack.\n");
        exit(1);
    }

    /* put information in node */
    newNode->element = malloc(sizeof(char) * strlen(element));
    strcpy(newNode->element,element);


    /* link new top node to old top node */
    newNode->next = stkPtr->top;

    /* make the new node the top node in stack */
    stkPtr->top = newNode;
}


/* The function that removes the element from the top of the stack */
stackElement pop(Stack *stkPtr) {

    /* Check if the stack  is empty. */
    if (isEmpty(stkPtr)) {
        fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
        exit(1);
    }

    stackElement element = (stkPtr->top)->element;

    stackNode *temp = stkPtr->top;
    stkPtr->top = (stkPtr->top)->next;
    free(temp);

    return element;
}


/* The function that returns a true value if the stack is empty */
bool isEmpty(stack *stkPtr) {
    return stkPtr->top == NULL;
}


/* The function that returns the number of elements in the stack */
int length(Stack *stkPtr) {
    int count = 0;

    stkNode *temp = stkPtr->top;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

/* function that returns the top element in the stack without removing it */
stackElement top(Stack *stkPtr) {

    /* Check if the stack is empty. */
    if (isEmpty(stkPtr)) {
        perror("Stack is empty - can't peek.\n");
        exit(1);
    }

    return (stkPtr->top)->element;
}
