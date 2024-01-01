//
// Created by ge on 2023/12/19.
//

/**
 * 迪杰斯特拉算法
 */

#include <stdio.h>

int main() {
    int arr[3][3] = {
            1,2,3,
            4,5,6,
            7,8,9
    };

    printf("%X\n",*arr + 3* 2 + 1);
    int a = *(*arr + 3 * 2 + 1);
    printf("%d",a);
}
