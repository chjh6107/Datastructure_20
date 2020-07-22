#include <stdio.h>
#include <stdlib.h>

#define NIL 0
#define DELETED -1

int compare_hash(int M, int *key, int N, int C1, int C2);

int linear_probing(int k, int M);
int linear_hash_func(int k, int i, int M);

int quadratic_probing(int k, int M, int C1, int C2);
int quadratic_hash_func(int k, int i, int M, int C1, int C2);

int main(){
    int M = 20;
    int N = 15;
    int key[15] = {432025320, 1470895010, 1483763984, 1982794092, 776711393, 1990779951, 643445809,
    1416446822, 1058311823, 1159981259, 668521661, 1643697457, 128634380, 142633774, 400658964};
    int C1 = 1;
    int C2 = 1;
    
    int res = compare_hash(M, key, N, C1, C2);
    return 0;
}

int compare_hash(int M, int *key, int N, int C1, int C2){
    int res1 = 0, res2 = 0;
    for(int i = 0; i < N; i++){
        res1 += linear_probing(key[i], M);
        res2 += quadratic_probing(key[i], M, C1, C2);
    }
    printf("l = %d q = %d\n", res1,res2);
    return (res1 - res2);
}

int linear_probing(int k, int M){
    int T[] = {0};
    int i,j;

    i = 0;
    while(i != M){
        j = linear_hash_func(k, i, M);
        if(T[j] == NIL || T[j] == DELETED){
            T[j] = k;
            return i;
        }
        else{
            i = i+1;
            return i;
        }

    }
}

int linear_hash_func(int k, int i, int M){
    return (k + i) % M;
}

int quadratic_probing(int k, int M, int C1, int C2){
    int T[] = {0};
    int i,j;
    int count = 0;
    i = 0;
    while(i != M){
    count++;
        j = quadratic_hash_func(k, i, M, C1, C2);
        if(T[j] == NIL || T[j] == DELETED){
            T[j] = k;
            return j;
        }
        else i = i+1;
    }

    return count;
    // return count;
}

int quadratic_hash_func(int k, int i, int M, int C1, int C2){
    return (k + (C1*i) + (C2*i) *i) % M;
}