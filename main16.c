//
// Created by ge on 2023/12/13.
//
#include <stdlib.h>
#include <stdio.h>

// 二叉排序树  无重复值

typedef struct TreeNode{
    int data;
    struct TreeNode*    lchild;
    struct TreeNode*    rchild;
}TreeNode;

TreeNode *bstSearch(TreeNode *T, int key){
    if (T) {
        if (T->data == key){
            return T;
        } else if (T->data > key){
            return bstSearch(T->lchild, key);
        } else{
            return bstSearch(T->rchild, key);
        }
    }else {
        return NULL;
    }
}

void bstInsert(TreeNode** T, int key){
    if (*T == NULL) {
        *T = (TreeNode *) malloc(sizeof(TreeNode));
        (*T)->data = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }else if ((*T)->data == key) {
        return;
    }else if ((*T)->data > key) {
        bstInsert(&(*T)->lchild, key);
    } else {
        bstInsert(&((*T)->rchild),key);
    }
}

void preOrder(TreeNode* T ){
    if (T){
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }

}

int main (){
    TreeNode *T = NULL;

    int nums[6] = {8,6,10,9,11,23};
    for (int i = 0; i < 6; i++) {
        bstInsert(&T, nums[i]);
    }

    preOrder(T);
    printf("\n");
}