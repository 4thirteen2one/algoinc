#include <cstdio>
#include <cstring>

const int maxn = 256;                   //题目要求最大255，取256是留位给\0

bool judge(char* str) {
    int len = strlen(str);              //字符数组就是待遇好，自带长度函数
    for(int i = 0; i < len/2; i++) {    //不需要取到i==len/2，因为i最小为0
        if(str[i] != str[len-1-i])      //只要检测到一处不等，就不是回文串
            return false;               //无需确保每处相等只需找到一处不等
    }
    return true;
}

int main() {
    char str[maxn];
    while(gets(str)) {
        bool flag = judge(str);
        if(flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

