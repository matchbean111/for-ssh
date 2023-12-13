//
// Created by ge on 2023/12/13.
//
#include <stdio.h>
#include <stdlib.h>

/*
 *      AVL
 */


typedef struct TreeNode {
    int data;
    int h;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

int getH(TreeNode *node) {
    return node ? node->h : 0;
}

void rrRotation(TreeNode *node, TreeNode* root){
    TreeNode *temp = node->rchild;
    node->rchild = temp->lchild;
}

void avlInsert(TreeNode **T, int data) {
    if (*T == NULL) {
        *T = (TreeNode *) malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->h = 0;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    } else if (data < (*T)->data) {
        avlInsert(&(*T)->lchild, data);
        int lH = getH((*T)->lchild);
        int rH = getH((*T)->rchild);
        if (data < (*T)->lchild->data){
            // LL

        } else {
            // LR
        }
    } else {
        avlInsert(&(*T)->rchild, data);
        avlInsert(&(*T)->lchild, data);
        int lH = getH((*T)->lchild);
        int rH = getH((*T)->rchild);
        if (data > (*T)->lchild->data){
            // RR

        } else {
            // RL
        }
    }
}

void preOrder(TreeNode *T) {
    if (T) {

        preOrder(T->lchild);
        printf("%d ", T->data);
        preOrder(T->rchild);
    }

}

int main() {
    TreeNode *T = NULL;
    int nums[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i) {
        avlInsert(&T, nums[i]);
    }

    preOrder(T);
}








