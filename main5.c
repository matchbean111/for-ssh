//
// Created by ge on 2023/12/11.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *initQueue() {
    Node *Q = (Node *) malloc(sizeof(Node));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}

void *enQueue(Node *Q, int data) {
    Node *q = Q;
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;

    for (int i = 0; i < Q->data; i++) {
        q = q->next;
    }

    node->next = q->next;
    q->next = node;
    Q->data++;
}

int isEmpty(Node * Q){
    return Q->data == 0 || Q->next == NULL;
}

int deQueue(Node *Q){
    if (isEmpty(Q)){
        return -1;
    }
    Node *node = Q->next;
    int data = node->data;
    Q->next = node->next;
    free(node);
    Q->data--;
    return data;
}


void printQueue(Node *S) {
    Node *node = S->next;
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node * Q = initQueue();
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);
    printQueue(Q);
    printf("%d\n", deQueue(Q));
}
