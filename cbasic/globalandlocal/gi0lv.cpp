#include <stdio.h>
int x = 10;
void change() {
    x += 1;
}

int main() {
    change();
    printf("%d\n", x);
    return 0;
}

