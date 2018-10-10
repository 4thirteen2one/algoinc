#include <stdio.h>
int x;
void change(int x) {
    x += 1;
}

int main() {
    x = 10;
    change(x);
    printf("%d\n", x);
    return 0;
}

