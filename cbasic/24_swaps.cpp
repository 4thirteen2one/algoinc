#include <stdio.h>
void fakeswapint(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void fakeswapp(int* q, int *b) {
    int* temp = a;
    a = b;
    b = temp;
}

void pswap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maycausingERRswap(int* a, int* b) {
    int* temp;
    //temp未被初始化，故指针变量temp中存放的地址是随机的
    //很有可能指向的是系统工作区间
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void inittempswap(int* a, int* b) {
    int x;
    int* temp = &x;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void referswap(int* &p1, int* &p2) {
    //引用：C++的语法
    //引用不产生副本，只是给原变量起取了个别名
    //引用的使用方法：在函数参数类型后加个“&”
    //引用的&与取地址符&无关
    //
    //不可写成swap(&a, &b)，因为引用是对变量的引用
    //而此处&a和&b是常量
    //
    int* temp = p1;
    p1 = p2;
    p2 = temp;
}

