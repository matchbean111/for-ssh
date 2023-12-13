//
// Created by ge on 2023/12/13.
//

#include <stdlib.h>
#include <stdio.h>

// 后序 非递归

typedef struct TreeNode {
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int ltag;
    int rtag;
}TreeNode;

typedef struct StackNode {
    TreeNode *data;
    struct StackNode *next;
}StackNode;

void createTree(TreeNode** T, char * data, int *index){
    char  ch;
    ch = data[*index];
    *index +=1;
    if (ch == '#') {
        *T = NULL;
    }else {
        *T = (TreeNode *) malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->rtag = ch;
        (*T)->ltag = ch;
        createTree(&((*T)->lchild), data, index);
        createTree(&((*T)->rchild), data, index);
    }
}

void inThreadTree(TreeNode* T, TreeNode** pre){
    if (T) {
        inThreadTree(T->lchild, pre);
        // do something
        if (T->lchild == NULL){
            T->ltag = 1;
            T->lchild = *pre;
        }
        if (*pre != NULL && (*pre)->rchild == NULL){
            (*pre)->rtag = 1;
            (*pre)->rchild = T;
        }
        *pre = T;
        inThreadTree(T->rchild,pre);
    }
}

TreeNode *getFirst(TreeNode *T){
    while (T->ltag == 0){
        T = T->lchild;
    }
    return T;
}

TreeNode *getNext(TreeNode *T){
    if (T->rtag == 1){
        return T->rchild;
    }else {
        return getFirst(T->rchild);
    }
}

StackNode *initStack() {
    StackNode *S = (StackNode*) malloc(sizeof(StackNode));
    S->data = NULL;
    S->next = NULL;
    return S;
}



int main(int argc, char* argv[]) {
    TreeNode *T;
    TreeNode *pre = NULL;
    int index = 0;
    createTree(&T,argv[1],&index);
    inThreadTree(T,&pre);
    pre->rtag = 1;
    pre->rchild = NULL;

    return 0;
}
