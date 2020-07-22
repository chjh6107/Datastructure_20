#include <stdio.h>

void insertion_sort(int A[], int n);

int main(void){
    int i;
    int A[9] = {1, 8, 6, 3, 2, 7, 4, 9, 10};

    for ( int i=0; i<9; i++ ) printf("%d ", A[i]);
    printf("\n");
    insertion_sort(A,8);

    for ( int i=0; i<9; i++ ) printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}

void insertion_sort(int A[], int n){//n==8
    int i,j;
    int key;

    for(j = 1; j <= n; j++){
        key = A[j];
        i = j - 1;
        while(i>0 && A[i]>key){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}