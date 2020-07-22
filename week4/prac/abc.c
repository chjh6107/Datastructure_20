#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b )
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

}

void heapify( int A[], int q, int i)
{
    int largest = i;
    int l = 2 * i + 1 ;
    int r = 2 * i + 2;

    if( l < q && A[l] > A[largest])
    {
        largest = l;
    }
    if( r < q && A[r] > A[largest])
    {
        largest = r;
    }
    if( largest != i)
    {
        swap( &A[i] , &A[largest]);
        heapify(A, q, largest);
    }
}



void max_heap_append(int A[], int p , int q)
{
    int i;

    for( i = q-1; i >= 0; i--)
    {
        heapify( A , q , i);
    }
    // sort the heap
    for( i = q-1; i>= 0; i--)
    {
        swap(&A[0] , &A[i]);

        heapify(A, i, 0);
    }


}
void printA(int A[], int q)
{
    int i;
    for( i = 0; i < q; i++)
    {
        printf("%d ", A[i]);

    }
    printf("\n");
}


int main()
{

    int A[] = {12,10,9,2,11,8,14,3};

    max_heap_append(A,3,8);

    printf("Sorted: ");

    printA(A, 8);

    return 0;
}
