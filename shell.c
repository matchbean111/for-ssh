//
// Created by ge on 2023/12/31.
//

#include <stdio.h>


void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        printf("%d\t",arr[i]);
    }
}

void shellSort(int arr[9], int i) {

}

int main() {
    int arr[] = {6,5,1,2,3,8,9,4,7};
    shellSort(arr,9);
    printArr(arr,9);
}
