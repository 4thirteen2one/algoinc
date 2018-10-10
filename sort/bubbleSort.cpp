#include <stdio.h>
#include "mylib.h"

void swapint(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int arrlen, int direction) {
    for(int i = 0; i < arrlen-1;  i++) {
        printf("                ");
        printf("第%d趟，还有%d趟\n", i+1, arrlen-i-2);
        for(int j = 0; j < arrlen-1-i; j++) {
            printf("第%d次，还有%d次 ", j+1, arrlen-i-j-2);
            if(!direction) {
                if(*(arr+j) > *(arr+j+1)) {
                    swapint((arr+j), (arr+j+1));
                }
            } else {
                if(*(arr+j) < *(arr+j+1)) {
                    swapint((arr+j), (arr+j+1));
                }
            }
            print1dIntarray(arr, arrlen);
        }
    }
}

int main() {
    int arr[8] = {3, 1, 4, 1, 5, 9, 2, 6};
    int arrlen = ARR1D_LEN(arr);
    print1dIntarray(arr, arrlen);
    printf("                数组长度为：%d\n", arrlen);
    bubbleSort(arr, arrlen, 0);
    putchar('\n');
    print1dIntarray(arr, arrlen);
    return 0;
}

