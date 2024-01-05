//
// Created by ge on 2023/12/31.
//

#include <stdio.h>

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


void shellSort(int arr[], int n, int gap) {
    for (int i = 0; i < n; i++) {
        for (int j = i + gap; j < n; j += gap) {
            for (int k = i; k < j; k += gap) {
                if (arr[j] < arr[k]) {
                    int temp = arr[j];
                    for (int l = j - gap; l >= k; l -= gap) {
                        arr[l + gap] = arr[l];
                    }
                    arr[k] = temp;
                }
            }
        }
    }
}

/**
 *
 * @param arr
 */
void shellSort1(int arr[], int n) {
    /**
     * 伪代码如下
     * # Sort an array a[0...n-1].
        gaps = [701, 301, 132, 57, 23, 10, 4, 1]  # Ciura gap sequence

        # Start with the largest gap and work down to a gap of 1
        # similar to insertion sort but instead of 1, gap is being used in each step
        foreach (gap in gaps)
        {
            # Do a gapped insertion sort for every elements in gaps
            # Each loop leaves a[0..gap-1] in gapped order
            for (i = gap; i < n; i += 1)
            {
                # save a[i] in temp and make a hole at position i
                temp = a[i]
                # shift earlier gap-sorted elements up until the correct location for a[i] is found
                for (j = i; (j >= gap) && (a[j - gap] > temp); j -= gap)
                {
                    a[j] = a[j - gap]
                }
                # put temp (the original a[i]) in its correct location
                a[j] = temp
            }
        }
     */

    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    int gaps_len = 8;
    for (int i = 0; i < gaps_len; ++i){
        for (int j = gaps[i]; j < n; j += 1) {
            int temp = arr[j];
            int k;
            for (k = j; (k >= gaps[i]) && (arr[k - gaps[i]] > temp); k -= gaps[i]) {
                arr[k] = arr[k-gaps[i]];
            }
            arr[k] = temp;
        }
    }
}

int main() {
    int arr[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    int gaps[] = {5, 3, 1};
//    for (int i = 0; i < 3; ++i) {
//        shellSort1(arr, 10, gaps[i]);
//        printArr(arr, 9);
//    }
    shellSort1(arr, 10);
    printArr(arr, 10);
}
