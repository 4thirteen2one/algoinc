#include <cstdio>

#define ARR1D_LEN(arr) (sizeof(arr))/(sizeof(arr[0]))

void print1dIntarray(int* arr, int arrlen) {
    // 数组名作为函数参数时，传入的其实是数组首元素的地址
    // 一个4字节的常量
    for(int i = 0; i < arrlen; i++) {
        printf("%d", arr[i]);
        if(i < arrlen-1) putchar(' ');
        else putchar('\n');
    }
}

void swapint(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectSort(int* arr, int arrlen, bool direction) {
    for(int i = 0; i < arrlen; i++) {
        int k = i;
        for(int j = i; j < arrlen; j++) {
            if(!direction) {
                if(arr[k] > arr[j]) k = j;
            } else {
                if(arr[k] < arr[j]) k = j;
            }
        }
        swapint((arr+i), (arr+k));
    }
}

int main() {
    int arr[8] = {3, 1, 4, 1, 5, 9, 2, 6};
    int arrlen = ARR1D_LEN(arr);
    print1dIntarray(arr, arrlen);
    printf("                数组长度为：%d\n", arrlen);
    selectSort(arr, arrlen, 0);
    putchar('\n');
    print1dIntarray(arr, arrlen);
    return 0;
}

