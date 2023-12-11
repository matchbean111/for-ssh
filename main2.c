//
// Created by ge on 2023/12/11.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pre;
    struct Node *next;
}Node;

Node * initList() {
    Node *L = (Node *) malloc(sizeof(Node));
    L->data = 0;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

void headInsert(Node *L, int data){

}
