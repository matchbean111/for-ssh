//
// Created by ge on 2023/12/10.
//

#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *initList(){
    Node * list = (Node *) malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}

void headInsert(Node *list, int data) {
    Node * node = (Node *) malloc(sizeof(Node));

    node->data = data;
    node->next = list->next;
    list->next = node;
    list->data++;
}

void tailInsert(Node *list, int data) {
    Node *head = list;
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    list = list->next;
    while (list->next)
    {
        list = list->next;
    }
    list->next = node;
    head->data++;
}

void delete(Node *list, int data){

    Node *pre = list;
    Node *cur = list->next;
    list = list->next;
    while (cur)
    {
        if (list->data == data){
            pre->next = cur->next;
            cur->next = NULL;
            free(cur);
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    list->data--;
}

void printList(Node *list) {
    list = list->next;
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");

}

int main() {
    printf("Hello world\n");
    Node *list = initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);
    headInsert(list, 6);
    headInsert(list, 8);
    tailInsert(list, 10);
    delete(list,6);
    printList(list);
    return 0;
}

#pragma clang diagnostic pop