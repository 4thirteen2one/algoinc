#include <cstdio>
#include "mylib.h"
//#include <string.h>
//#include <math.h>

const double PI = acos(-1.0);

void print1dIntarray(int* arr, int arrlen) {
    // 数组名作为函数参数时，传入的其实是数组首元素的地址
    // 一个4字节的常量
    for(int i = 0; i < arrlen; i++) {
        printf("%d", arr[i]);
        if(i < arrlen-1) putchar(' ');
        else putchar('\n');
    }
}

void show_n_char(char ch, int num) {
    for(int count = 1; count <= num; count++) {
        putchar(ch);
    }
}

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

char* dec2nbase(int decint, int base, char* coes) {
    if(decint >= 0) {       //保证输入的数为非负整数
        if(1<base && base<=16){                         //确保进制在2到16范围内
            int i = 0, temp[33] = {0};
            do {
                temp[i++] += decint%base;
                decint /= base;
            } while(decint != 0);                       //除基取余，保存至整形数组
            //print1dIntarray(temp, ARR1D_LEN(temp));
            //print1dIntarray(temp, i);
            for(int j = 0; j <= i-1; j++) {             //按高位到低位转化
                if(temp[i-1-j] < 10)
                    coes[j] = '0'+temp[i-1-j];
                else
                    coes[j] = 'A'+temp[i-1-j]-10;
            }
            //printf("%s\n", coes);
            return coes;
        } else
            return NULL;
    } else
        return NULL;
}

