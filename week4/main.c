#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void max_heap_append(int A[], int p, int q);

int main(void){
    int A[]={3, 5, 3, 1, 2, 4, 6};
    int i = 0;

    printf("Input : ");
    while(A[i] != NULL){
        printf("%d ",A[i]);
        i++;
    }
    // max_heap_append(A, 3, 8);

    return 0;
}