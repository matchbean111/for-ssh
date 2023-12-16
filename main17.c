#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    int height;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

int getHeight(TreeNode* node){
    return node ? node->height : 0;
}

int max(int a, int b){
    return a > b ? a : b;
}

void rrRotation(TreeNode* node, TreeNode** root){
    TreeNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;
    *root = temp;
}

void llRotation(TreeNode* node, TreeNode** root){
    TreeNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;
    *root = temp;
}


//void lrRotation(TreeNode* node, TreeNode** root){
//    rrRotation(node->rchild, &(node->rchild));
//    llRotation(node,root);
//}
//
//void rlRotation(TreeNode* node, TreeNode** root){
//    llRotation(node->lchild, &(node->lchild));
//    rrRotation(node,root);
//}


void avlInsert(TreeNode** T, int data){
    if (*T == NULL) {
        *T = (TreeNode*) malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->height = 0;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }else if (data < (*T)->data){
        avlInsert(&(*T)->lchild, data);
        // 调整
        int leftHeight = getHeight((*T)->lchild);
        int rightHeight = getHeight((*T)->rchild);
        // 判断高度差
        if (leftHeight - rightHeight == 2){
            if (data < (*T)->lchild->data){
                // LL
                llRotation(*T, T);
            }else {
                // LR
                rrRotation((*T)->lchild, &(*T)->lchild);
                llRotation(*T,T);
            }
        }

    }else if (data > (*T)->data){
        avlInsert(&(*T)->rchild,data);
        int leftHeight = getHeight((*T)->lchild);
        int rightHeight = getHeight((*T)->rchild);
        // 判断高度差
        if (rightHeight - leftHeight == 2){
            if (data > (*T)->rchild->data){
                // RR
                rrRotation(*T,T);
            }else {
                // RL
                llRotation((*T)->rchild, &(*T)->rchild);
                rrRotation(*T,T);
            }
        }

    }
    (*T)->height = max(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;
}

void inOrder(TreeNode *T){
    if (T) {
        printf("%d ",T->data);
        inOrder(T->lchild);
        inOrder(T->rchild);
    }
}

int main() {
    TreeNode *T = NULL;
    int nums[5] = {1,8,6,7,10};
    for (int i = 0; i < 5; ++i){
        avlInsert(&T, nums[i]);
    }
    inOrder(T);
}








