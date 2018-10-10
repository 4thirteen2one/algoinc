#include <cstdio>

const int maxn = 1001;

int main() {
    double A[2][maxn] = {{0.0}};
    for(int j = 0; j < 2; j++){
        int k, i;
        double coef;
        scanf("%d", &k);
        while(k--) {
            scanf("%d %lf", &i, &coef);
            A[j][i] += coef;
            //奇怪的是，如果我写成
            //scanf("%d %lf", &i, &A[j][i];
            //它上面声明数组A的时候，列数为2时刚输入第一个多项式就报段错误
            //而且后面计算出来的结果也是错误的，直接从0下标开始往后填
        }
    }

    int n = 0;
    double S[maxn] = {0.0};
    for(int i = 0; i < maxn; i++) {
        S[i] = A[0][i] + A[1][i];
        if(S[i] != 0.0)
            n++;
    }
    printf("%d", n);
    for(int i = maxn-1; i >= 0; i--)
        if(S[i] != 0.0) {
            printf(" %d %.1lf", i, S[i]);
        }
    return 0;
}
