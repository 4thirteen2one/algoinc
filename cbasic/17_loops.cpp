#include <stdio.h>
void show_n_char(char ch, int num);
void whileanddo(void);
void forloop(void);
void breakandcontinue(void);

void show_n_char(char ch, int num) {
    for(int count = 1; count <= num; count++) {
        putchar(ch);
    }
}

void whileanddo() {
    printf("\nwhile\n");
    int n = 1, sum = 0;
    while(n <= 100) {
        sum += n;
        n++;
    }
    show_n_char(' ', 24);
    printf("%d\n", sum);
    
    printf("while(n) 等效于 while(n != 0)\n");
    printf("while(!n) 等效于 while(n == 0)\n");

    int m = 12345, count = 0;
    while(m) {
        count += m % 10;
        m /= 10;
    }
    printf("1 + 2 + 3 + 4 + 5 = %d\n", count);

    printf("\ndo...while\n");
    int i = 1, s = 0;
    do{
        s += i;
        i++;
    } while(i <= 100);
    show_n_char(' ', 24);
    printf("%d", s);

    printf("\ndo... while 会先执行循环一次，然后才去判断循环条件是否为真\n");                      
    printf("这使得 do... while 语句的实用性远不如 while \n");
}

void forloop() {
    printf("\nfor\n");
    int sum = 0;
    for(int i = 1; i <= 100; i++) {
        sum += i;
    }
    show_n_char(' ', 24);
    printf("%d", sum);

    printf("\nfor(循环变量赋初值; 循环条件; 循环变量改变) {\n    ...\n}\n");
    printf("1. 在for循环开始前，先执行表达式A\n2. 判断表达式B是否成立：若成立，执行省略内容；否则，退出循环\n3. 在省略内容执行完毕后，执行表达式C，然后回到[2]\n");
    printf("\nC语言中不允许在for语句中的表达式A里定义变量，但在C++中可以\n");
}

void breakandcontinue() {
    printf("\nbreak\n");

    int i, sum = 0;
    for(i = 1; i <= 100; i++){
        sum += i;
        if(sum >= 2000) break;
    }
    printf("i = %d, sum = %d >= 2000\n", i, sum);
    printf("break，直接退出循环\n");

    printf("\ncontinue\n");

    int n, s = 0;
    for (int n = 1; n <= 10; n++) {
        if(n%2 == 1) {
            printf("n = %d, n %% 2 == 1, s = %d\n", n, s);
            continue;
        }
        s += n;
    }
    printf("n = %d, s = %d\n", n, s);
    printf("continue，可跳过当前loop后的语句不执行，直接进入下一循环\n");
}

int main() {
     printf("1 + 2 + 3 + ... + 100 =\n");
     whileanddo();
     forloop();
     breakandcontinue();
}

