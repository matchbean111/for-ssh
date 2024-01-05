//
// Created by ge on 2024/1/2.
//

#include <stdio.h>

int moveZeros(int arr[], int R) {
    int i;
    int j=0;
    for (i = 0; i < R; i++)
    {
        if (arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {0,1,0,3,12};
    moveZeros(arr,5);
    printArr(arr,5);
}