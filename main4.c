//
// Created by ge on 2023/12/11.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node * initStack() {
    Node *S = (Node*) malloc(sizeof(Node));
    S->data = 0;
    S->next = NULL;
    return S;
}

int isEmpty(Node * S) {
    if(S->data == 0 || S->next == NULL){
        return 1;
    }else {
        return  0;
    }
}

int pop(Node *S){
    if (isEmpty(S)){
        return -1;
    }else {
        Node * node = S->next;
        int data = node->data;
        S->next = node->next;
        S->data--;
        free(node);
        return data;
    }
}

void push(Node *S, int data){
    Node *node = (Node*) malloc(sizeof (Node));
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data++;
}

void printStack(Node *S) {
    Node * node = S->next;
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL");
}

int main() {
    Node *S = initStack();
    push(S,1);
    push(S,2);
    push(S,3);
    push(S,4);
    pop(S);
    push(S,6);
    push(S,7);
    pop(S);

    printStack(S);
}
