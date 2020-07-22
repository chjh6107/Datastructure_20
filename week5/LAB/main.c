#include <stdio.h>

int parent(int i){
    return (int)((i - 1) / 2);
}

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i +2;
}

void max_heapify(int A[], int i, int n){
    int l, r;
    int largest;
    int tmp;

    l = left(i);
    r = right(i);

    if(l <= n && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if(r <= n && A[r] > A[largest])
        largest = r;

    if(largest != i){
        tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        max_heapify(A, largest, n);
    }
}

void build_max_heap(int A[], int n){
    int i;

    for(i = parent(n); i>=0; i--)
        max_heapify(A, i, n);
}

void heapsort(int A[], int n){
    int i;
    int tmp;

    build_max_heap(A, n);
    for(i = 0; i<14; i++) printf("%d ", A[i]);
    printf("\n");
    for(i = n; i>=1; i--){
        tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        max_heapify(A, 0, i-1);
    }
}


int main(void){
    int A[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int i;

    for(i = 0; i<14; i++) printf("%d ", A[i]);
    printf("\n");

    heapsort(A, 13); 

    for(i = 0; i<14; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}
