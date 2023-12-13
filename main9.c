//
// Created by ge on 2023/12/12.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    char    data;
    struct BTNode*    lchild;
    struct BTNode*    rchild;
}BTNode, *Tree;

void create_biTree(Tree *T){
    char ch;

    scanf("%c", &ch);
    if (ch == '#'){
        *T = NULL;
    }else {
        *T = (BTNode *) malloc(sizeof(BTNode));
        (*T)->data = ch;
        printf("\n建立左子树\n");
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        create_biTree(&((*T)->lchild));
        printf("\n建立右子树\n");
        create_biTree(&((*T)->rchild));
    }
    return;
}

void destroy_tree(Tree *T){
    if (*T) {
        if ((*T)->lchild) {
            destroy_tree(&((*T)->lchild));
        }
        if ((*T)->rchild) {
            destroy_tree(&((*T)->rchild));
        }
        free(*T);
        *T = NULL;
    }
    printf("\n销毁成功\n");
    return;
}

int main () {
    Tree tree;
    create_biTree(&tree);


}
