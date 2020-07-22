#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int p, int q, int r);
void merge_sort(int A[], int p, int r);
int main(void){
    int A[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;

    for (i = 0; i < 9; i++) printf("%d ", A[i]);
    printf("\n");

    merge_sort(A, 0, 8);

    for (i = 0; i < 9; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}

void merge(int A[], int p, int q, int r) {
    int *tmpL, *tmpR; //L, R
    int boundary; //Infinity
    int n1, n2;
    int i, j, k;

    n1 = q - p + 1;
    n2 = r - q;

    tmpL = (int*)malloc(sizeof(int) * (n1 + 1));
    tmpR = (int*)malloc(sizeof(int) * (n2 + 1));

for (i = 0; i < n1; i++) tmpL[i] = A[p + i];
for (j = 0; j < n2; j++) tmpR[j] = A[q + j + 1];

boundary = tmpL[n1 - 1] > tmpR[n2 - 1] ? tmpL[n1 - 1] + 1 : tmpR[n2 - 1] + 1; //Infinity
tmpL[n1] = boundary;
tmpR[n2] = boundary;

i = 0;
j = 0;

    for(k = p; k <= r; k++){
        if(tmpL[i] <= tmpR[j]){
            A[k] = tmpL[i];
            i = i + 1;
        }
        else{
            A[k] = tmpR[j];
            j = j + 1;
        }
    }





free(tmpL);
free(tmpR);
}

void merge_sort(int A[], int p, int r){
    int q;

    if(p < r){
        q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}