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
        if (*pre != NULL && )
        inThreadTree(T->rchild,pre);
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
    int index = 0;
    createTree(&T,argv[1],&index);



    return 0;
}
