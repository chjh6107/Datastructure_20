#include <stdio.h>

void insertionSort(int A[], int n){
    int i, j;
    int key, cnt=0;


    for(j = 1; j < n; j++){
        key = A[j];
        i = j - 1;
        while(i >= 0 && A[i] > key){
            A[i + 1] = A[i];
            i--;
            cnt++;
            printf("Count = %d\n", cnt);
        }
        A[i + 1] = key;
    }
}

int main(void){
    int n = 10;
    int A[10] = {3,3,7,6,5,4,3,3,3,3};
    int i;
    
    for(i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    insertionSort(A,n);

    for(i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}