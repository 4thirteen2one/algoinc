#include <stdio.h>
#define ADD(a, b) ((a)+(b))
#define CAL(x) (x*2+1)
int main() {
    int num1 = 3, num2 = 5;
    printf("%d\n", ADD(num1, num2));

    int a = 1;
    printf("%d\n", CAL(a+1));
    printf("%d\n", (a+1)*2+1);
    return 0;
}

