#include <stdio.h>
int main() {
    int a = 1, b = 2, n1, n2;
    n1 = a++;
    n2 = ++b;
    printf("%d %d\n", n1, a);
    printf("%d %d\n", n2, b);
    return 0;
}

