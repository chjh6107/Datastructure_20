#include <stdio.h>

typedef struct Node_{
    int key;
    struct Node_ *left;
    struct Node_ *right;
    struct Node_ *parent;
}Node;

int counter = 0;
int probe_edge(Node *x);

int distance_bst(Node *x){
    probe_edge(x);
    return counter;
}

int probe_edge(Node *x){
    if(x != NULL){
        if(x->left != NULL && x->key < x->left->key) counter++;
        if(x->right != NULL && x->key > x->right->key) counter++;   

        probe_edge(x->left);
        probe_edge(x->right);
    }
}
