//
// Created by ge on 2024/1/1.
//

#include <stdio.h>

int countOnes1(int num){
    int c = 0;
    while (num > 0) {
        if (num & 1) {
            c++;
        }
        num = num >> 1;
    }
    return c;
}

int countOnes2(int num){
    int c = 0;
    while (num > 0) {
        if (num & 1) {
            c++;
        }
        num = num >> 1;
    }
    return c;
}

int main() {
    int c = countOnes1(8);
    printf("%d\n",c);

    return 0;
}
