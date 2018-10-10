#include <cstdio>
#include <cstring>

char* dec2nbase(int decint, int base, char* coes) {
    if(1<base && base<=16){
        int i = 0, temp[33] = {0};
        do {
            temp[i++] += decint%base;
            decint /= base;
        } while(decint != 0);
        for(int j = 0; j <= i-1; j++) {
            if(temp[i-1-j] < 10)
                coes[j] = '0'+temp[i-1-j];
            else
                coes[j] = 'A'+temp[i-1-j]-10;
        }
        return coes;
    }
    else
        return NULL;
}

int main() {
    int a, b, d, sum;
    char coes[33];
    while(scanf("%d%d%d", &a, &b,&d) != EOF) {
        memset(coes, 0, sizeof(coes));
        sum = a + b;
        char* nbasenum = dec2nbase(sum, d, coes);
        printf("%s", nbasenum);
    }
    return 0;
}

