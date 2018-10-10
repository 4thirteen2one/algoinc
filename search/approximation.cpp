#include <cstdio>

const double eps = 1e-5;

double f(double x) {
    return x*x;
}

double solve(double L, double R) {
    double left = L, right = R, mid;
    while(right - left > eps) {
        mid = left + (right-left)/2;
        if(f(mid) - 2 > 0)
            right = mid;
        else
            left = mid;
    }
    return mid;
}

int main() {
    printf("\\sqrt{2} = %f\n", solve(1, 2));
    return 0;
}
