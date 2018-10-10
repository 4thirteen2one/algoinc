#include <stdio.h>
int main() {
    printf("\n- scanf的%%c格式可以读入空格和换行\n\n");
    char space, linefeed;
    printf("输入空格：\n");
    scanf("%c", &space);
    printf("输入换行符：\n");
    scanf("%c", &linefeed);
    printf("Hello%cworld!%c", space, linefeed); 
    return 0;
}
