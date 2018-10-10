#include <stdio.h>
#include "mylib.h"
int main() {
    printf("指针是一个4字节长的unsigned整数\n\n");
    int a = 233;
    int* p;
    p = &a;
    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    printf("*p = %d\n", *p);
    printf("“int*”一般写作“int *”，表示指针指向的变量为整型\n");
    printf("“int* p = &a;”表示：整型变量a的地址&a被赋值给指向整型变量的指针p\n");
    printf("“int *p1, p2;”表示：p1是int*型的，而p2是int型的\n"); 
    printf("“int *p1, *p2;”表示：p1是int*型的，p2也是*int型的\n"); 
    printf("直接对*p赋值，等于对a赋值：");
    *p = 666;
    printf("%d\n", a);

    putchar('\n');
    printf("\"arr + i = &arr[i]\"\n");
    printf("“p+1”表示p所指int型变量的下一个int型变量（4byte）的地址\n");
    printf("指针变量支持自增和自减操作\n");

    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int* pa = arr;
    int arrlen = ARR1D_LEN(arr);
    print1dIntarray(arr, arrlen);
    printf("  *pa   = %d,   pa   = %p\n", *pa, pa);
    printf("*(pa+1) = %d, (pa+1) = %p\n", *(pa+1), pa+1);
    printf("Input new value for arr[1]: ");
    scanf("%d", arr+1);
    for(int* i = arr; i-arr < 10; i++) {
        printf("%d", *i);
        if(i-arr != 9) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }

    return 0;
}

