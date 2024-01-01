//
// Created by ge on 2023/12/31.
//
#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int n) {
    int key = arr[n];
    int i = n;
    while (arr[i-1] > key){
        arr[i] = arr[i-1];
        i--;
        if (i == 0) {
            break;
        }
    }
    arr[i] = key;
}

void insertionSort(int  arr[], int n){
    int i;
    for (i = 1; i < n; i++) {
        insert(arr,i);
    }
}
void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        printf("%d\t",arr[i]);
    }
}


int main() {
    int arr[] = {6,5,1,2,3,8,9,4,7};
    insertionSort(arr,9);
    printArr(arr,9);

    return 0;
}