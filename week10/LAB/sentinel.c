#include <stdio.h>
#include <stdlib.h>

typedef struct _Element{
    int key;
    struct _Element *prev;
    struct _Element *next;
}Element;

void list_print(Element *L);
Element *list_searach(Element *L, int k);
void list_insert(Element *L, int k);
void list_delete(Element *L, int k);

int main(void){
    Element L;

    L.prev = &L;
    L.next = &L;

    list_insert(&L, 5);
    list_insert(&L, 1);
    list_insert(&L, 3);
    list_print(&L);
    list_delete(&L, 1);
    list_print(&L);

    return 0;
}

void list_print(Element *L){
    Element *x;

    x = L->next;
    while(x != L){
        printf("%d ", x->key);
        x = x->next;
    }
    printf("\n");
}

Element *list_searach(Element *L, int k){
    Element *x;

    x = L->next;
    while(x != L && x->key != k)
        x = x->next;
    return x;
}

void list_insert(Element *L, int k){
    Element *x;

    x = (Element *)malloc(sizeof(Element));
    x->key = k;

    x->next = L->next;
    L->next->prev = x;
    L->next = x;
    x->prev = L;
}

void list_delete(Element *L, int k){
    Element *x;

    x = list_searach(L, k);
    x->prev->next = x->next;
    x->next->prev = x->prev;
    free(x);

}