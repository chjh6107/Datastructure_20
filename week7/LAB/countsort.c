#include <stdio.h>
#include <stdlib.h>

void counting_sort(int A[], int B[], int n, int k);

int main(void){
    int A[10] = {3, 0, 1, 2, 5, 2, 1, 2, 1, 0};
    int B[10];
    int i;

    for(i = 0; i < 10; i++) printf("%d ", A[i]);
    printf("\n");

    counting_sort(A, B, 10, 5);

    for(i = 0; i < 10; i++) printf("%d ", B[i]);
    printf("\n");

    return 0;
}

void counting_sort(int A[], int B[], int n, int k){
    int *C;;
    int i;

    C = (int *)malloc(sizeof(int)*(k+1));

    for(i = 0; i < k+1; i++)
        C[i] = 0;

    for(i = 0; i < n; i++)
        C[A[i]] = C[A[i]] + 1;

    //     printf("six : ");
    // for(i=0;i<k+1;i++) printf("%d : %d, ",i, C[i]);
    // printf("\n");

    for(i = 1; i < k+1; i++)
        C[i] = C[i] + C[i-1];
    
    //     printf("niner : ");
    // for(i=0;i<k+1;i++) printf("%d : %d, ",i, C[i]);
    // printf("\n");

    for(i = n - 1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }

 for(i=0;i<k+1;i++) printf("%d : %d, ",i, C[i]);
    printf("\n");
    printf("\n");
    free(C);
}
