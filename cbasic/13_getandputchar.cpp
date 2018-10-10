#include <stdio.h>
int main() {
    char c1, c2, c3;
    printf("输入4个字符：");
    c1 = getchar();
    getchar();
    c2 = getchar();
    c3 = getchar();
    printf("输出3个字符：");
    putchar(c1);
    putchar(c2);
    putchar(c3);
    putchar('\n');
    printf("\ngetchar：用于输入单个字符\n");
    printf("\nputchar：用于输出单个字符\n");

    return 0;
}

