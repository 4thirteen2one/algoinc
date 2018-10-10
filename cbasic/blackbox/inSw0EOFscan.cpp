#include <stdio.h>

int main()
{
    char str[100];
    printf("Input a string(length less than 100): \n");
    while(scanf("%s", str) != EOF) {
        printf("Here you got: %s\n", str);
    }
    return 0;
}

