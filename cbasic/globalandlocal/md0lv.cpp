#include <stdio.h>
void change(void);

int main() {
    int x = 10;
    change();
    printf("%d\n", x);
    return 0;
}

void change() {
    x += 1;
}
