#include <stdio.h>

void quicksort(int A[], int p, int r);
int partition(int A[], int p, int r);

int main(void){
    int A[10] = {3, 0, 9, 2, 5, 8, 7, 4, 1, 6};
    int i;
    for(i = 0; i < 10; i++) printf("%d ", A[i]);
    printf("\n");

    quicksort(A, 0, 9);
    for(i = 0; i < 10; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}

void quicksort(int A[], int p, int r){
    int q;
    
    if (p < r){
        q = partition(A, p, r);
        printf("return from partition : %d\n", q);
        // printf("After call partition : ");
        // for(int i=0; i<10; i++) printf("%d ", A[i]);

        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int partition(int A[], int p, int r){
    int x;
    int i, j, tmp;

    x = A[r];
    i = p -1;

    for (j = p; j <= r - 1; j++){
        if(A[j] <= x){
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i+1];
    A[i+1] = A[j];
    A[j] = tmp;

    return i+1;
}