#include <stdio.h>
#define QUEUE_SIZE 7

typedef struct _Queue{
    int queue[QUEUE_SIZE];
    int head;
    int tail;
}Queue;

void enqueue(Queue *Q, int x);
int dequeue(Queue *Q);

int main(void){
    Queue Q;
    int x[4] = {0,1,5,3};
    int i;

    Q.head = 0;
    Q.tail = 0;

    for(i = 0; i < 4; i++) enqueue(&Q, x[i]);
    for(i = 0; i < 4; i++) printf("%d ", dequeue(&Q));
    printf("\n");
    
    return 0;
}

void enqueue(Queue *Q, int x){
    Q->queue[Q->tail] = x;
    if(Q->tail == QUEUE_SIZE - 1)
        Q->tail = 0;
    else
        Q->tail = Q->tail + 1;
}

int dequeue(Queue *Q){
    int x;

    x = Q->queue[Q->head];
    if(Q->head == QUEUE_SIZE - 1)
        Q->head = 0;
    else
        Q->head = Q->head + 1;
    return x;
}