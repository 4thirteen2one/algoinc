#include <stdio.h>
#include "mylib.h"

void array1d(void){
    int a[10];
    int alen = ARR1D_LEN(a);
    print1dIntarray(a, alen);
    printf("未初始化，数组元素中都是垃圾值\n");

    int b[10] = {5, 3, 2, 6, 8, 4};
    int blen = ARR1D_LEN(b);
    print1dIntarray(b, blen);
    printf("当初始化元素个数小于数组声明时的元素个数时，剩余元素都初始化为0\n");

    int c[10] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    int clen = ARR1D_LEN(c);
    print1dIntarray(c, clen);
    printf("C99新特性：初始化指定元素，跟随初始化，覆盖初始化\n");

    int d[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int dlen = ARR1D_LEN(d);
    print1dIntarray(d, dlen);
    printf("初始化时省略方括号中数字时，编译器会根据初始化列表中的元素个数确定数组大小\n");

    printf("\nC不允许把数组作为一个单元赋给另一数组，除初始化以外不允许使用花括号列表形式的整体赋值\n");
    printf("声明数组后，可借助数组索引给数组元素赋值\n");

    int elen = 10;
    int e[elen];
    print1dIntarray(e, elen);
    printf("C99标准开始支持变长数组（variable-length array, VLA）\n");
    printf("声明VLA时不能进行初始化\n");
    printf("编译时加上参数 -std=c99\n");
    
    double f[10];

    char g[10];

    bool h[10];
}

void array2d(void) {
    int i, j;
    int ba[5][6] = {
        {3, 1, 2},
        {8, 4},
        {},
        {1, 2, 3, 4, 5, 6}
    };
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 6; j++) {
            printf("%d", ba[i][j]);
        }
        putchar('\n');
    }

    printf("Input 2 3*3 matrix: \n");
    int ba1[3][3], ba2[3][3], ba3[3][3];
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &ba1[i][j]);
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &ba2[i][j]);
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            ba3[i][j] = ba1[i][j] + ba2[i][j];
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%2d", ba3[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    array1d();
    array2d();

    return 0;
}

