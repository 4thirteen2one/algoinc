#include <cstdio>

void show_n_char(int n, char c) {
    for(int i = 0; i < n; i++) {
        putchar(c);
    }
}

int main() {
    int N, rowC;
    char C;
    while(scanf("%d %c", &N, &C) != EOF && (3<=N && N<=20)) {
        rowC = (N%2)? N/2+1: N/2;

        show_n_char(N, C);
        putchar('\n');

        for(int i = 2; i < rowC; i++) {
            putchar(C);
            show_n_char(N-2, ' ');
            putchar(C);
            putchar('\n');
        }
        
        show_n_char(N,C);
        putchar('\n');
    }
    return 0;
}

