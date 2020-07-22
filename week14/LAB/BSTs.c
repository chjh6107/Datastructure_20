#include <stdio.h>
#include <stdlib.h>

#define NIL NULL

typedef struct Node_{
    int key;                //키값
    struct Node_ *left;     //자식node의 왼쪽
    struct Node_ *right;    //자식node의 오른쪽
    struct Node_ *parent;     //부모node
}Node;

typedef struct Tree_{       //이진트리 자체를 다루는 struct 
    struct Node_ *root;     //전체 노드 참조를 위해 루트를 가지고 있는 트리
}Tree;

void inorder_tree_walk(Node *x);
Node *recursive_tree_search(Node *x, int k);
Node *iterative_tree_search(Node *x, int k);
Node *tree_minimum(Node *x);
Node *tree_maximum(Node *x);
Node *tree_successor(Node *x);
Node *tree_predecessor(Node *x);
void tree_insert(Tree *t, int k);
void tree_delete(Tree *t, int k);
void transplant(Tree *t, Node *u, Node *v);

int main(){
    Tree t;
    int m, k;

    t.root = NULL;
    while(1){
        printf("tree\n");
        inorder_tree_walk(t.root);
        printf("\n");
        printf("select : ");
        scanf("%d", &m);

        if(m == 0 || m == 1 || m == 2){
            printf("number :");
            scanf("%d", &k);
            if(m == 0) tree_insert(&t, k);
            else if(m == 2) tree_delete(&t, k);
            printf("\n");
        }
    }

    return 0;
}

void inorder_tree_walk(Node *x){
    if(x != NULL){
        inorder_tree_walk(x->left);
        printf("%d ", x->key);
        inorder_tree_walk(x->right);

    }
}

Node *recursive_tree_search(Node *x, int k){
    if(x == NULL || k == x->key) return x;
    if(k < x->key) return recursive_tree_search(x->left, k);
    else return recursive_tree_search(x->right, k);
}

Node *iterative_tree_search(Node *x, int k){
    while(x != NULL && k != x->key){
        if(k < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}

Node *tree_minimum(Node *x){
    while(x->left != NULL) x = x->left;
    return x;
}

Node *tree_maximum(Node *x){
    while(x->right != NULL) x = x->right;
    return x;
}

Node *tree_successor(Node *x){
    Node *y;

    if(x->right != NULL) return tree_minimum(x->right);
    y = x->parent;
    while(y != NULL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

Node *tree_predecessor(Node *x){
    Node *y;

    if(x->left != NULL) return tree_maximum(x->left);
    y = x->parent;
    while(y != NULL && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

void tree_insert(Tree *t, int k){
    Node *x = t->root;
    Node *y = NULL;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;

    while(x != NULL){
        y = x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if(y == NULL) t->root = z;
    else if(z->key < y->key) y->left = z;
    else y->right =z;
}

void tree_delete(Tree *t, int k){
    Node *x = t->root;
    Node *y = NULL;
    Node *z;

    z = recursive_tree_search(x, k); //삭제할노드 탐색

    if(z->left == NULL) transplant(t,z,z->right);
    else if(z->right == NULL) transplant(t, z, z->left);
    else{
        y = tree_minimum(z->right);

        if(y->parent != z){
            transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    free(z);
}

void transplant(Tree *t, Node *u, Node *v){
    if(u->parent == NULL) t->root = v;
    else if(u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;

    if(v != NULL) v->parent = u->parent;
}