//
// Created by ge on 2024/1/2.
//

#include <stdio.h>
#include <stdlib.h>

int f(int n);

int g(int n);


int main(int argc, char *argv[]) {
//    int n = strtol(argv[1],);
//    int a = f(n);
//
//    printf("%d\n", a);
}

int g(int n) {
    if (n <= 1) return 1;
    return f(n + 1) + g(n - 1);
}

int f(int n) {
    if (n <= 1) return 1;
    return f(n - 1) + g(n - 2);
}