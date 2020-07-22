#include <stdio.h>
#include <stdlib.h>


void insert_node_head(int *next, int *key, int *prev, int n, int *L, int *free, int k) {
        int idx = *free;
        *free = next[*free];

        key[idx] = k;
        next[idx] = *L;
        prev[idx] = -1;
        if ( *L != -1 ) prev[*L] = idx;
        *L = idx;
}
void insert_node_tail(int *next, int *key, int *prev, int n, int *L, int *free, int k) {
        int idx = *free;
        *free = next[*free];
        key[idx] = k;
        next[idx] = -1;

        int tmp = *L;
        if ( *L != -1 ) {
                while( next[tmp] != -1 ) tmp = next[tmp];
                next[tmp] = idx;
        }
        else *L = idx;

        prev[idx] = tmp;
}

void delete_node_head(int *next, int *key, int *prev, int n, int *L, int *free) {
        int idx;
        if ( *L != -1 ) {
                idx = *L;

                *L = next[idx];
                if ( *L != -1 ) prev[*L] = -1;

                next[idx] = *free;
                *free = idx;
        }
}

void delete_node_tail(int *next, int *key, int *prev, int n, int *L, int *free) {
        int cur = *L, prv = -1;

        if ( *L != -1 ) {
                while( next[cur] != -1 ) {
                        prv = cur;
                        cur = next[cur];
                }
                if ( prv != -1 ) {
                        next[prv] = -1;
                } else
                        *L = -1;

                next[cur] = *free;
                *free = cur;
        }
}
