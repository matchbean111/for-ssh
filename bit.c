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

int countOnes2(int a){
    int m_1 = 0x55555555;
    int m_2 = 0x33333333;
    int m_4 = 0x0f0f0f0f;
    int m_8 = 0x00ff00ff;
    int m_16 = 0x0000ffff;


    int b = (a & m_1) + ((a>>1) & m_1);
    int c = (b & m_2) + ((b>>2) & m_2);
    int d = (c & m_4) + ((c>>4) & m_4);
    int e = (d & m_8) + ((d>>8) & m_8);
    int f = (d & m_16) + ((e>>16) & m_16);

    return f;
}

int main() {
    int c = countOnes2(0b010111);
    printf("%d\n",c);

    return 0;
}
