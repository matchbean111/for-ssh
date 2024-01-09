//
// Created by ge on 2024/1/9.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int Chinese;
    int Math;
    int English;
} Student;

Student students[7];

void readData() {
    FILE *file = fopen("D:\\p\\c\\for-ssh\\mark.txt", "r");
    if (file != NULL) {
        int i;
        for (i = 0; i < 7; i++) {
            fscanf(file, "%s", students[i].name);
            fscanf(file, "%d", &students[i].Chinese);
            fscanf(file, "%d", &students[i].Math);
            fscanf(file, "%d", &students[i].English);
        }
    }


    fclose(file);
}

void displayData() {
    int i;
    for (i = 0; i < 7; i++) {
        printf("%s    ", students[i].name);
        printf("%d    ", students[i].Chinese);
        printf("%d    ", students[i].Math);
        printf("%d    ", students[i].English);
        printf("%d    ", students[i].English + students[i].Chinese + students[i].Math);
        printf("\n");
    }

}

int compare(const void *a, const void *b) {
    Student *pa = (Student *) a;
    Student *pb = (Student *) b;
    int num1 = pa->Math + pa->Chinese + pa->English;
    int num2 = pb->Math + pb->Chinese + pb->English;

    return num1 - num2;
}

int compare2(const void *key, const void *e) {
    int *pNum1 = (int *) key;
    Student *pS = (Student *) e;


    int num1 = *pNum1;
    printf("%d   ",num1);
    int num2 = pS->Math + pS->Chinese + pS->English;
    printf("%d\n",num2);
    return num1 - num2;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    readData();
    qsort(students, 7, sizeof(Student), compare);
    displayData();

    int key = 225;

    Student *r = (Student *) bsearch(&key, students, 7,
                                     sizeof(Student), compare2);
    printf("%s\n", r->name);

    return 0;
}