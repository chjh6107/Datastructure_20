#include <stdio.h>
#include <stdlib.h>

#define MAX 8
#define None -1

typedef struct _Linked_List{
    int L;
    int next[MAX];
    int key[MAX];
    int prev[MAX];
}Linked_list;

Linked_list *create_linked_list(void);
void *remove_linked_list(Linked_list *l);
void insert(Linked_list *l, int k);
void delete(Linked_list *l, int k);
void print(Linked_list *l);

int main(void){
    Linked_list *l = create_linked_list();
    int k;

    while(1){
        scanf("%d", &k);
        if(k > 0)
            insert(l, k);
        else if(k < 0)
            delete(l, (-1)*k);
        else
            break;
        print(l);
    }
    remove_linked_list(l);
    return 0;
}

Linked_list *create_linked_list(void){
    Linked_list *tmp;
    int i;

    tmp = (Linked_list *)malloc(sizeof(Linked_list));
    tmp->L = None;

    for(i = 0; i < MAX; i++){
        tmp->next[i] = None;
        tmp->prev[i] = None;
    }
    return tmp;
}

void *remove_linked_list(Linked_list *l){
    free(l);

}

void insert(Linked_list *l, int k){
    int i;
    int tmp_index;
    int tmp_L = None;

    if(l->L == None){
        l->L = 0;
        l->key[l->L] = k;
        l->key[0] = k;
    }
    else{
        for(i = 0; i < MAX; i++){
            if(i != l->L && l->next[i] == None && l->prev[i] == None){
                tmp_L = i;
                break;
            }
        }
        if(tmp_L != None){
            tmp_index = l->L;
            while(l->next[tmp_index] != None)
                tmp_index = l->next[tmp_index];
            l->next[tmp_index] = tmp_L;
            l->key[tmp_L] = k;
            l->prev[tmp_L] = tmp_index;
        }
    }
}

void delete(Linked_list *l, int k){
    int tmp_index;

    tmp_index = l->L;
    while(l->next[tmp_index] != None && l->key[tmp_index] != k)
        tmp_index = l->next[tmp_index];
    if(l->key[tmp_index] == k){
        if(l->prev[tmp_index] != None)
            l->next[l->prev[tmp_index]] = l->next[tmp_index];
        else
            l->L = l->next[tmp_index];

        if(l->next[tmp_index] != None)
            l->prev[l->next[tmp_index]] = l->prev[tmp_index]; // 삭제할 부분의 다음 노드에 이전 노드를 가리키는 부분에 삭제할 노드의 이전 노드를 가리키게 함 
        l->prev[tmp_index] = None;
        l->next[tmp_index] = None;
    }
}

void print(Linked_list *l){
    int tmp_index;

    tmp_index = l->L;
    while(tmp_index != None){
        printf("%d ", l->key[tmp_index]);
        tmp_index = l->next[tmp_index];
    }
    printf("\n");
}