//
// Created by ge on 2023/12/20.
//

#include <stdlib.h>
#include <stdio.h>


#define MAX 32767

typedef struct Graph {
    char *vexs;
    int **arcs;
    int vexNum;
    int arcNum;
} Graph;
