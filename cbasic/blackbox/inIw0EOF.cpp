#include <stdio.h>

int main()
{
    int a, b;
    printf("Input 2 int numbers:\n");
    while(scanf("%d%d", &a, &b) != EOF) {
        //scanf 函数的返回值反映的是按照指定的格式符正确读入的数据的个数。
        //如果输入数据与指定格式不符，则会产生输入错误。遇到输入错误，scanf函数会立即终止，返回已经成功读取的数据的个数。
        //所以，通过scanf函数的返回值和指定输入数据的个数（由格式符决定）的比较，可以判断数据输入是否成功。
        //EOF(End Of File) represents -1
        //表示"文字流"（stream）的结尾。这里的"文字流"，可以是文件（file），也可以是标准输入（stdin）。
        //如果在scanf的时候在终端输入ctrl+d，那么scanf的返回值将是-1=EOF
        //如果一个文件含有n个字符，那么while循环的内部操作会运行n+1次
        printf("sum = %d\n", a+b);
    }
    return 0;
}

