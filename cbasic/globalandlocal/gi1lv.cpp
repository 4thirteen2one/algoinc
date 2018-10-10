#include <stdio.h>
int x = 10;
void change(int x) {
    x += 1;
}

int main() {
    change(x);
    printf("%d\n", x);
    return 0;
}

