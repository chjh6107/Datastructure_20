#include <stdio.h>
#define STACK_SIZE 7

typedef struct _Stack{
    int stack[STACK_SIZE];
    int top;
}Stack;

void push(Stack *S, int x);
int pop(Stack *S);

int main(void){
    Stack S;
    int x[4] = {3, 1, 2, 5};
    int i;

    S.top = -1;
    for(i = 0; i < 4; i++) push(&S, x[i]);
    for(i = 0; i < 4; i++) printf("%d ", pop(&S));
    printf("\n");

    return 0;
}

void push(Stack *S, int x){
    S->top = S->top + 1;
    S->stack[S->top] = x;
}

int pop(Stack *S){
    S->top = S->top - 1;

    return S->stack[S->top + 1];
}