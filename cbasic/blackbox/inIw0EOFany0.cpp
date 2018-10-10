#include <stdio.h>
int main()
{
    int a, b;
    printf("Input 2 int numbers: \n");
    while(scanf("%d%d", &a, &b) != EOF) {
        if(a == 0 && b == 0) break;
        printf("Here you got: %d\n", a+b);
    }
    /*
    while(scanf("%d%d", &a, &b), a || b) {
    }
    */
    return 0;
}

