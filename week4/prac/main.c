#include <stdio.h>
#include <string.h>

void heap_increase_key(int A[], int i, int key){
    int tmp;

    if(key < A[i]) return;

    A[i] = key;

    while(i > 1 && A[parent(i)] < A[i]){
        tmp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = tmp;
        i = parent(i);
    }
}

void max_heap_insert(int A[], int key, int n){
    n = n + 1;
    A[n] = -1000000;
    heap_increase_key(A, n, key);
}

int main(int argc, char *argv[]){
    
    int i;

    printf("Input : ");
    for(i=0; i<strlen(argv[1]); i++)
    printf("%c ", argv[1][i]);
    printf("\n");

    // max_heap_append(A, 3, 8);
    max_heap_insert((int)argv[1],3,8);

    return 0;
}
