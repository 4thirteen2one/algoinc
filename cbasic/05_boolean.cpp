#include <cstdio>
//bool型在C++中可以直接使用，在C中则需添加stdbool.h头文件

int main() {
    bool flag1 = 0, flag2 = true, flag3 = -1;
    //bool的取值只有true或false，分别代表非零和零
    //用整型常量赋值给bool型变量时会自动转换为true和false
    //即正整数和负整数都会转化为true，零会转化为0
    //用%d输出bool变量时：true会输出1，false会输出0
    int a = 1, b = 1;
    printf("%d %d %d %d\n", flag1, flag2, flag3, a==b);
    return 0;
}

