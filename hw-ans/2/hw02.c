#include <stdio.h>

int parent(int i) { return (int)((i - 1) / 2); }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void max_heapify_upward(int A[], int x) {
        int i=x, tmp;
        while ( i>0 && A[parent(i)] < A[i] ) {
                tmp = A[i];
                A[i] = A[parent(i)];
                A[parent(i)] = tmp;
                i = parent(i);
        }
}
void max_heap_append(int A[], int p, int r) {
        int i;
        for ( i=p+1; i<=r; i++ )
                max_heapify_upward(A, i);
}

