#include <cstdio>
//#include "mylib.h"
#include <cmath>
#include <cstring>

int nbase2dec(int base, char* coes) {
    if(1<base && base<=16){
        int coe, res = 0;
        int len = strlen(coes);      //need "string.h"
        for(int i = len-1; i >= 0; i--) {   //从最低位算起
            if('0'<=coes[i] && coes[i]<='9')
                coe = coes[i]-'0';
            else if('A'<=coes[i] && coes[i]<='F')
                coe = coes[i]-'A' + 10;
            else {
                printf("Number illegal!\n");
                return -1;
            }
            if(coe < base)
                res += coe * pow(base, len-1-i);//need "math.h"
            else
                return -1;
        }
        return res;
    } else
        return -1;
}

int main() {
    printf("Input: base N(1<N<=16) and positive N-based integer C\n");
    char coes[32];
    int base, decnum;
    while(scanf("%d%s", &base, coes) != EOF) {
        decnum = nbase2dec(base, coes);
        printf("Convert to decimal integer: %d\n", decnum);
    }
    return 0;
}

