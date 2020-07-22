#include <stdio.h>

void insertion_sort(int A[], int p, int r) {
        int i, j;
        int key;

        for (j = p+1; j <= r ; j++) {
                key = A[j];
                i = j - 1;
                while (i > -1 && A[i] > key) {
                        A[i + 1] = A[i];
                        i = i - 1;
                }
                A[i + 1] = key;
        }
//      static int ct = 0;
//      printf("called - %d\n", ++ct);
}
void swap(int *a, int *b){
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

int partition(int A[], int p, int r) {
        int x;
        int i, j;

        x = A[r];
        i = p - 1;
        for (j = p; j <= r - 1; j++) {
                if (A[j] <= x) {
                        i = i + 1;
                        swap(&A[i], &A[j]);
                }
        }
        swap(&A[i + 1], &A[r]);

        return i + 1;
}

int hybridsort(int A[], int p, int r, int t){
        int q;
        int ct=0;

        if (p < r) {
                q = partition(A, p, r);
                if ( q - p <= t ) { insertion_sort(A, p, q-1); ct++; }
                // if ( q - p <= t && q-p>0 ) { insertion_sort(A, p, q-1); ct++;                                                                                                        }
                else ct += hybridsort(A, p, q - 1, t);
                if ( r - q <= t ) { insertion_sort(A, q+1, r); ct++; }
                // if ( r - q <= t && r-q>0 ) { insertion_sort(A, q+1, r); ct++;                                                                                                        }
                else ct += hybridsort(A, q + 1, r, t);
        }
        return ct;
}

