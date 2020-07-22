#define QUEUE_SIZE 100

typedef struct _Queue{
    int queue[QUEUE_SIZE];
    int head;
    int tail;
}Queue;

void relocate(Queue *Q, int which, int base, int reverse) {
    int i, j;
    Queue temp;

    for (i = 0; i < QUEUE_SIZE; i++)
        temp.queue[i] = 0;
    temp.head = temp.tail = 0;

    if (which == 'H') {
        temp.head = base;
        temp.tail = (base - Q->head + Q->tail + QUEUE_SIZE) % QUEUE_SIZE;
    }
    else {
        temp.tail = base;
        temp.head = (base + Q->head - Q->tail + QUEUE_SIZE) % QUEUE_SIZE;
    }

    if (reverse == 0) {
        for (i = Q->head, j = temp.head; i != Q->tail; i=(i+1)%QUEUE_SIZE, j=(j+1)%QUEUE_SIZE) {
            temp.queue[j] = Q->queue[i];
        }
    }
    else {
        for (i = Q->head, j = temp.tail; i != Q->tail; i=(i+1)%QUEUE_SIZE, j=(j-1+QUEUE_SIZE)%QUEUE_SIZE)
            temp.queue[(j-1+QUEUE_SIZE)%QUEUE_SIZE] = Q->queue[i];
    }

    for (i = 0; i < QUEUE_SIZE; i++)
        Q->queue[i] = temp.queue[i];
    Q->head = temp.head;
    Q->tail = temp.tail;
}