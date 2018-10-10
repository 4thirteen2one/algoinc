#include <cstdio>
#include <cstring>
//#include "mylib.h"

using namespace std;

char* dec2nbase(int decint, int base, char* coes) {
    if(decint>=0) {
        if(1<base && base<=16){
            int i = 0, temp[33] = {0};
            do {
                temp[i++] += decint%base;
                decint /= base;
            } while(decint != 0);
            //print1dIntarray(temp, ARR1D_LEN(temp));
            //print1dIntarray(temp, i);
            for(int j = 0; j <= i-1; j++) {
                if(temp[i-1-j] < 10)
                    coes[j] = '0'+temp[i-1-j];
                else
                    coes[j] = 'A'+temp[i-1-j]-10;
            }
            //printf("%s\n", coes);
            return coes;
        }
        else
            return NULL;
    } else
        return NULL;
}

int main() {
    printf("Input: decimal integer D and base N(1<N<=16)\n");
    int D, N;
    char coes[33];
    while(scanf("%d%d", &D,&N) != EOF) {
        memset(coes, 0, sizeof(coes));  //need "string.h"
        char* nbasenum = dec2nbase(D, N, coes);
        printf("Convert to %d-base integer: %s\n", N, nbasenum);
    }
    return 0;
}

