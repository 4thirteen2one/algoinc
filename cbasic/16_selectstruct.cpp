#include <stdio.h>
int main() {
    int n = 0, m = 5;
    printf("if(n != 0) 等效于 if(n)\n");
    if(!n) {
        if(m < 5) {
            printf("%d is less than 5\n", m);
        } else if(m > 5) {
            printf("%d is greater tan 5\n", m);
        } else {
            printf("%d equals to 5\n", m);
        }
    }

    n += 1;
    printf("if(n == 0) 等效于 if(!n)\n");
    if(n) {
        printf("%d does not equal to zero\n", n);
    } else {
        printf("%d equals to zero\n", n);
    }

    switch(n + m) {
        case 6:
            printf("\nIf you don't add \"break;\" below the sentences in each case,\n");
        case 5:
            printf("it will keep run the sentences following\n");
            printf("until\n");
        case 4:
            printf("...\n");
        default:
            printf("meeting the default case.\n");
    }

    return 0;
}
