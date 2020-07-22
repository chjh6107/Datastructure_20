#include <stdio.h>
#include <stdio.h>

#define N 10

typedef struct _Element{
    int key;
    int value;
}Element;

Element *direct_address_search(Element *T[], int k);
void direct_address_insert(Element *T[], Element *x);
void direct_address_delete(Element *T[], int k);
void print_direct_address_table(Element *T[]);

int main(){
    Element *T[N] = {NULL};
    Element E[4] = {{2, 5}, {3, 2}, {5, 10}, {8, 5}};

    for(int i = 0; i < 4; i++){
        direct_address_insert(T, &E[i]);
        print_direct_address_table(T);
        printf("\n");
    }
    for(int i = 0; i<4; i++){
        direct_address_delete(T, E[i].key);
        print_direct_address_table(T);
        printf("\n");
    }
    return 0;
}

Element *direct_address_search(Element *T[], int k){
    return T[k];
}

void direct_address_insert(Element *T[], Element *x){
    T[x->key] = x;
}

void direct_address_delete(Element *T[], int k){
    T[k] = NULL;
}

void print_direct_address_table(Element *T[]){
    for(int i = 0; i < N; i++){
        if(T[i] != NULL) printf("%d, %d\n", T[i]->key, T[i]->value);
    }
}