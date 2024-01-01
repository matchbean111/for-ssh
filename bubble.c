//
// Created by ge on 2023/12/31.
//

#include <stdio.h>

void bubble(int arr[], int n){
    int i;
    int temp;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

void bubbleSort(int arr[], int n){
    int i;
    for (i = n; i >= 1; i--) {
        bubble(arr,i);
    }

}

void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        printf("%d\n",arr[i]);
    }
}


int main() {
    int arr[] = {6,5,1,2,3,8,9,4,7};
    bubbleSort(arr,9);
    printArr(arr,9);
}
