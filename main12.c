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
    int flag; // 0 初始状态
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
        (*T)->flag = 0;
        createTree(&((*T)->lchild), data, index);
        createTree(&((*T)->rchild), data, index);
    }
}

StackNode *initStack() {
    StackNode *S = (StackNode*) malloc(sizeof(StackNode));
    S->data = NULL;
    S->next = NULL;
    return S;
}

void destroyTree(TreeNode *T ){
    if (T == NULL) {
        return;
    }
    destroyTree(T->lchild);
    destroyTree(T->rchild);
    free(T);
}

void push(TreeNode* data, StackNode* S){
    StackNode *node = (StackNode*) malloc(sizeof(StackNode));
    node->data = data;
    node->next = S->next;
    S->next = node;
}

int isEmpty(StackNode * S){
    if (S->next == NULL)
    {
        return 1;
    } else{
        return 0;
    }
}

StackNode * pop(StackNode* S){
    if (isEmpty(S)){
        return NULL;
    }else {
        StackNode  * node = S->next;
        S->next = node->next;
        return node;
    }
}

StackNode * getPop(StackNode* S){
    if (isEmpty(S)){
        return NULL;
    }else {
        StackNode  * node = S->next;
        return node;
    }
}

void postTraverse(TreeNode *T){
    TreeNode *node = T;
    StackNode *S = initStack();
    while (node || !isEmpty(S)){
        if (node) {
            push(node, S);
            node = node->lchild;
        }else {
            TreeNode *top = getPop(S)->data;
            if (top->rchild && top->rchild->flag == 0){
                top = top->rchild;
                push(top,S);
                node = top->lchild;
            }else {
                top = pop(S)->data;
                printf("%c ",top->data);
                top->flag = 1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    TreeNode *T;
    int index = 0;
    createTree(&T,argv[1],&index);
    postTraverse(T);


    return 0;
}





