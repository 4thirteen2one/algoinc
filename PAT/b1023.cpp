#include <cstdio>

int main() {
    int count[10];
    for(int i = 0; i < 10; i++)
        scanf("%d", &count[i]);

    for(int i = 1; i < 10; i++) {   //为第一位从1~9中选择最小的count不为0的数
        if(count[i] > 0) {
            printf("%d", i);
            count[i]--;
            break;  //因为count只存储各数位的数的个数
                    //所以一旦找到，即为最小，可马上退出循环
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) { //为剩余位从0~9中依次输出对应个数的数
            printf("%d", i);
        }
    }
    return 0;
}

