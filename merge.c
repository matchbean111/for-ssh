//
// Created by ge on 2023/12/31.
//
#include <stdio.h>

void merge(int arr[], int L, int M, int R) {
    int LEFT_SIZE = M - L;
    int RIGHT_SIZE = R - M + 1;
    int left[LEFT_SIZE];
    int right[RIGHT_SIZE];

    int i, j, k;
    for (i = L; i < M; i++) {
        left[i - L] = arr[i];
    }

    for (i = M; i <= R; i++) {
        right[i - M] = arr[i];
    }


    i = 0;
    j = 0;
    k = L;
    while (i < LEFT_SIZE && j < RIGHT_SIZE) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
            k++;
        } else {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < LEFT_SIZE) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < RIGHT_SIZE) {
        arr[k] = right[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int L, int R) {
    if (L == R) {
        return;
    } else {
        int M = (L + R) / 2;
        mergeSort(arr, L, M);
        mergeSort(arr, M + 1, R);
        merge(arr, L, M + 1, R);
    }
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
}

int main() {
    int arr[] = {2, 8, 9, 10, 4, 5, 6, 7};
    int L = 0;
    int R = 7;
//    int M = (L + R) / 2;
//    merge(arr, L, M+1, R);
    mergeSort(arr, L, R);
    printArr(arr, 8);
//    printArr(arr,8);


}