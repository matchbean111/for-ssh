//
// Created by ge on 2023/12/31.
//
#include <stdio.h>

int findMaxPos(int arr[], int n){
    int max = arr[0];
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}

void selectionSort(int arr[], int n){
    while (n>1) {


        int pos = findMaxPos(arr, n);
        int temp = arr[pos];
        arr[pos] = arr[n - 1];
        arr[n - 1] = temp;
        n--;
    }
}

void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        printf("%d\t",arr[i]);
    }
}

int main() {
    int arr[] = {6,5,1,2,3,8,9,4,7};
    selectionSort(arr,9);
    printArr(arr,9);
}
