void quicksort(int A[], int p, int r, int t);
int partition(int A[], int p, int r);
int insertion_sort(int A[], int start, int end);

int count=0;

int hybridsort(int A[], int p, int r, int t){ //t == 임계점
    quicksort(A,p,r,t);

    return count;
}

void quicksort(int A[], int p, int r, int t){
    int q;

    if (p < r){
            q = partition(A, p, r);

            if(q-p <= t){
                insertion_sort(A,p,q-1);
                quicksort(A, q+1, r, t);
            }               
            else if(r-q+2 <= t){
                insertion_sort(A,q+1,r);
                quicksort(A, p, q-1, t);
            }
            // else if(q-1-p+1 <= t && r-q+2 <= t){
            //     insertion_sort(A,p,q-1);
            //     insertion_sort(A,q+1,r);
            //     // quicksort(A, p, q-1, t);
            // //     quicksort(A, q+1, r, t);
            // }
            else{
                quicksort(A, p, q-1, t);
                quicksort(A, q+1, r, t);
            }
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

int insertion_sort(int A[],int start, int end){
    int i,j;
    int key;
    count++;

    for(j = start; j <= end; j++){
        key = A[j];
        i = j - 1;
        while(i>0 && A[i]>key){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
    
}