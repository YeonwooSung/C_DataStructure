/*
 * The header file for a linked list implementation of queue interface.
 *
 * @author Yeonwoo Sung
 */

#ifndef _QUEUE_H
#define _QUEUE_H


/* Interface for integer MQueue */
typedef struct node{
    int data; //the message data
    struct node *next; //pointer to the next node to implement the linked list
} queueNode;

/* The struct for queue */
typedef struct queue {
    queueNode *head; //the first node of the queue.
    queueNode *tail; //the last node of the queue.
} Queue;

void enqueue(Queue *s, int value ); // enqueue
queueNode *dequeue(Queue *); // dequeue
void initQueue(Queue *); // initializer
void freeQueue(Queue *); // free the message queue.
void empty(Queue *queue); // makes the queue empty

#endif //_QUEUE_H
