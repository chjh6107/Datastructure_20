//next, key, prev : 연결리스트를 구현하는 3개의 배열
//n : 위 3개 배열의 크기
//L, free: 연결리스트와 free리스트의 시작 인덱스(0based)
//k : 삽입하는 경우의 key값
//NIL은 -1로 표현

#define NIL -1

void insert_node_head(int *next, int *key, int *prev, int n, int *L, int *free, int k){
    int i;
    int tmp_index;
    int tmp_L = NIL;
    
    if(prev == NIL){
        L = free;
        key[L] = k;
        prev[L] = NIL;
        free = next[free];
        next[L] = NIL;
    }else{
        tmp_L = free;
        tmp_index = L;
        while(next[tmp_index] != NIL)
            tmp_index = next[tmp_index];
        next[tmp_index] = tmp_L;
        key[tmp_L] = k;
        prev[tmp_L] = tmp_index;
        free = next[free];
        next[tmp_L] = NIL;
    }
}

void delete_node_head(int *next, int *key, int *prev, int n, int *L, int *free){
    // int tmp_index;

    // tmp_index = L;

    // if(L != NIL){
    //     while(next[tmp_index] != NIL && key[tmp_index] != k)
    //         tmp_index = next[tmp_index];
    //     if(key[tmp_index] == k){
    //         if(prev[tmp_index] != NIL)
    //             next[prev[tmp_index]] = next[tmp_index];
    //         else
    //             L = next[tmp_index];
    //         if(next[tmp_index] != NIL)
    //             prev[next[tmp_index]] = prev[tmp_index];
    //         prev[tmp_index] = NIL;
    //         next[tmp_index] = free;
    //         free = tmp_index;
    //     }
    // }
}

void insert_node_tail(int *next, int *key, int *prev, int n, int *L, int *free, int k){
    int i;
    int tmp_index;
    int tmp_L = NIL;
    
    if(prev == NIL){
        L = free;
        key[L] = k;
        prev[L] = NIL;
        free = next[free];
        next[L] = NIL;
    }else{
        tmp_L = free;
        tmp_index = L;
        while(next[tmp_index] != NIL)
            tmp_index = next[tmp_index];
        next[tmp_index] = tmp_L;
        key[tmp_L] = k;
        prev[tmp_L] = tmp_index;
        free = next[free];
        next[tmp_L] = NIL;
    }
}

void delete_node_tail(int *next, int*key, int *prev, int n, int *L, int *free){
    // int tmp_index;

    // tmp_index = L;

    // if(L != NIL){
    //     while(next[tmp_index] != NIL && key[tmp_index] != k)
    //         tmp_index = next[tmp_index];
    //     if(key[tmp_index] == k){
    //         if(prev[tmp_index] != NIL)
    //             next[prev[tmp_index]] = next[tmp_index];
    //         else
    //             L = next[tmp_index];
    //         if(next[tmp_index] != NIL)
    //             prev[next[tmp_index]] = prev[tmp_index];
    //         prev[tmp_index] = NIL;
    //         next[tmp_index] = free;
    //         free = tmp_index;
    //     }
    // }
}