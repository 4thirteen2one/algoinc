#include <stdio.h>
#include <string.h>
#include "mylib.h"
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int alen = ARR1D_LEN(a);
    print1dIntarray(a, alen);
    printf("\nvoid *(memset)(void *s, int c, size_t n) {\n    const unsigned char uc = c;\n    unsigned char *su;\n    for(su = s; o < n; ++su, --n)\n        *su = uc;\n    return (s);\n}");
    printf("\n作用：在给定长度内存块中填充某给定值，进行快速清零\n\n");
    memset(a, 0, sizeof(a));
    print1dIntarray(a, alen);
    memset(a, -1, sizeof(a));
    print1dIntarray(a, alen);
    memset(a, 1, sizeof(a));
    print1dIntarray(a, alen);

    printf("\n");
}

