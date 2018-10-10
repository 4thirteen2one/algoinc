#ifndef __MYLIB_H__
#define __MYLIB_H__

#include <cmath>
#include <cstring>
int nbase2dec(int, char*);
char* dec2nbase(int, int, char*);

#define ARR1D_LEN(arr) (sizeof(arr))/(sizeof(arr[0]))
// #define ARR1D_LEN(arr, arrlen) {arrlen = (sizeof(arr))/(sizeof(arr[0]));}
void print1dIntarray(int*, int);

const int INF = (1 << 30) - 1;
//const int INF = 0x3fffffff;

const double eps = 1e-8;
#define EQUAL_X(a, b) ((fabs((a)-(b)))<(eps))
#define GREATER(a, b) (((a)-(b))>(eps))
#define LESS(a, b) (((a)-(b))<(-eps))
#define GEQUAL(a,b) (((a)-(b))>(-eps))
#define LEQUAL(a,b) (((a)-(b))<(eps))

void show_n_char(char, int);

#endif //__MYLIB_H__

//编译：gcc mylib.c [filename.c] -o output

