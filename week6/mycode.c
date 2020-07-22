#include <stdlib.h>

int char_counting_sort(char A[], char B[], int n) {
    int i, j;
    int *C;

    C = (int *)malloc(sizeof(int)*(128)); 

    for(i = 0; i < 128; i++)
        C[i] = 0;

    for(j = 0; j < n; j++)
        C[A[j]] = C[A[j]] + 1;


	for(i = 0; i < 26; i++) {

        C['A' + i] = C['A' + i] + C['a' + i - 1];
        C['a' + i] = C['a' + i] + C['A' + i];
	}

    for(j = n - 1; j >= 0; j--){
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    free(C);

    for(i = 0; i<n;i++)
        if(A[0] == B[i])
            return i;
}