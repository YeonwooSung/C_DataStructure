//
// Created by YeonwooSung on 2018. 5. 29..
//

#include <stdio.h>
#include <malloc.h>
#include <stdint.h>  // gcc needs this for intptr_t.
#include "xor_linked_list.h"


/**
 * Traverses the list given either the head or the tail.
 *
 * @param start the starting point of the xor linked list.
 */
void traverse( XOR_LinkedList *start ) {
    XOR_LinkedList *prev, *cur;

    cur = prev = start;

    while (cur) {
        printf( "value = %d\n", cur->value );

        if ( cur->np == cur ) { //check if the xor pointer is same with the current nodes' pointer
            break;
        }

        if ( cur == prev )
            cur = cur->np;   // start of list
        else {
            xorll *save = cur;
            cur = (XOR_LinkedList*) ((uintptr_t)prev ^ (uintptr_t)cur->np);
            prev = save;
        }
    }
}


/**
 * Creates a new node adding it to the given end and return it.
 *
 * @param cur the pointer of the current node.
 * @param value the value to store in the xor linked list.
 * @return the new node's pointer.
 */
XOR_LinkedList *put(XOR_LinkedList *cur, int value ) {
    XOR_LinkedList *next;
    XOR_LinkedList *prev = cur->np;

    next = (XOR_LinkedList*) malloc( sizeof( xorll ));
    next->value = value;
    next->np = cur;  // end node points to previous one

    if ( cur == NULL ); // very first node - we'll just return it
    else if ( prev == NULL ) {
        // this is the second node (they point at each other)
        cur->np = next;
        next->np = cur;
    } else {
        // do the xor magic
        cur->np = (XOR_LinkedList*) ((uintptr_t)prev ^ (uintptr_t)next);
    }

    return next;
}
