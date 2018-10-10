#include <cstdio>

#define ARR1D_LEN(arr) (sizeof(arr))/(sizeof(arr[0]))

void print1dIntarray(int* arr, int arrlen) {
    //数组名作为函数参数时，传入的其实是数组首元素的地址
    // 一个4字节的常量
    for(int i = 0; i < arrlen; i++) {
        printf("%d", arr[i]);
        if(i < arrlen-1) putchar(' ');
        else putchar('\n');
    }
}

void justinsertSort(int* arr, int arrlen, bool direction) {
    for(int i = 1; i < arrlen; i++) {
        int j, temp = arr[i];      //备份已有序部分的最后一个元素
        if(!direction) {
            for(j = i; j>0 && arr[j-1]>temp; --j)   //直到找到一个比temp大的
                arr[j] = arr[j-1];
        } else {
            for(j = i; j>0 && arr[j-1]<temp; --j)
                arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

/*
//从小到大进行排序
justinsertSort(int *arr, int arrlen) {
    int i, j, temp;
    for(i = 1; i < n; i++) {
        temp = arr[i];                //将要比较的值先绶存起来留出一个空位，方便移动
        j = i - 1;
        while(j>=0 && arr[j]>temp) {  //比较直到出现比temp大的值，或向前找到头
            arr[j+1] = arr[j];          //将前面的值往后移
            j--;
        }
        arr[j+1] = temp;                  //插在a[j]的后面
    }
}
*/

int main() {
    int arr[8] = {3, 1, 4, 1, 5, 9, 2, 6};
    int arrlen = ARR1D_LEN(arr);
    print1dIntarray(arr, arrlen);
    printf("                数组长度为：%d\n", arrlen);
    justinsertSort(arr, arrlen, 0);
    putchar('\n');
    print1dIntarray(arr, arrlen);
    return 0;
}

