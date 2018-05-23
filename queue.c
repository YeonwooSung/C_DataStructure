/*
 * This is a linked list implementation of queue interface.
 *
 * @author Yeonwoo Sung
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//Dequeue function.
queueNode *dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return NULL; //return null if the message queue does not have any node in it.
    }

    queueNode *currentNode = queue->head;
    queue->head = currentNode->next;

    if (queue->head == NULL) { //check if the current node is the last node of the queue
        queue->tail == NULL; //set the tail of the queue as NULL as well.
    }

    return currentNode; //return the current node to dequeue.
}


//Enqueue the new node to the queue
void enqueue(MQueue *queue, int value) {

    queueNode *node = (Node *) malloc(sizeof(queueNode)); //allocate memory to create node.
    node->data = value; //set the data value of the new node
    node->next = NULL; //set the pointer of the next node

    if (queue->head == NULL) { //check whether the queue contains the node or not
        queue->head = node; //set the initial head of the message queue
    } else {
        //Otherwise, link the new node to the previous tail.
        queue->tail->next = node;
    }

    queue->tail = node; //add the node to the queue

}


//Makes the queue and initializes it.
Queue *initQueue() {
    Queue *queue = (Queue) malloc(sizeof(Queue)); //make a new queue.

    if (queue != NULL) {
        queue->head = NULL; //initialize the head of the queue as NULL.
        queue->tail = NULL; //initialize the tail of the queue as NULL.
        return queue;
    }

    // If the malloc does not worked properly, print out the error message.
    perror("The queue is not initialized!");
    abort();
}


//This function makes the queue empty.
void empty(Queue *queue) {
    while (dequeue(queue) != NULL); //dequeue until the read_msg returns the NULL.
}


//Free the given queue.
void freeMQueue(MQueue *queue) {
    emptyQueue(queue); //free the allocated memory of all nodes in the message queue
    free(queue); //free the queue.
}
