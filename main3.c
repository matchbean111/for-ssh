//
// Created by ge on 2023/12/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define MAXSIZE  100

typedef struct {
    Element     *element;
    int         length;
}SqList;

Status InitList_Sq(SqList *L) {
    L->element = (Element *) malloc(sizeof(Element) * MAXSIZE);
    if (!L->element) exit(OVERFLOW);
    return OK;
}

int main() {
    SqList L;
    InitList_Sq(&L);
    return 0;
}
