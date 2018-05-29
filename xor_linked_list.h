//
// Created by YeonwooSung on 2018. 5. 29..
//

#ifndef XOR_LINKED_LIST_H
#define XOR_LINKED_LIST_H

typedef struct xor_linkedlist {
    int value;
    struct xor_linkedlist  *np;
}  XOR_LinkedList;

void traverse( XOR_LinkedList *start );
XOR_LinkedList *put( XOR_LinkedList *prev, XOR_LinkedList *cur, int value );

#endif //C_DATASTRUCTURE_XOR_LINKED_LIST_H
