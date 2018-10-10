#include <cstdio>
#include <algorithm>

using namespace std;

struct Mooncake {
    double reserve;
    double totalprice;
    double price;
} instock[1010];

bool cmp(Mooncake a, Mooncake b) {
    return a.price > b.price;
}

int main() {
    int n;
    double D;
    scanf("%d%lf", &n, &D);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &instock[i].reserve);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lf", &instock[i].totalprice);
        instock[i].price = instock[i].totalprice / instock[i].reserve;
    }
    sort(instock, instock+n, cmp);
    double ans = 0;
    for(int i = 0; i < n; i++) {
        if(instock[i].reserve <= D) {
            D -= instock[i].reserve;
            ans += instock[i].totalprice;
        } else {
            ans += instock[i].price *D;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}

