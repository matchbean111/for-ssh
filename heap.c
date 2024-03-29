//
// Created by ge on 2023/12/31.
//

#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int tree[], int n, int i) {
    if (i >= n) {
        return;
    }
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;
    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }

    if (max != i) {
        swap(tree,max,i);
        heapify(tree, n,max);
    }
}

void build_heap(int tree[], int n){
    int last_node = n-1;
    int parent = (last_node-1)/2;
    for (int i = parent; i >= 0; i--) {
        heapify(tree,n,i);
    }
}

void heap_sort(int tree[], int n){
    build_heap(tree,n);
    int i;
    for(i=n-1;i>=0;i--){
        swap(tree,i,0);
        heapify(tree,i,0);
    }
}


void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6,5,1,2,3,8,9,4,7};
    int tree[] = {4,3,5,1,10,2};

    build_heap(arr,9);
    printArr(arr, 9);

    build_heap(tree,6);
    printArr(tree, 6);

    heap_sort(tree, 6);
    printArr(tree,6);

    return 0;
}
