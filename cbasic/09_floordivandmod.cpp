#include <stdio.h>
int main() {
    int a =3, b = 4, c = 5, d = 6;
    printf("6 / 3 = %d\n", d/a);
    printf("5 / 3 = %d\n", c/a);
    printf("3 / 3 = %d\n", a/a);
    // 取模运算符的优先级和除法运算符相同
    printf("6 % 3 = %d\n", d%a);
    printf("5 % 3 = %d\n", c%a);
    printf("3 % 3 = %d\n", a%a);
    printf("3 % 5 = %d\n", a%c);
    return 0;
}

