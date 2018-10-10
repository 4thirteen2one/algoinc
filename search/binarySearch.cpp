#include <cstdio>

void print1dIntarray(int* arr, int arrlen) {
    for(int i = 0; i < arrlen; i++) {
        printf("%d", arr[i]);
        if(i < arrlen-1) putchar(' ');
        else putchar('\n');
    }
}

int binarySearch(int A[], int left, int right, int x) {
    //在一个严格递增序列A中查找给定数x
    //非递归式写法
    int mid;
    while(left <= right) {
        mid = left + (right-left)/2;    //避免left+right溢出
        if(A[mid] == x)
            return mid;
        else if(A[mid] > x)     //若序列递减，改为A[mid] < x
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int binarySearch1stFit(int A[], int left, int right, int x) {
    //二分区间为左闭右闭的[left, right]，初值必须能覆盖解的所有可能取值
    int mid;
    while(left < right) {       //对[left, right]来说，left==right意味着找到唯一位置
        mid = left + (right-left)/2;
        if(A[mid] > x)         //条件成立，第一个满足条件的元素的位置<=mid
        // A[mid] <= x      //获取第一个大于等于x的元素的位置
        // A[mid] > x       //获取第一个大于x的元素的位置
            right = mid;        //往左子区间[left, mid]查找
        else                    //条件不成立，第一个满足条件的元素位置>mid
            left = mid + 1;     //往右子区间[mid+1,right]查找
    }
    return left;                //返回夹出来的位置
}


int main() {
    const int n = 10;
    int A[n] = {1, 3, 4, 6, 7, 8, 10, 11, 12, 15};
    print1dIntarray(A, n);
    int x;
    while(scanf("%d", &x) != EOF) {
        printf("Position found: %d\n", binarySearch(A, 0, n-1, x));
        printf("1stFit position found: %d\n", binarySearch1stFit(A, 0, n-1, x));
    }
    return 0;
}

