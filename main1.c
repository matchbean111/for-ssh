//
// Created by ge on 2023/12/10.
//

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *initList(){
    Node *L = (Node *)malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
    return L;
}

void headInsert(Node *L, int data){
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    L->next = node;
}

void tailInsert(Node *L, int data){
    Node *n = L;

    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;

    while (n->next != L) {
        n = n->next;
    }
    node->next = L;
    n->next = node;
}

int delete(Node *L, int data){
    Node * pre = L;
    Node * cur = L->next;

    while (cur != L) {
        if (cur->data == data) {
            pre->next = cur->next;
            free(cur);
            return TRUE;
        }

        pre = cur;
        cur = cur->next;
    }

    return FALSE;
}

void printList(Node *L) {
    Node *node = L->next;
    while (node != L)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("NULL\n");

}

int main() {
    Node *L = initList();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    headInsert(L, 6);
    tailInsert(L,0);
    delete(L,6);
    printList(L);
}