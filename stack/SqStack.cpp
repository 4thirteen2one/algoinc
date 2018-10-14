#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct {
    ElemType data[MAXSIZE];
    int top; /* 用于栈顶指针 */
} SqStack;

bool visit(ElemType e) {
    printf("%d ", e);
    return true;
}

/*  构造一个空栈S */
bool InitStack(SqStack *S) {
    /* S.data=(ElemType *)malloc(MAXSIZE*sizeof(ElemType)); */
    S->top = -1;
    return true;
}

/* 把S置为空栈 */
bool ClearStack(SqStack *S) {
    S->top = -1;
    return true;
}

/* 若栈S为空栈，则返回true，否则返回false */
bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else
        return false;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S) {
    return S.top+1;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回true；否则返回false */
bool GetTop(SqStack S, ElemType e) {
    if (S.top == -1)
        return false;
    else
        e = S.data[S.top];
    return true;
}

/* 插入元素e为新的栈顶元素 */
bool Push(SqStack *S, ElemType e) {
    if(S->top == MAXSIZE -1) {  //栈满
        return false;
    }
    S->top++;               /* 栈顶指针增加一 */
    S->data[S->top]=e;  /* 将新插入元素赋值给栈顶空间 */
    return true;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回true；否则返回false */
bool Pop(SqStack *S, ElemType *e) {
    if(S->top==-1)
        return false;
    *e = S->data[S->top]; /* 将要删除的栈顶元素赋值给e */
    S->top--;               /* 栈顶指针减一 */
    return true;
}

/* 从栈底到栈顶依次对栈中每个元素显示 */
bool StackTraverse(SqStack S) {
    int i = 0;
    while(i <= S.top) {
        visit(S.data[i++]);
    }
    printf("\n");
    return true;
}

int main()
{
    int j;
    SqStack s;
    int e;
    if(InitStack(&s) == true)
        for(j = 1; j <= 10; j++)
            Push(&s, j);
    printf("栈中元素依次为：");
    StackTraverse(s);
    Pop(&s, &e);
    printf("弹出的栈顶元素 e=%d\n", e);
    printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
    GetTop(s, e);
    printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));

    return 0;
}

