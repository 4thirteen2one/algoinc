#include <stdio.h>
#include <string.h>
#include "mylib.h"
int main() {
    printf("`strlen(string)`：得到字符数组中从指针所指位置到第一个\\0前的字符个数\n");
    printf("二维数组的列数至少多一位，用于存放\\0\n");
    char str[3][11];
    printf("输入3个长度为10的字符串\n");
    printf("（实际拿来存储这三个长度为10的字符串的二维字符数组维度为3×11）\n");
    for(int i = 0; i < 3; i++) {
        gets(str[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("str[%d]: ", i);
        puts(str[i]);
        printf("strlen(str[%d]) = %d\n", i, strlen(str[i]));
    }
    printf("可见，puts在输出字符串尾自动换行\n");
    putchar('\n');

    printf("`strcmp(str1, str2)`\n");
    printf("若str1的字典序小于str2，返回一个负整数\n");
    printf("若str1==str2，返回0\n");
    printf("若str1>str2，返回一个正整数\n");
    int cmp = strcmp(str[0], str[1]);
    if(cmp < 0) {
        printf("str[0] < str[1]\n");
    } else if(!cmp) {
        printf("str[0] == str[1]\n");
    } else {
        printf("str[0] > str[1]\n");
    }
    putchar('\n');

    printf("`strcpy(str1, str2)`: 把str2复制给str1（包括结束符\\0）\n");
    strcpy(str[0],str[1]);
    for(int i = 0; i < 3; i++) {
        puts(str[i]);
    }
    putchar('\n');

    printf("`strcat(str1, str2)`: 把str2接到str1后面（不包括结束符\\0）\n");
    char tmp[50];
    strcat(tmp, str[0]);
    puts(tmp);
    strcat(tmp, str[1]);
    puts(tmp);
    putchar('\n');

    printf("`sscanf(str, \"%%d\", &num)`：把字符数组str中的内容以%%d的格式写入num中\n");
    printf("`sprintf(str, \"%%d\", num)`：把num以%%d的格式写入到字符数组str中\n");
    char date[50] = "Sat Jul 14 07:14:20 CST 2018";
    puts(date);
    char dayow[4], mon[4], tzone[4];
    int day, hour, min, sec, year;
    sscanf(date, "%s %s %d %d:%d:%d %s %d", dayow, mon, &day, &hour, &min, &sec, tzone, &year);
    char dateinfo[100];
    sprintf(dateinfo, "Dayofweek: %s\nMonth: %s\nDay: %d\nTime: %d:%d:%d\nTimezone: %s\nYear: %d\n", dayow, mon, day, hour, min, sec, tzone, year);
    puts(dateinfo);
    return 0;
}


