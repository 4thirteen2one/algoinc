#include <stdio.h>
int x;
void change() {
    x += 1;
}

int main() {
    x = 10;
    change();
    printf("%d\n", x);
    return 0;
}

