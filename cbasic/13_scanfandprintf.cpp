#include <stdio.h>
int main() {
    //scanf
    printf("\n# `scanf(\"格式控制字符串\", 变量地址);`\n");

    printf("\nInput: -char, -char, -(int), -int, -int, -int, -str[10]\n");

    printf("\n- scanf的%%c格式可以读入空格和换行\n\n");
    char space, linefeed;
    printf("输入空格：\n");
    scanf("%c", &space);
    printf("输入换行符：\n");
    scanf("%c", &linefeed);
    printf("\nHello%cworld!%c\n", space, linefeed);

    printf("\n- scanf对其他格式符（如%%d）的输入以空白符（即空格、换行等）为结束判断标志\n\n");
    int b1, b2;
    printf("输入两个整数（例如输入“3 4”）\n");
    scanf("%d%d", &b1, &b2);
    printf("%d%d\n", b1, b2);

    printf("\n- scanf对字符串（char数组）使用%%s读入，以空格或换行为读入结束标志\n\n");
    printf("输入10个字符（例如输入“abcd efghij”）：");
    char str[10];
    scanf("%s", str);
    printf("（scanf读入char数组时，变量地址无需加&）\n");
    printf("%s\n", str);

    printf("\n- scanf()的格式控制串中可以使用其它非空白字符，但在输入时必须输入这些字符\n\n");
    int a1 = 1, a2 = 1;
    printf("a1 = %d, a2 = %d\n重新为a1和(a2)赋值: \n", a1, a2);
    scanf("%d", &a1);
    printf("a1 = %d\n", a1);
    scanf("(%d)", &a2);
    printf("(a2) = %d\n", a2);

    //printf
    printf("\n# `printf(\"格式控制字符串\", 变量名);`\n");

    printf("\n- double类型变量的输入格式为%%lf，输出格式为%%f\n");
    printf("\n- float的精度较低，建议使用double：\n");
    float f1 = 8765.4, f2 = 8765.4;
    double d1 = 8765.4, d2 = 8765.4;
    printf("float : 8765.4*8765.4 = %f\n", f1*f2);
    printf("double: 8765.4*8765.4 = %f\n", f1*f2);

    int h1 = 123, h2 = 1234567;
    printf("h1 = %d, h2 = %d\n", h1, h2);
    printf("\n- `%%md`，高位空格补齐：不足m位则在右填充空格对齐\n");
    printf("%5d\n%5d\n", h1, h2);
    printf("\n- `%%0md`，高位填零补齐：不足m位则在右用0填充对齐\n");
    printf("%05d\n%05d\n", h1, h2);

    printf("\n- `%%.mf`，保留m位小数\n");
    double d = 12.3456;
    printf("%.0f\n", d);
    printf("%.1f\n", d);
    printf("%.2f\n", d);
    printf("%.3f\n", d);
    printf("%.4f\n", d);

    return 0;
}
