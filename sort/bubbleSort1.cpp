#include <cstdio>

void print1dIntarray(int* arr, int arrlen) {
    for(int i = 0; i < arrlen; i++) {
        printf("%d", arr[i]);
        if(i < arrlen-1) putchar(' ');
        else putchar('\n');
    }
}

void swapint(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort1(int A[], int n) {
    for(bool sorted = false; !sorted; n--) {
        sorted = true;
        for(int i = 1; i < n; i++)
            if(A[i-1] > A[i]) {
                swapint(A+i-1, A+i);
                sorted = false;
            }
    }
}

int main() {
    int A[10];
    int n = sizeof(A)/sizeof(A[0]);
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    print1dIntarray(A, n);
    bubbleSort1(A, n);
    print1dIntarray(A, n);
    return 0;
}

