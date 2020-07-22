#include <stdio.h>
#define QUEUE_SIZE 100

#define INDEX(i) ((i+QUEUE_SIZE)%QUEUE_SIZE)

typedef struct _Queue {
        int queue[QUEUE_SIZE];
        int head;
        int tail;
}Queue;

void relocate(Queue *Q, int which, int base, int reverse) {
        int i, temp[QUEUE_SIZE];
        int n = Q->tail - Q->head;
        if ( n < 0 ) n += QUEUE_SIZE;
        if ( reverse == 1 )
            for ( i=0; i<n; i++ ) temp[n-1-i] = Q->queue[INDEX(Q->head + i)];                                                                                                       ;
        else
            for ( i=0; i<n; i++ ) temp[i] = Q->queue[INDEX(Q->head + i)];

        if ( which == 'H' ) {
           for (i=0; i<n; i++) Q->queue[ INDEX(base+i) ] = temp[i];
           Q->head = base;
           Q->tail = INDEX(base+n);
        } else if ( which == 'T' ) {
           for (i=0; i<n; i++) Q->queue[ INDEX(base-i-1) ] = temp[n-i-1];
           Q->head = INDEX(base-n);
           Q->tail = base;
        }
}
