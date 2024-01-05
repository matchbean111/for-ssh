//
// Created by ge on 2024/1/1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int             data;
    struct node*    next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
}LinkedList;

LinkedList *createList(){
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertData(LinkedList* list, int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else{
        list->tail->next = node;
        list->tail = node;
    }
}

void printList(LinkedList* list){
    Node *p = list->head;
    while (p != NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    LinkedList *list = createList();
    insertData(list,11);
    insertData(list,12);
    insertData(list,13);
    insertData(list,15);
    insertData(list,14);
    printList(list);
}