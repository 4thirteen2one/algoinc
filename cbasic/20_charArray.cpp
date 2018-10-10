#include <stdio.h>
#include "mylib.h"

void initChararray(void) {
    char s[] = {'G', 'o', 'o', 'd', ' ', 's', 't', 'o', 'r', 'y', '!'};
    // char s[] = "Good story!";
    int slen = ARR1D_LEN(s);
    for(int i = 0; i < slen; i++) {
        printf("%c", s[i]);
    }
    putchar('\n');
}

void scanf_printf(void) {
    char s[10];
    printf("scanf, printf\n");
    printf("输入长度为10的字符串：");
    scanf("%s", s);
    putchar('\n');
    printf("%s\n", s);
}

void getchar_putchar() {
    printf("\ngetchar：读入单个字符\nputchar：输出单个字符\n");
    char s[5][5];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            s[i][j] = getchar();
        }
        getchar();  //吸收每行结束的换行符
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            putchar(s[i][j]);
        }
        putchar('\n');
    }
}

void gets_puts(void){
    printf("\ngets识别换行符\\n作为输入结束标志\n");
    char s[5][5];
    for(int i = 0; i < 3; i++) {
        gets(s[i]);
    }
    for(int i = 0; i < 3; i++) {
        puts(s[i]);
    }
}

void ends4str(void) {
    printf("\ngets和scanf输入字符串时在末尾添加空字符\\0作为结束标志，占用一个字符位；\n");
    printf("puts和printf通过检测\\0来结束输出字符串\n");
    char s[15];
    for(int i = 0; i < 3; i++) {
        s[i] = getchar();
    }
    puts(s);
    printf("\n字符数组的长度一定比实际存储字符串长度至少多1\n");
}

int main() {
    initChararray();
    scanf_printf();
    getchar_putchar();
    gets_puts();
    ends4str();
    return 0;
}

