#include <cstdio>

int fib0(int n) {
    return ((n<=2)? n-1: fib0(n-2)+fib0(n-1));
}

int fib1(int n) {
    int pre = 0, forw = 1;
    while(n--) {
        forw += pre;
        pre = forw - pre;
    }
    return forw;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%d\n", fib1(n));
    return 0;
}

