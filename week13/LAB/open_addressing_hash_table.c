#include <stdio.h>
#include <stdlib.h>

#define M 10
#define NIL 0
#define DELETED -1

int hash_func2(int k);
int hash_func(int k, int i);
int hash_search(int T[], int k);
void print_table(int T[]);
int hash_insert(int T[], int k);
int hash_delete(int T[], int k);

int main(){
    int T[M] = {0};
    int key[8] = {3, 1, 5, 10, 2, 100, 7, 20};
    int i;

    for(i = 0; i < 8; i++){
        hash_insert(T, key[i]);
        print_table(T);
    }
    printf("---------------\n");
    hash_insert(T, key[7]);
    print_table(T);
    printf("---------------\n");
    hash_insert(T, key[7]);
    print_table(T);
    printf("---------------\n");
    hash_insert(T, key[7]);
    print_table(T);
    printf("---------------\n");
    hash_insert(T, key[2]);
    print_table(T);
    hash_delete(T, 10);
    print_table(T);
    hash_delete(T, 100);
    print_table(T);
    hash_delete(T, 5);
    print_table(T);
    hash_delete(T, 1);
    print_table(T);
    hash_delete(T, 2);
    print_table(T);
    hash_delete(T, 7);
    print_table(T);
    hash_delete(T, 3);
    print_table(T);

    return 0;
}

int hash_func2(int k){
    return k%M;
}

int hash_func(int k, int i){
    // return ((k % M) + i) % M;
    return (hash_func2(k) + i) % M;
}

int hash_search(int T[], int k){
    int i, j;

    i = 0;
    do{
        j = hash_func(k, i);
        if(T[j] != DELETED && T[j] == k)
            return j;
        i = i+1;
    }while(T[j] != NIL || i != M);

    return NIL;
}

void print_table(int T[]){
    for(int i = 0; i<M; i++) printf("%d ", T[i]);
    printf("\n");
}

int hash_insert(int T[], int k){
    int i,j;

    i = 0;

    do{
        j = hash_func(k, i);
        if(T[j] == NIL || T[j] == DELETED){ // Table의 index가 deletion되었거나 NULL일 경우에만 insertion
            T[j] = k;
            return j;
        }
        else i = i+1;
        printf("\n%d : collision detected!!\n", i);
    }while(i != M);                         // Bucket의 Max 값 까지 loop

    return NIL;
}

int hash_delete(int T[], int k){
    int key = hash_search(T, k);
    T[key] = DELETED;
}