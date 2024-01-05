//
// Created by ge on 2024/1/2.
//

#include <stdio.h>

int partition(int arr[], int L, int R) {
    int pivot = R;
    int j = L;
    for (int i = L; i < R; ++i) {
        if (arr[i] < arr[pivot]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    int temp = arr[j];
    arr[j] = arr[R];
    arr[R] = temp;
    return j;
}

void quickSort(int arr[], int L, int R) {
    if (L < R) {
        int M = partition(arr,L,R);
        quickSort(arr,L,M-1);
        quickSort(arr,M+1, R);
    }

}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 8, 1, 2, 5, 4};
    quickSort(arr, 0, 5);
    printArr(arr, 6);
    return 0;
}
