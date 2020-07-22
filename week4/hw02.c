int parent(int i){
    return (int)((i - 1) / 2);
}

void heap_increase_key(int A[], int i){
    int tmp;

    while(i > 0 && A[parent(i)] < A[i]){
        tmp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = tmp;
        i = parent(i);
    }
}

void max_heap_append(int A[], int p, int q){
    heap_increase_key(A,p,q);
}
