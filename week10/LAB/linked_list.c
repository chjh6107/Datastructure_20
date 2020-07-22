#include <stdio.h>
#include <stdlib.h>

typedef struct _Element{
    int key;
    struct _Element *prev;
    struct _Element *next;
}Element;

typedef struct _Linked_List{
    Element *head;
}Linked_List;

void list_print(Linked_List *L);
Element *list_searach(Linked_List *L, int k);
void list_insert(Linked_List *L, int k);
void list_delete(Linked_List *L, int k);

int main(void){
    Linked_List L;

    L.head = NULL;

    list_insert(&L, 5);
    list_insert(&L, 1);
    list_insert(&L, 3);
    list_print(&L);
    list_delete(&L, 1);
    list_print(&L);

    return 0;
}

void list_print(Linked_List *L){
    Element *x;

    x = L->head;
    while(x != NULL){
        printf("%d ", x->key);
        x = x->next;
    }
    printf("\n");
}

Element *list_searach(Linked_List *L, int k){
    Element *x;

    x = L->head;
    while(x != NULL && x->key != k)
        x = x->next;
    return x;
}

void list_insert(Linked_List *L, int k){
    Element *x;

    x = (Element *)malloc(sizeof(Element));
    x->key = k;

    x->next = L->head;
    if(L->head != NULL)
        L->head->prev = x;
    L->head = x;
    x->prev = NULL;
}

void list_delete(Linked_List *L, int k){
    Element *x;

    x = list_searach(L, k);
    if(x != NULL){
        if(x->prev != NULL)
            x->prev->next = x->next;
        else
            L->head = x->next;
        if(x->next != NULL)
            x->next->prev = x->prev;
        free(x);
    }
}