#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct _Element{
    int key;
    int value;
    struct _Element *next;
    struct _Element *prev;
}Element;

int hash_func(int k);
Element *chained_hash_search(Element *T[], int k);
void chained_hash_insert(Element *T[], Element *x);
void chained_hash_delete(Element *T[], int k);
void print_table(Element *T[], int k);

int main(){
    Element *T[N] = {NULL};
    Element E[4] = {{2, 5}, {12, 2}, {22, 10}, {8, 5}};

    for(int i=0; i<4; i++){
        chained_hash_insert(T, &E[i]);
        print_table(T, E[i].key);
    }
    chained_hash_delete(T, 12);
    print_table(T, 12);
    return 0;
}

void print_table(Element *T[], int k){
    Element *tmp;

    tmp = chained_hash_search(T,k);
    if(tmp != NULL) printf("%d, %d\n", k, tmp->value);
}

int hash_func(int k){
    return k%N;
}
Element *chained_hash_search(Element *T[], int k){
    int key = hash_func(k);
    Element *tmp = T[key];

    while(tmp != NULL){
        if(tmp->key == k) return tmp;
        else tmp = tmp->next;
    }
    return tmp;
}

void chained_hash_insert(Element *T[], Element *x){
    int key = hash_func(x->key);

    if(T[key] == NULL) T[key] = x;
    else{
        T[key]->prev = x;
        x->next = T[key];
        T[key] = x;
    }
}

void chained_hash_delete(Element *T[], int k){
    int key = hash_func(k);
    Element *tmp = chained_hash_search(T, k);

    if(tmp != NULL){
        if(tmp->prev == NULL){
            if(tmp->next != NULL)
                tmp->next->prev = NULL;
            T[key] = tmp->next;
        }
        else{
            if(tmp->next != NULL)
                tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
        }
    }
}
